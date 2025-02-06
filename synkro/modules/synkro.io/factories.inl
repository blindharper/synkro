using namespace synkro::io;

#include <io/ZipDirectoryFactory.h>
static ZipDirectoryFactory _factZipDirectory;

#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
#include <io/Win32/Win32StreamSystemFactory.h>
static Win32StreamSystemFactory _factWin32StreamSystem;
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS

static synkro::core::IFactory* _factories[] =
{
	//--------------------------------------------------------------------------
	// Stream directories.
	//--------------------------------------------------------------------------
	&_factZipDirectory,

	//--------------------------------------------------------------------------
	// Stream systems.
	//--------------------------------------------------------------------------
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	&_factWin32StreamSystem,
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
};
