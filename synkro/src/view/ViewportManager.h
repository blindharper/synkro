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
#ifndef _SYNKRO_VIEW_VIEWPORTMANAGER_
#define _SYNKRO_VIEW_VIEWPORTMANAGER_


#include "config.h"
#include <lang/Map.h>
#include <core/IContext.h>
#include <view/IViewportManager.h>
#include <view/IViewportFilterFactory.h>
#include <view/ViewportFilter.h>
#include <over/IFont.h>
#include "Viewport.h"
#include "BaseViewportManager.h"


namespace synkro
{


namespace view
{


// Viewport manager implementation.
class ViewportManager :
	public core::ObjectImpl<IViewportManager>,
	public BaseViewportManager,
	public Logger
{
public:
	// Constructor & destructor.
	ViewportManager( core::IContext* context, diag::ILog* log );
	~ViewportManager();

	// ISystem methods.
	Bool													Update( Double delta );

	// IViewportManager methods.
	IViewport*												CreateViewport( gfx::IFrameRenderWindowEx* window, const lang::Rect& rect, scene::ICamera* camera, const img::Color& color );
	IViewport*												CreateViewport( gfx::IRenderView* view, scene::ICamera* camera );
	IViewportTransitionController*							CreateTransitionController( ViewportListener* listener );
	UInt													GetViewportCount() const;
	IViewport*												GetViewport( UInt index ) const;
	IViewport*												GetViewport( gfx::IRenderView* view ) const;
	IViewport*												GetViewport( gfx::IFrameRenderWindowEx* window, const lang::Point& location ) const;
	IViewport*												GetActiveViewport() const;

	// BaseViewportManager methods.
	IViewportFilter*										CreateFilter( IViewport* viewport, const ViewportFilter& type );
	over::IText*											CreateLabel( gfx::IRenderView* view, const img::Color& color, const lang::Point& location, const lang::String& text );
	over::IPolyLine*										CreatePolyLine( gfx::IRenderView* view, UInt pointCount, const img::Color& color );
	void													SetActiveViewport( BaseViewport* viewport );
	void													AddViewport( BaseViewport* viewport );
	void													RemoveViewport( BaseViewport* viewport );
	void													AddTransitionController( BaseViewportTransitionController* controller );
	void													RemoveTransitionController( BaseViewportTransitionController* controller );
	void													AddStopEvent( IViewportTransitionController* sender, ViewportListener* listener );
	void													AddLoopEvent( IViewportTransitionController* sender, ViewportListener* listener );

	// Other methods.
	void													Init();
	void													RegisterViewportFilterFactory( IViewportFilterFactory* factory );
	Bool													Call( BaseViewport* viewport );

private:
	enum TransitionEventType
	{
		TRANSITION_EVENT_STOP,
		TRANSITION_EVENT_LOOP
	};

	struct TransitionEvent
	{
		TransitionEvent( TransitionEventType type, IViewportTransitionController* sender, ViewportListener* listener ) :
			Type( type ),
			Sender( sender ),
			Listener( listener )
		{
		}

		TransitionEvent() :
			Type( TRANSITION_EVENT_LOOP ),
			Sender( nullptr ),
			Listener( nullptr )
		{
		}

		TransitionEventType				Type;
		IViewportTransitionController*	Sender;
		ViewportListener*				Listener;
	};

	typedef lang::MapPair<UInt, IViewportFilterFactory*>	FactoryEntry;
	typedef lang::MapPair<UInt, BaseViewport*>				ViewEntry;

	lang::Vector<TransitionEvent>							_transitionEvents;
	lang::Vector<BaseViewport*>								_viewports;
	lang::Vector<BaseViewportTransitionController*>			_transitionControllers;
	lang::Map<UInt, IViewportFilterFactory*>				_filterFactories;
	lang::Map<UInt, BaseViewport*>							_views;
	core::IContext*											_context;
	BaseViewport*											_activeViewport;
	P(over::IFont)											_fontLabel;
};


#include "ViewportManager.inl"


} // view


} // synkro


#endif // _SYNKRO_VIEW_VIEWPORTMANAGER_
