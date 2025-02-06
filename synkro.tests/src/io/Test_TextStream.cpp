#include "config.h"
#include "Test.h"
#include <io/TextStream.h>
#include <internal/Zero.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::io;
using namespace synkro;

//------------------------------------------------------------------------------

class TestTextStream :
	public Test
{
public:
	TestTextStream() : Test( "TestTextStream", 601 ) {}

	void Run()
	{
		// Creation.
		String buffer( "Test string buffer" );
		P(IStream) stream = new TextStream( buffer, "UTF-8" );

		// Opening.
		stream->Open( OpenMode::Read );
		Assert( stream->GetMode() == (OpenMode::Read) );

		// Reading.
		char buf[12];
		Zero( buf, 12 );
		UInt bytesRead = stream->Read( &buf, 11 );
		Assert( bytesRead == 11 );
		Assert( String(buf) == String("Test string") );
	}
} _tst;