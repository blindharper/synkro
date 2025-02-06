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
// Purpose: Implements triangle set.
//==============================================================================
#ifndef _SYNKRO_SCENE_TRIANGLESET_
#define _SYNKRO_SCENE_TRIANGLESET_


#include "config.h"
#include <core/ObjectImpl.h>
#include <core/IContext.h>
#include <scene/ITriangleSet.h>
#include <scene/IPrimitiveAnimationController.h>
#include <scene/DebugMode.h>
#include <gfx/ILineRenderObject.h>
#include <gfx/IParameterSet.h>
#include <gfx/IPrimitiveEx.h>
#include <lang/Vector.h>


namespace synkro
{


namespace scene
{


// Triangle set implementation.
class TriangleSet :
	public core::ObjectImpl<ITriangleSet>
{
public:
	// Constructor.
	TriangleSet( ITriangleSet* set, core::IContext* context, const DebugMode& debugMode, UInt start, UInt count );

	// IPrimitive methods.
	IPrimitiveAnimationController*							CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );
	void													Show( Bool show );
	void													SetElementRange( const lang::Range& range );
	void													SetInstanceRange( const lang::Range& range );
	void													SetTransform( const math::Matrix4x4& transform );
	void													SetOwnerTransform( const math::Matrix4x4& transform );
	void													SetInstanceTransform( UInt index, const math::Matrix4x4& transform );
	void													SetInstanceColor( UInt index, const img::Color& color );
	void													Resize( UInt vertexCount, UInt indexCount );
	Bool													IsVisible() const;
	void													GetElementRange( lang::Range& range ) const;
	void													GetInstanceRange( lang::Range& range ) const;
	UInt													GetVertexCount() const;
	UInt													GetIndexCount() const;
	UInt													GetElementCount() const;
	void													GetTransform( math::Matrix4x4& transform ) const;
	void													GetCenter( math::Vector3& center ) const;
	Float													GetBoundSphere() const;
	IPointSet*												AsPointSet() const;
	ILineSet*												AsLineSet() const;
	ITriangleSet*											AsTriangleSet() const;

	// ITriangleSet methods.
	Bool													BeginSetBoneWeights();
	void													EndSetBoneWeights();
	void													SetPositions( const math::Vector3* positions, UInt start, UInt count );
	void													SetNormals( const math::Vector3* normals, UInt start, UInt count );
	void													SetColors( const img::Color* colors, UInt start, UInt count );
	void													SetTextureCoordinates( const math::Vector2* coords, UInt start, UInt count );
	void													SetIndices( const UInt* indices, UInt start, UInt count );
	void													SetBoneWeights( UInt index, const Byte* bones, const Float* weights, UInt count );
	void													SetBoneTransforms( const math::Matrix4x4* transforms, UInt count );
	Bool													GetPositions( math::Vector3* positions, UInt start, UInt count ) const;
	Bool													GetNormals( math::Vector3* normals, UInt start, UInt count ) const;
	Bool													GetColors( img::Color* colors, UInt start, UInt count ) const;
	Bool													GetTextureCoordinates( math::Vector2* coords, UInt start, UInt count ) const;
	Bool													GetIndices( UInt* indices, UInt start, UInt count ) const;
	gfx::ISceneRenderObject*								GetRenderObject() const;

private:
	core::IContext*											_context;
	P(ITriangleSet)											_set;
	P(IPrimitiveAnimationController)						_ctrlAnimation;
	lang::Vector<math::Vector3>								_normals;
	P(gfx::ILineRenderObject)								_objectNormals;
	gfx::ProgramParam*										_paramNormalsTransform;
	Bool													_base;
};


#include "TriangleSet.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_TRIANGLESET_
