#include <prf/Profiler.h>
#include <prf/StdProfiler.h>


//------------------------------------------------------------------------------

using namespace synkro::prf;

//------------------------------------------------------------------------------


int main( int argc, char* argv[] )
{
	SynkroProfileInit( "../../../synkro/bin/win64/synkro.prf", true, "../../data/prf/StdPrfReport.txt", false, true );

	{
		SynkroProfile( "Block1" );
		Sleep( 1254 );

		for ( UInt i = 0; i < 3; ++i )
		{
			SynkroProfile( "Block1.1" );
			Sleep( 40 );
		}

		Sleep( 300 );
	}

	for ( UInt i = 0; i < 5; ++i )
	{
		SynkroProfile( "Block2" );
		Sleep( 50 );
	}

	return 0;
}
