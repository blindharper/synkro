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
// Purpose: Defines window system monitor.
//==============================================================================
#ifndef _SYNKRO_WIN_IMONITOR_
#define _SYNKRO_WIN_IMONITOR_


#include "config.h"
#include <core/IObject.h>
#include <lang/String.h>
#include <lang/Point.h>
#include <lang/Size.h>
#include <win/MonitorOrientation.h>


namespace synkro
{


namespace win
{


/**
 * Window system monitor.
 */
iface IMonitor :
	public core::IObject
{
public:
	/**
	 * Retrieves monitor's location in virtual screen coordinates.
	 * @param [out] location Monitor's location. Can be negative for non-primary monitors.
	 */
	virtual void											GetLocation( lang::Point& location ) const = 0;

	/**
	 * Retrieves monitor's size.
	 * @param [out] size Monitor's size.
	 */
	virtual void											GetSize( lang::Size& size ) const = 0;

	/**
	 * Retrieves monitor orientation.
	 */
	virtual MonitorOrientation								GetOrientation() const = 0;

	/**
	 * Retrieves unique monitor descriptor.
	 */
	virtual UInt											GetHandle() const = 0;

	/**
	 * Retrieves monitor's name.
	 */
	virtual lang::String									GetName() const = 0;
};


} // win


} // synkro


#endif // _SYNKRO_WIN_IMONITOR_
