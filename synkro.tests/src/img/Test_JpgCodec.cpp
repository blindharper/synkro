#include "config.h"
#include "Test.h"
#include <img/ImageCodec/JpgImageCodecFactory.h>
#include <img/ImageManager.h>
#include <gfx/IGraphicsDevice.h>
#include <gfx/IGraphicsSystemEx.h>
#include <io/FileStream.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::io;
using namespace synkro;

//------------------------------------------------------------------------------

class TestJpgCodec :
	public Test
{
public:
	TestJpgCodec() : Test( "TestJpgCodec", 905 ) {}

	void Run()
	{
		try
		{
			JpgImageCodecFactory fact;
			P(ImageManager) imgMgr = new ImageManager( 1.0f, nullptr, nullptr );
			imgMgr->RegisterCodec( &fact );

			// Read image from file.
			P(io::IStream) is = new FileStream( "../../data/img/test.jpg" );
			PixelFormat format = PixelFormat::R8G8B8;
			P(IImage) image = imgMgr->LoadImage( is, format );
			Assert( image->GetWidth() == 91 );
			Assert( image->GetHeight() == 69 );
			Assert( image->GetFormat() == PixelFormat::R8G8B8 );

			// Write image to file.
			P(io::IStream) os = new FileStream( "../../data/img/test_copy.jpg" );
			image->Save( os, PixelFormat::R8G8B8 );

			// Read what we've written.
			is = new FileStream( "../../data/img/test_copy.jpg" );
			image = imgMgr->LoadImage( is, format );
			Assert( image->GetWidth() == 91 );
			Assert( image->GetHeight() == 69 );
			Assert( image->GetFormat() == PixelFormat::R8G8B8 );
		}
		catch ( Exception& ex )
		{
			char buf[260];
			ex.Message().GetBytes( buf, 260 );
			FatalError( buf );
		}
	}

} _tst;
