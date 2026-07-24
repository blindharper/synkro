using namespace synkro::io;

#include <io/ZipDirectoryFactory.h>
#include <io/Win32/Win32StreamSystemFactory.h>

static ZipDirectoryFactory _factZipDirectory;
static Win32StreamSystemFactory _factWin32StreamSystem;

static synkro::core::IFactory* _factories[] =
{
	//--------------------------------------------------------------------------
	// Stream directories.
	//--------------------------------------------------------------------------
	&_factZipDirectory,

	//--------------------------------------------------------------------------
	// Stream systems.
	//--------------------------------------------------------------------------
	&_factWin32StreamSystem,
};
