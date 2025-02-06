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
// Purpose: Generic mesh implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_MESHIMPL_
#define _SYNKRO_SCENE_MESHIMPL_


#include "config.h"
#include "NodeImpl.h"
#include <lang/Vector.h>


namespace synkro
{


namespace scene
{


// Generic mesh implementation.
template <class T>
class MeshImpl :
	public NodeImpl<T>
{
public:
	// Constructor & destructor.
	MeshImpl( ISceneEx* scene, core::IContext* context, const lang::String& name, Bool visualize = false );
	virtual ~MeshImpl();

	// INode methods.
	IMesh*													AsMesh() const;

	// IMesh methods.
	virtual void											Show( Bool show );
	virtual UInt											GetSubsetCount() const;
	virtual lang::String									GetSubsetName( UInt index ) const;
	virtual IPrimitive*										GetSubset( UInt index ) const;
	virtual IPrimitive*										GetSubset( const lang::String& name ) const;
	virtual void											GetCenter( math::Vector3& center ) const;
	virtual Float											GetBoundSphere() const;
	virtual Bool											IsVisible() const;
	virtual IPointMesh*										AsPoint() const;
	virtual ILineMesh*										AsLine() const;
	virtual ITriangleMesh*									AsTriangle() const;

protected:
	struct SubsetDesc
	{
		SubsetDesc( IPrimitive* primitive, const math::Matrix4x4& transform, const lang::String& name ) :
			Primitive( primitive ),
			Name( name )
		{
			primitive->SetTransform( transform );
		}

		SubsetDesc( IPrimitive* primitive, IPrimitive* base, const lang::String& name ) :
			Primitive( primitive ),
			Name( name )
		{
			Matrix4x4 transform;
			base->GetTransform( transform );
			primitive->SetTransform( transform );
		}

		SubsetDesc()
		{
		}

		P(IPrimitive)		Primitive;
		lang::String		Name;
	};

	lang::Vector<SubsetDesc>								_subsets;
	SubsetDesc												_base;
	Bool													_visible;
};


#include "MeshImpl.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_MESHIMPL_
