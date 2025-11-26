#include "testcommon.h"
#include <sound/Mp3Codec.h>
#include <sound/SoundCodecContext.h>
#include <io/FileStream.h>

//------------------------------------------------------------------------------

using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::sound;
using namespace synkro;

//------------------------------------------------------------------------------

class TestMp3Codec :
	public tst::Test
{
public:
	TestMp3Codec() : tst::Test( "TestMp3Codec", 1005 ) {}

	void Run()
	{
		try
		{
			/*P(ISoundCodec) codec = new Mp3Codec();

			// Read sound from file.
			P(io::IStream) is = new FileStream( "../data/sound/test.mp3" );
			SoundCodecContext context( is, false );
			SoundFormat format;
			UInnt length = codec->Load( &context, format );
			Assert( format == SoundFormat::Mono22kHz8bit );
			Assert( length == 2 );*/
		}
		catch ( Exception& ex )
		{
			char buf[260];
			ex.Message().GetBytes( buf, 260 );
			FatalError( buf );
		}
	}

} _tst;
