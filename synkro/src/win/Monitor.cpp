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
#include "config.h"
#include "Monitor.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace win
{


Monitor::Monitor( UInt handle, const String& name, const Point& location, const Size& size, const MonitorOrientation& orientation ) :
	_handle( handle ),
	_name( name ),
	_location( location ),
	_size( size ),
	_orientation( orientation )
{
}


} // win


} // synkro
