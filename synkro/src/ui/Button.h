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
// Purpose: Logical button widget.
//==============================================================================
#ifndef _SYNKRO_UI_BUTTON_
#define _SYNKRO_UI_BUTTON_


#include "config.h"
#include "WidgetWrapperImpl.h"
#include <ui/IButton.h>
#include "BaseWidgetImpl.h"
#include "BaseAnchoredObjectImpl.h"


namespace synkro
{


namespace ui
{


// Logical button widget.
class Button :
	public WidgetWrapperImpl<IButton>,
	public BaseWidgetImpl<BaseWidget>,
	public BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>
{
public:
	// Constructor.
	Button( BaseUiEx* ui, UInt id, IFrame* parent, IButton* widget );

	// IWidget methods.
	void													Activate( Bool activate );
	void													SetLocation( const lang::Point& location );
	void													SetSize( const lang::Size& size );
	void													SetAnchor( const Anchor& anchor );
	IButton*												AsButton() const;

	// IButton methods.
	void													Press( Bool press );
	void													Highlight( Bool highlight );
	void													SetText( const lang::String& text );
	Bool													IsPressed() const;
	Bool													IsHighlighted() const;
	lang::String											GetText() const;

	// BaseWidget methods.
	UiEvent													OnHotKey( const HotKey& hotkey );
	UiEvent													OnKeyDown( Double deltaTime, const input::Key& key, Bool alt, Bool shift, Bool control );
	UiEvent													OnKeyUp( const input::Key& key, Bool alt, Bool shift, Bool control );
	UiEvent													OnMouseEnter();
	UiEvent													OnMouseLeave();
	UiEvent													OnMouseDown( const lang::Point& location );
	UiEvent													OnMouseUp();

private:
	P(IButton)												_button;
};


#include "Button.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_BUTTON_
