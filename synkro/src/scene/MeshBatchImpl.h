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
// Purpose: Generic mesh batch implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_MESHBATCHIMPL_
#define _SYNKRO_SCENE_MESHBATCHIMPL_


#include "config.h"
#include "MeshImpl.h"
#include <lang/Range.h>


namespace synkro
{


namespace scene
{


// Generic mesh batch implementation.
template <class T, class I>
class MeshBatchImpl :
	public MeshImpl<T>
{
public:
	// Constructor & destructor.
	MeshBatchImpl( ISceneEx* scene, core::IContext* context, const lang::String& name, UInt capacity );
	virtual ~MeshBatchImpl();

	// INode methods.
	virtual INode*											GetParent() const;

	// I<*>MeshBatch methods.
	virtual void											SetRange( const lang::Range& range );
	virtual UInt											GetCapacity() const;
	virtual UInt											GetInstanceCount() const;
	virtual I*												GetInstance( UInt index ) const;
	virtual void											GetRange( lang::Range& range ) const;

protected:
	struct InstanceDesc
	{
		InstanceDesc( INode* parent, IMesh* mesh, const math::Matrix4x4& transform, const img::Color& color ) :
			Parent( parent ),
			Mesh( mesh ),
			Transform( transform ),
			Color( color )
		{
			mesh->SetParent( parent );
			mesh->SetTransform( transform );
		}

		InstanceDesc() :
			Parent( nullptr ),
			Mesh( nullptr )
		{
		}

		INode*				Parent;
		IMesh*				Mesh;
		math::Matrix4x4		Transform;
		img::Color			Color;
	};

	lang::Vector<InstanceDesc>								_instances;
	lang::Range												_range;
};


#include "MeshBatchImpl.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_MESHBATCHIMPL_
