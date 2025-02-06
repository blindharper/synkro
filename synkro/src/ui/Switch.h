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
// Purpose: Logical switch widget.
//==============================================================================
#ifndef _SYNKRO_UI_SWITCH_
#define _SYNKRO_UI_SWITCH_


#include "config.h"
#include "WidgetWrapperImpl.h"
#include <ui/ISwitch.h>
#include "BaseWidgetImpl.h"
#include "BaseAnchoredObjectImpl.h"


namespace synkro
{


namespace ui
{


// Logical switch widget.
class Switch :
	public WidgetWrapperImpl<ISwitch>,
	public BaseWidgetImpl<BaseWidget>,
	public BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>
{
public:
	// Constructor.
	Switch( BaseUiEx* ui, UInt id, IFrame* parent, ISwitch* widget, Bool on );

	// IWidget methods.
	void													Activate( Bool activate );
	void													SetLocation( const lang::Point& location );
	void													SetSize( const lang::Size& size );
	void													SetAnchor( const Anchor& anchor );
	ISwitch*												AsSwitch() const;

	// ISwitch methods.
	void													Turn( Bool on );
	void													Highlight( Bool highlight );
	void													SetText( const lang::String& text );
	Bool													IsOn() const;
	Bool													IsHighlighted() const;
	lang::String											GetText() const;

	// BaseWidget methods.
	UiEvent													OnHotKey( const HotKey& hotkey );
	UiEvent													OnKeyUp( const input::Key& key, Bool alt, Bool shift, Bool control );
	UiEvent													OnMouseEnter();
	UiEvent													OnMouseLeave();
	UiEvent													OnMouseUp();

private:
	P(ISwitch)												_switch;
};


#include "Switch.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_SWITCH_
