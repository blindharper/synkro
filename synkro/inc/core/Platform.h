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
// Purpose: Defines target platform.
//==============================================================================
#ifndef _SYNKRO_CORE_PLATFORM_
#define _SYNKRO_CORE_PLATFORM_


#include "config.h"


namespace synkro
{


namespace core
{


/**
 * Target platform.
 */
class SYNKRO_API Platform
{
public:
	/**
	 * Line delimiter.
	 */
	static const Char*										LineDelimiter;

	/**
	 * Path delimiter.
	 */
	static const Char										PathDelimiter;

	/**
	 * Dynamic library extension.
	 */
	static const Char*										DynamicLibraryExtension;

	/**
	 * The total number of processors in the system.
	 */
	static const UInt										ProcessorCount;

	/**
	 * Displays an error message.
	 * @param message Error message.
	 */
	static void												Error( const Char* message );

	/**
	 * Displays a Yes/No question.
	 * @param title Dialog box title.
	 * @param question Question text.
	 * @return True, if the user hit Yes, false otherwise.
	 */
	static Bool												Question( const Char* title, const Char* question );

	/**
	 * Suspends the calling thread for the specified amount of time.
	 * @param time Sleep time, in milliseconds.
	 */
	static void												Sleep( UInt time );

	/**
	 * Returns given value incremented by one. Increment is thread-safe.
	 */
	static Int												Increment( Int value );

	/**
	 * Returns given value decremented by one. Decrement is thread-safe.
	 */
	static Int												Decrement( Int value );

	/**
	 * Returns unique identifier.
	 */
	static UInt												NextID();
};


} // core


} // synkro


#endif // _SYNKRO_CORE_PLATFORM_
