#include <anim/AnimationCodec/BinAnimationCodecFactory.h>
#include <anim/AnimationCodec/SqlAnimationCodecFactory.h>
#include <anim/AnimationCodec/XmlAnimationCodecFactory.h>
#include <anim/AnimationTrack/NoiseFloatTrackFactory.h>
#include <anim/AnimationTrack/WaveFloatTrackFactory.h>

using namespace synkro::anim;

static BinAnimationCodecFactory		_factBinAnimationCodec;
static SqlAnimationCodecFactory		_factSqlAnimationCodec;
static XmlAnimationCodecFactory		_factXmlAnimationCodec;

static NoiseFloatTrackFactory		_factNoiseFloatTrack;
static WaveFloatTrackFactory		_factWaveFloatTrack;

static synkro::core::IFactory* _factories[] =
{
	//--------------------------------------------------------------------------
	// Animation Codecs.
	//--------------------------------------------------------------------------
	&_factBinAnimationCodec,
	&_factSqlAnimationCodec,
	&_factXmlAnimationCodec,

	//--------------------------------------------------------------------------
	// Animation tracks.
	//--------------------------------------------------------------------------
	&_factNoiseFloatTrack,
	&_factWaveFloatTrack,
};
