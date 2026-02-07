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
// Purpose: PhysX collision shape implementation.
//=============================================================================
#ifndef _SYNKRO_PHYS_PHYSXSHAPEIMPL_
#define _SYNKRO_PHYS_PHYSXSHAPEIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <physx/include/PxShape.h>
#include <physx/include/PxPhysics.h>
#include <phys/IPhysicsMaterial.h>
#include "PhysxBaseMaterial.h"
#include "Physx.h"


namespace synkro
{


namespace phys
{


// PhysX collision shape implementation.
template <class T>
class PhysxShapeImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	PhysxShapeImpl( physx::PxPhysics* physics, physx::PxGeometry& geometry, IPhysicsMaterial* material );
	virtual ~PhysxShapeImpl();

	// IShape methods.
	virtual void											SetContactOffset( Float offset );
	virtual void											SetRestOffset( Float offset );
	virtual void											SetLocalTransform( const math::Matrix4x4& transform );
	virtual Float											GetContactOffset() const;
	virtual Float											GetRestOffset() const;
	virtual void											GetLocalTransform( math::Matrix4x4& transform ) const;
	virtual void											GetTransform( math::Matrix4x4& transform ) const;

protected:
	physx::PxShape*											_shape;
	math::Matrix4x4											_transform;
};


#include "PhysxShapeImpl.inl"


} // phys


} // synkro


#endif // _SYNKRO_PHYS_PHYSXSHAPEIMPL_
