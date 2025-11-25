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
	Timer() SYNKRO_NOEXCEPT;

	// Returns the time, in milliseconds, elapsed since last method call.
	synkro::Double											GetElapsedMilliseconds() SYNKRO_NOEXCEPT;

	// Returns the time, in milliseconds, elapsed since the specified timestamp.
	synkro::Double											GetElapsedMilliseconds( synkro::ULong& lastTime, synkro::Bool modify = true ) const SYNKRO_NOEXCEPT;

	// Returns the time, in seconds, elapsed since last method call.
	synkro::Double											GetElapsedSeconds() SYNKRO_NOEXCEPT;

	// Returns the time, in seconds, elapsed since the specified timestamp.
	synkro::Double											GetElapsedSeconds( synkro::ULong& lastTime, synkro::Bool modify = true ) const SYNKRO_NOEXCEPT;

	// Returns the time, in ticks, elapsed since last method call.
	synkro::ULong											GetElapsedTicks() SYNKRO_NOEXCEPT;

	// Returns the time, in ticks, elapsed since the specified timestamp.
	synkro::ULong											GetElapsedTicks( synkro::ULong& lastTime, synkro::Bool modify = true ) const SYNKRO_NOEXCEPT;

	// Returns current time stamp.
	synkro::ULong											GetTimeStamp() const SYNKRO_NOEXCEPT;

	// Retrieves timer's frequency.
	synkro::Double											GetTicksPerSecond() const SYNKRO_NOEXCEPT;

private:
	Timer( const Timer& );
	Timer& operator=( const Timer& );

	synkro::Double											_ticksPerSecond;
	synkro::ULong											_lastTime;
};


#include "Timer.inl"


#endif // _SYNKRO_INTERNAL_TIMER_
