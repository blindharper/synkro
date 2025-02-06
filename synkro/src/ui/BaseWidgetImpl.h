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
// Purpose: Base widget implementation.
//=============================================================================
#ifndef _SYNKRO_UI_BASEWIDGETIMPL_
#define _SYNKRO_UI_BASEWIDGETIMPL_


#include "config.h"
#include "BaseWidget.h"


namespace synkro
{


namespace ui
{


// Base widget implementation.
template <class T>
class BaseWidgetImpl :
	public T
{
public:
	// Constructor and destructor.
	BaseWidgetImpl();
	virtual ~BaseWidgetImpl();

	// BaseWidget methods.
	virtual UiEvent											OnHotKey( const HotKey& hotkey );
	virtual UiEvent											OnKeyDown( Double deltaTime, const input::Key& key, Bool alt, Bool shift, Bool control );
	virtual UiEvent											OnKeyUp( const input::Key& key, Bool alt, Bool shift, Bool control );
	virtual UiEvent											OnKeyPress( Char key );
	virtual UiEvent											OnMouseClick( const lang::Point& location );
	virtual UiEvent											OnMouseDoubleClick( const lang::Point& location );
	virtual UiEvent											OnMouseMove( const lang::Point& location );
	virtual UiEvent											OnMouseScroll( Int delta );
	virtual UiEvent											OnMouseEnter();
	virtual UiEvent											OnMouseLeave();
	virtual UiEvent											OnMouseDown( const lang::Point& location );
	virtual UiEvent											OnMouseUp();
};


#include "BaseWidgetImpl.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_BASEWIDGETIMPL_
