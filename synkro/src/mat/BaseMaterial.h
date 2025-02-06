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
// Purpose: Defines base material.
//==============================================================================
#ifndef _SYNKRO_MAT_BASEMATERIAL_
#define _SYNKRO_MAT_BASEMATERIAL_


#include "config.h"
#include <scene/ITriangleMeshBatch.h>


namespace synkro
{


namespace mat
{


// Base material.
class BaseMaterial
{
public:
	virtual IVisualMaterial*								CreateInstance( scene::ITriangleMeshBatch* batch, UInt index ) = 0;
	virtual void											Assign( scene::ITriangleMesh* mesh, gfx::ISceneRenderObject* object, UInt index ) = 0;
	virtual void											SetIndex( UInt index ) = 0;
	virtual void											SetParam( const lang::String& name, const lang::String& value ) = 0;
	virtual void											OnDiffuseMapSet() = 0;
	virtual void											OnOpacityMapSet() = 0;
};


// Casts object to BaseMaterial.
#define AsBaseMaterial( OBJ ) dynamic_cast<BaseMaterial*>( OBJ )


} // mat


} // synkro


#endif // _SYNKRO_MAT_BASEMATERIAL_
