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
// Purpose: Generic window system implementation.
//=============================================================================
#ifndef _SYNKRO_WIN_WINDOWSYSTEMIMPL_
#define _SYNKRO_WIN_WINDOWSYSTEMIMPL_


#include "config.h"
#include <lang/Vector.h>
#include <core/ObjectImpl.h>
#include <win/IMonitor.h>


namespace synkro
{


namespace win
{


// Generic window system implementation.
template <class T>
class WindowSystemImpl :
	public core::ObjectImpl<T>,
	public Logger
{
public:
	// Constructor and destructor.
	WindowSystemImpl( diag::ILog* log );
	virtual ~WindowSystemImpl();

	// ISystem methods.
	virtual Bool											Update( Double delta );

	// IWindowSystem methods.
	virtual UInt											GetMonitorCount() const;
	virtual IMonitor*										GetMonitor( UInt index ) const;
	virtual IMonitor*										GetMonitor() const;

protected:
	lang::Vector<P(IMonitor)>								_monitors;
	IMonitor*												_monitor;
};


#include "WindowSystemImpl.inl"


} // win


} // synkro


#endif // _SYNKRO_WIN_WINDOWSYSTEMIMPL_
