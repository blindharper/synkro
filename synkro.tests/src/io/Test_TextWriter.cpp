#include "config.h"
#include "Test.h"
#include <io/TextWriter.h>
#include <io/FileStream.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::io;

//------------------------------------------------------------------------------

class TestTextWriter :
	public Test
{
public:
	TestTextWriter() : Test( "TestTextWriter", 503 ) {}

	void Run()
	{
		try
		{
			TextWriter writer( new FileStream("../../data/io/stream_out.txt"), "UTF-32LE" );
			writer.WriteLine( "first line" );
			writer.WriteLine( "second line" );
			writer.WriteLine( "third line" );
		}
		catch ( Exception& ex )
		{
			char buf[260];
			ex.Message().GetBytes( buf, 260 );
			FatalError( buf );
		}
	}

} _tst;
