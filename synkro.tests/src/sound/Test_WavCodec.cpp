#include "testcommon.h"
#include <sound/WavCodec.h>
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

class TestWavCodec :
	public tst::Test
{
public:
	TestWavCodec() : tst::Test( "TestWavCodec", 1004 ) {}

	void Run()
	{
		try
		{
			/*P(ISoundCodec) codec = new WavCodec();

			// Read sound from file.
			P(io::IStream) is = new FileStream( "../data/sound/test.wav" );
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
