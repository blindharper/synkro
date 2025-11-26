#include <prf/Profiler.h>
#include <core/Platform.h>
#include <profiler/StdProfiler.h>


//------------------------------------------------------------------------------

using namespace synkro::prf;
using namespace synkro::core;

//------------------------------------------------------------------------------


int main( int argc, char* argv[] )
{
	SynkroProfileInit( "../../../synkro/bin/win64/profiler", true, "../../data/prf/StdPrfReport.txt", false, true );

	{
		SynkroProfile( "Block1" );
		Platform::Sleep( 1254 );

		for ( UInt i = 0; i < 3; ++i )
		{
			SynkroProfile( "Block1.1" );
			Platform::Sleep( 40 );
		}

		Platform::Sleep( 300 );
	}

	for ( UInt i = 0; i < 5; ++i )
	{
		SynkroProfile( "Block2" );
		Platform::Sleep( 50 );
	}

	return 0;
}
