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

#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	#define SYNKROLNG_API __declspec( dllexport )
#endif // ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )

SYNKRO_EXTERN_C SYNKROLNG_API const synkro::Char* SynkroLibGetName();
SYNKRO_EXTERN_C SYNKROLNG_API const synkro::Char* SynkroLibGetDescription();
SYNKRO_EXTERN_C SYNKROLNG_API const synkro::Char* SynkroLibGetAuthor();
SYNKRO_EXTERN_C SYNKROLNG_API const synkro::Char* SynkroLibGetCopyright();
SYNKRO_EXTERN_C SYNKROLNG_API const synkro::Char* SynkroLibGetComment();
SYNKRO_EXTERN_C SYNKROLNG_API const synkro::Char* SynkroLibGetLanguage();
SYNKRO_EXTERN_C SYNKROLNG_API synkro::ULong SynkroLibGetCoreVersion();
SYNKRO_EXTERN_C SYNKROLNG_API synkro::ULong SynkroLibGetVersion();
SYNKRO_EXTERN_C SYNKROLNG_API synkro::ULong SynkroLibGetStringCount();
SYNKRO_EXTERN_C SYNKROLNG_API const synkro::Char* SynkroLibGetStringName( synkro::ULong index );
SYNKRO_EXTERN_C SYNKROLNG_API const synkro::Char* SynkroLibGetStringValue( synkro::ULong index );
