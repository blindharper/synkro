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
// Purpose: Defines blending operation.
//==============================================================================
#include "config.h"
#include <gfx/BlendOperation.h>
#include <internal/Enum.h>


namespace synkro
{


namespace gfx
{


SYNKRO_DEFINE_CONST( BlendOperation, Add,		0 )
SYNKRO_DEFINE_CONST( BlendOperation, Sub,		1 )
SYNKRO_DEFINE_CONST( BlendOperation, RevSub,	2 )
SYNKRO_DEFINE_CONST( BlendOperation, Min,		3 )
SYNKRO_DEFINE_CONST( BlendOperation, Max,		4 )


struct TypeDesc
{
	BlendOperation	type;
	const Char*		name;
};

static TypeDesc _desc[] = 
{
	{ BlendOperation::Add,		L"Add" },
	{ BlendOperation::Sub,		L"Sub" },
	{ BlendOperation::RevSub,	L"RevSub" },
	{ BlendOperation::Min,		L"Min" },
	{ BlendOperation::Max,		L"Max" },
};
static UInt _count = SizeOf( _desc );

BlendOperation::BlendOperation( const lang::String& op ) :
	Enum( 0 )
{
	SET_ENUM_VALUE( op )
}

lang::String BlendOperation::ToString() const
{
	ENUM_TO_STRING()
}


} // gfx


} // synkro
