#ifndef __DIAL__
#define __DIAL__


#include <synkro.h>


//------------------------------------------------------------------------------

using namespace synkro;

//------------------------------------------------------------------------------


class Dial
{
public:
	// Constructor.
	Dial( core::ISynkro* synkro, scene::ISceneEx* scene, Float radius );

private:
	enum
	{
		TICK_COUNT = 12,
	};

	PtrSynkro												_synkro;

	PtrTriangleMesh											_face;
	PtrTriangleMesh											_border;
	PtrTriangleMeshBatch									_tick;
	PtrTriangleMesh											_ticks[TICK_COUNT];

	PtrTriangleMesh											_hourArrow;
	PtrTriangleMesh											_minuteArrow;
	PtrTriangleMesh											_secondArrow;

	PtrOpaqueMaterial										_materialFace;
	PtrOpaqueMaterial										_materialBorder;
	PtrOpaqueMaterial										_materialMetal;
	PtrOpaqueMaterial										_materialRed;

	mat::IOpaqueMaterial*									CreateMaterial( const img::Color& color );
	scene::ITriangleMesh*									CreateArrow( scene::ISceneEx* scene, const lang::String& name, mat::IOpaqueMaterial* material, const scene::MeshBuilder& type, const math::Vector4& param1, const lang::Size& param2, const math::Matrix4x4& transform );
};


#endif // __DIAL__
