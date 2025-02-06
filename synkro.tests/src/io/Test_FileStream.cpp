#include "config.h"
#include "Test.h"
#include <io/FileStream.h>
#include <internal/Zero.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::io;
using namespace synkro;

//------------------------------------------------------------------------------

class TestFileStream :
	public Test
{
public:
	TestFileStream() : Test( "TestFileStream", 602 ) {}

	void Run()
	{
		// Creation.
		P(IStream) stream = new FileStream( "../../data/io/stream_in.txt" );

		// Opening.
		stream->Open( OpenMode::Read | OpenMode::Write | OpenMode::Append );
		Assert( stream->GetMode() == (OpenMode::Read | OpenMode::Write | OpenMode::Append) );

		// Info.
		Assert( stream->GetLength() == 63 );

		// Writing.
		const char* line1 = "one more line\r\n";
		UInt lenOld = stream->GetLength();
		stream->Write( line1, (UInt)strlen(line1) );
		stream->Flush();
		UInt lenNew = stream->GetLength();
		Assert( (lenNew-lenOld) == strlen(line1) );

		// Setting length.
		stream->SetLength( lenOld );
		Assert( stream->GetLength() == lenOld );

		// Positioning.
		stream->Seek( 20, SeekOrigin::Start );
		Assert( stream->GetPosition() == 20 );
		stream->Reset();
		Assert( stream->GetPosition() == 0 );

		// Reading.
		char buf[12];
		Zero( buf, 12 );
		UInt bytesRead = stream->Read( &buf, 10 );
		Assert( bytesRead == 10 );
		Assert( String(buf) == String("first line") );

		// Closing.
		stream->Close();
	}
} _tst;