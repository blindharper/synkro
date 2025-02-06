//==============================================================================
// This file is a part of the Synkro Framework.
// 
// Copyright (c) Nobody. No rights reserved ;-7
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is allowed without any permission from the Synkro Project.
// Website: https://synkro.pro Email: mailto:blindharper70@gmail.com
//
// Purpose: Viewport implementation.
//==============================================================================
#include "config.h"
#include "Viewport.h"
#include "ViewportAnimationController.h"
#include "ViewportManager.h"
#include "ViewModeConst.h"
#include "StereoModeConst.h"
#include <audio/IAudioEnvironment.h>
#include <scene/BaseCamera.h>
#include <math/Math.h>
#include <scene/ISceneEx.h>
#include <scene/ITriangleMesh.h>
#include <scene/ITriangleSet.h>
#include <view/ViewportFilter.h>
#include <view/IDepthFilter.h>
#include <gfx/IGraphicsDevice.h>
#include <gfx/IPlainRenderTexture.h>
#include <gfx/IPostProcessRenderQueue.h>
#include <internal/SafeDelete.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::audio;
using namespace synkro::core;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::lang;
using namespace synkro::math;
using namespace synkro::scene;

//------------------------------------------------------------------------------


namespace synkro
{


namespace view
{


Viewport::Viewport( BaseViewportManager* viewportManager, IContext* context, IRenderView* view, ICamera* camera ) :
	_filters( A(IViewportFilter*) ),
	_viewportManager( viewportManager ),
	_context( context ),
	_view( view ),
	_alphaFilter( nullptr ),
	_depthFilter( nullptr ),
	_camera( nullptr ),
	_labelColor( Color::White ),
	_labelVisible( false ),
	_borderColor( Color::White ),
	_borderVisible( false ),
	_viewMode( ViewMode::Color ),
	_stereoMode( StereoMode::None ),
	_boundsDirty( true )
{
	assert( _view != nullptr );

	SetCamera( camera );

	Int left; Int top; Int right; Int bottom;
	_view->GetBounds( left, top, right, bottom );
	_location.X = left;
	_location.Y = top;
	_size.Width = (right-left);
	_size.Height = (bottom-top);

	_viewportManager->AddViewport( this );
}

Viewport::~Viewport()
{
	_viewportManager->RemoveViewport( this );
}

IViewportAnimationController* Viewport::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new ViewportAnimationController( this, _context->GetAnimationSystem(), animation, listener) : _ctrlAnimation;
}

IViewportFilter* Viewport::CreateFilter( const ViewportFilter& type )
{
	return _viewportManager->CreateFilter( this, type );
}

IDepthMap* Viewport::CreateDepthTarget()
{
	if ( _depthTarget == nullptr )
	{
		IPlainDepthTexture* depthTexture = _view->GetDepthTarget();
		if ( (depthTexture == nullptr) || (depthTexture->GetFormat() != DepthFormat::D32F) )
		{
			Int left; Int top; Int right; Int bottom;
			_view->GetBounds( left, top, right, bottom );
			depthTexture = _context->GetGraphicsSystem()->GetDevice()->CreateDepthTexture( (right-left), (bottom-top), _view->GetWindow()->GetPixelFormat(), DepthFormat::D32F, false, 1, 0 );
		}
		_depthTarget = new DepthMap( depthTexture );
		_view->SetDepthTarget( _depthTarget->GetTexture() );
	}
	return _depthTarget;
}

void Viewport::Activate()
{
	_viewportManager->SetActiveViewport( this );
	if ( _camera != nullptr )
	{
		AsBaseCamera( _camera.AsPtr() )->Activate();
	}
}

void Viewport::SetCamera( ICamera* camera )
{
	if ( camera != _camera )
	{
		if ( camera != nullptr )
		{
			ISceneEx* scene = camera->GetSceneEx();
			BaseScene* baseScene = AsBaseScene( scene );
			_view->SetQueue( scene->GetRenderQueue() );
			_view->SetVertexParams( baseScene->GetVertexParams() );
			_view->SetVertexResources( baseScene->GetVertexResources() );
			_view->SetFragmentParams( baseScene->GetFragmentParams() );
			IProgram* program = _context->GetGraphicsSystem()->GetProgram(scene->IsLit() ? L"viewport.lit" : L"viewport");
			if ( program != _program )
			{
				_paramsLeft.Init( program->GetVertexStage()->GetParameters()->Clone(this->ID(), true) );
				_paramsRight.Init( nullptr );
				_program = program;
			}
		}
		else
		{
			_view->SetQueue( nullptr );
		}

		if ( _camera != nullptr )
		{
			AsBaseScene( _camera->GetSceneEx() )->DecrementCameraCount();
		}
		_camera = camera;
		if ( _camera != nullptr )
		{
			AsBaseScene( _camera->GetSceneEx() )->IncrementCameraCount();
			if ( this == dynamic_cast<IViewportManager*>(_viewportManager)->GetActiveViewport() )
			{
				AsBaseCamera( _camera.AsPtr() )->Activate();
			}
		}

		// Update viewport label.
		SetLabelText( _labelText );
	}
}

void Viewport::SetViewMode( const ViewMode& viewMode )
{
	if ( viewMode != _viewMode )
	{
		switch ( viewMode )
		{
			case VIEW_MODE_COLOR:
				// Deactivate irrelevant filters.
				if ( _depthFilter != nullptr )
				{
					_depthFilter->Enable( false );
				}

				if ( _alphaFilter != nullptr )
				{
					_alphaFilter->Enable( false );
				}

				_view->ShowStencil( false );

				// Set targets.
				_view->SetDepthTarget( nullptr );
				_view->GetPostProcessQueue()->SetInput( _view->GetColorTarget() );
				break;

			case VIEW_MODE_ALPHA:
				assert( _view->GetColorTarget()->GetFormat().HasAlpha() );

				if ( _alphaFilter == nullptr )
				{
					_alphaFilter = CreateFilter( ViewportFilter::Alpha );
				}

				// Activate alpha channel filter.
				_alphaFilter->Enable( true );
				_alphaFilter->SetOrder( 0 );

				// Deactivate irrelevant filters.
				if ( _depthFilter != nullptr )
				{
					_depthFilter->Enable( false );
				}
				_view->ShowStencil( false );

				// Set targets.
				_view->GetPostProcessQueue()->SetInput( _view->GetColorTarget() );
				break;

			case VIEW_MODE_DEPTH:
				// Create custom depth target, if needed.
				CreateDepthTarget();

				// Create depth filter, if needed.
				if ( _depthFilter == nullptr )
				{
					_depthFilter = CreateFilter( ViewportFilter::Depth )->AsDepth();
				}

				// Activate depth filter.
				if ( _camera != nullptr )
				{
					_depthFilter->Enable( true );
					_depthFilter->SetOrder( 0 );
					_depthFilter->SetCamera( _camera );
					_depthFilter->SetDepthMap( _depthTarget );
					_view->SetDepthTarget( _depthTarget->GetTexture() );
					_view->GetPostProcessQueue()->SetInput( _depthTarget->GetResource() );
				}

				// Deactivate irrelevant filters.
				if ( _alphaFilter != nullptr )
				{
					_alphaFilter->Enable( false );
				}
				_view->ShowStencil( false );
				break;

			case VIEW_MODE_STENCIL:
				_view->ShowStencil( true );
				break;
		}
		_viewMode = viewMode;
	}
}

void Viewport::SetStereoMode( const StereoMode& stereoMode )
{
	if ( stereoMode != _stereoMode )
	{
		PixelChannel leftMask( PixelChannel::All );
		PixelChannel rightMask( PixelChannel::All );
		switch ( stereoMode )
		{
			case STEREO_MODE_RED_CYAN:
				leftMask = PixelChannel::Red;
				rightMask = PixelChannel::Green|PixelChannel::Blue;
				break;

			case STEREO_MODE_GREEN_MAGENTA:
				leftMask = PixelChannel::Green;
				rightMask = PixelChannel::Red|PixelChannel::Blue;
				break;

			case STEREO_MODE_BLUE_YELLOW:
				leftMask = PixelChannel::Blue;
				rightMask = PixelChannel::Red|PixelChannel::Green;
				break;

			case STEREO_MODE_CYAN_RED:
				leftMask = PixelChannel::Green|PixelChannel::Blue;
				rightMask = PixelChannel::Red;
				break;

			case STEREO_MODE_MAGENTA_GREEN:
				leftMask = PixelChannel::Red|PixelChannel::Blue;
				rightMask = PixelChannel::Green;
				break;

			case STEREO_MODE_YELLOW_BLUE:
				leftMask = PixelChannel::Red|PixelChannel::Green;
				rightMask = PixelChannel::Blue;
				break;
		}
		_view->SetLeftChannelMask( leftMask );
		_view->SetRightChannelMask( rightMask );
		_stereoMode = stereoMode;
	}
}

void Viewport::ShowBorder( Bool show )
{
	_borderVisible = show;
	Bool visible = IsVisible() && _borderVisible;
	if ( visible && (_border == nullptr) )
	{
		_border = _viewportManager->CreatePolyLine( _view, 5, _borderColor );
	}
	if ( _border != nullptr )
	{
		_border->Show( visible );
		_border->SetOpacity( GetOpacity() );
	}
}

void Viewport::ShowLabel( Bool show )
{
	_labelVisible = show;
	Bool visible = IsVisible() && _labelVisible;
	if ( visible && (_label == nullptr) )
	{
		String text = _labelText;
		if ( text.IsNullOrEmpty() && (_camera != nullptr) )
		{
			text = _camera->GetName();
		}
		const Point loc( _location.X+8, _location.Y+_size.Height-28 );
		_label = _viewportManager->CreateLabel( _view, _labelColor, loc, text );
	}
	if ( _label != nullptr )
	{
		_label->Show( visible );
		_label->SetOpacity( GetOpacity() );
	}
}

void Viewport::Show( Bool show )
{
	_view->Show( show );
	if ( _border != nullptr)
	{
		_border->Show( show && _borderVisible );
	}
	if ( _label != nullptr )
	{
		_label->Show( show && _labelVisible );
	}
}

void Viewport::MakeOverlay( ITriangleMesh* mesh, Bool overlay )
{
	assert( mesh != nullptr );

	for ( UInt i = 0; i < mesh->GetSubsetCount(); ++i )
	{
		ISceneRenderObject* obj = mesh->GetSubset( i )->AsTriangleSet()->GetRenderObject();
		_view->MakeOverlay( obj, overlay );
	}
}

ITriangleMesh* Viewport::PickMesh( const Point& location, Float* distance ) const
{
	// Get underlying scene.
	if ( _camera == nullptr )
		return nullptr;

	// Convert point coordinates to NDC.
	const Float x = (2.0f*CastFloat(location.X)/CastFloat(_size.Width))-1.0f;
	const Float y = 1.0f-(2.0f*CastFloat(location.Y)/CastFloat(_size.Height));

	// Convert NDC coordinates to 3D ray.
	const Float front = _camera->GetFront();
	const Float dx = Math::Tan(_camera->GetHorizontalFieldOfView()*0.5f) * front * x;
	const Float dy = Math::Tan(_camera->GetVerticalFieldOfView()*0.5f) * front * y;
	Matrix4x4 transCamera; _camera->GetWorldTransform( transCamera );
	const Vector3 origin = transCamera.Translation();
	const Vector3 target = origin + (transCamera.Right() * dx) + (-transCamera.Up() * dy) + (transCamera.Forward() * front);
	Vector3 direction = (target - origin); direction.Normalize();

	// Let the scene do the rest.
	return _camera->GetSceneEx()->PickMesh( origin, direction, distance );
}

Bool Viewport::IsOverlay( ITriangleMesh* mesh ) const
{
	assert( mesh != nullptr );

	if ( mesh->GetSubsetCount() == 0 )
		return false;

	ISceneRenderObject* obj = mesh->GetSubset( 0 )->AsTriangleSet()->GetRenderObject();
	return _view->IsOverlay( obj );
}

void Viewport::AddFilter( IViewportFilter* filter )
{
	_filters.Add( filter );
}

void Viewport::RemoveFilter( IViewportFilter* filter )
{
	_filters.Remove( filter );
}

void Viewport::SetActive( Bool active )
{
	if ( (_camera != nullptr) && (_camera->GetSceneEx()->GetAudioEnvironment() != nullptr) )
	{
		_camera->GetSceneEx()->GetAudioEnvironment()->Activate();
	}
	SetBorderColor( active ? Color::White : Color::Black );
}

void Viewport::Update()
{
	// See if the underlying rendering view has been resized due to the window resize.
	Int left = 0; Int top = 0; Int right = 0; Int bottom = 0;
	_view->GetBounds( left, top, right, bottom );
	UInt width = right - left; UInt height = bottom - top;
	const Bool resized = (width != _size.Width) || (height != _size.Height);

	// Reposition view, if needed.
	if ( _boundsDirty || resized )
	{
		left = _location.X; top = _location.Y;
		if ( _boundsDirty )
		{
			width = _size.Width;
			height = _size.Height;
		}
		else
		{
			_size.Width = width;
			_size.Height = height;
		}
		if ( _border != nullptr )
		{
			Point pos[] =
			{
				Point( left+2,		top+2 ),
				Point( left+width,	top+2 ),
				Point( left+width,	top+height ),
				Point( left+2,		top+height ),
				Point( left+2,		top ),
			};
			_border->SetPositions( pos );
		}
		if ( _label != nullptr )
		{
			_label->SetLocation( Point(left+8, top+height-28) );
		}
		if ( _boundsDirty )
		{
			_view->SetBounds( _location.X, _location.Y, _location.X+width, _location.Y+height );
		}
		if ( _camera != nullptr )
		{
			// Update camera aspect ratio.
			_camera->SetAspect( CastFloat(width)/CastFloat(height) );
		}
		_boundsDirty = false;
	}

	if ( _camera == nullptr )
		return;

	// Update filters.
	_filters.Each( *this );

	// Set render view parameters.
	if ( (_stereoMode != StereoMode::None) && (_stereoMode != StereoMode::True) )
	{
		if ( _camera->GetEyeDistance() == 0.0f )
		{
			_camera->SetEyeDistance( 0.005f );
		}
		// Set right channel's stuff, if stereo mode is active.
		Matrix4x4 transView; _camera->GetViewTransform( transView );
		Matrix4x4 transProj; _camera->GetProjectionTransform( transProj );
		_camera->GetLeftViewTransform( transView );
		_paramsLeft.Set( transView, transProj );
		_view->SetLeftChannelVertexParams( _paramsLeft.Params );

		// Make sure the right channel's stuff is initialized.
		if ( _paramsRight.Params == nullptr )
		{
			_paramsRight.Init( _paramsLeft.Params->Clone(_paramsLeft.Params->ID(), true) );
		}
		_camera->GetRightViewTransform( transView );
		_paramsRight.Set( transView, transProj );
		_view->SetRightChannelVertexParams( _paramsRight.Params );
	}
	else
	{
		Matrix4x4 transView; _camera->GetViewTransform( transView );
		Matrix4x4 transProj; _camera->GetProjectionTransform( transProj );
		_paramsLeft.Set( transView, transProj );
		_view->SetLeftChannelVertexParams( _paramsLeft.Params );
	}
}


} // view


} // synkro
