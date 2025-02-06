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
// Purpose: Defines Synkro version.
//==============================================================================
#include "config.h"
#include <core/Version.h>
#include <cfg/SynkroVersion.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace core
{


const Version Version::Current( SYNKRO_VERSION );


Version::Version( UInt version ) :
	Major( (version & 0x00ff0000) >> 16 ),
	Minor( (version & 0x0000ff00) >> 8 ),
	Patch( version & 0x000000ff )
{
}

Version::Version() :
	Major( 0 ),
	Minor( 0 ),
	Patch( 0 )
{
}

String Version::ToString() const
{
#if ( SYNKRO_PROCESSOR == SYNKRO_PROCESSOR_X86 )
	const Char* platform = L"x86";
#elif ( SYNKRO_PROCESSOR == SYNKRO_PROCESSOR_X64 )
	const Char* platform = L"x64";
#endif // SYNKRO_PROCESSOR == SYNKRO_PROCESSOR_X86

#if defined( SYNKRO_DEBUG )
	const Char* suffix = L" debug";
#elif defined( SYNKRO_PERF )
	const Char* suffix = L" perf";
#else
	const Char* suffix = L"";
#endif // defined( SYNKRO_DEBUG )

	return String::Format( L"{0} {1}.{2}.{3}{4}", platform, CastDouble(Major), CastDouble(Minor), CastDouble(Patch), suffix );
}

Bool Version::IsCompatible( const Version& other ) const
{
	return (Major == other.Major);
}


} // core


} // synkro
