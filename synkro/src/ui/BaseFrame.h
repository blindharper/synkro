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
// Purpose: Base user interface frame.
//==============================================================================
#ifndef _SYNKRO_UI_BASEFRAME_
#define _SYNKRO_UI_BASEFRAME_


#include "config.h"
#include <ui/ITheme.h>
#include "BaseOption.h"


namespace synkro
{


namespace ui
{


// Base user interface frame.
class BaseFrame
{
public:
	virtual void											SetTheme( ITheme* theme ) = 0;
	virtual void											AddWidget( IWidget* widget ) = 0;
	virtual void											AddFrame( IFrame* frame ) = 0;
	virtual void											OnOptionSelected( BaseOption* option ) = 0;
	virtual void											UpdateTabOrder() = 0;
	virtual IWidget*										GetNextWidget( IWidget* widget ) const = 0;
	virtual IWidget*										GetPrevWidget( IWidget* widget ) const = 0;
	virtual IFrame*											GetInnerFrame() const = 0;
};


// Casts object to BaseFrame.
#define AsBaseFrame( OBJ ) dynamic_cast<BaseFrame*>( OBJ )


} // ui


} // synkro


#endif // _SYNKRO_UI_BASEFRAME_
