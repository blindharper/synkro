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
// Purpose: Default switch widget implementation.
//==============================================================================
#ifndef _SYNKRO_UI_DEFAULTSWITCH_
#define _SYNKRO_UI_DEFAULTSWITCH_


#include "config.h"
#include <ui/WidgetImpl.h>
#include <ui/ISwitch.h>
#include <ui/BaseThemeWidgetImpl.h>
#include <ui/BaseThemeWidget.h>


namespace synkro
{


namespace ui
{


// Default switch widget.
class DefaultSwitch :
	public WidgetImpl<ISwitch>,
	public BaseThemeWidgetImpl<BaseThemeWidget>
{
public:
	// Constructor.
	DefaultSwitch( BaseUi* ui, IFrame* parent, const lang::Point& location, const lang::Size& size, const lang::String& text, const img::Color& color );

	// IWidget methods.
	void													Activate( Bool activate );
	void													Enable( Bool enable );
	void													SetLocation( const lang::Point& location );
	void													SetSize( const lang::Size& size );

	// ISwitch methods.
	void													Turn( Bool on );
	void													Highlight( Bool highlight );
	void													SetText( const lang::String& text );
	Bool													IsOn() const;
	Bool													IsHighlighted() const;
	lang::String											GetText() const;

	// BaseThemeWidget methods.
	void													SetTheme( ITheme* theme );
	void													UpdateRect();

private:
	Bool													_on;
	Bool													_highlighted;

	void													Update();
};


#include "DefaultSwitch.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_DEFAULTSWITCH_
