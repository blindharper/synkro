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
// Purpose: Base theme-aware widget.
//==============================================================================
#ifndef _SYNKRO_UI_BASETHEMEWIDGET_
#define _SYNKRO_UI_BASETHEMEWIDGET_


#include "config.h"
#include <ui/ITheme.h>


namespace synkro
{


namespace ui
{


// Base theme-aware widget.
class BaseThemeWidget
{
public:
	virtual void											SetTheme( ITheme* theme ) = 0;
	virtual void											UpdateRect() = 0;
};


// Casts object to BaseThemeWidget.
#define AsBaseThemeWidget( OBJ ) dynamic_cast<BaseThemeWidget*>( OBJ )


} // ui


} // synkro


#endif // _SYNKRO_UI_BASETHEMEWIDGET_
