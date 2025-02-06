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
// Purpose: Defines mesh builder types.
//==============================================================================
#include "config.h"
#include <scene/MeshBuilder.h>
#include <internal/Enum.h>


namespace synkro
{


namespace scene
{


SYNKRO_DEFINE_CONST( MeshBuilder, Custom,		0 )
SYNKRO_DEFINE_CONST( MeshBuilder, Box,			1 )
SYNKRO_DEFINE_CONST( MeshBuilder, Cone,			2 )
SYNKRO_DEFINE_CONST( MeshBuilder, Cylinder,		3 )
SYNKRO_DEFINE_CONST( MeshBuilder, Ellipsoid,	4 )
SYNKRO_DEFINE_CONST( MeshBuilder, Plane,		5 )
SYNKRO_DEFINE_CONST( MeshBuilder, Pyramid,		6 )
SYNKRO_DEFINE_CONST( MeshBuilder, Torus,		7 )


struct TypeDesc
{
	MeshBuilder	type;
	const Char*	name;
};

static TypeDesc _desc[] = 
{
	{ MeshBuilder::Custom,		L"Custom" },
	{ MeshBuilder::Box,			L"Box" },
	{ MeshBuilder::Cone,		L"Cone" },
	{ MeshBuilder::Cylinder,	L"Cylinder" },
	{ MeshBuilder::Ellipsoid,	L"Ellipsoid" },
	{ MeshBuilder::Plane,		L"Plane" },
	{ MeshBuilder::Pyramid,		L"Pyramid" },
	{ MeshBuilder::Torus,		L"Torus" },
};
static UInt _count = SizeOf( _desc );

lang::String MeshBuilder::ToString() const
{
	ENUM_TO_STRING()
}


} // scene


} // synkro
