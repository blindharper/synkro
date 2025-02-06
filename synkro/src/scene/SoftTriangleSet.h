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
// Purpose: Implements software triangle set.
//==============================================================================
#ifndef _SYNKRO_SCENE_SOFTTRIANGLESET_
#define _SYNKRO_SCENE_SOFTTRIANGLESET_


#include "config.h"
#include <core/ObjectImpl.h>
#include <scene/ITriangleSet.h>
#include <lang/Vector.h>


namespace synkro
{


namespace scene
{


// Software triangle set implementation.
class SoftTriangleSet :
	public core::ObjectImpl<ITriangleSet>
{
public:
	// Constructor.
	SoftTriangleSet( SoftTriangleSet* base, UInt vertexCount, UInt indexCount, const lang::Range& range );

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
	void													GetInstanceTransform( UInt index, math::Matrix4x4& transform ) const;
	void													GetCenter( math::Vector3& center ) const;
	Float													GetBoundSphere() const;
	ILineSet*												AsLineSet() const;
	IPointSet*												AsPointSet() const;
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
	lang::Vector<math::Vector3>								_positions;
	lang::Vector<math::Vector3>								_normals;
	lang::Vector<math::Vector2>								_textureCoords;
	lang::Vector<img::Color>								_colors;
	lang::Vector<UInt>										_indices;
	SoftTriangleSet*										_base;
	lang::Range												_range;

	template <class T>
	void													SetData( lang::Vector<T>& stream, const T* data, UInt start, UInt count );
	template <class T>
	Bool													GetData( T* data, const lang::Vector<T>& stream, UInt start, UInt count ) const;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_SOFTTRIANGLESET_
