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
// Purpose: Logical button widget.
//==============================================================================
#include "config.h"
#include "Button.h"


//------------------------------------------------------------------------------

using namespace synkro::input;

//------------------------------------------------------------------------------


namespace synkro
{


namespace ui
{


Button::Button( BaseUiEx* ui, UInt id, IFrame* parent, IButton* widget ) :
	WidgetWrapperImpl<IButton>( ui, id, parent, widget ),
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>( widget ),
	_button( widget )
{
}

void Button::Activate( Bool activate )
{
	// Call base implementation.
	WidgetWrapperImpl<IButton>::Activate( activate );

	if ( activate )
	{
		_ui->ListenKeyDown( Key::Space, true );
		_ui->ListenKeyUp( Key::Space );
	}
}


} // ui


} // synkro
