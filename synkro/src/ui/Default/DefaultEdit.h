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
// Purpose: Default edit widget implementation.
//==============================================================================
#ifndef _SYNKRO_UI_DEFAULTEDIT_
#define _SYNKRO_UI_DEFAULTEDIT_


#include "config.h"
#include <ui/WidgetImpl.h>
#include <ui/IEdit.h>
#include <ui/BaseThemeWidgetImpl.h>
#include <ui/BaseThemeWidget.h>


namespace synkro
{


namespace ui
{


// Default edit widget implementation.
class DefaultEdit :
	public WidgetImpl<IEdit>,
	public BaseThemeWidgetImpl<BaseThemeWidget>
{
public:
	// Constructor.
	DefaultEdit( BaseUi* ui, IFrame* parent, const lang::Point& location, const lang::Size& size, const lang::String& text );

	// IWidget methods.
	void													Activate( Bool activate );
	void													Enable( Bool enable );
	void													SetLocation( const lang::Point& location );
	void													SetSize( const lang::Size& size );

	// IEdit methods.
	void													Clear();
	void													SetText( const lang::String& text );
	void													SetStyle( const EditStyle& style );
	void													SetValue( Float value );
	void													SetMinValue( Float minValue );
	void													SetMaxValue( Float maxValue );
	void													SetMaxLength( UInt maxLength );
	void													SetScrollOffset( UInt offset );
	Bool													IsEmpty() const;
	lang::String											GetText() const;
	EditStyle												GetStyle() const;
	Float													GetValue() const;
	Float													GetMinValue() const;
	Float													GetMaxValue() const;
	UInt													GetMaxLength() const;
	UInt													GetScrollOffset() const;

	// BaseThemeWidget methods.
	void													SetTheme( ITheme* theme );
	void													UpdateRect();

private:
	EditStyle												_style;
	Float													_minValue;
	Float													_maxValue;
	UInt													_maxLength;
	UInt													_scrollOffset;

	void													Update();
};


#include "DefaultEdit.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_DEFAULTEDIT_
