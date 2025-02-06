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
// Purpose: Synkro configuration.
//==============================================================================
#ifndef _SYNKRO_CFG_CONFIGSYNKRO_
#define _SYNKRO_CFG_CONFIGSYNKRO_


// Processor endianess.
#define SYNKRO_ENDIAN_LITTLE		0
#define SYNKRO_ENDIAN_BIG			1


// Processor identifiers.
#define SYNKRO_PROCESSOR_UNKNOWN	0
#define SYNKRO_PROCESSOR_X86		1
#define SYNKRO_PROCESSOR_X64		2


// Platform identifiers.
#define SYNKRO_PLATFORM_UNKNOWN		0
#define SYNKRO_PLATFORM_WINDOWS		1
#define SYNKRO_PLATFORM_LINUX		2


// Compiler identifiers.
#define SYNKRO_COMPILER_UNKNOWN		0
#define SYNKRO_COMPILER_MSVC		1
#define SYNKRO_COMPILER_GNUC		2


// Specifies debug build.
#if defined( DEBUG ) || defined( _DEBUG )
#	define SYNKRO_DEBUG
#endif // defined( DEBUG ) || defined( _DEBUG )


// Detect processor.
#if defined( _M_X64 ) || defined( _M_IA64 ) || defined( __amd64__ )
#	define SYNKRO_PROCESSOR SYNKRO_PROCESSOR_X64
#	define SYNKRO_ENDIAN SYNKRO_ENDIAN_LITTLE
#elif defined( _M_IX86 ) || defined( _X86_ )
#	define SYNKRO_PROCESSOR SYNKRO_PROCESSOR_X86
#	define SYNKRO_ENDIAN SYNKRO_ENDIAN_LITTLE
#else
#	define SYNKRO_PROCESSOR SYNKRO_PROCESSOR_UNKNOWN
#	pragma message( "SYNKRO_PROCESSOR: SYNKRO_PROCESSOR_UNKNOWN" )
#endif // defined( _M_IX86 )


// Detect platform.
#if defined( WIN64 ) || defined( _WIN64 ) || defined( __WIN32__ ) || defined( _WIN32 )
#	define SYNKRO_PLATFORM SYNKRO_PLATFORM_WINDOWS
#elif defined( __linux__ ) || defined( _LINUX )
#	define SYNKRO_PLATFORM SYNKRO_PLATFORM_LINUX
#else 
#	error Unknown platform. Compilation aborted.
#endif // defined( WIN64 ) || defined( _WIN64 ) || defined( __WIN32__ ) || defined( _WIN32 )


// Detect compiler type and version.
#if defined( _MSC_VER )
#	define SYNKRO_COMPILER SYNKRO_COMPILER_MSVC
#	define SYNKRO_COMPILER_VERSION _MSC_VER
#elif defined( __GNUC__ )
#	define SYNKRO_COMPILER SYNKRO_COMPILER_GNUC
#	define SYNKRO_COMPILER_VERSION __GNUC__.__GNUC_MINOR__
#else
#	error Unknown compiler. Compilation aborted.
#endif // defined( _MSC_VER )


// Define export directive.
#if !defined( SYNKRO_API )
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
#	if defined( SYNKRO_STATIC )
#		define SYNKRO_API
#	elif defined( SYNKRO_EXPORTS )
#		define SYNKRO_API __declspec( dllexport )
#	else
#		define SYNKRO_API __declspec( dllimport )
#	endif // defined( SYNKRO_EXPORTS )
#else
#	define SYNKRO_API
#	pragma message( "SYNKRO_API:" )
#endif // ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
#endif // !defined( SYNKRO_API )


// Define extern "C" macro.
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
#	define SYNKRO_EXTERN_C extern "C"
#elif ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_LINUX )
#	define SYNKRO_EXTERN_C
#endif // ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )


// Define inlining directive.
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
#	define SYNKRO_INLINE __forceinline
#elif ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_LINUX )
#	define SYNKRO_INLINE inline
#endif // ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )


// Platform-specific headers.
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
#	include "ConfigWindows.h"
#elif ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_LINUX )
#	include "ConfigLinux.h"
#endif // ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )

// Preliminary declarations.
#define iface class
#include "Interfaces.h"


// Type castings.
#define CastByte( a )	static_cast<synkro::Byte>(a)
#define CastChar( a )	static_cast<synkro::Char>(a)
#define CastDouble( a )	static_cast<synkro::Double>(a)
#define CastFloat( a )	static_cast<synkro::Float>(a)
#define CastInt( a )	static_cast<synkro::Int>(a)
#define CastUInt( a )	static_cast<synkro::UInt>(a)
#define CastLong( a )	static_cast<synkro::Long>(a)
#define CastULong( a )	static_cast<synkro::ULong>(a)
#define CastShort( a )	static_cast<synkro::Short>(a)
#define CastUShort( a )	static_cast<synkro::UShort>(a)


// Function prototypes.
typedef void ( *SYNKRO_FUNC_VOID )();
typedef synkro::Bool ( *SYNKRO_FUNC_GETBOOL )();
typedef void ( *SYNKRO_FUNC_SETBOOL )( synkro::Bool );
typedef synkro::UInt ( *SYNKRO_FUNC_GETUINT )();
typedef const synkro::Char* ( *SYNKRO_FUNC_GETSTRING )();
typedef const synkro::Char* ( *SYNKRO_FUNC_GETSTRING_INDEX )( synkro::UInt );
typedef synkro::core::IFactory* ( *SYNKRO_FUNC_GETFACTORY )( synkro::UInt );
typedef synkro::core::IResource* ( *SYNKRO_FUNC_GETRESOURCE )( synkro::UInt );
typedef void* ( *SYNKRO_FUNC_ALLOCATE )( synkro::UInt, const char*, synkro::UInt );
typedef void ( *SYNKRO_FUNC_FREE )( void*, synkro::UInt );
typedef void ( *SYNKRO_FUNC_GET_STATS )( synkro::UInt*, synkro::UInt );
typedef void ( *SYNKRO_FUNC_SAVE_REPORT )( const char*, synkro::Bool, synkro::Bool );
typedef void ( *SYNKRO_FUNC_BEGIN )( const char*, synkro::Bool );


#endif // _SYNKRO_CFG_CONFIGSYNKRO_
