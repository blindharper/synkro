using namespace synkro::gfx;

#include <gfx/Dx11/Dx11GraphicsSystemFactory.h>

static Dx11GraphicsSystemFactory _factDx11GraphicsSystem;

static synkro::core::IFactory* _factories[] =
{
	//--------------------------------------------------------------------------
	// Graphics systems.
	//--------------------------------------------------------------------------
	&_factDx11GraphicsSystem,
};
