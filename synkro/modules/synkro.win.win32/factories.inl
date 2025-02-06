using namespace synkro::win;

#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
#include <win/Win32/Win32WindowSystemFactory.h>
static Win32WindowSystemFactory _factWin32WindowSystem;
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS

static synkro::core::IFactory* _factories[] =
{
	//--------------------------------------------------------------------------
	// Window systems.
	//--------------------------------------------------------------------------
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	&_factWin32WindowSystem,
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
};
