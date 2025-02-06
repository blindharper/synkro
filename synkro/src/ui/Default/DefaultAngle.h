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
// Purpose: Default angle widget implementation.
//==============================================================================
#ifndef _SYNKRO_UI_DEFAULTANGLE_
#define _SYNKRO_UI_DEFAULTANGLE_


#include "config.h"
#include <ui/WidgetImpl.h>
#include <ui/IAngle.h>
#include <ui/BaseThemeWidgetImpl.h>
#include <ui/BaseThemeWidget.h>


namespace synkro
{


namespace ui
{


// Default angle widget implementation.
class DefaultAngle :
	public WidgetImpl<IAngle>,
	public BaseThemeWidgetImpl<BaseThemeWidget>
{
public:
	// Constructor.
	DefaultAngle( BaseUi* ui, IFrame* parent, const lang::Point& location, const lang::Size& size, const img::Color& color );

	// IWidget methods.
	void													Activate( Bool activate );
	void													Enable( Bool enable );
	void													SetLocation( const lang::Point& location );

	// IAngle methods.
	void													Highlight( Bool highlight );
	void													SetValue( Float value );
	Float													GetValue() const;

	// BaseThemeWidget methods.
	void													SetTheme( ITheme* theme );
	void													UpdateRect();

private:
	Float													_value;
	lang::Rect												_rectCircle;
	lang::Rect												_rectThumb;

	void													UpdateTextureCoordinates();
	void													UpdateCircle();
	void													UpdateThumb();
	void													CenterText();
};


#include "DefaultAngle.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_DEFAULTANGLE_
