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
// Purpose: Default button widget implementation.
//==============================================================================
#ifndef _SYNKRO_UI_DEFAULTBUTTON_
#define _SYNKRO_UI_DEFAULTBUTTON_


#include "config.h"
#include <ui/WidgetImpl.h>
#include <ui/IButton.h>
#include <ui/BaseThemeWidgetImpl.h>
#include <ui/BaseThemeWidget.h>


namespace synkro
{


namespace ui
{


// Default button widget.
class DefaultButton :
	public WidgetImpl<IButton>,
	public BaseThemeWidgetImpl<BaseThemeWidget>
{
public:
	// Constructor.
	DefaultButton( BaseUi* ui, IFrame* parent, const lang::Point& location, const lang::Size& size, const lang::String& text, const img::Color& color );

	// IWidget methods.
	void													Activate( Bool activate );
	void													Enable( Bool enable );
	void													SetLocation( const lang::Point& location );
	void													SetSize( const lang::Size& size );
	IButton*												AsButton() const;

	// IButton methods.
	void													Press( Bool press );
	void													Highlight( Bool highlight );
	void													SetText( const lang::String& text );
	Bool													IsPressed() const;
	Bool													IsHighlighted() const;
	lang::String											GetText() const;

	// BaseThemeWidget methods.
	void													SetTheme( ITheme* theme );
	void													UpdateRect();

private:
	enum
	{
		PRESS_DELTA = 2,
	};

	Bool													_pressed;
	Bool													_highlighted;

	void													Update( Int delta );
	void													CenterText( Int delta );
};


#include "DefaultButton.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_DEFAULTBUTTON_
