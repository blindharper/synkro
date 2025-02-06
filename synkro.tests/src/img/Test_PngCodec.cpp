#include "config.h"
#include "Test.h"
#include <img/ImageCodec/PngImageCodecFactory.h>
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

class TestPngCodec :
	public Test
{
public:
	TestPngCodec() : Test( "TestPngCodec", 907 ) {}

	void Run()
	{
		try
		{
			PngImageCodecFactory fact;
			P(ImageManager) imgMgr = new ImageManager( 1.0f, nullptr, nullptr );
			imgMgr->RegisterCodec( &fact );

			// Read image from file.
			P(IStream) is = new FileStream( "../../data/img/test.png" );
			PixelFormat format = PixelFormat::R8G8B8A8;
			P(IImage) image = imgMgr->LoadImage( is, format );
			Assert( image->GetWidth() == 91 );
			Assert( image->GetHeight() == 69 );
			Assert( image->GetFormat() == PixelFormat::R8G8B8A8 );

			// Write image to file.
			P(IStream) os = new FileStream( "../../data/img/test_copy.png" );
			image->Save( os, PixelFormat::R8G8B8A8 );

			// Read what we've written.
			is = new FileStream( "../../data/img/test_copy.png" );
			image = imgMgr->LoadImage( is, format );
			Assert( image->GetWidth() == 91 );
			Assert( image->GetHeight() == 69 );
			Assert( image->GetFormat() == PixelFormat::R8G8B8A8 );
		}
		catch ( Exception& ex )
		{
			char buf[260];
			ex.Message().GetBytes( buf, 260 );
			FatalError( buf );
		}
	}

} _tst;
