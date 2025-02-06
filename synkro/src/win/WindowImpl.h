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
// Purpose: Generic window implementation.
//==============================================================================
#ifndef _SYNKRO_WIN_WINDOWIMPL_
#define _SYNKRO_WIN_WINDOWIMPL_


#include "config.h"
#include <core/ObjectImpl.h>


namespace synkro
{


namespace win
{


// Generic window implementation.
template <class T>
class WindowImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	WindowImpl( Int left, Int top, UInt width, UInt height );
	virtual ~WindowImpl();

	// IWindow methods.
	virtual void											SetPosition( Int left, Int top );
	virtual void											SetSize( UInt width, UInt height );
	virtual Int												GetLeft() const;
	virtual Int												GetTop() const;
	virtual UInt											GetWidth() const;
	virtual UInt											GetHeight() const;
	virtual UInt											GetHandle() const;
	virtual UInt											GetDpi() const;
	virtual Bool											IsActive() const;
	virtual Bool											IsClosing() const;

protected:
	Pointer													_handle;
	Bool													_active;
	Bool													_closing;
	Int														_left;
	Int														_top;
	UInt													_width;
	UInt													_height;
	UInt													_dpi;
};


#include "WindowImpl.inl"


} // win


} // synkro


#endif // _SYNKRO_WIN_WINDOWIMPL_
