using namespace synkro::input;

#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
#include <input/Di8/Di8InputSystemFactory.h>
static Di8InputSystemFactory _factDi8InputSystem;
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS

static synkro::core::IFactory* _factories[] =
{
	//--------------------------------------------------------------------------
	// Input systems.
	//--------------------------------------------------------------------------
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	&_factDi8InputSystem,
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
};
