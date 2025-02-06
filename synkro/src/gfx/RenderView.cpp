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
// Purpose: Rendering view implementation.
//==============================================================================
#include "config.h"
#include "RenderView.h"
#include "Program.h"
#include "GraphicsDevice.h"


//------------------------------------------------------------------------------

using namespace synkro::img;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


RenderView::RenderView( GraphicsDevice* device, IRenderWindow* window, IProgram* programPass, IProgram* program, IBlendStateSet* blendStateEnabled, IBlendStateSet* blendStateDisabled, const PixelFormat& format, const DepthFormat& depthFormat, Int left, Int top, UInt width, UInt height, UInt sampleCount, const Vector4& color ) :
	_device( device ),
	_window( window ),
	_programPass( programPass ),
	_program( program ),
	_blendStateEnabled( blendStateEnabled ),
	_blendStateDisabled( blendStateDisabled ),
	_scene( nullptr ),
	_vertexParams( nullptr ),
	_vertexResources( nullptr ),
	_fragmentParams( nullptr ),
	_leftVertexParams( nullptr ),
	_rightVertexParams( nullptr ),
	_colorTarget( nullptr ),
	_depthTexture( nullptr ),
	_visible( true ),
	_showStencil( false ),
	_left( left ),
	_top( top ),
	_width( width ),
	_height( height ),
	_windowWidth( window->GetWidth() ),
	_windowHeight( window->GetHeight() ),
	_sampleCount( sampleCount ),
	_dataNdc( window, width, height ),
	_screenNdc( window, window->GetWidth(), window->GetHeight() ),
	_fill( FillMode::Solid ),
	_leftMask( PixelChannel::All ),
	_rightMask( PixelChannel::All ),
	_format( format ),
	_depthFormat( depthFormat ),
	_backColor( 0.0f, 0.0f, 0.0f, 0.0f ),
	_overlayColor( 1.0f, 1.0f, 1.0f, 1.0f ),
	_frameCount( 0 ),
	_gatherStats( false ),
	_delta( 0.0 ),
	_overlays( A(OverlayEntry) )
{
	// Clone parameters.
	_params = _program->GetFragmentStage()->GetParameters()->Clone( this->ID(), true );
	_paramColor = _params->GetParam( L"p_color" );
	_params->Set( _paramColor, Vector4(1.0f, 1.0f, 1.0f, 1.0f) );

	// Create textures.
	CreateTextures();

	// Prepare view-specific geometry.
	_data = (Primitive*)_device->CreatePrimitive( _program, DataUsage::Dynamic, DataAccess::WriteOnly, PrimitiveType::TriangleStrip, IndexType::None, 4, 0, 0, 0, true, false );
	_data->Prepare( &_dataNdc );
	FillData( _data, 0, 0, _width, _height );

	// Prepare screen-specific geometry.
	_screen = (Primitive*)_device->CreatePrimitive( _program, DataUsage::Dynamic, DataAccess::WriteOnly, PrimitiveType::TriangleStrip, IndexType::None, 4, 0, 0, 0, true, false );
	_screen->Prepare( &_screenNdc );
	FillData( _screen, _left, _top, _width, _height );

	// Set background color.
	SetBackColor( color );
}

RenderView::RenderView() :
	_device( nullptr ),
	_window( nullptr ),
	_program( nullptr ),
	_blendStateEnabled( nullptr ),
	_blendStateDisabled( nullptr ),
	_scene( nullptr ),
	_postProcess( nullptr ),
	_leftVertexParams( nullptr ),
	_rightVertexParams( nullptr ),
	_colorTarget( nullptr ),
	_depthTexture( nullptr ),
	_left( 0 ),
	_top( 0 ),
	_width( 0 ),
	_height( 0 ),
	_windowWidth( 0 ),
	_windowHeight( 0 ),
	_dataNdc( nullptr, 0, 0 ),
	_screenNdc( nullptr, 0, 0 ),
	_fill( FillMode::Solid ),
	_leftMask( PixelChannel::All ),
	_rightMask( PixelChannel::All ),
	_backColor( 0.0f, 0.0f, 0.0f, 0.0f ),
	_overlayColor( 1.0f, 1.0f, 1.0f, 1.0f ),
	_overlays( A(OverlayEntry) )
{
}

void RenderView::EnablePostProcess()
{
	if ( _postProcess == nullptr )
	{
		_quad = (Primitive*)_device->CreatePrimitive( _program, DataUsage::Dynamic, DataAccess::WriteOnly, PrimitiveType::TriangleStrip, IndexType::None, 4, 0, 0, 0, true, false );
		_quad->Prepare( &_dataNdc );
		FillData( _quad, 0, 0, _window->GetWidth(), _window->GetHeight() );

		_postProcess = new PostProcessRenderQueue( (IGraphicsDevice*)_device, this, _programPass );
		_postProcess->SetInput( _colorTarget );
	}
}

void RenderView::Resize()
{
	_width *= CastFloat(_window->GetWidth())/CastFloat(_windowWidth);
	_height *= CastFloat(_window->GetHeight())/CastFloat(_windowHeight);
	_windowWidth = _window->GetWidth();
	_windowHeight = _window->GetHeight();

	// See what is the type of post-process queue input.
	Bool inputIsDepth = false;
	if ( _postProcess != nullptr )
	{
		IResource* input = _postProcess->GetInput();
		inputIsDepth = (input->AsDepthTexture() != nullptr);
	}

	// Re-create textures.
	CreateTextures();

	// Update view-specific geometry.
	_dataNdc.Update();
	_data->Update();
	FillData( _data, 0, 0, _width, _height );

	// Update screen-specific geometry.
	_screenNdc.Update();
	_screen->Update();
	FillData( _screen, _left, _top, _width, _height );

	// Update background.
	const Vector4 color = _backColor;
	_backColor = Vector4( 0.0f, 0.0f, 0.0f, 0.0f );
	SetBackColor( color );

	// Update references to inputs and targets.
	if ( _postProcess != nullptr )
	{
		_postProcess->SetInput( inputIsDepth ? (IResource*)_depthTarget : _colorTarget );
		_postProcess->Resize();
	}
}

void RenderView::Draw( Double delta, GraphicsStats& stats )
{
	// Gather view stats, if needed.
	if ( _gatherStats )
	{
		++_frameCount;
		_delta += delta;
		if ( _delta >= 1.0 )
		{
			_stats.FramesPerSecond = CastFloat(_frameCount)/CastFloat(_delta);
			_frameCount = 0; _delta = 0.0;
		}
	}

	// Render view contents.
	if ( this->GetColorTarget()->Bind() )
	{
		_targetIndex = 0;
		this->GetColorTarget()->Clear();

		// Render scene.
		if ( _vertexParams != nullptr )
		{
			_vertexParams->Bind();
		}
		if ( _vertexResources != nullptr )
		{
			_vertexResources->Bind();
		}
		if ( _fragmentParams != nullptr )
		{
			_fragmentParams->Bind();
		}
		this->GetDepthTarget()->Clear();
		if ( _scene != nullptr )
		{
			_scene->Process( this, false, _fill, _leftMask, _leftVertexParams, stats );
			if ( _leftMask != _rightMask )
			{
				this->GetDepthTarget()->Clear();
				_scene->Process( this, false, _fill, _rightMask, _rightVertexParams, stats );
			}

			// Draw line geometry.
			_scene->ProcessLines( stats );
		}
	
		// Present results.
		if ( !this->GetColorTarget()->Present() )
			return;

		// Visualize stancil buffer, if needed.
		if ( _showStencil )
		{
			// NB: Render quad in pixels where stencil != 0;
			// Prepare enabled stencil state + turn the depth off.
			// NB: Only if depth format has stencil enabled, otherwise ignore.
		}

		// Perform post-processing.
		const UInt cnt = (_postProcess != nullptr) ? _postProcess->Process( this, this->GetColorTarget() ) : 0;

		// Draw scene in overlay mode.
		const Bool drawOverlays = (_overlays.Size() > 0) && (_scene != nullptr);
		if ( drawOverlays )
		{
			_scene->Process( this, true, _fill, _leftMask, _leftVertexParams, stats );
		}

		// Swap targets.
		if ( cnt > 0 )
		{
			_targetIndex = (_targetIndex == 0) ? 1 : 0;
			_backBuffer = _targets[_targetIndex];
		}
		else
		{
			_backBuffer = this->GetColorTarget();
		}

		// Present results.
		if ( drawOverlays )
		{
			_backBuffer->Present();
		}
	}
}

void RenderView::CreateTextures()
{
	_targets.Clear();
	_depthTexture = _device->CreateDepthTexture( _width, _height, _format, _depthFormat, false, _sampleCount, 0 );
	_targets.Add( _device->CreateRenderTexture(_width, _height, _format, _sampleCount, 0) );
	_targets.Add( _device->CreateRenderTexture(_width, _height, _format, _sampleCount, 0) );
	for ( UInt i = 0; i < _targets.Size(); ++i )
	{
		_targets[i]->SetDepthTexture( _depthTexture );
	}
	_colorTexture = _device->CreateRenderTexture( _width, _height, _format, _sampleCount, 0 );
	_colorTexture->SetDepthTexture( _depthTexture );
	_colorTarget = _colorTexture;
	_depthTarget = _depthTexture;
}

void RenderView::FillData( IPrimitiveEx* data, Int left, Int top, UInt width, UInt height )
{
	P(IVector4Stream) streamPos = (IVector4Stream*)data->GetVertexStream( DataStream::Position2D, 0 );
	if ( (streamPos != nullptr) && streamPos->Open(OpenMode::Write) )
	{
		const Vector4 pos[] =
		{
			Vector4( left,			top,		0.0f, 1.0f ),
			Vector4( left+width,	top,		0.0f, 1.0f ),
			Vector4( left,			top+height,	0.0f, 1.0f ),
			Vector4( left+width,	top+height,	0.0f, 1.0f ),
		};
		streamPos->Write( pos, 4 );
		streamPos->Close();
	}

	P(IVector2Stream) streamTexCoord = (IVector2Stream*)data->GetVertexStream( DataStream::TexCoord2D, 0 );
	if ( (streamTexCoord != nullptr) && streamTexCoord->Open(OpenMode::Write) )
	{
		GraphicsDeviceDesc desc;
		_device->GetDesc( desc );
		const Vector2 coords[] = 
		{
			Vector2( 0.0f, desc.TopDown ? 1.0f : 0.0f ),
			Vector2( 1.0f, desc.TopDown ? 1.0f : 0.0f ),
			Vector2( 0.0f, desc.TopDown ? 0.0f : 1.0f ),
			Vector2( 1.0f, desc.TopDown ? 0.0f : 1.0f ),
		};
		streamTexCoord->Write( coords, 4 );
		streamTexCoord->Close();
	}
}


} // gfx


} // synkro
