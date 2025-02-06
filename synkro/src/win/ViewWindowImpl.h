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
// Purpose: Generic view window implementation.
//==============================================================================
#ifndef _SYNKRO_WIN_VIEWWINDOWIMPL_
#define _SYNKRO_WIN_VIEWWINDOWIMPL_


#include "config.h"
#include "WindowImpl.h"


namespace synkro
{


namespace win
{


// Generic view window implementation.
template <class T>
class ViewWindowImpl :
	public WindowImpl<T>
{
public:
	// Constructor & destructor.
	ViewWindowImpl( IFrameWindow* parent, Int left, Int top, UInt width, UInt height );
	virtual ~ViewWindowImpl();

	// IWindow methods.
	virtual Bool											Update();

	// IViewWindow methods.
	virtual void											Show( Bool show );
	virtual Bool											IsVisible() const;
	virtual IFrameWindow*									GetParent() const;

protected:
	IFrameWindow*											_parent;
	Bool													_visible;
};


#include "ViewWindowImpl.inl"


} // win


} // synkro


#endif // _SYNKRO_WIN_VIEWWINDOWIMPL_
