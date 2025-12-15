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
// Purpose: Host window implementation.
//==============================================================================
#include "config.h"
#include "HostWindow.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace win
{


HostWindow::HostWindow( IHostWindow* window ) :
	_windows( A(P(IViewWindowEx)) ),
	_window( window )
{
}

Bool HostWindow::Update()
{
	// Update underlying window.
	return _window->Update();
}


} // win


} // synkro
