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
// Purpose: Generic triangle set implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_TRIANGLESETIMPL_
#define _SYNKRO_SCENE_TRIANGLESETIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <gfx/IGraphicsSystemEx.h>
#include <gfx/IGraphicsDeviceEx.h>
#include <gfx/ISceneRenderQueue.h>
#include <gfx/ISceneRenderObject.h>
#include <gfx/IProgram.h>
#include <gfx/IProgramStage.h>
#include <gfx/IResourceSet.h>
#include <gfx/ITypedBuffer.h>
#include <gfx/IParameterSet.h>
#include <gfx/IVector2Stream.h>
#include <gfx/IVector3Stream.h>
#include <gfx/IVector4Stream.h>
#include <gfx/IMatrix4x4Stream.h>
#include <gfx/IShortStream.h>
#include <gfx/ILongStream.h>
#include <gfx/IPrimitiveEx.h>
#include <gfx/DataStream.h>
#include <gfx/DataStreamWriter.h>
#include <img/Color.h>
#include <lang/Range.h>
#include <lang/Vector.h>


namespace synkro
{


namespace scene
{


// Generic triangle set implementation.
template <class T>
class TriangleSetImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	TriangleSetImpl( gfx::ISceneRenderObject* object, UInt start, UInt count );
	virtual ~TriangleSetImpl();

	// IPrimitive methods.
	virtual	IPrimitiveAnimationController*					CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );
	virtual	void											Show( Bool show );
	virtual void											SetElementRange( const lang::Range& range );
	virtual void											SetInstanceRange( const lang::Range& range );
	virtual	void											SetTransform( const math::Matrix4x4& transform );
	virtual	void											SetOwnerTransform( const math::Matrix4x4& transform );
	virtual	void											SetInstanceTransform( UInt index, const math::Matrix4x4& transform );
	virtual	void											SetInstanceColor( UInt index, const img::Color& color );
	virtual void											Resize( UInt vertexCount, UInt indexCount );
	virtual Bool											IsVisible() const;
	virtual void											GetElementRange( lang::Range& range ) const;
	virtual void											GetInstanceRange( lang::Range& range ) const;
	virtual UInt											GetVertexCount() const;
	virtual UInt											GetIndexCount() const;
	virtual UInt											GetElementCount() const;
	virtual	void											GetTransform( math::Matrix4x4& transform ) const;
	virtual void											GetCenter( math::Vector3& center ) const;
	virtual Float											GetBoundSphere() const;
	virtual IPointSet*										AsPointSet() const;
	virtual ILineSet*										AsLineSet() const;
	virtual ITriangleSet*									AsTriangleSet() const;

	// ITriangleSet methods.
	virtual Bool											BeginSetBoneWeights();
	virtual void											EndSetBoneWeights();
	virtual void											SetPositions( const math::Vector3* positions, UInt start, UInt count );
	virtual void											SetNormals( const math::Vector3* normals, UInt start, UInt count );
	virtual void											SetColors( const img::Color* colors, UInt start, UInt count );
	virtual void											SetTextureCoordinates( const math::Vector2* coords, UInt start, UInt count );
	virtual void											SetIndices( const UInt* indices, UInt start, UInt count );
	virtual void											SetBoneWeights( UInt index, const Byte* bones, const Float* weights, UInt count );
	virtual void											SetBoneTransforms( const math::Matrix4x4* transforms, UInt count );
	virtual Bool											GetPositions( math::Vector3* positions, UInt start, UInt count ) const;
	virtual Bool											GetNormals( math::Vector3* normals, UInt start, UInt count ) const;
	virtual Bool											GetColors( img::Color* colors, UInt start, UInt count ) const;
	virtual Bool											GetTextureCoordinates( math::Vector2* coords, UInt start, UInt count ) const;
	virtual Bool											GetIndices( UInt* indices, UInt start, UInt count ) const;
	virtual gfx::ISceneRenderObject*						GetRenderObject() const;

protected:
	P(gfx::ISceneRenderObject)								_object;
	gfx::ProgramParam*										_paramTransform;
	math::Matrix4x4											_transform;
	math::Vector3											_center;
	Float													_boundSphere;
	lang::Vector<math::Vector3>								_positions;
	lang::Vector<UInt>										_indices;
	P(gfx::ILongStream)										_boneIndices;
	P(gfx::IVector4Stream)									_boneWeights;
	gfx::ProgramParam*										_paramBoneTransforms;
	Bool													_base;
};


#include "TriangleSetImpl.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_TRIANGLESETIMPL_
