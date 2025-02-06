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
// Purpose: Defines viewport filter types.
//==============================================================================
#include "config.h"
#include <view/ViewportFilter.h>
#include <internal/Enum.h>


namespace synkro
{


namespace view
{


SYNKRO_DEFINE_CONST( ViewportFilter, Custom,		0 )
SYNKRO_DEFINE_CONST( ViewportFilter, Red,			1 )
SYNKRO_DEFINE_CONST( ViewportFilter, Green,			2 )
SYNKRO_DEFINE_CONST( ViewportFilter, Blue,			3 )
SYNKRO_DEFINE_CONST( ViewportFilter, Alpha,			4 )
SYNKRO_DEFINE_CONST( ViewportFilter, Grayscale,		5 )
SYNKRO_DEFINE_CONST( ViewportFilter, Sepia,			6 )
SYNKRO_DEFINE_CONST( ViewportFilter, Negative,		7 )
SYNKRO_DEFINE_CONST( ViewportFilter, Color,			8 )
SYNKRO_DEFINE_CONST( ViewportFilter, Hue,			9 )
SYNKRO_DEFINE_CONST( ViewportFilter, Brightness,	10 )
SYNKRO_DEFINE_CONST( ViewportFilter, Contrast,		11 )
SYNKRO_DEFINE_CONST( ViewportFilter, Depth,			12 )
SYNKRO_DEFINE_CONST( ViewportFilter, Fog,			13 )
SYNKRO_DEFINE_CONST( ViewportFilter, MotionBlur,	14 )
SYNKRO_DEFINE_CONST( ViewportFilter, DepthOfField,	15 )
SYNKRO_DEFINE_CONST( ViewportFilter, Blur,			16 )
SYNKRO_DEFINE_CONST( ViewportFilter, Dilation,		17 )
SYNKRO_DEFINE_CONST( ViewportFilter, Erosion,		18 )
SYNKRO_DEFINE_CONST( ViewportFilter, Sharpen,		19 )
SYNKRO_DEFINE_CONST( ViewportFilter, Emboss,		20 )
SYNKRO_DEFINE_CONST( ViewportFilter, Laplacian,		21 )
SYNKRO_DEFINE_CONST( ViewportFilter, Prewitt,		22 )
SYNKRO_DEFINE_CONST( ViewportFilter, Sobel,			23 )


struct TypeDesc
{
	ViewportFilter	type;
	const Char*		name;
};

static TypeDesc _desc[] = 
{
	{ ViewportFilter::Custom,		L"filter" },
	{ ViewportFilter::Red,			L"filter.red" },
	{ ViewportFilter::Green,		L"filter.green" },
	{ ViewportFilter::Blue,			L"filter.blue" },
	{ ViewportFilter::Alpha,		L"filter.alpha" },
	{ ViewportFilter::Grayscale,	L"filter.grayscale" },
	{ ViewportFilter::Sepia,		L"filter.sepia" },
	{ ViewportFilter::Negative,		L"filter.negative" },
	{ ViewportFilter::Color,		L"filter.color" },
	{ ViewportFilter::Hue,			L"filter.hue" },
	{ ViewportFilter::Brightness,	L"filter.brightness" },
	{ ViewportFilter::Contrast,		L"filter.contrast" },
	{ ViewportFilter::Depth,		L"filter.depth" },
	{ ViewportFilter::Fog,			L"filter.fog" },
	{ ViewportFilter::MotionBlur,	L"filter.motionblur" },
	{ ViewportFilter::DepthOfField,	L"filter.depthoffield" },
	{ ViewportFilter::Blur,			L"filter.blur" },
	{ ViewportFilter::Dilation,		L"filter.dilation" },
	{ ViewportFilter::Erosion,		L"filter.erosion" },
	{ ViewportFilter::Sharpen,		L"filter.sharpen" },
	{ ViewportFilter::Emboss,		L"filter.emboss" },
	{ ViewportFilter::Laplacian,	L"filter.laplacian" },
	{ ViewportFilter::Prewitt,		L"filter.prewitt" },
	{ ViewportFilter::Sobel,		L"filter.sobel" },
};
static UInt _count = SizeOf( _desc );

lang::String ViewportFilter::ToString() const
{
	ENUM_TO_STRING()
}


} // view


} // synkro
