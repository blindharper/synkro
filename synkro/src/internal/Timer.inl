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
SYNKRO_INLINE Timer::Timer() SYNKRO_NOEXCEPT :
	_ticksPerSecond( 0.0 ),
	_lastTime( 0 )
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	LARGE_INTEGER frequency;
	::QueryPerformanceFrequency( &frequency );
	_ticksPerSecond = synkro::Double( frequency.QuadPart );
	GetElapsedTicks(); // Save last time.
#else
#	error Timer::Timer() is not defined.
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
}

SYNKRO_INLINE synkro::Double Timer::GetElapsedMilliseconds() SYNKRO_NOEXCEPT
{
	return 1000.0*GetElapsedSeconds();
}

SYNKRO_INLINE synkro::Double Timer::GetElapsedMilliseconds( synkro::ULong& lastTime, synkro::Bool modify ) const SYNKRO_NOEXCEPT
{
	return 1000.0*GetElapsedSeconds( lastTime, modify );
}

SYNKRO_INLINE synkro::Double Timer::GetElapsedSeconds() SYNKRO_NOEXCEPT
{
	const synkro::ULong ticks = GetElapsedTicks();
	return CastDouble(ticks) / _ticksPerSecond;
}

SYNKRO_INLINE synkro::Double Timer::GetElapsedSeconds( synkro::ULong& lastTime, synkro::Bool modify ) const SYNKRO_NOEXCEPT
{
	const synkro::ULong ticks = GetElapsedTicks( lastTime, modify );
	return CastDouble(ticks) / _ticksPerSecond;
}

SYNKRO_INLINE synkro::ULong Timer::GetElapsedTicks() SYNKRO_NOEXCEPT
{
	const synkro::ULong currentTime = GetTimeStamp();
	const synkro::ULong ticks = currentTime - _lastTime;
	_lastTime = currentTime;
	return ticks;
}

SYNKRO_INLINE synkro::ULong Timer::GetElapsedTicks( synkro::ULong& lastTime, synkro::Bool modify ) const SYNKRO_NOEXCEPT
{
	synkro::ULong currentTime = GetTimeStamp();
	const synkro::ULong ticks = currentTime - lastTime;
	if ( modify )
	{
		lastTime = currentTime;
	}
	return ticks;
}

SYNKRO_INLINE synkro::ULong Timer::GetTimeStamp() const SYNKRO_NOEXCEPT
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	static LARGE_INTEGER currentTime;
	::QueryPerformanceCounter( &currentTime );
	return CastULong(currentTime.QuadPart);
#else
#	error Timer::GetTimeStamp() is not defined.
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
}

SYNKRO_INLINE synkro::Double Timer::GetTicksPerSecond() const SYNKRO_NOEXCEPT
{
	return _ticksPerSecond;
}
