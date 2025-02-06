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
// Purpose: Generic icon window implementation.
//==============================================================================
#ifndef _SYNKRO_WIN_ICONWINDOWIMPL_
#define _SYNKRO_WIN_ICONWINDOWIMPL_


#include "config.h"
#include "WindowImpl.h"
#include <lang/Vector.h>
#include <win/WindowListener.h>


namespace synkro
{


namespace win
{


// Generic icon window implementation.
template <class T>
class IconWindowImpl :
	public WindowImpl<T>
{
public:
	// Constructor & destructor.
	IconWindowImpl( UInt icon, const lang::String& hint );
	virtual ~IconWindowImpl();

	// IIconWindow methods.
	virtual void											Listen( WindowListener* listener );
	virtual void											SetIcon( UInt icon );
	virtual void											SetHint( const lang::String& hint );
	virtual UInt											GetIcon() const;
	virtual lang::String									GetHint() const;

protected:
	lang::Vector<WindowListener*>							_listeners;
	UInt													_icon;
	lang::String											_hint;

	void													FireCommandEvent( UInt command );
};


#include "IconWindowImpl.inl"


} // win


} // synkro


#endif // _SYNKRO_WIN_ICONWINDOWIMPL_
