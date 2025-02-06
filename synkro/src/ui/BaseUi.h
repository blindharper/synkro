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
// Purpose: Base user interface.
//==============================================================================
#ifndef _SYNKRO_UI_BASEUI_
#define _SYNKRO_UI_BASEUI_


#include "config.h"
#include <gfx/IndexType.h>
#include <gfx/PrimitiveType.h>
#include <gfx/IRect.h>
#include <over/ITextPool.h>
#include <over/IText.h>
#include <over/IFont.h>
#include <over/IQuad.h>
#include <over/ISprite.h>
#include <over/Order.h>
#include <ui/ITheme.h>
#include "WidgetEffect.h"


namespace synkro
{


namespace ui
{


// Base user interface.
class BaseUi
{
public:
	virtual gfx::IOverlayRenderObject*						CreateObject( const gfx::PrimitiveType& type, const gfx::IndexType& indexType, UInt vertexCount, UInt indexCount, UInt order ) = 0;
	virtual gfx::IOverlayRenderObject*						CreateLineObject( const gfx::PrimitiveType& type, UInt vertexCount, UInt order ) = 0;
	virtual gfx::IRect*										CreateScissorRect( Int left, Int top, Int right, Int bottom ) = 0;
	virtual WidgetEffect*									CreateEffect( gfx::IOverlayRenderObject* widget, gfx::IOverlayRenderObject* widget2, over::IText* text ) = 0;
	virtual over::ITextPool*								CreateTextPool( over::IFont* font, UInt capacity ) = 0;
	virtual over::ISprite*									CreateSprite( img::IImage* image, const lang::Point& location, const lang::Size& size ) = 0;
	virtual over::IQuad*									CreateQuad( const over::Order& groupOrder, const over::Order& order, const lang::Point& location, const lang::Size& size, const img::Color& color ) = 0;
	virtual over::IFont*									GetFont() const = 0;
	virtual ITheme*											Theme() const = 0;
};


} // ui


} // synkro


#endif // _SYNKRO_UI_BASEUI_
