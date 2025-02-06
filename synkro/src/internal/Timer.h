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
// Purpose: Defines system timer.
//==============================================================================
#ifndef _SYNKRO_INTERNAL_TIMER_
#define _SYNKRO_INTERNAL_TIMER_


#include "config.h"


// System timer.
class Timer
{
public:
	// Constructor.
	Timer();

	// Returns the time, in milliseconds, elapsed since last method call.
	synkro::Double											GetElapsedMilliseconds();

	// Returns the time, in milliseconds, elapsed since the specified timestamp.
	synkro::Double											GetElapsedMilliseconds( synkro::ULong& lastTime, synkro::Bool modify = true ) const;

	// Returns the time, in seconds, elapsed since last method call.
	synkro::Double											GetElapsedSeconds();

	// Returns the time, in seconds, elapsed since the specified timestamp.
	synkro::Double											GetElapsedSeconds( synkro::ULong& lastTime, synkro::Bool modify = true ) const;

	// Returns the time, in ticks, elapsed since last method call.
	synkro::ULong											GetElapsedTicks();

	// Returns the time, in ticks, elapsed since the specified timestamp.
	synkro::ULong											GetElapsedTicks( synkro::ULong& lastTime, synkro::Bool modify = true ) const;

	// Returns current time stamp.
	synkro::ULong											GetTimeStamp() const;

	// Retrieves timer's frequency.
	synkro::Double											GetTicksPerSecond() const;

private:
	Timer( const Timer& );
	Timer& operator=( const Timer& );

	synkro::Double											_ticksPerSecond;
	synkro::ULong											_lastTime;
};


#include "Timer.inl"


#endif // _SYNKRO_INTERNAL_TIMER_
