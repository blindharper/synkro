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
#ifndef _SYNKRO_CORE_RUBIKCUBECONFIGURATIONSCENE_
#define _SYNKRO_CORE_RUBIKCUBECONFIGURATIONSCENE_


#include "config.h"
#include "ConfigurationScene.h"
#include <lang/Map.h>
#include <lang/Vector.h>
#include <lang/Random.h>
#include <scene/ITriangleMesh.h>
#include <mat/IOpaqueMaterial.h>
#include <mat/IMultiMaterial.h>
#include <core/TimerListener.h>


namespace synkro
{


namespace core
{


// Configuration scene.
class RubikCubeConfigurationScene :
	public ConfigurationScene,
	public TimerListener
{
public:
	// Constructor.
	RubikCubeConfigurationScene( ISynkro* synkro );

	// TimerListener methods.
	void													OnTimerTick( UInt timer );

private:
	enum
	{
		SIDE_LENGTH = 3,
		COUNT = SIDE_LENGTH * SIDE_LENGTH * SIDE_LENGTH,
	};

	enum Face
	{		
		FACE_RIGHT = 0,
		FACE_LEFT,
		FACE_TOP,
		FACE_BOTTOM,
		FACE_BACK,
		FACE_FRONT,
		FACE_NONE,
	};

	typedef lang::MapPair<UInt, mat::IMultiMaterial*>		OwnerEntry;

	P(scene::INode)											_center;
	lang::Vector<P(scene::ITriangleMesh)>					_cubes;
	lang::Vector<P(mat::IMultiMaterial)>					_materials;
	lang::Vector<P(mat::IOpaqueMaterial)>					_coloredMaterials;
	lang::Map<UInt, mat::IMultiMaterial*>					_owners;
	P(mat::IOpaqueMaterial)									_blackMaterial;
	lang::Random											_random;

	Bool													HasColor( mat::IMultiMaterial* material, const img::Color& color );
	mat::IOpaqueMaterial*									CreateMaterial( mat::IMultiMaterial* owner, UInt face );
	mat::IMultiMaterial*									CreateMaterial( UInt right, UInt left, UInt top, UInt bottom, UInt back, UInt front );
	void													CreateMaterials();
};


} // core


} // synkro


#endif // _SYNKRO_CORE_RUBIKCUBECONFIGURATIONSCENE_
