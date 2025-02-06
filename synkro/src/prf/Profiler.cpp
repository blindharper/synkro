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
// Purpose: Code profiler wrapper.
//==============================================================================
#include "config.h"
#include <prf/Profiler.h>
#include <core/Platform.h>
#include <internal/DynamicLibrary.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro;

//------------------------------------------------------------------------------


static DynamicLibrary _module; // Library module handle.


static void StubPrfInitialize( Bool )
{
	// Do nothing.
}

static void StubPrfBegin( const char*, Bool )
{
	// Do nothing.
}

static void StubPrfEnd()
{
	// Do nothing.
}

static void StubPrfSaveReport( const char*, Bool, Bool )
{
	// Do nothing.
}

//------------------------------------------------------------------------------

namespace synkro
{


namespace prf
{


static SYNKRO_FUNC_SETBOOL		_funcInitialize = nullptr;	// Initialize().
static SYNKRO_FUNC_BEGIN		_funcBegin = nullptr;		// BeginProfile().
static SYNKRO_FUNC_VOID			_funcEnd = nullptr;			// EndProfile().
static SYNKRO_FUNC_SAVE_REPORT	_funcSaveReport = nullptr;	// SaveReport().


void Profiler::Initialize( const char* filename, Bool expand )
{
#if defined( SYNKRO_PERF )

	if ( (_funcInitialize == nullptr) && (_funcBegin == nullptr) && (_funcEnd == nullptr) && (_funcSaveReport == nullptr) )
	{
		if ( (filename != nullptr) && (strlen(filename) > 0) )
		{
			// Get full module name.
			char module[260] = {};
			strcpy( module, filename );
			const size_t len = wcslen( Platform::DynamicLibraryExtension );
			for ( size_t i = 0; i < len; ++i )
			{
				const char ch = (char)Platform::DynamicLibraryExtension[i];
				strncat( module, &ch, 1 );
			}

			// Load module into memory.
			_module.Open( module );
			if ( !_module.IsOpen() )
			{
				Platform::Error( L"Failed to load profiler." );
				throw;
			}

			// Get required entry points.
			_funcInitialize	= (SYNKRO_FUNC_SETBOOL)_module.GetSymbol( "SynkroPrfInitialize" );
			_funcBegin		= (SYNKRO_FUNC_BEGIN)_module.GetSymbol( "SynkroPrfBegin" );
			_funcEnd		= (SYNKRO_FUNC_VOID)_module.GetSymbol( "SynkroPrfEnd" );
			_funcSaveReport	= (SYNKRO_FUNC_SAVE_REPORT)_module.GetSymbol( "SynkroPrfSaveReport" );
			
			// Verify entry points.
			if ( (_funcInitialize == nullptr) || (_funcBegin == nullptr) || (_funcEnd == nullptr) || (_funcSaveReport == nullptr) )
			{
				Platform::Error( L"Profiler is corrupted." );
				throw;
			}
		}
		else
		{
			// Use stub implementation.
			_funcInitialize	= StubPrfInitialize;
			_funcBegin		= StubPrfBegin;
			_funcEnd		= StubPrfEnd;
			_funcSaveReport	= StubPrfSaveReport;
		}

		// Perform initialization.
		_funcInitialize( expand );
	}

#endif // defined( SYNKRO_PERF )
}

void Profiler::Finalize()
{
#if defined( SYNKRO_PERF )

	_module.Close();
	_funcInitialize = nullptr;
	_funcBegin = nullptr;
	_funcEnd = nullptr;
	_funcSaveReport = nullptr;

#endif // defined( SYNKRO_PERF )
}

void Profiler::BeginProfile( const char* name, Bool collapse )
{
#if defined( SYNKRO_PERF )

	_funcBegin( name, collapse );

#endif // defined( SYNKRO_PERF )
}

void Profiler::EndProfile()
{
#if defined( SYNKRO_PERF )

	_funcEnd();

#endif // defined( SYNKRO_PERF )
}

void Profiler::SaveReport( const char* filename, Bool accumulate, Bool plain )
{
#if defined( SYNKRO_PERF )

	if ( _funcSaveReport != nullptr)
	{
		_funcSaveReport( filename, accumulate, plain );
	}

#endif // defined( SYNKRO_PERF )
}


} // prf


} // synkro
