#include "config.h"
#include "Test.h"
#include <lang/Vector.h>
#include <io/BinaryStream.h>
#include <internal/Zero.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::io;
using namespace synkro;

//------------------------------------------------------------------------------

class TestBinaryStream :
	public Test
{
public:
	TestBinaryStream() : Test( "TestBinaryStream", 600 ) {}

	void Run()
	{
		// Creation.
		Byte bytes[] = { 0x54, 0x17, 0xfe, 0xa4, 0x63, 0x45, 0xd3, 0x7c, 0x01, 0x4b };
		Vector<Byte> buffer( bytes, sizeof(bytes), A(Byte) );

		P(IStream) stream = new BinaryStream( buffer.Begin(), buffer.Size() );

		// Opening.
		stream->Open( OpenMode::Read | OpenMode::Write | OpenMode::Append );
		Assert( stream->GetMode() == (OpenMode::Read | OpenMode::Write | OpenMode::Append) );

		// Info.
		Assert( stream->GetLength() == sizeof(bytes) );

		// Positioning.
		stream->Seek( 5, SeekOrigin::Start );
		Assert( stream->GetPosition() == 5 );
		stream->Reset();
		Assert( stream->GetPosition() == 0 );

		// Reading.
		Byte buf[32];
		Zero( buf, 32 );
		UInt bytesRead = stream->Read( &buf, 10 );
		Assert( bytesRead == 10 );
		for ( int i = 0; i < sizeof(bytes); ++i )
		{
			Assert( buf[i] == bytes[i] );
		}

		// Writing.
		UInt lenOld = stream->GetLength();
		Byte extraBytes[] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a };
		stream->Write( extraBytes, (UInt)sizeof(extraBytes) );
		UInt lenNew = stream->GetLength();
		Assert( (lenNew-lenOld) == sizeof(extraBytes) );

		// Setting length.
		stream->SetLength( lenOld+1 );
		Assert( stream->GetLength() == lenOld+1 );

		// Closing.
		stream->Close();
	}
} _tst;