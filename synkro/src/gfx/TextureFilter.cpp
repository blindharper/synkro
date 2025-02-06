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
// Purpose: Defines texture filtering filters.
//==============================================================================
#include "config.h"
#include <gfx/TextureFilter.h>
#include <internal/Enum.h>


namespace synkro
{


namespace gfx
{


SYNKRO_DEFINE_CONST( TextureFilter, Point,			1 )
SYNKRO_DEFINE_CONST( TextureFilter, Linear,			2 )
SYNKRO_DEFINE_CONST( TextureFilter, Anisotropic,	3 )
SYNKRO_DEFINE_CONST( TextureFilter, PyramidalQuad,	4 )
SYNKRO_DEFINE_CONST( TextureFilter, GaussianQuad,	5 )


struct TypeDesc
{
	TextureFilter	type;
	const Char*		name;
};

static TypeDesc _desc[] = 
{
	{ TextureFilter::Point,			L"Point" },
	{ TextureFilter::Linear,		L"Linear" },
	{ TextureFilter::Anisotropic,	L"Anisotropic" },
	{ TextureFilter::PyramidalQuad,	L"PyramidalQuad" },
	{ TextureFilter::GaussianQuad,	L"GaussianQuad" },
};
static UInt _count = SizeOf( _desc );

TextureFilter::TextureFilter( const lang::String& filter ) :
	Enum( 0 )
{
	SET_ENUM_VALUE( filter )
}

lang::String TextureFilter::ToString() const
{
	ENUM_TO_STRING()
}


} // gfx


} // synkro
