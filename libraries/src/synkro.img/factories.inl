using namespace synkro::img;

#include <img/ImageCodec/BmpImageCodecFactory.h>
#include <img/ImageCodec/JpgImageCodecFactory.h>
#include <img/ImageCodec/PngImageCodecFactory.h>
#include <img/ImageCodec/TgaImageCodecFactory.h>

static BmpImageCodecFactory _factBmpImageCodec;
static JpgImageCodecFactory _factJpgImageCodec;
static PngImageCodecFactory _factPngImageCodec;
static TgaImageCodecFactory _factTgaImageCodec;

#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
#include <img/ImageCodec/DdsImageCodecFactory.h>
static DdsImageCodecFactory _factDdsImageCodec;
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS

static synkro::core::IFactory* _factories[] =
{
	//--------------------------------------------------------------------------
	// Image codecs.
	//--------------------------------------------------------------------------
	&_factBmpImageCodec,
	&_factJpgImageCodec,
	&_factPngImageCodec,
	&_factTgaImageCodec,
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
 	&_factDdsImageCodec,
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
};
