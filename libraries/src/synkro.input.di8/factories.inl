using namespace synkro::input;

#include <input/Di8/Di8InputSystemFactory.h>

static Di8InputSystemFactory _factDi8InputSystem;

static synkro::core::IFactory* _factories[] =
{
	//--------------------------------------------------------------------------
	// Input systems.
	//--------------------------------------------------------------------------
	&_factDi8InputSystem,
};
