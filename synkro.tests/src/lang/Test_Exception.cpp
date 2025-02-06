#include "config.h"
#include "Test.h"
#include <lang/Exception.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------

class TestException :
	public Test
{
public:
	TestException() : Test( "TestException", 103 ) {}

	void Run()
	{
		try
		{
			DoBug();
		}
		catch ( Exception& ex )
		{
			Assert( ex.Message() == "Hello! I am a bug." );
		}
	}

	void DoBug()
	{
		throw Exception( "Hello! I am a bug." );
	}

} _tst;
