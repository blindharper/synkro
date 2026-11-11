using namespace synkro::gfx;

#include <gfx/Dx12/Dx12GraphicsSystemFactory.h>

static Dx12GraphicsSystemFactory _factDx12GraphicsSystem;

static synkro::core::IFactory* _factories[] =
{
	//--------------------------------------------------------------------------
	// Graphics systems.
	//--------------------------------------------------------------------------
	&_factDx12GraphicsSystem,
};
