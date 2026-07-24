using namespace synkro::net;

#include <net/Ws2/Ws2NetworkSystemFactory.h>

static Ws2NetworkSystemFactory _factWs2NetworkSystem;

static synkro::core::IFactory* _factories[] =
{
	//--------------------------------------------------------------------------
	// Network systems.
	//--------------------------------------------------------------------------
	&_factWs2NetworkSystem,
};
