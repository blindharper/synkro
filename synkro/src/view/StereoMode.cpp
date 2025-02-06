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
// Purpose: Defines stereo mode.
//==============================================================================
#include "config.h"
#include <view/StereoMode.h>
#include <internal/Enum.h>
#include "StereoModeConst.h"


namespace synkro
{


namespace view
{


SYNKRO_DEFINE_CONST( StereoMode, None,			STEREO_MODE_NONE )
SYNKRO_DEFINE_CONST( StereoMode, True,			STEREO_MODE_TRUE )
SYNKRO_DEFINE_CONST( StereoMode, RedCyan,		STEREO_MODE_RED_CYAN )
SYNKRO_DEFINE_CONST( StereoMode, GreenMagenta,	STEREO_MODE_GREEN_MAGENTA )
SYNKRO_DEFINE_CONST( StereoMode, BlueYellow,	STEREO_MODE_BLUE_YELLOW )
SYNKRO_DEFINE_CONST( StereoMode, CyanRed,		STEREO_MODE_CYAN_RED )
SYNKRO_DEFINE_CONST( StereoMode, MagentaGreen,	STEREO_MODE_MAGENTA_GREEN )
SYNKRO_DEFINE_CONST( StereoMode, YellowBlue,	STEREO_MODE_YELLOW_BLUE )


struct TypeDesc
{
	StereoMode	type;
	const Char*	name;
};

static TypeDesc _desc[] = 
{
	{ StereoMode::None,			L"None" },
	{ StereoMode::True,			L"True" },
	{ StereoMode::RedCyan,		L"Red-Cyan" },
	{ StereoMode::GreenMagenta,	L"Green-Magenta" },
	{ StereoMode::BlueYellow,	L"Blue-Yellow" },
	{ StereoMode::CyanRed,		L"Cyan-Red" },
	{ StereoMode::MagentaGreen,	L"Magenta-Green" },
	{ StereoMode::YellowBlue,	L"Yellow-Blue" },
};
static UInt _count = SizeOf( _desc );

StereoMode::StereoMode( const lang::String& mode ) :
	Enum( 0 )
{
	SET_ENUM_VALUE( mode )
}

lang::String StereoMode::ToString() const
{
	ENUM_TO_STRING()
}


} // view


} // synkro
