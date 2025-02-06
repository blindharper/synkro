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
// Purpose: Defines pixel format.
//==============================================================================
#include "config.h"
#include <img/PixelFormat.h>
#include <internal/Enum.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace img
{


SYNKRO_DEFINE_CONST( PixelFormat, Unknown,			0 )
SYNKRO_DEFINE_CONST( PixelFormat, R32G32B32A32F,	1 )
SYNKRO_DEFINE_CONST( PixelFormat, R32G32F,			2 )
SYNKRO_DEFINE_CONST( PixelFormat, R16G16B16A16F,	3 )
SYNKRO_DEFINE_CONST( PixelFormat, R16G16B16A16,		4 )
SYNKRO_DEFINE_CONST( PixelFormat, R32F,				5 )
SYNKRO_DEFINE_CONST( PixelFormat, R16G16F,			6 )
SYNKRO_DEFINE_CONST( PixelFormat, R10G10B10A2,		7 )
SYNKRO_DEFINE_CONST( PixelFormat, R16G16,			8 )
SYNKRO_DEFINE_CONST( PixelFormat, R8G8B8A8,			9 )
SYNKRO_DEFINE_CONST( PixelFormat, R8G8B8X8,			10 )
SYNKRO_DEFINE_CONST( PixelFormat, B8G8R8A8,			11 )
SYNKRO_DEFINE_CONST( PixelFormat, B8G8R8X8,			12 )
SYNKRO_DEFINE_CONST( PixelFormat, R8G8B8,			13 )
SYNKRO_DEFINE_CONST( PixelFormat, B8G8R8,			14 )
SYNKRO_DEFINE_CONST( PixelFormat, R16F,				15 )
SYNKRO_DEFINE_CONST( PixelFormat, R5G5B5A1,			16 )
SYNKRO_DEFINE_CONST( PixelFormat, R5G5B5X1,			17 )
SYNKRO_DEFINE_CONST( PixelFormat, R5G6B5,			18 )
SYNKRO_DEFINE_CONST( PixelFormat, R4G4B4A4,			19 )
SYNKRO_DEFINE_CONST( PixelFormat, R4G4B4X4,			20 )
SYNKRO_DEFINE_CONST( PixelFormat, R3G3B2A8,			21 )
SYNKRO_DEFINE_CONST( PixelFormat, R3G2B3A8,			22 )
SYNKRO_DEFINE_CONST( PixelFormat, R3G3B2,			23 )
SYNKRO_DEFINE_CONST( PixelFormat, R3G2B3,			24 )
SYNKRO_DEFINE_CONST( PixelFormat, R8,				25 )
SYNKRO_DEFINE_CONST( PixelFormat, A8,				26 )
SYNKRO_DEFINE_CONST( PixelFormat, BC1,				27 )
SYNKRO_DEFINE_CONST( PixelFormat, BC2,				28 )
SYNKRO_DEFINE_CONST( PixelFormat, BC3,				29 )
SYNKRO_DEFINE_CONST( PixelFormat, BC4,				30 )
SYNKRO_DEFINE_CONST( PixelFormat, BC5,				31 )


struct TypeDesc
{
	PixelFormat	type;
	const Char*	name;
	UInt		bits;
	UInt		channels;
	UInt		alpha;
	Bool		fp;
};

static TypeDesc _desc[] = 
{
	{ PixelFormat::Unknown,			L"",				  0, 0,	0x00000000, false },
	{ PixelFormat::R32G32B32A32F,	L"R32G32B32A32F",	128, 4,	0x00000000, true },
	{ PixelFormat::R32G32F,			L"R32G32F",			 64, 2,	0x00000000, true },
	{ PixelFormat::R16G16B16A16F,	L"R16G16B16A16F",	 64, 4,	0x00000000, true },
	{ PixelFormat::R16G16B16A16,	L"R16G16B16A16",	 64, 4,	0x00000000, false },
	{ PixelFormat::R32F,			L"R32F",			 32, 1,	0x00000000, true },
	{ PixelFormat::R16G16F,			L"R16G16F",			 32, 2,	0x00000000, true },
	{ PixelFormat::R10G10B10A2,		L"R10G10B10A2",		 32, 4,	0x03000000, false },
	{ PixelFormat::R16G16,			L"R16G16",			 32, 2,	0x00000000, false },
	{ PixelFormat::R8G8B8A8,		L"R8G8B8A8",		 32, 4,	0xff000000, false },
	{ PixelFormat::R8G8B8X8,		L"R8G8B8X8",		 32, 3,	0x00000000, false },
	{ PixelFormat::B8G8R8A8,		L"B8G8R8A8",		 32, 4,	0xff000000, false },
	{ PixelFormat::B8G8R8X8,		L"B8G8R8X8",		 32, 3,	0x00000000, false },
	{ PixelFormat::R8G8B8,			L"R8G8B8",			 24, 3,	0x00000000, false },
	{ PixelFormat::B8G8R8,			L"B8G8R8",			 24, 3,	0x00000000, false },
	{ PixelFormat::R16F,			L"R16F",			 16, 2,	0x00000000, true },
	{ PixelFormat::R5G5B5A1,		L"R5G5B5A1",		 16, 4, 0x00008000, false },
	{ PixelFormat::R5G5B5X1,		L"R5G5B5X1",		 16, 3, 0x00000000, false },
	{ PixelFormat::R5G6B5,			L"R5G6B5",			 16, 3, 0x00000000, false },
	{ PixelFormat::R4G4B4A4,		L"R4G4B4A4",		 16, 4, 0x0000f000, false },
	{ PixelFormat::R4G4B4X4,		L"R4G4B4X4",		 16, 3, 0x00000000, false },
	{ PixelFormat::R3G3B2A8,		L"R3G3B2A8",		 16, 4, 0x0000ff00, false },
	{ PixelFormat::R3G2B3A8,		L"R3G2B3A8",		 16, 4, 0x0000ff00, false },
	{ PixelFormat::R3G3B2,			L"R3G3B2",			  8, 3, 0x00000000, false },
	{ PixelFormat::R3G2B3,			L"R3G2B3",			  8, 3, 0x00000000, false },
	{ PixelFormat::R8,				L"R8",				  8, 1, 0x00000000, false },
	{ PixelFormat::A8,				L"A8",				  8, 1, 0x000000ff, false },
	{ PixelFormat::BC1,				L"BC1",				  0, 0,	0x00000000, false },
	{ PixelFormat::BC2,				L"BC2",				  0, 0,	0x00000000, false },
	{ PixelFormat::BC3,				L"BC3",				  0, 0,	0x00000000, false },
	{ PixelFormat::BC4,				L"BC4",				  0, 0,	0x00000000, false },
	{ PixelFormat::BC5,				L"BC5",				  0, 0,	0x00000000, false },
};
static UInt _count = SizeOf( _desc );

UInt GetPixelFormat( UInt red, UInt green, UInt blue, UInt alpha );

//------------------------------------------------------------------------------

PixelFormat::PixelFormat( UInt red, UInt green, UInt blue, UInt alpha ) :
	Enum( GetPixelFormat(red, green, blue, alpha) )
{
}

PixelFormat::PixelFormat( const String& format ) :
	Enum( 0 )
{
	SET_ENUM_VALUE( format )
}

UInt PixelFormat::ChannelCount() const
{
	return _desc[this->Value()].channels;
}

UInt PixelFormat::BytesPerPixel() const
{
	return _desc[this->Value()].bits >> 3;
}

UInt PixelFormat::BitsPerPixel() const
{
	return _desc[this->Value()].bits;
}

Bool PixelFormat::HasAlpha() const
{
	return _desc[this->Value()].alpha > 0;
}

Bool PixelFormat::IsCompressed() const
{
	return (this->Value() != 0) && (_desc[this->Value()].bits == 0);
}

Bool PixelFormat::IsFloatingPoint() const
{
	return _desc[this->Value()].fp;
}

String PixelFormat::ToString() const
{
	ENUM_TO_STRING()
}


} // img


} // synkro
