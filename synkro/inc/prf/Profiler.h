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
// Purpose: Interface to Synkro code profiler.
//==============================================================================
#ifndef _SYNKRO_PRF_PROFILER_
#define _SYNKRO_PRF_PROFILER_


#include "config.h"


// Initializes code profiler.
#define SynkroProfileInit( MODULE, EXPAND, REPORT, ACCUMULATE, PLAIN ) synkro::prf::ProfileInitializer __pi( MODULE, EXPAND, REPORT, ACCUMULATE, PLAIN )


// Starts profiling a block of code.
#if defined( SYNKRO_PERF )
	#define SynkroProfile( NAME ) synkro::prf::ProfileTrigger __pt( NAME, false )
	#define SynkroProfileCollapsed( NAME ) synkro::prf::ProfileTrigger __pt( NAME, true )
	#define SynkroProfileBegin( NAME ) { synkro::prf::ProfileTrigger __pt( NAME, false )
	#define SynkroProfileEnd() }
#else
	#define SynkroProfile( NAME )
	#define SynkroProfileCollapsed( NAME )
	#define SynkroProfileBegin( NAME )
	#define SynkroProfileEnd()
#endif // defined( SYNKRO_PERF )


namespace synkro
{


namespace prf
{


/**
 * Code profiler.
 */
class SYNKRO_API Profiler
{
public:
	/**
	 * Loads and initializes the specified profiler module.
	 * @param filename Profiler module filename. If empty, there will be no profiler.
	 * @param expand Indicates whether to force expanding collapsed blocks.
	 */
	static void												Initialize( const char* filename, Bool expand );

	/**
	 * Uninitializes and unloads profiler.
	 */
	static void												Finalize();

	/**
	 * Begins profiling of the specified block of code.
	 * @param name Name of the scope to profile.
	 * @param collapse Indicates whether to profile nested blocks. If true, nested blocks are not profiled.
	 */
	static void												BeginProfile( const char* name, Bool collapse );

	/**
	 * Ends profiling of the current block of code.
	 */
	static void												EndProfile();

	/** 
	 * Saves profiler report to a file.
	 * @param filename Profiler report filename.
	 * @param accumulate True to enable cumulative profiling.
	 * @param plain True to create plain text report, false for rich text report.
	 */
	static void												SaveReport( const char* filename, Bool accumulate, Bool plain );
};


/**
 * Helper object used to start block profiling.
 */
class ProfileTrigger
{
public:
	SYNKRO_INLINE ProfileTrigger( const char* name, Bool collapse )
	{
		Profiler::BeginProfile( name, collapse );
	}

	SYNKRO_INLINE ~ProfileTrigger()
	{
		Profiler::EndProfile();
	}
};


/**
 * Helper object used to initialize and finalize profiler.
 */
class ProfileInitializer
{
public:
	SYNKRO_INLINE ProfileInitializer( const char* module, Bool expand, const char* report, Bool accumulate, Bool plain ) :
		_report( report ),
		_accumulate( accumulate ),
		_plain( plain )
	{
		Profiler::Initialize( module, expand );
	}

	SYNKRO_INLINE ~ProfileInitializer()
	{
		Profiler::SaveReport( _report, _accumulate, _plain );
		Profiler::Finalize();
	}

private:
	const char*	_report;
	Bool		_accumulate;
	Bool		_plain;
};


} // prf


} // synkro


#endif // _SYNKRO_PRF_PROFILER_
