//==============================================================================
// This file is a part of the Synkro Framework.
// 
// Copyright (c) Nobody. No rights reserved ;-7
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is allowed without any permission from the Synkro Project.
// Website: https://synkro.pro Email: mailto:blindharper70@gmail.com
//
// Purpose: Scene displayed in the configuration editor.
//==============================================================================
#ifndef _SYNKRO_CORE_SIERPINSKICONFIGURATIONSCENE_
#define _SYNKRO_CORE_SIERPINSKICONFIGURATIONSCENE_


#include "config.h"
#include "ConfigurationScene.h"
#include <lang/Vector.h>
#include <mat/IOpaqueMaterial.h>
#include <scene/ITriangleMeshBatch.h>


namespace synkro
{


namespace core
{


// Configuration scene.
class SierpinskiConfigurationScene :
	public ConfigurationScene
{
public:
	// Constructor.
	SierpinskiConfigurationScene( ISynkro* synkro );

private:
	enum
	{
		CAPACITY = 5*5
	};

	P(scene::INode)											_center;
	P(scene::ITriangleMeshBatch)							_pyramid;
	lang::Vector<P(scene::ITriangleMesh)>					_pyramids;
	P(mat::IOpaqueMaterial)									_material;

	void													Build( UInt steps );
	void													Split( UInt step, Float size, Float x, Float y, Float z, const img::Color& color );
	mat::IOpaqueMaterial*									CreateMaterial( const img::Color& color );
};


} // core


} // synkro


#endif // _SYNKRO_CORE_SIERPINSKICONFIGURATIONSCENE_
