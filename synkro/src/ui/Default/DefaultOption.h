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
// Purpose: Default option widget implementation.
//==============================================================================
#ifndef _SYNKRO_UI_DEFAULTOPTION_
#define _SYNKRO_UI_DEFAULTOPTION_


#include "config.h"
#include <ui/WidgetImpl.h>
#include <ui/IOption.h>
#include <ui/BaseThemeWidgetImpl.h>
#include <ui/BaseThemeWidget.h>


namespace synkro
{


namespace ui
{


// Default option widget.
class DefaultOption :
	public WidgetImpl<IOption>,
	public BaseThemeWidgetImpl<BaseThemeWidget>
{
public:
	// Constructor.
	DefaultOption( BaseUi* ui, IFrame* parent, const lang::Point& location, const lang::Size& size, const lang::String& text, const img::Color& color );

	// IWidget methods.
	void													Activate( Bool activate );
	void													Enable( Bool enable );
	void													SetLocation( const lang::Point& location );
	void													SetSize( const lang::Size& size );

	// IOption methods.
	void													Select( Bool select );
	void													Highlight( Bool highlight );
	void													SetText( const lang::String& text );
	Bool													IsSelected() const;
	lang::String											GetText() const;

	// BaseThemeWidget methods.
	void													SetTheme( ITheme* theme );
	void													UpdateRect();

private:
	Bool													_selected;

	void													Update();
};


#include "DefaultOption.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_DEFAULTOPTION_
