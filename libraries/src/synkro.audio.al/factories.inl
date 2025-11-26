using namespace synkro::audio;

#include <audio/Al/AlAudioSystemFactory.h>
static AlAudioSystemFactory _factAlAudioSystem;

static synkro::core::IFactory* _factories[] =
{
	//--------------------------------------------------------------------------
	// Audio systems.
	//--------------------------------------------------------------------------
	&_factAlAudioSystem,
};
