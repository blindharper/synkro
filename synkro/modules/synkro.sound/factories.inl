using namespace synkro::sound;

#include <sound/SoundCodec/Mp3SoundCodecFactory.h>
static Mp3SoundCodecFactory _factMp3SoundCodec;

#include <sound/SoundCodec/WavSoundCodecFactory.h>
static WavSoundCodecFactory _factWavSoundCodec;

static synkro::core::IFactory* _factories[] =
{
	//--------------------------------------------------------------------------
	// Sound codecs.
	//--------------------------------------------------------------------------
	&_factMp3SoundCodec,
	&_factWavSoundCodec,
};
