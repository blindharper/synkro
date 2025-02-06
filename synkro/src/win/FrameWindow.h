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
// Purpose: Frame window implementation.
//==============================================================================
#ifndef _SYNKRO_WIN_FRAMEWINDOW_
#define _SYNKRO_WIN_FRAMEWINDOW_


#include "config.h"
#include <lang/Vector.h>
#include <core/ObjectImpl.h>
#include <win/WindowListener.h>
#include <win/IFrameWindowEx.h>
#include <win/IViewWindowEx.h>


namespace synkro
{


namespace win
{


// Frame window implementation.
class FrameWindow :
	public core::ObjectImpl<IFrameWindowEx>
{
public:
	// Constructor.
	FrameWindow( IFrameWindow* window );

	// IWindow methods.
	Bool													Update();
	void													Close();
	void													SetPosition( Int left, Int top );
	void													SetSize( UInt width, UInt height );
	Int														GetLeft() const;
	Int														GetTop() const;
	UInt													GetWidth() const;
	UInt													GetHeight() const;
	UInt													GetHandle() const;
	UInt													GetDpi() const;
	Bool													IsActive() const;
	Bool													IsClosing() const;

	// IFrameWindow methods.
	void													Center();
	void													Activate();
	void													SetTitle( const lang::String& title );
	void													SetPopup( Bool popup );
	UInt													GetIcon() const;
	lang::String											GetTitle() const;
	IMonitor*												GetMonitor() const;
	Bool													IsPopup() const;
	Bool													IsSizeable() const;
	Bool													IsRenderable() const;

	// IFrameWindowEx methods.
	void													Listen( WindowListener* listener );
	UInt													GetWindowCount() const;
	IViewWindowEx*											GetWindow( UInt index ) const;

	// Other methods.
	void													AddWindow( IViewWindowEx* window );

private:
	lang::Vector<WindowListener*>							_listeners;
	lang::Vector<P(IViewWindowEx)>							_windows;
	P(IFrameWindow)											_window;
	Bool													_active;
	UInt													_width;
	UInt													_height;

	Bool													FireClosingEvent();
	void													FireActivateEvent( Bool active );
	void													FireResizeEvent( UInt width, UInt height );
};


#include "FrameWindow.inl"


} // win


} // synkro


#endif // _SYNKRO_WIN_FRAMEWINDOW_
