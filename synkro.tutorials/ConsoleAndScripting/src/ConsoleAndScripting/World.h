#ifndef __WORLD__
#define __WORLD__


#include "Tiny.h"


class Universe;


class World
{
public:
	World( Universe* universe, core::ISynkro* synkro, const lang::String& name, const img::Color& color );
	World();
	~World();

	void													Load( const char* script );
	Tiny*													CreateTiny( const char* name, Float x, Float y );
	Tiny*													GetTiny( const char* name ) const;
	lang::String											GetName() const;
	void													GetColor( img::Color& color ) const;
	scene::ICamera*											GetCamera() const;
	script::IScriptMachine*									GetMachine() const;
	script::IScriptObject*									GetObject() const;

private:
	enum
	{
		MAX_TINY_COUNT = 10,
	};
	Universe*												_universe;
	PtrSynkro												_synkro;
	PtrScriptMachine										_machine;
	PtrScriptObject											_object;
	PtrSceneEx												_scene;
	PtrCamera												_camera;
	lang::String											_name;
	img::Color												_color;
	PtrOpaqueMaterial										_materialFloor;
	PtrTriangleMesh											_floor;
	Tiny*													_tinys[MAX_TINY_COUNT];
	UInt													_tinyCount;

	img::IImage*											GetImage( const lang::String& name );
	io::IStream*											GetStream( const lang::String& name );
};


#endif // __WORLD__
