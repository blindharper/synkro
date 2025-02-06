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
// Purpose: Synkro configuration file for Windows platform.
//==============================================================================
#ifndef _SYNKRO_CFG_CONFIGWINDOWS_
#define _SYNKRO_CFG_CONFIGWINDOWS_


namespace synkro
{

// Redefine basic types.
#if ( SYNKRO_COMPILER_VERSION >= 1400 )
typedef wchar_t				Char;
#	else
typedef unsigned __int16	Char;
#endif // ( SYNKRO_COMPILER_VERSION >= 1400 )

typedef bool				Bool;
typedef float				Float;
typedef double				Double;

typedef __int16				Short;
typedef __int32				Int;
typedef __int64				Long;

typedef unsigned __int8		Byte;
typedef unsigned __int16	UShort;
typedef unsigned __int32	UInt;
typedef unsigned __int64	ULong;

#if ( SYNKRO_PROCESSOR == SYNKRO_PROCESSOR_X64 )
typedef unsigned __int64	Pointer;
#elif ( SYNKRO_PROCESSOR == SYNKRO_PROCESSOR_X86 )
typedef unsigned __int32	Pointer;
#endif

} // synkro

// 'null' pointer.
constexpr synkro::Pointer null = 0;

// 'none' index.
constexpr synkro::UInt none = (synkro::UInt)-1;

// Disable some compiler warnings.
#pragma warning ( disable : 4101 )	// 'identifier' : unreferenced local variable
#pragma warning ( disable : 4244 )	// 'conversion' conversion from 'type1' to 'type2', possible loss of data
#pragma warning ( disable : 4251 )	// 'identifier' : class 'type' needs to have dll-interface to be used by clients of class 'type2'
#pragma warning ( disable : 4302 )	// 'type cast': truncation from 'type 1' to 'type 2'
#pragma warning ( disable : 4311 )	// 'type cast' : pointer truncation from 'type1' to 'type2'
#pragma warning ( disable : 4312 )	// 'type cast' : conversion from 'type1' to 'type2' of greater size
#pragma warning ( disable : 4595 )	// 'identifier': non-member operator new or delete functions may not be declared inline

// Standard includes.
#define _WIN32_WINNT 0x0600
#define WIN32_LEAN_AND_MEAN			// Exclude rarely-used stuff from Windows headers
#define _CRT_SECURE_NO_DEPRECATE	// Eliminate deprecation warnings
#include <windows.h>				// Windows stuff
#include <algorithm>				// Standard algorithms
#include <assert.h>					// Debug assertions
#include <string.h>					// String manipulation routines
#include <stdlib.h>					// Standard library routines
#include <stdio.h>					// Standard input/output
#include <math.h>					// Mathematic library
#include <time.h>					// Time routines


#endif // _SYNKRO_CFG_CONFIGWINDOWS_
