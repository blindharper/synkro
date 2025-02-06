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
// Purpose: Base theme widget implementation.
//=============================================================================
#ifndef _SYNKRO_UI_BASETHEMEWIDGETIMPL_
#define _SYNKRO_UI_BASETHEMEWIDGETIMPL_


#include "config.h"
#include <ui/ITheme.h>


namespace synkro
{


namespace ui
{


// Base theme widget implementation.
template <class T>
class BaseThemeWidgetImpl :
	public T
{
public:
	// Constructors and destructor.
	BaseThemeWidgetImpl( const img::Color& color );
	BaseThemeWidgetImpl();
	virtual ~BaseThemeWidgetImpl();

	// BaseThemeWidget methods.
	virtual void											SetTheme( ITheme* theme );

protected:
	ITheme*													_theme;
	img::Color												_widgetColors[4];
	img::Color												_textColors[4];
	img::Color												_customColor;

	void													SetDefaults();
	void													SetColors( const WidgetState& state );
};


#include "BaseThemeWidgetImpl.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_BASETHEMEWIDGETIMPL_
