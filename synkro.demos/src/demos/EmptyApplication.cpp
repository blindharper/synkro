#include "../Demo.h"


class EmptyApplication :
	public Demo
{
public:
	EmptyApplication() :
		Demo( L"Empty Application" )
	{
	}

	void Configure( IConfiguration* config ) override
	{
		// TODO: Do custom configuration.
	}

	DebugMode GetDebugMode() const override
	{
		// TODO: Choose which debug geometry to display.
		return DebugMode::None;
	}

	Bool IsLit() const override
	{
		// TODO: Return true for lit scenes.
		return false;
	}

	void InitScene() override
	{
		// TODO: Create scene objects.
	}

	void InitView() override
	{
		// TODO: Setup cameras and viewports.
	}

	void InitUi() override
	{
		// TODO: Create UI widgets.
	}

	// UiListener methods.
	Bool OnUiClick( IWidget* sender ) override
	{
		if ( Demo::OnUiClick(sender) )
			return true;

		// TODO: Handle button clicks.

		return false;
	}

private:
	// TODO: Define private members.
	// PtrTriangleMesh											_mesh;
};

SYNKRO_DEMO_BEGIN
	EmptyApplication demo;
	demo.Run();
SYNKRO_DEMO_END
