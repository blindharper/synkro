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
// Purpose: Win32 frame window implementation.
//==============================================================================
#ifndef _SYNKRO_WIN_WIN32FRAMEWINDOW_
#define _SYNKRO_WIN_WIN32FRAMEWINDOW_


#include "config.h"
#include <win/FrameWindowImpl.h>
#include <win/IFrameWindow.h>


namespace synkro
{


namespace win
{


// Win32 frame window implementation.
class Win32FrameWindow :
	public FrameWindowImpl<IFrameWindow>
{
public:
	// Constructors & destructor.
	Win32FrameWindow( Bool popup, Bool sizeable, const lang::String& title, UInt icon, UInt width, UInt height );
	Win32FrameWindow( IMonitor* monitor );
	~Win32FrameWindow();

	// IWindow methods.
	Bool													Update();
	void													Close();
	void													SetPosition( Int left, Int top );
	void													SetSize( UInt width, UInt height );

	// IFrameWindow methods.
	void													Center();
	void													Activate();
	void													SetPopup( Bool popup );
	void													SetTitle( const lang::String& title );

	// Other methods
	void													Create( Bool popup, Bool sizeable, const lang::String& title, UInt icon, Int left, Int top, UInt width, UInt height );
	virtual LRESULT											HandleMessage( UINT msg, WPARAM wp, LPARAM lp );
};


// Windows frame window stub.
class Win32FrameWindowStub :
	public FrameWindowImpl<IFrameWindow>
{
public:
	// Constructor.
	Win32FrameWindowStub( Pointer handle );

	// IWindow methods.
	Bool													Update();
	void													Close();
	void													SetPosition( Int left, Int top );
	void													SetSize( UInt width, UInt height );

	// IFrameWindow methods.
	void													Center();
	void													Activate();
	void													SetPopup( Bool popup );
	void													SetTitle( const lang::String& title );
};


} // win


} // synkro


#endif // _SYNKRO_WIN_WIN32FRAMEWINDOW_
