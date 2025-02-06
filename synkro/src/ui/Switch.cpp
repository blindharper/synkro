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
// Purpose: Logical switch widget.
//==============================================================================
#include "config.h"
#include "Switch.h"


//------------------------------------------------------------------------------

using namespace synkro::input;

//------------------------------------------------------------------------------


namespace synkro
{


namespace ui
{


Switch::Switch( BaseUiEx* ui, UInt id, IFrame* parent, ISwitch* widget, Bool on ) :
	WidgetWrapperImpl<ISwitch>( ui, id, parent, widget ),
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>( widget ),
	_switch( widget )
{
	Turn( on );
}

void Switch::Activate( Bool activate )
{
	// Call base implementation.
	WidgetWrapperImpl<ISwitch>::Activate( activate );

	if ( activate )
	{
		_ui->ListenKeyUp( Key::Space );
	}
}


} // ui


} // synkro
