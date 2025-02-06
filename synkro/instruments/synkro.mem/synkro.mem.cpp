//==============================================================================
// This file is a part of the Synkro Project.
// 
// Copyright (c) Nobody. No rights reserved :)
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is encouraged without any permission from the Synkro Project.
// Website: https://synkro.org Email: mailto:blindharper70@gmail.com
//
// Purpose: Standard memory manager.
//==============================================================================
#include "config.h"
#include "../synkroinstr.h"
#include <mem/StdMemoryManager.h>


synkro::Bool _showLines = false;


SYNKRO_EXTERN_C SYNKROINSTR_API void SynkroMemInitialize( synkro::Bool showLines )
{
	_showLines = showLines;
}

SYNKRO_EXTERN_C SYNKROINSTR_API void* SynkroMemAllocate( synkro::UInt size, const char* file, synkro::UInt line )
{
	char name[260] = {};
	sprintf_s( name, 260, _showLines ? "%s:%d" : "%s", file, line );
	void* group = synkro::mem::StdMemoryManager::GroupCreate( name );
	return synkro::mem::StdMemoryManager::Allocate( group, size );
}

SYNKRO_EXTERN_C SYNKROINSTR_API void SynkroMemFree( void* ptr, synkro::UInt size )
{
	synkro::mem::StdMemoryManager::Free( ptr );
}

SYNKRO_EXTERN_C SYNKROINSTR_API void SynkroMemGetStats( synkro::UInt* stats, synkro::UInt count )
{
	stats[0] = synkro::mem::StdMemoryManager::BytesUsed();
	stats[1] = synkro::mem::StdMemoryManager::BytesMaximum();
	stats[2] = synkro::mem::StdMemoryManager::BytesTotal();
}

SYNKRO_EXTERN_C SYNKROINSTR_API void SynkroMemSaveReport( const char* filename, synkro::Bool leaksOnly, synkro::Bool plain )
{
	synkro::mem::StdMemoryManager::SaveReport( filename, leaksOnly, plain );
}
