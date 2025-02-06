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
// Purpose: Implements line set.
//==============================================================================
#ifndef _SYNKRO_SCENE_LINESET_
#define _SYNKRO_SCENE_LINESET_


#include "config.h"
#include <core/IContext.h>
#include <core/ObjectImpl.h>
#include <scene/ILineSet.h>
#include <scene/ILineSetAnimationController.h>
#include <gfx/ILineRenderObject.h>
#include <gfx/IPrimitiveEx.h>
#include <gfx/IParameterSet.h>


namespace synkro
{


namespace scene
{


// Line set implementation.
class LineSet :
	public core::ObjectImpl<ILineSet>
{
public:
	// Constructor.
	LineSet( core::IContext* context, gfx::ILineRenderObject* object, UInt start, UInt count );

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

	// ILineSet methods.
	void													SetPositions( const math::Vector3* positions, UInt start, UInt count );
	void													SetPositions( const math::Vector4* positions, UInt start, UInt count );
	void													SetColors( const img::Color* colors, UInt start, UInt count );
	void													SetIndices( const UInt* indices, UInt start, UInt count );
	void													SetColor( const img::Color& color );

	// Other methods.
	ILineSet*												CreateSubset( UInt start, UInt count );

private:
	core::IContext*											_context;
	P(ILineSetAnimationController)							_ctrlAnimation;
	P(gfx::ILineRenderObject)								_object;
	gfx::ProgramParam*										_paramColor;
	gfx::ProgramParam*										_paramTransform;
	math::Matrix4x4											_transform;
	math::Vector3											_center;
	Float													_boundSphere;
};


#include "LineSet.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_LINESET_
