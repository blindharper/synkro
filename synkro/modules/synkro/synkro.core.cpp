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
// Purpose: Synkro library.
//==============================================================================
#include "config.h"

using namespace synkro;
using namespace synkro::core;

#define SYNKROLIB_NAME			L"synkro"
#define SYNKROLIB_DESC			L"Synkro Core Library"
#define SYNKROLIB_COMMENT		L"Synkro Core"
#define SYNKROLIB_STRINGS		_strings
#define SYNKROLIB_VERSION_MAJOR	SYNKRO_VERSION_MAJOR
#define SYNKROLIB_VERSION_MINOR	SYNKRO_VERSION_MINOR
#define SYNKROLIB_VERSION_PATCH	SYNKRO_VERSION_PATCH
#include "../synkrolib.inl"
#include <core/Synkro.h>
#include <core/CallStack.h>
#include <prf/Profiler.h>


static Pointer _module = null;


#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
BOOL WINAPI DllMain( HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved )
{
	switch ( fdwReason )
	{
		case DLL_PROCESS_ATTACH: _module = (Pointer)hinstDLL; break;
		default: break;
	}

	return TRUE;
}
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS


namespace synkro
{


SYNKRO_API ISynkro* SynkroCreate( UInt version, SynkroListener* listener )
{
	// Initialize standard memory manager.
	mem::MemoryManager::Initialize( 0, true );
	prf::Profiler::Initialize( 0, false );
	io::Path::Initialize();
	core::CallStack::Initialize();

	// Prevent creating multiple Synkro objects.
	static ISynkro* _synkro = nullptr;
	if ( _synkro != nullptr )
		return _synkro;

	// Determine module handle, if needed.
	if ( _module == null )
	{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
		::GetModuleHandleEx( 0, nullptr, (HMODULE*)&_module );
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
	}

	// Create Synkro object.
	return _synkro = new Synkro( _module, version, listener );
}


} // synkro
