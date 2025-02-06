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
SYNKRO_INLINE void Monitor::GetLocation( lang::Point& location ) const
{
	location = _location;
}

SYNKRO_INLINE void Monitor::GetSize( lang::Size& size ) const
{
	size = _size;
}

SYNKRO_INLINE MonitorOrientation Monitor::GetOrientation() const
{
	return _orientation;
}

SYNKRO_INLINE UInt Monitor::GetHandle() const
{
	return _handle;
}

SYNKRO_INLINE lang::String Monitor::GetName() const
{
	return _name;
}
