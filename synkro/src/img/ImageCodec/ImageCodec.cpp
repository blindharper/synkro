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
// Purpose: Defines image codec types.
//==============================================================================
#include "config.h"
#include <img/ImageCodec.h>
#include <internal/Enum.h>


namespace synkro
{


namespace img
{


SYNKRO_DEFINE_CONST( ImageCodec, Unknown,	0 )
SYNKRO_DEFINE_CONST( ImageCodec, Custom,	1 )
SYNKRO_DEFINE_CONST( ImageCodec, Bmp,		2 )
SYNKRO_DEFINE_CONST( ImageCodec, Dds,		3 )
SYNKRO_DEFINE_CONST( ImageCodec, Jpg,		4 )
SYNKRO_DEFINE_CONST( ImageCodec, Png,		5 )
SYNKRO_DEFINE_CONST( ImageCodec, Tga,		6 )


struct TypeDesc
{
	ImageCodec	type;
	const Char*	name;
};

static TypeDesc _desc[] = 
{
	{ ImageCodec::Unknown,		L"" },
	{ ImageCodec::Custom,		L"img" },
	{ ImageCodec::Bmp,			L"bmp" },
	{ ImageCodec::Dds,			L"dds" },
	{ ImageCodec::Jpg,			L"jpg" },
	{ ImageCodec::Png,			L"png" },
	{ ImageCodec::Tga,			L"tga" },
};
static UInt _count = SizeOf( _desc );

ImageCodec::ImageCodec( const lang::String& type ) :
	Enum( 0 )
{
	SET_ENUM_VALUE( type )
}

lang::String ImageCodec::ToString() const
{
	ENUM_TO_STRING()
}

Bool ImageCodec::IsValid( const lang::String& name )
{
	IS_VALID_ENUM( name )
}


} // img


} // synkro
