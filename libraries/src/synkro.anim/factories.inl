#include <anim/AnimationCodec/BinAnimationCodecFactory.h>
#include <anim/AnimationCodec/SqlAnimationCodecFactory.h>
#include <anim/AnimationCodec/XmlAnimationCodecFactory.h>
#include <anim/AnimationTrack/WaveFloatTrackFactory.h>
#include <anim/AnimationTrack/NoiseBoolTrackFactory.h>
#include <anim/AnimationTrack/NoiseColorTrackFactory.h>
#include <anim/AnimationTrack/NoiseColorGradientTrackFactory.h>
#include <anim/AnimationTrack/NoiseFloatTrackFactory.h>
#include <anim/AnimationTrack/NoiseQuaternionTrackFactory.h>
#include <anim/AnimationTrack/NoiseVector3TrackFactory.h>

using namespace synkro::anim;

static BinAnimationCodecFactory			_factBinAnimationCodec;
static SqlAnimationCodecFactory			_factSqlAnimationCodec;
static XmlAnimationCodecFactory			_factXmlAnimationCodec;

static WaveFloatTrackFactory			_factWaveFloatTrack;
static NoiseBoolTrackFactory			_factNoiseBoolTrack;
static NoiseColorTrackFactory			_factNoiseColorTrack;
static NoiseColorGradientTrackFactory	_factNoiseColorGradientTrack;
static NoiseFloatTrackFactory			_factNoiseFloatTrack;
static NoiseQuaternionTrackFactory		_factNoiseQuaternionTrack;
static NoiseVector3TrackFactory			_factNoiseVector3Track;

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
	&_factWaveFloatTrack,
	&_factNoiseBoolTrack,
	&_factNoiseColorTrack,
	&_factNoiseColorGradientTrack,
	&_factNoiseFloatTrack,
	&_factNoiseQuaternionTrack,
	&_factNoiseVector3Track,
};
