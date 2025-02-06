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
// Purpose: Base widget.
//==============================================================================
#ifndef _SYNKRO_UI_BASEWIDGET_
#define _SYNKRO_UI_BASEWIDGET_


#include "config.h"
#include "UiEvent.h"
#include <ui/HotKey.h>
#include <lang/Point.h>
#include <input/Key.h>


namespace synkro
{


namespace ui
{


// Base widget.
class BaseWidget
{
public:
	virtual UiEvent											OnHotKey( const HotKey& hotkey ) = 0;
	virtual UiEvent											OnKeyDown( Double deltaTime, const input::Key& key, Bool alt, Bool shift, Bool control ) = 0;
	virtual UiEvent											OnKeyUp( const input::Key& key, Bool alt, Bool shift, Bool control ) = 0;
	virtual UiEvent											OnKeyPress( Char key ) = 0;
	virtual UiEvent											OnMouseClick( const lang::Point& location ) = 0;
	virtual UiEvent											OnMouseDoubleClick( const lang::Point& location ) = 0;
	virtual UiEvent											OnMouseMove( const lang::Point& location ) = 0;
	virtual UiEvent											OnMouseScroll( Int delta ) = 0;
	virtual UiEvent											OnMouseEnter() = 0;
	virtual UiEvent											OnMouseLeave() = 0;
	virtual UiEvent											OnMouseDown( const lang::Point& location ) = 0;
	virtual UiEvent											OnMouseUp() = 0;
};


// Casts object to BaseWidget.
#define AsBaseWidget( OBJ ) dynamic_cast<BaseWidget*>( OBJ )


} // ui


} // synkro


#endif // _SYNKRO_UI_BASEWIDGET_
