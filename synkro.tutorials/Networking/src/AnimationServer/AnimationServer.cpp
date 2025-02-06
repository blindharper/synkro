#include "App.h"


#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
int APIENTRY WinMain( HINSTANCE, HINSTANCE, LPSTR, int )
#endif // ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
{
	App app;
	app.Run();
	return 0;
}
