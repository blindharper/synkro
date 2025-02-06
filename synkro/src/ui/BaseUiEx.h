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
// Purpose: Base extended user interface.
//==============================================================================
#ifndef _SYNKRO_UI_BASEUIEX_
#define _SYNKRO_UI_BASEUIEX_


#include "config.h"
#include <over/IFont.h>
#include <over/IQuad.h>
#include <over/ISprite.h>
#include <input/Axis.h>
#include <input/MouseButton.h>
#include <ui/HotKey.h>
#include <gfx/IndexType.h>
#include <gfx/PrimitiveType.h>
#include "BaseWidget.h"


namespace synkro
{


namespace ui
{


// Base extended user interface.
class BaseUiEx
{
public:
	virtual gfx::IOverlayRenderObject*						CreateObject( const gfx::PrimitiveType& type, const gfx::IndexType& indexType, UInt vertexCount, UInt indexCount, UInt order ) = 0;
	virtual void											ActivateWidget( BaseWidget* widget ) = 0;
	virtual void											RegisterHotKey( const HotKey& hotkey ) = 0;
	virtual void											ListenKeyDown( const input::Key* keys, UInt count, Bool discrete ) = 0;
	virtual void											ListenKeyDown( const input::Key& key, Bool discrete ) = 0;
	virtual void											ListenKeyUp( const input::Key* keys, UInt count ) = 0;
	virtual void											ListenKeyUp( const input::Key& key ) = 0;
	virtual void											ListenKeyPress() = 0;
	virtual void											ListenMouseDoubleClick( const input::MouseButton& buttons ) = 0;
	virtual void											ListenMouseAxisMove( const input::Axis& axis ) = 0;
	virtual void											FireEvent( UiEvent event, BaseWidget* widget ) = 0;
	virtual void											DoListen( UiListener* listener ) = 0;
	virtual over::ISprite*									CreateSprite( img::IImage* image, const lang::Point& location, const lang::Size& size ) = 0;
	virtual over::IQuad*									CreateQuad( const over::Order& groupOrder, const over::Order& order, const lang::Point& location, const lang::Size& size, const img::Color& color ) = 0;
	virtual over::IFont*									GetFont() const = 0;
	virtual ITheme*											GetThemeEx() const = 0;
};


} // ui


} // synkro


#endif // _SYNKRO_UI_BASEUIEX_
