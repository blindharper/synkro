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
// Purpose: Implements monitor.
//==============================================================================
#ifndef _SYNKRO_WIN_MONITOR_
#define _SYNKRO_WIN_MONITOR_


#include "config.h"
#include <core/ObjectImpl.h>
#include <win/IMonitor.h>


namespace synkro
{


namespace win
{


// Monitor implementation.
class SYNKRO_API Monitor :
	public core::ObjectImpl<IMonitor>
{
public:
	// Constructor.
	Monitor( UInt handle, const lang::String& name, const lang::Point& location, const lang::Size& size, const MonitorOrientation& orientation );

	// IMonitor methods.
	void													GetLocation( lang::Point& location ) const;
	void													GetSize( lang::Size& size ) const;
	MonitorOrientation										GetOrientation() const;
	UInt													GetHandle() const;
	lang::String											GetName() const;

private:
	Pointer													_handle;
	lang::String											_name;
	lang::Point												_location;
	lang::Size												_size;
	MonitorOrientation										_orientation;
};


#include "Monitor.inl"


} // win


} // synkro


#endif // _SYNKRO_WIN_MONITOR_
