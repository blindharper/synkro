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
// Purpose: Defines dynamically-loaded library.
//==============================================================================
#ifndef _SYNKRO_INTERNAL_DYNAMICLIBRARY_
#define _SYNKRO_INTERNAL_DYNAMICLIBRARY_


#include "config.h"


// Dynamic library wrapper.
class DynamicLibrary
{
public:
	// Constructor.
	DynamicLibrary();

	// Loads library into memory.
	void													Open( const char* name );

	// Unloads library. The library cannot be accessed after this method call.
	void													Close();

	// Indicates whether the library is loaded.
	synkro::Bool											IsOpen() const;

	// Retrieves address of the specified symbol.
	void*													GetSymbol( const char* symbol ) const;

private:
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	HINSTANCE												_dll;
#elif ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_LINUX )
	void*													_dll;
#else
#	error DynamicLibrary is not defined.
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
};


#include "DynamicLibrary.inl"


#endif // _SYNKRO_INTERNAL_DYNAMICLIBRARY_
