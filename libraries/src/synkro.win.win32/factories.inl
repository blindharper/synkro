using namespace synkro::win;

#include <win/Win32/Win32WindowSystemFactory.h>

static Win32WindowSystemFactory _factWin32WindowSystem;

static synkro::core::IFactory* _factories[] =
{
	//--------------------------------------------------------------------------
	// Window systems.
	//--------------------------------------------------------------------------
	&_factWin32WindowSystem,
};
