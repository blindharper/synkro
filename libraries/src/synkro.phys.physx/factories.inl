using namespace synkro::phys;

#include <phys/Physx/PhysxPhysicsSystemFactory.h>

static PhysxPhysicsSystemFactory _factPhysxPhysicsSystem;

static synkro::core::IFactory* _factories[] =
{
	//--------------------------------------------------------------------------
	// Physics systems.
	//--------------------------------------------------------------------------
	&_factPhysxPhysicsSystem,
};
