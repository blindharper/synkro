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
// Purpose: Standard profiler.
//==============================================================================
#include "config.h"
#include "../synkroinstr.h"
#include <prf/StdProfiler.h>


SYNKRO_EXTERN_C SYNKROINSTR_API void SynkroPrfInitialize( synkro::Bool expand )
{
	synkro::prf::StdProfiler::Initialize( expand );
}

SYNKRO_EXTERN_C SYNKROINSTR_API void SynkroPrfBegin( const char* name, synkro::Bool collapse )
{
	synkro::prf::StdProfiler::BeginProfile( name, collapse );
}

SYNKRO_EXTERN_C SYNKROINSTR_API void SynkroPrfEnd()
{
	synkro::prf::StdProfiler::EndProfile();
}

SYNKRO_EXTERN_C SYNKROINSTR_API void SynkroPrfSaveReport( const char* filename, synkro::Bool accumulate, synkro::Bool plain )
{
	synkro::prf::StdProfiler::SaveReport( filename, accumulate, plain );
}
