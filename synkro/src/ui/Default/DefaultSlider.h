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
// Purpose: Default slider widget implementation.
//==============================================================================
#ifndef _SYNKRO_UI_DEFAULTSLIDER_
#define _SYNKRO_UI_DEFAULTSLIDER_


#include "config.h"
#include <ui/WidgetImpl.h>
#include <ui/ISlider.h>
#include <ui/BaseThemeWidgetImpl.h>
#include <ui/BaseThemeWidget.h>


namespace synkro
{


namespace ui
{


// Default slider widget implementation.
class DefaultSlider :
	public WidgetImpl<ISlider>,
	public BaseThemeWidgetImpl<BaseThemeWidget>
{
public:
	// Constructor.
	DefaultSlider( BaseUi* ui, IFrame* parent, const lang::Point& location, const lang::Size& size, const Orientation& orientation, UInt minPosition, UInt maxPosition, const img::Color& color );

	// IWidget methods.
	void													Activate( Bool activate );
	void													Enable( Bool enable );
	void													SetLocation( const lang::Point& location );
	void													SetSize( const lang::Size& size );

	// ISlider methods.
	void													Highlight( Bool highlight );
	void													SetMinPosition( UInt minPosition );
	void													SetMaxPosition( UInt maxPosition );
	void													SetPosition( UInt position );
	Orientation												GetOrientation() const;
	UInt													GetMinPosition() const;
	UInt													GetMaxPosition() const;
	UInt													GetPosition() const;
	void													GetThumbSize( lang::Size& size ) const;

	// BaseThemeWidget methods.
	void													SetTheme( ITheme* theme );
	void													UpdateRect();

private:
	Orientation												_orientation;
	UInt													_minPosition;
	UInt													_maxPosition;
	UInt													_position;
	lang::Rect												_rectRails;
	lang::Rect												_rectRailsCenter;
	lang::Rect												_rectThumb;

	void													SetOrientation( const Orientation& orientation );
	void													UpdateTextureCoordinates();
	void													UpdateSize();
	void													UpdateRails();
	void													UpdateThumb( const lang::Point& location );
};


#include "DefaultSlider.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_DEFAULTSLIDER_
