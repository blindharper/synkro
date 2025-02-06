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
// Purpose: Logical option widget.
//==============================================================================
#include "config.h"
#include "Option.h"


//------------------------------------------------------------------------------

using namespace synkro::input;

//------------------------------------------------------------------------------


namespace synkro
{


namespace ui
{


Option::Option( BaseUiEx* ui, UInt id, IFrame* parent, IOption* widget, Bool selected ) :
	WidgetWrapperImpl<IOption>( ui, id, parent, widget ),
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>( widget ),
	_option( widget )
{
	Select( selected );
}

void Option::Activate( Bool activate )
{
	// Call base implementation.
	WidgetWrapperImpl<IOption>::Activate( activate );

	if ( activate )
	{
		_ui->ListenKeyUp( Key::Space );
	}
}


} // ui


} // synkro
