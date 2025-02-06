#include "config.h"
#include "Test.h"
#include <img/DdsCodec.h>
#include <img/ImageManager.h>
#include <gfx/IGraphicsDevice.h>
#include <gfx/IGraphicsSystemEx.h>
#include <io/FileStream.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::img;
using namespace synkro::io;
using namespace synkro;

//------------------------------------------------------------------------------

class TestDdsCodec :
	public Test
{
public:
	TestDdsCodec() : Test( "TestDdsCodec", 903 ) {}

	void Run()
	{
		try
		{
			/*P(IImageManager) imgMgr = new ImageManager( null );
			P(IImageCodec) codec = new DdsCodec( imgMgr );

			// Read image from file.
			P(IStream) is = new FileStream( "../data/img/test.dds" );
			is->Open( OpenMode::Read );
			P(IImage) image = codec->Load( is );
			is->Close();
			Assert( image->GetWidth() == 64 );
			Assert( image->GetHeight() == 32 );
			Assert( image->GetFormat() == PixelFormat::DXT3 );
			Assert( image->GetData() != null );*/
		}
		catch ( Exception& ex )
		{
			char buf[260];
			ex.Message().GetBytes( buf, 260 );
			FatalError( buf );
		}
	}

} _tst;
