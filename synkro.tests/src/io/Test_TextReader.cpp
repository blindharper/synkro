#include "config.h"
#include "Test.h"
#include <io/TextReader.h>
#include <io/FileStream.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::io;

//------------------------------------------------------------------------------

class TestTextReader :
	public Test
{
public:
	TestTextReader() : Test( "TestTextReader", 502 ) {}

	void Run()
	{
		try
		{
			TextReader rd( new FileStream("../../data/io/stream_in.txt") );
			String str = rd.Read( 5 );
			Assert( str == "first" )

			str = rd.Read( 1 );
			Assert( str == " " )

			str = rd.Read( 4 );
			Assert( str == "line" )

			str = rd.Read( 2 );

			Assert( rd.ReadLine() == "second line" );
			Assert( rd.ReadLine() == "third line" );
		}
		catch ( Exception& ex )
		{
			char buf[260];
			ex.Message().GetBytes( buf, 260 );
			FatalError( buf );
		}
	}

} _tst;
