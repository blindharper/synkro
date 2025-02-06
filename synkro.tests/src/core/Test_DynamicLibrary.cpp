#include "config.h"
#include "Test.h"
#include <internal/DynamicLibrary.h>

//------------------------------------------------------------------------------

using namespace synkro::core;

//------------------------------------------------------------------------------

class TestDynamicLibrary :
	public Test
{
public:
	TestDynamicLibrary() : Test( "TestDynamicLibrary", 801 ) {}
	
	void Run()
	{
		try
		{
			DynamicLibrary dll;
#if ( SYNKRO_PROCESSOR == SYNKRO_PROCESSOR_X86 )
			dll.Open( "../../data/core/x86/synkro.io.dll" );
#elif ( SYNKRO_PROCESSOR == SYNKRO_PROCESSOR_X64 )
			dll.Open( "../../data/core/x64/synkro.io.dll" );
#endif // SYNKRO_PROCESSOR == SYNKRO_PROCESSOR_X86
			void* addr = dll.GetSymbol( "SynkroLibGetAuthor" );
			Assert( addr != 0 );
		}
		catch ( ... )
		{
			FatalError( "Failed to open dynamic library." );
		}
	}
} _tst;
