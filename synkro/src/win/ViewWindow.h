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
#ifndef _SYNKRO_WIN_VIEWWINDOW_
#define _SYNKRO_WIN_VIEWWINDOW_


#include "config.h"
#include <lang/Vector.h>
#include <core/ObjectImpl.h>
#include <win/WindowListener.h>
#include <win/IViewWindowEx.h>


namespace synkro
{


namespace win
{


// View window implementation.
class ViewWindow :
	public core::ObjectImpl<IViewWindowEx>
{
public:
	// Constructor.
	ViewWindow( IViewWindow* window );

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

	// IViewWindow methods.
	void													Show( Bool show );
	Bool													IsVisible() const;
	IFrameWindow*											GetParent() const;

	// IViewWindowEx methods.
	void													Listen( WindowListener* listener );

private:
	lang::Vector<WindowListener*>							_listeners;
	P(IViewWindow)											_window;
};


#include "ViewWindow.inl"


} // win


} // synkro


#endif // _SYNKRO_WIN_VIEWWINDOW_
