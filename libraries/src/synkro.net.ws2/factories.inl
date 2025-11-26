using namespace synkro::net;

#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
#include <net/Ws2/Ws2NetworkSystemFactory.h>
static Ws2NetworkSystemFactory _factWs2NetworkSystem;
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS

static synkro::core::IFactory* _factories[] =
{
	//--------------------------------------------------------------------------
	// Network systems.
	//--------------------------------------------------------------------------
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	&_factWs2NetworkSystem,
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
};
