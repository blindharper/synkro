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
#include "config.h"
#include <core/Platform.h>


// Defines string constant.
#define SYNKRO_PLATFORM_STRING( CONST, VALUE ) \
	const Char* Platform::CONST = L##VALUE;

// Defines character constant.
#define SYNKRO_PLATFORM_CHAR( CONST, VALUE ) \
	const Char Platform::CONST = VALUE;


namespace synkro
{


namespace core
{


#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	SYNKRO_PLATFORM_STRING( LineDelimiter, "\r\n" )
	SYNKRO_PLATFORM_CHAR( PathDelimiter, '\\' )
	SYNKRO_PLATFORM_STRING( DynamicLibraryExtension, ".dll" )
#else
	SYNKRO_PLATFORM_STRING( LineDelimiter, "\n" )
	SYNKRO_PLATFORM_CHAR( PathDelimiter, '/' )
	SYNKRO_PLATFORM_STRING( DynamicLibraryExtension, ".so" )
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS

	const UInt Platform::ProcessorCount = 0;
	static UInt _id = 0;

void Platform::Error( const Char* message )
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	::MessageBoxW( NULL, message, L"ERROR", MB_ICONERROR|MB_OK );
#else
#	error Platform::Error is not defined.
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
}

Bool Platform::Question( const Char* title, const Char* question )
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	return ::MessageBoxW( NULL, question, title, MB_ICONQUESTION|MB_YESNO ) == IDYES;
#else
#	error Platform::Question is not defined.
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
}

void Platform::Sleep( UInt time )
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	::Sleep( time );
#else
#	error Platform::Sleep is not defined.
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
}

Int Platform::Increment( Int value )
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	return ::InterlockedIncrement( (LONG*)&value );
#else
#	error Platform::Increment is not defined.
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
}

Int Platform::Decrement( Int value )
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	return ::InterlockedDecrement( (LONG*)&value );
#else
#	error Platform::Decrement is not defined.
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
}

UInt Platform::NextID()
{
	return ++_id;
}


} // core


} // synkro
