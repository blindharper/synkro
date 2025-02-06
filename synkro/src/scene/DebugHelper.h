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
// Purpose: Debug geometry visualizer.
//==============================================================================
#ifndef _SYNKRO_SCENE_DEBUGHELPER_
#define _SYNKRO_SCENE_DEBUGHELPER_


#include "config.h"
#include <lang/Ptr.h>
#include <img/Color.h>
#include <math/Vector3.h>
#include <math/Matrix4x4.h>
#include <gfx/ILineRenderObject.h>
#include <gfx/PrimitiveType.h>


namespace synkro
{


namespace scene
{


// Debug geometry visualizer.
class DebugHelper
{
public:
	// Constructor.
	DebugHelper();

	// DebugHelper methods.
	void													Create( gfx::IGraphicsSystemEx* graphicsSystem, IScene* scene, UInt vertexCount, UInt indexCount, const img::Color& color );
	void													CreateStrip( gfx::IGraphicsSystemEx* graphicsSystem, IScene* scene, UInt vertexCount, const img::Color& color );
	void													Resize( UInt vertexCount, UInt indexCount );
	void													SetVisibleVertexCount( UInt count );
	void													SetVertices( const math::Vector3* data, UInt count );
	void													SetIndices( const UShort* data, UInt count );
	void													SetTransform( const math::Matrix4x4& transform );
	void													SetColor( const img::Color& color );
	void													Show( Bool show );
	UInt													GetVertexCount() const;
	Bool													IsCreated() const;

private:
	P(gfx::ILineRenderObject)								_helper;
	gfx::ProgramParam*										_paramTransform;
	gfx::ProgramParam*										_paramColor;

	void													Create( const gfx::PrimitiveType& type, gfx::IGraphicsSystemEx* graphicsSystem, IScene* scene, UInt vertexCount, UInt indexCount, const img::Color& color );
};


#include "DebugHelper.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_DEBUGHELPER_
