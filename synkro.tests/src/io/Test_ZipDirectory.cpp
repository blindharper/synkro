#include "config.h"
#include "Test.h"
#include <io/FileStream.h>
#include <io/ZipDirectory.h>
#include <internal/Zero.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::io;
using namespace synkro;

//------------------------------------------------------------------------------

class TestZipDirectory :
	public Test
{
public:
	TestZipDirectory() : Test( "TestZipDirectory", 604 ) {}

	void Run()
	{
		//----------------------------------------------------------------------
		// Reading
		//----------------------------------------------------------------------

		// Creation.
		IStream* stream = new FileStream( "../../data/io/zip_dir_in.zip" );
		P(IStreamDirectory) dir = new ZipDirectory( stream, false );

		// Top-level streams.
		Assert( dir->GetStreamCount() == 1 );
		Assert( dir->GetStream(0)->GetName() == L"manifest.xml" );
		Assert( dir->GetStream(0)->GetLength() == 2407 );

		// Top-level directories.
		Assert( dir->GetDirectoryCount() == 1 );

		// Locate arbitrary stream.
		P(IStreamDirectory) dir0 = dir->GetDirectory( L"OpenGL/filter" );
		P(IStream) stream0 = dir->GetStream( L"OpenGL/filter/emboss.ps" );
		P(IStream) stream1 = dir0->GetStream( L"emboss.ps" );
		Assert( stream0 == stream1 );

		//----------------------------------------------------------------------
		// Writing
		//----------------------------------------------------------------------

		// Creation.
		IStream* streamZip = new FileStream( "../../data/io/zip_dir_out.zip" );
		P(ZipDirectory) zipDir = new ZipDirectory( streamZip, true );
		
		// Opening.
		IStream* stream2 = zipDir->CreateStream( "stream2.txt" );
		stream2->Open( OpenMode::Write );
		Assert( stream2->GetMode() == OpenMode::Write );

		// Writing.
		const char* line1 = "one more line\r\n";
		UInt lenOld = stream2->GetLength();
		stream2->Write( line1, (UInt)strlen(line1) );
		stream2->Flush();

		// Opening.
		IStream* stream3 = zipDir->CreateStream( "dir2/stream3.txt" );
		stream3->Open( OpenMode::Write );
		Assert( stream3->GetMode() == OpenMode::Write );

		// Writing.
		line1 = "yet another line\r\n";
		lenOld = stream3->GetLength();
		stream3->Write( line1, (UInt)strlen(line1) );
		stream3->Flush();

		// Opening.
		IStream* stream4 = zipDir->CreateStream( "dir2/stream4.txt" );
		stream4->Open( OpenMode::Write );
		Assert( stream4->GetMode() == OpenMode::Write );

		// Writing.
		line1 = "yet another line\r\n";
		lenOld = stream4->GetLength();
		stream4->Write( line1, (UInt)strlen(line1) );
		stream4->Flush();
	}
} _tst;