using namespace synkro::ui;

#include <ui/Default/DefaultUiFactory.h>

static DefaultUiFactory _factDefaultUi;

static synkro::core::IFactory* _factories[] =
{
	//--------------------------------------------------------------------------
	// UIs.
	//--------------------------------------------------------------------------
	&_factDefaultUi,
};
