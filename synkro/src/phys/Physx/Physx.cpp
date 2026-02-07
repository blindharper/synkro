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
// Purpose: PhysX API.
//==============================================================================
#include "config.h"
#include "Physx.h"


//------------------------------------------------------------------------------

using namespace synkro::math;
using namespace physx;

//------------------------------------------------------------------------------


namespace synkro
{


namespace phys
{


void Physx::Convert( const PxTransform& trans, Matrix4x4& transform )
{
	Matrix4x4 matPosition; matPosition.SetTranslation( Vector3(trans.p.x, trans.p.y, trans.p.z) );
	Matrix4x4 matOrientation; matOrientation.SetOrientation( Quaternion(trans.q.x, trans.q.y, trans.q.z, trans.q.w) );
	transform = matPosition * matOrientation;
}

PxTransform Physx::Convert( const Matrix4x4& trans )
{
	return PxTransform( Convert(trans.Translation()), Convert(trans.Orientation()) );
}

PxVec3 Physx::Convert( const Vector3& vec )
{
	return PxVec3( vec.x, vec.y, vec.z );
}

PxQuat Physx::Convert( const Quaternion& quat )
{
	return PxQuat( quat.x, quat.y, quat.z, quat.w );
}

PxForceMode::Enum Physx::Convert( const ForceMode& mode )
{
	static PxForceMode::Enum consts[] =
	{
		PxForceMode::Enum::eFORCE,
		PxForceMode::Enum::eFORCE,
		PxForceMode::Enum::eIMPULSE,
		PxForceMode::Enum::eVELOCITY_CHANGE,
		PxForceMode::Enum::eACCELERATION,
	};
	return consts[mode];
}


} // physx


} // synkro
