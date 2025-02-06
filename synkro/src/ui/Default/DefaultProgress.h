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
// Purpose: Default progress widget implementation.
//==============================================================================
#ifndef _SYNKRO_UI_DEFAULTPROGRESS_
#define _SYNKRO_UI_DEFAULTPROGRESS_


#include "config.h"
#include <ui/WidgetImpl.h>
#include <ui/IProgress.h>
#include <ui/BaseThemeWidgetImpl.h>
#include <ui/BaseThemeWidget.h>


namespace synkro
{


namespace ui
{


// Default progress widget.
class DefaultProgress :
	public WidgetImpl<IProgress>,
	public BaseThemeWidgetImpl<BaseThemeWidget>
{
public:
	// Constructor.
	DefaultProgress( BaseUi* ui, IFrame* parent, const lang::Point& location, const lang::Size& size, const ProgressType& type, const img::Color& color );

	// IWidget methods.
	void													Show( Bool show );
	void													SetLocation( const lang::Point& location );
	void													SetSize( const lang::Size& size );

	// IProgress methods.
	void													SetMaxValue( UInt value );
	void													SetValue( UInt value );
	void													ShowText( Bool show );
	ProgressType											GetType() const;
	UInt													GetMaxValue() const;
	UInt													GetValue() const;
	Bool													IsTextVisible() const;

	// BaseThemeWidget methods.
	void													SetTheme( ITheme* theme );
	void													UpdateRect();

private:
	ProgressType											_type;
	UInt													_value;
	UInt													_maxValue;
	Bool													_textVisible;

	void													SetType( const ProgressType& type );
	void													Update();
	void													CenterText();
	void													PrintValue();
};


#include "DefaultProgress.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_DEFAULTPROGRESS_
