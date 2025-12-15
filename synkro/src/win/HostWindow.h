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
#ifndef _SYNKRO_WIN_HOSTWINDOW_
#define _SYNKRO_WIN_HOSTWINDOW_


#include "config.h"
#include <lang/Vector.h>
#include <core/ObjectImpl.h>
#include <win/IHostWindowEx.h>
#include <win/IViewWindowEx.h>


namespace synkro
{


namespace win
{


// Host window implementation.
class HostWindow :
	public core::ObjectImpl<IHostWindowEx>
{
public:
	// Constructor.
	HostWindow( IHostWindow* window );

	// IWindow methods.
	Bool													Update();
	void													Close();
	void													SetPosition( Int left, Int top );
	void													SetSize( UInt width, UInt height );
	Int														GetLeft() const;
	Int														GetTop() const;
	UInt													GetWidth() const;
	UInt													GetHeight() const;
	Pointer													GetHandle() const;
	UInt													GetDpi() const;
	Bool													IsActive() const;
	Bool													IsClosing() const;

	// IHostWindow methods.
	void													SetTitle( const lang::String& title );
	lang::String											GetTitle() const;

	// IHostWindowEx methods.
	UInt													GetWindowCount() const;
	IViewWindowEx*											GetWindow( UInt index ) const;

	// Other methods.
	void													AddWindow( IViewWindowEx* window );

private:
	lang::Vector<P(IViewWindowEx)>							_windows;
	P(IHostWindow)											_window;
};


#include "HostWindow.inl"


} // win


} // synkro


#endif // _SYNKRO_WIN_HOSTWINDOW_
