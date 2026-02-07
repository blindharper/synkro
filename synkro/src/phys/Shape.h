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
// Purpose: Wrapper collision shape.
//=============================================================================
#ifndef _SYNKRO_PHYS_SHAPE_
#define _SYNKRO_PHYS_SHAPE_


#include "config.h"
#include <core/ObjectImpl.h>
#include <phys/IShape.h>


namespace synkro
{


namespace phys
{


// Wrapper collision shape.
class Shape :
	public core::ObjectImpl<IShape>
{
public:
	// Constructor.
	Shape( IShape* shape );

	// IShape methods.
	void													SetContactOffset( Float offset );
	void													SetRestOffset( Float offset );
	void													SetLocalTransform( const math::Matrix4x4& transform );
	Float													GetContactOffset() const;
	Float													GetRestOffset() const;
	void													GetLocalTransform( math::Matrix4x4& transform ) const;
	void													GetTransform( math::Matrix4x4& transform ) const;

private:
	friend class PhysicsEnvironment;

	P(IShape)												_shape;
};


} // phys


} // synkro


#endif // _SYNKRO_PHYS_SHAPE_
