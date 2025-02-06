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
// Purpose: Win32 view window implementation.
//==============================================================================
#ifndef _SYNKRO_WIN_WIN32VIEWWINDOW_
#define _SYNKRO_WIN_WIN32VIEWWINDOW_


#include "config.h"
#include <win/ViewWindowImpl.h>
#include <win/IViewWindow.h>


namespace synkro
{


namespace win
{


// Win32 view window implementation.
class Win32ViewWindow :
	public ViewWindowImpl<IViewWindow>
{
public:
	// Constructor & destructor.
	Win32ViewWindow( IFrameWindow* parent, Int left, Int top, UInt width, UInt height );
	~Win32ViewWindow();

	// IWindow methods.
	void													Close();
	void													SetPosition( Int left, Int top );
	void													SetSize( UInt width, UInt height );

	// IViewWindow methods.
	void													Show( Bool show );
};


} // win


} // synkro


#endif // _SYNKRO_WIN_WIN32VIEWWINDOW_
