using namespace synkro::input;

#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
#include <input/Win32/Win32InputSystemFactory.h>
static Win32InputSystemFactory _factWin32InputSystem;
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS

static synkro::core::IFactory* _factories[] =
{
	//--------------------------------------------------------------------------
	// Input systems.
	//--------------------------------------------------------------------------
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	&_factWin32InputSystem,
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
};
