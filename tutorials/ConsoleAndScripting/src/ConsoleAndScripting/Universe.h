#ifndef __UNIVERSE__
#define __UNIVERSE__


#include "World.h"


class Universe
{
public:
	Universe( core::ISynkro* synkro, script::IScriptMachine* machine, const gfx::DisplayMode& displayMode );
	~Universe();

	World*													CreateWorld( const lang::String& name );
	void													ActivateWorld( const lang::String& name );
	void													GetDisplayMode( gfx::DisplayMode& displayMode ) const;
	script::IScriptObject*									GetObject() const;

private:
	enum
	{
		MAX_WORLD_COUNT = 4,
	};

	PtrSynkro												_synkro;
	PtrScriptMachine										_machine;
	PtrScriptObject											_object;
	gfx::DisplayMode										_displayMode;
	World*													_worlds[MAX_WORLD_COUNT];
	UInt													_worldCount;

	World*													GetWorld( const lang::String& name );
};


#endif // __UNIVERSE__