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
// Purpose: Gizmo helper.
//==============================================================================
#ifndef _SYNKRO_SCENE_GIZMO_
#define _SYNKRO_SCENE_GIZMO_


#include "config.h"
#include <lang/Ptr.h>
#include <math/Vector3.h>
#include <math/Vector4.h>
#include <math/Matrix4x4.h>
#include <gfx/ILineRenderObject.h>


namespace synkro
{


namespace scene
{


// Gizmo helper.
class Gizmo
{
public:
	// Constructor.
	Gizmo();

	// Gizmo methods.
	void													Create( gfx::IGraphicsSystemEx* graphicsSystem, IScene* scene );
	void													SetSize( Float size );
	void													SetTransform( const math::Matrix4x4& transform );
	void													Show( Bool show );
	Bool													IsCreated() const;

private:
	P(gfx::ILineRenderObject)								_gizmo;
	gfx::ProgramParam*										_paramTransform;

	void													SetVertices( const math::Vector3* data, UInt count );
	void													SetColors( const math::Vector4* data, UInt count );
};


#include "Gizmo.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_GIZMO_
