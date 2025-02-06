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
// Purpose: Generic frame window implementation.
//==============================================================================
#ifndef _SYNKRO_WIN_FRAMEWINDOWIMPL_
#define _SYNKRO_WIN_FRAMEWINDOWIMPL_


#include "config.h"
#include "WindowImpl.h"
#include <win/IMonitor.h>


namespace synkro
{


namespace win
{


// Generic frame window implementation.
template <class T>
class FrameWindowImpl :
	public WindowImpl<T>
{
public:
	// Constructors & destructor.
	FrameWindowImpl( Bool popup, Bool sizeable, Bool renderable, const lang::String& title, UInt icon, UInt width, UInt height );
	FrameWindowImpl( IMonitor* monitor );
	virtual ~FrameWindowImpl();

	// IFrameWindow methods.
	virtual void											SetTitle( const lang::String& title );
	virtual void											SetPopup( Bool popup );
	virtual UInt											GetIcon() const;
	virtual lang::String									GetTitle() const;
	virtual IMonitor*										GetMonitor() const;
	virtual Bool											IsPopup() const;
	virtual Bool											IsSizeable() const;
	virtual Bool											IsRenderable() const;

protected:
	IMonitor*												_monitor;
	lang::String											_title;
	UInt													_icon;
	Bool													_popup;
	Bool													_sizeable;
	Bool													_renderable;
};


#include "FrameWindowImpl.inl"


} // win


} // synkro


#endif // _SYNKRO_WIN_FRAMEWINDOWIMPL_
