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
// Purpose: Default scene implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_DEFAULTSCENE_
#define _SYNKRO_SCENE_DEFAULTSCENE_


#include "config.h"
#include <core/ObjectImpl.h>
#include <scene/IScene.h>
#include <gfx/ISceneRenderQueue.h>
#include <lang/Vector.h>


namespace synkro
{


namespace scene
{


// Default scene implementation.
class DefaultScene :
	public core::ObjectImpl<IScene>
{
public:
	// Constructor.
	DefaultScene( gfx::ISceneRenderQueue* queue, Bool lit );

	// IScene methods.
	ITriangleMesh*											CreateTriangleMesh( INode* parent, const lang::String& name, mat::IVisualMaterial* material, ISkeleton* skeleton );
	ITriangleMeshBatch*										CreateTriangleMeshBatch( mat::IVisualMaterial* material, ISkeleton* skeleton, UInt capacity );
	ITriangleMesh*											PickMesh( const math::Vector3& origin, const math::Vector3& direction, Float* distance ) const;
	gfx::ISceneRenderQueue*									GetRenderQueue() const;
	Bool													IsLit() const;

	// Other methods.
	void													RemoveMesh( ITriangleMesh* mesh );

private:
	P(gfx::ISceneRenderQueue)								_queue;
	lang::Vector<ITriangleMesh*>							_meshes;
	Bool													_lit;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_DEFAULTSCENE_
