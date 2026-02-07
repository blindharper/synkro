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
// Purpose: Generic physical environment implementation.
//=============================================================================
#ifndef _SYNKRO_PHYS_PHYSICSENVIRONMENTIMPL_
#define _SYNKRO_PHYS_PHYSICSENVIRONMENTIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <math/Vector3.h>


namespace synkro
{


namespace phys
{


// Generic environment implementation.
template <class T>
class PhysicsEnvironmentImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	PhysicsEnvironmentImpl( const lang::String& name );
	virtual ~PhysicsEnvironmentImpl();

	// IPhysicsEnvironment methods.
	virtual void											SetGravity( const math::Vector3& gravity );
	virtual void											GetGravity( math::Vector3& gravity ) const;
	virtual lang::String									GetName() const;

protected:
	math::Vector3											_gravity;
	lang::String											_name;
};


#include "PhysicsEnvironmentImpl.inl"


} // phys


} // synkro


#endif // _SYNKRO_PHYS_PHYSICSENVIRONMENTIMPL_
