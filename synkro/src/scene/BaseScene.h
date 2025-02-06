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
// Purpose: Defines base scene.
//==============================================================================
#ifndef _SYNKRO_SCENE_BASESCENE_
#define _SYNKRO_SCENE_BASESCENE_


#include "config.h"
#include <lang/String.h>
#include <lang/Vector.h>
#include <math/Vector4.h>
#include <math/Matrix4x4.h>


namespace synkro
{


namespace scene
{


// Base scene.
class BaseScene
{
public:
	virtual void											Update() = 0;
	virtual void											IncrementCameraCount() = 0;
	virtual void											DecrementCameraCount() = 0;
	virtual lang::String									GetDummyName( const lang::String& name ) = 0;
	virtual lang::String									GetCameraName( const lang::String& name ) = 0;
	virtual lang::String									GetCurveName( const lang::String& name ) = 0;
	virtual lang::String									GetLightName( const lang::String& name ) = 0;
	virtual lang::String									GetSoundName( const lang::String& name ) = 0;
	virtual lang::String									GetLineMeshName( const lang::String& name ) = 0;
	virtual lang::String									GetPointMeshName( const lang::String& name ) = 0;
	virtual lang::String									GetTriangleMeshName( const lang::String& name ) = 0;
	virtual gfx::IParameterSet*								GetVertexParams() const = 0;
	virtual gfx::IResourceSet*								GetVertexResources() const = 0;
	virtual gfx::IParameterSet*								GetFragmentParams() const = 0;
};


// Casts object to BaseScene.
#define AsBaseScene( OBJ ) dynamic_cast<BaseScene*>( OBJ )


} // scene


} // synkro


#endif // _SYNKRO_SCENE_BASESCENE_
