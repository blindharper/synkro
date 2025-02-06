using namespace synkro::audio;

#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
#include <audio/Ds8/Ds8AudioSystemFactory.h>
static Ds8AudioSystemFactory _factDs8AudioSystem;
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS

static synkro::core::IFactory* _factories[] =
{
	//--------------------------------------------------------------------------
	// Audio systems.
	//--------------------------------------------------------------------------
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	&_factDs8AudioSystem,
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
};
