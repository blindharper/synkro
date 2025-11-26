#include <io/IStreamSystemFactory.h>
#include <io/IStreamDirectory.h>
#include <io/IStream.h>
#include <io/StreamSystemEx.h>


//------------------------------------------------------------------------------

using namespace synkro::mem;
using namespace synkro::core;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro;

//------------------------------------------------------------------------------


class StreamSystemTest
{
public:
	StreamSystemTest( const String& pathMain, IStreamSystemFactory* factStreamSys ) :
		_pathMain( pathMain ),
		_factStreamSys( factStreamSys )
	{
	}

	void Run()
	{
		P(IStreamSystemEx) ws = new StreamSystemEx( _factStreamSys->Create(nullptr), nullptr );
		String pathData = Path::MakeAbsolute( _pathMain, L"..\\..\\data" );
		P(IStreamDirectory) dirData = ws->MapDirectory( pathData, true );
		String pathIO = Path::MakeAbsolute( _pathMain, L"..\\..\\data\\io" );
		P(IStreamDirectory) dirIO = ws->MapDirectory( pathIO, false );

		UInt cntIO = dirIO->GetStreamCount();
		UInt cntIO2 = dirIO->GetDirectoryCount();

		P(IStream) stream = dirIO->GetStream( L"zip_dir_in.zip" );
		stream->Open( OpenMode::Read );
		UInt len = stream->GetLength();
		stream->Close();

		P(IStream) stream2 = dirData->GetStream( L"StdMemReport.txt" );
		stream2->Open( OpenMode::Read );
		UInt len2 = stream2->GetLength();
		stream2->Close();
	}

private:
	String					_pathMain;
	IStreamSystemFactory*	_factStreamSys;
};
