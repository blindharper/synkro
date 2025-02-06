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
// Purpose: Defines stencil buffer operations.
//==============================================================================
#include "config.h"
#include <gfx/StencilOperation.h>
#include <internal/Enum.h>


namespace synkro
{


namespace gfx
{


SYNKRO_DEFINE_CONST( StencilOperation, None,			0 )
SYNKRO_DEFINE_CONST( StencilOperation, Zero,			1 )
SYNKRO_DEFINE_CONST( StencilOperation, Replace,			2 )
SYNKRO_DEFINE_CONST( StencilOperation, Invert,			3 )
SYNKRO_DEFINE_CONST( StencilOperation, IncrementClamp,	4 )
SYNKRO_DEFINE_CONST( StencilOperation, DecrementClamp,	5 )
SYNKRO_DEFINE_CONST( StencilOperation, IncrementWrap,	6 )
SYNKRO_DEFINE_CONST( StencilOperation, DecrementWrap,	7 )


struct TypeDesc
{
	StencilOperation	type;
	const Char*			name;
};

static TypeDesc _desc[] = 
{
	{ StencilOperation::None,				L"None" },
	{ StencilOperation::Zero,				L"Zero" },
	{ StencilOperation::Replace,			L"Replace" },
	{ StencilOperation::Invert,				L"Invert" },
	{ StencilOperation::IncrementClamp,		L"IncrementClamp" },
	{ StencilOperation::DecrementClamp,		L"DecrementClamp" },
	{ StencilOperation::IncrementWrap,		L"IncrementWrap" },
	{ StencilOperation::DecrementWrap,		L"DecrementWrap" },
};
static UInt _count = SizeOf( _desc );

StencilOperation::StencilOperation( const lang::String& op ) :
	Enum( 0 )
{
	SET_ENUM_VALUE( op )
}

lang::String StencilOperation::ToString() const
{
	ENUM_TO_STRING()
}


} // gfx


} // synkro
