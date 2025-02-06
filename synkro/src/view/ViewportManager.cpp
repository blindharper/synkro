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
// Purpose: Viewport manager implementation.
//==============================================================================
#include "config.h"
#include "ViewportManager.h"
#include "ViewportTransitionController.h"
#include <view/ViewportListener.h>
#include <over/IOverlayManager.h>
#include <over/IOverlay.h>
#include <scene/BaseScene.h>
#include <scene/NodeImpl.h>
#include <scene/ITriangleMesh.h>
#include <scene/ITriangleSet.h>
#include <core/IContext.h>
#include <gfx/IFrameRenderWindowEx.h>
#include <gfx/IViewRenderWindowEx.h>
#include <gfx/ISceneRenderObject.h>
#include <win/IWindowSystemEx.h>
#include <win/IFrameWindowEx.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::audio;
using namespace synkro::core;
using namespace synkro::diag;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::lang;
using namespace synkro::math;
using namespace synkro::over;
using namespace synkro::scene;
using namespace synkro::win;

//------------------------------------------------------------------------------


namespace synkro
{


namespace view
{


ViewportManager::ViewportManager( IContext* context, ILog* log ) :
	_transitionEvents( A(TransitionEvent) ),
	_viewports( A(BaseViewport*) ),
	_transitionControllers( A(BaseViewportTransitionController*) ),
	_filterFactories( A(FactoryEntry) ),
	_views( A(ViewEntry) ),
	_context( context ),
	_activeViewport( nullptr ),
	Logger( log, LogFacility::ViewportManager )
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Creating viewport manager...") );
}

ViewportManager::~ViewportManager()
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Destroying viewport manager...") );
}

Bool ViewportManager::Update( Double delta )
{
	SynkroProfile( "ViewportManager.Update" );

	// Perform frustum culling test.
	for ( UInt i = 0; i < _viewports.Size(); ++i )
	{
		// Skip invisible viewports.
		IViewport* viewport = _viewports[i]->AsViewport();
		if ( !viewport->IsVisible() )
			continue;

		// Test triangle meshes for visibility.
		ICamera* camera = viewport->GetCamera();
		if ( camera == nullptr )
			continue;

		INode* root = camera->GetSceneEx()->GetRoot();
		for ( INode* node = root; node != nullptr; node = ((NodeImpl<INode>*)node)->GetNextNode() )
		{
			// See if we found a mesh.
			IMesh* mesh = node->AsMesh();
			if ( mesh == nullptr )
				continue;

			// Skip invisible meshes.
			if ( !mesh->IsVisible() )
				continue;

			// Skip non-triangle meshes.
			ITriangleMesh* triangleMesh = mesh->AsTriangle();
			if ( triangleMesh == nullptr )
				continue;

			// Skip batches.
			if ( triangleMesh->AsBatch() != nullptr )
				continue;

			Matrix4x4 trans; triangleMesh->GetWorldTransform( trans );
			Vector3 position = trans.Translation();
			Vector3 center; triangleMesh->GetCenter( center );
			const Float radius = triangleMesh->GetBoundSphere();
			const Bool renderable = camera->IsInView( position+center, radius );
			for ( UInt k = 0; k < triangleMesh->GetSubsetCount(); ++k )
			{
				ITriangleSet* subset = triangleMesh->GetSubset( k )->AsTriangleSet();
				subset->GetRenderObject()->SetRenderable( viewport->GetView(), renderable );
			}
		}
	}

	// Update viewports.
	_viewports.Each( *this );

	// Update transition controllers.
	for ( UInt i = 0; i < _transitionControllers.Size(); ++i )
	{
		BaseViewportTransitionController* controller = _transitionControllers[i];
		IViewportTransitionController* ctrl = dynamic_cast<IViewportTransitionController*>( controller );
		if ( ctrl->GetState() == ControllerState::Active )
		{
			ctrl->Update( delta );
			controller->PostUpdate();
		}
	}

	// Notify listeners.
	for ( UInt i = 0; i < _transitionEvents.Size(); ++i )
	{
		TransitionEvent& event = _transitionEvents[i];
		switch ( event.Type )
		{
			case TRANSITION_EVENT_STOP: event.Listener->OnViewportTransitionStop( event.Sender ); break;
			case TRANSITION_EVENT_LOOP: event.Listener->OnViewportTransitionLoop( event.Sender ); break;
		}
	}
	_transitionEvents.Clear();

	return true;
}

IViewport* ViewportManager::CreateViewport( IFrameRenderWindowEx* window, const Rect& rect, ICamera* camera, const Color& color )
{
	IRenderView* view = window->CreateView( rect.Left, rect.Top, rect.Width(), rect.Height(), window->GetSampleCount(), ToVector(color) );
	return CreateViewport( view, camera );
}

IViewport* ViewportManager::CreateViewport( IRenderView* view, ICamera* camera )
{
	assert( view != nullptr );

	return _views.ContainsKey(view->ID()) ? _views[view->ID()]->AsViewport() : new Viewport( this, _context, view, camera );
}

IViewportTransitionController* ViewportManager::CreateTransitionController( ViewportListener* listener )
{
	return new ViewportTransitionController( this, listener );
}

IViewport* ViewportManager::GetViewport( IFrameRenderWindowEx* window, const Point& location ) const
{
	assert( window != nullptr );

	if ( window == nullptr )
		throw BadArgumentException( L"Bad window", L"window", L"nullptr" );

	IRenderView* view = nullptr;
	Int left = 0; Int top = 0; Int right = 0; Int bottom = 0;
	for ( UInt i = 0; i < window->GetViewCount(); ++i )
	{
		IRenderView* v = window->GetView( i );
		if ( !v->IsVisible() )
			continue;

		v->GetBounds( left, top, right, bottom );
		if ( (location.X >= left) && (location.X <= right) &&
			 (location.Y >= top) && (location.Y <= bottom) )
		{
			view = v;
		}
	}

	return (view != nullptr) ? GetViewport( view ) : nullptr;
}

IViewportFilter* ViewportManager::CreateFilter( IViewport* viewport, const ViewportFilter& type )
{
	if ( !_filterFactories.ContainsKey(type) )
		throw BadArgumentException( String::Format(L"Failed to create viewport filter of type {0}.", type.ToString()), L"type", type.ToString() );

	viewport->GetView()->EnablePostProcess();
	IViewportFilterFactory* factory = _filterFactories[type];
	return factory->Create( viewport, _context );
}

IText* ViewportManager::CreateLabel( IRenderView* view, const Color& color, const Point& location, const String& text )
{
	if ( _context->GetOverlayManager() == nullptr )
		return nullptr;

	IOverlay* overlay = _context->GetOverlayManager()->GetOverlay(view->GetWindow());
	_fontLabel = (overlay != nullptr) ? overlay->GetFont( L"Label" ) : nullptr;
	return (_fontLabel != nullptr) ? _fontLabel->CreateText( color, location, text, Order::Highest, Order::Highest ) : nullptr;
}

IPolyLine* ViewportManager::CreatePolyLine( IRenderView* view, UInt pointCount, const Color& color )
{
	if ( _context->GetOverlayManager()==nullptr )
		return nullptr;

	IOverlay* overlay = _context->GetOverlayManager()->GetOverlay(view->GetWindow());
	return (overlay != nullptr) ? overlay->CreatePolyLine( pointCount, 2, color ) : nullptr;
}

void ViewportManager::SetActiveViewport( BaseViewport* viewport )
{
	assert( viewport != nullptr );

	if ( viewport != _activeViewport )
	{
		AsBaseViewport( viewport )->SetActive( true );
		if ( _activeViewport != nullptr )
		{
			AsBaseViewport( _activeViewport )->SetActive( false );
		}
		_activeViewport = viewport;
	}
}

void ViewportManager::AddViewport( BaseViewport* viewport )
{
	_viewports.Add( viewport );
	_views[viewport->AsViewport()->GetView()->ID()] = viewport;
}

void ViewportManager::Init()
{
	// Create label font.
	if ( _context->GetOverlayManager() != nullptr )
	{
		_context->GetOverlayManager()->CreateFont(L"Label", Language::English, L"Tahoma", FontStyle::Normal, 10);
	}

	// Create viewport for each rendering window.
	IGraphicsSystemEx* graphicsSystem = _context->GetGraphicsSystem();
	for ( UInt i = 0; i < graphicsSystem->GetFrameWindowCount(); ++i )
	{
		CreateViewport( graphicsSystem->GetFrameWindow(i)->GetView(0), nullptr );
	}
	for ( UInt i = 0; i < graphicsSystem->GetViewWindowCount(); ++i )
	{
		CreateViewport( graphicsSystem->GetViewWindow(i)->GetView(), nullptr );
	}
}

void ViewportManager::RegisterViewportFilterFactory( IViewportFilterFactory* factory )
{
	assert( factory != nullptr );

	if ( factory == nullptr )
		throw BadArgumentException( L"Bad viewport filter factory pointer.", L"factory" );

	const UInt classID = factory->GetClassID();
	if ( !_filterFactories.ContainsKey(classID) )
		_filterFactories[classID] = factory;
}


} // view


} // synkro
