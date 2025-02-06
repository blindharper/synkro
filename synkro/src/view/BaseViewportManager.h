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
// Purpose: Base viewport manager.
//==============================================================================
#ifndef _SYNKRO_VIEW_BASEVIEWPORTMANAGER_
#define _SYNKRO_VIEW_BASEVIEWPORTMANAGER_


#include "config.h"
#include <img/Color.h>
#include <lang/Point.h>
#include <view/ViewportFilter.h>
#include "BaseViewport.h"
#include "BaseViewportTransitionController.h"


namespace synkro
{


namespace view
{


// Base viewport manager.
class BaseViewportManager
{
public:
	virtual IViewportFilter*								CreateFilter( IViewport* viewport, const ViewportFilter& type ) = 0;
	virtual over::IText*									CreateLabel( gfx::IRenderView* view, const img::Color& color, const lang::Point& location, const lang::String& text ) = 0;
	virtual over::IPolyLine*								CreatePolyLine( gfx::IRenderView* view, UInt pointCount, const img::Color& color ) = 0;
	virtual void											SetActiveViewport( BaseViewport* viewport ) = 0;
	virtual void											AddViewport( BaseViewport* viewport ) = 0;
	virtual void											RemoveViewport( BaseViewport* viewport ) = 0;
	virtual void											AddTransitionController( BaseViewportTransitionController* controller ) = 0;
	virtual void											RemoveTransitionController( BaseViewportTransitionController* controller ) = 0;
	virtual void											AddStopEvent( IViewportTransitionController* sender, ViewportListener* listener ) = 0;
	virtual void											AddLoopEvent( IViewportTransitionController* sender, ViewportListener* listener ) = 0;
};


} // view


} // synkro


#endif // _SYNKRO_VIEW_BASEVIEWPORTMANAGER_
