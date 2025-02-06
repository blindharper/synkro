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
// Purpose: View window implementation.
//==============================================================================
#include "config.h"
#include "ViewWindow.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace win
{


ViewWindow::ViewWindow( IViewWindow* window ) :
	_listeners( A(WindowListener*) ),
	_window( window )
{
}

void ViewWindow::Listen( WindowListener* listener )
{
	assert( listener != nullptr );

	if ( !_listeners.Contains(listener) )
	{
		_listeners.Add( listener );
	}
}


} // win


} // synkro
