//==============================================================================
// This file is a part of the Synkro Project.
// 
// Copyright (c) Nobody. No rights reserved :)
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is encouraged without any permission from the Synkro Project.
// Website: http://synkro.org Email: mailto:blindharper70@gmail.com
//
// Purpose: Language resource library.
//==============================================================================
#include "config.h"
#include "synkro.lng.h"
#include <internal/SizeOf.h>

using namespace synkro::core;
using namespace synkro;

struct StrDef
{
	const Char*	Name;
	const Char*	Value;
};

static StrDef _strings[] =
{
#if defined( SYNKROLNG_RUSSIAN )
	#include "languages/russian.inl"
#elif defined( SYNKROLNG_ENGLISH )
	#include "languages/english.inl"
#endif
};

//------------------------------------------------------------------------------

SYNKROLNG_API const Char* SynkroLibGetName()
{
	return L"synkro.lng";
}

SYNKROLNG_API const Char* SynkroLibGetDescription()
{
	return L"Synkro Language Resource Library";
}

SYNKROLNG_API const Char* SynkroLibGetAuthor()
{
	return L"blindharper";
}

SYNKROLNG_API const Char* SynkroLibGetCopyright()
{
	return L"Copyright (c) Synkro Project";
}

SYNKROLNG_API const Char* SynkroLibGetComment()
{
	return L"Resource strings";
}

SYNKROLNG_API const Char* SynkroLibGetLanguage()
{
#if defined( SYNKROLNG_RUSSIAN )
	return L"Russian";
#elif defined( SYNKROLNG_ENGLISH )
	return L"English";
#endif
}

SYNKROLNG_API ULong SynkroLibGetCoreVersion()
{
	return 1;
}

SYNKROLNG_API ULong SynkroLibGetVersion()
{
	return 1;
}

SYNKROLNG_API ULong SynkroLibGetStringCount()
{
	return SizeOf( _strings );
}

SYNKROLNG_API const Char* SynkroLibGetStringName( ULong index )
{
	if ( index < SynkroLibGetStringCount() )
		return _strings[index].Name;

	return 0;
}

SYNKROLNG_API const Char* SynkroLibGetStringValue( ULong index )
{
	if ( index < SynkroLibGetStringCount() )
		return _strings[index].Value;

	return 0;
}
