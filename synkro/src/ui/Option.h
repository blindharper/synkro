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
// Purpose: Logical option widget.
//==============================================================================
#ifndef _SYNKRO_UI_OPTION_
#define _SYNKRO_UI_OPTION_


#include "config.h"
#include "WidgetWrapperImpl.h"
#include <ui/IOption.h>
#include "BaseWidgetImpl.h"
#include "BaseAnchoredObjectImpl.h"
#include "BaseOption.h"


namespace synkro
{


namespace ui
{


// Logical option widget.
class Option :
	public WidgetWrapperImpl<IOption>,
	public BaseWidgetImpl<BaseWidget>,
	public BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>,
	public BaseOption
{
public:
	// Constructor.
	Option( BaseUiEx* ui, UInt id, IFrame* parent, IOption* widget, Bool selected );

	// IWidget methods.
	void													Activate( Bool activate );
	void													SetLocation( const lang::Point& location );
	void													SetSize( const lang::Size& size );
	void													SetAnchor( const Anchor& anchor );
	IOption*												AsOption() const;

	// IOption methods.
	void													Select( Bool select );
	void													Highlight( Bool highlight );
	void													SetText( const lang::String& text );
	Bool													IsSelected() const;
	lang::String											GetText() const;

	// BaseWidget methods.
	UiEvent													OnHotKey( const HotKey& hotkey );
	UiEvent													OnKeyUp( const input::Key& key, Bool alt, Bool shift, Bool control );
	UiEvent													OnMouseEnter();
	UiEvent													OnMouseLeave();
	UiEvent													OnMouseUp();

	// BaseOption methods.
	void													Unselect();

private:
	P(IOption)												_option;
};


#include "Option.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_OPTION_
