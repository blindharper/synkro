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
// Purpose: Defines log facility.
//==============================================================================
#include "config.h"
#include <diag/LogFacility.h>
#include <internal/Enum.h>


namespace synkro
{


namespace diag
{


SYNKRO_DEFINE_CONST( LogFacility, Default,			0 )
SYNKRO_DEFINE_CONST( LogFacility, AnimationSystem,	1 )
SYNKRO_DEFINE_CONST( LogFacility, AudioSystem,		2 )
SYNKRO_DEFINE_CONST( LogFacility, Console,			3 )
SYNKRO_DEFINE_CONST( LogFacility, Core,				4 )
SYNKRO_DEFINE_CONST( LogFacility, DatabaseSystem,	5 )
SYNKRO_DEFINE_CONST( LogFacility, GraphicsSystem,	6 )
SYNKRO_DEFINE_CONST( LogFacility, ImageManager,		7 )
SYNKRO_DEFINE_CONST( LogFacility, InputSystem,		8 )
SYNKRO_DEFINE_CONST( LogFacility, StreamSystem,		9 )
SYNKRO_DEFINE_CONST( LogFacility, MaterialManager,	10 )
SYNKRO_DEFINE_CONST( LogFacility, NetworkSystem,	11 )
SYNKRO_DEFINE_CONST( LogFacility, OverlayManager,	12 )
SYNKRO_DEFINE_CONST( LogFacility, SceneManager,		13 )
SYNKRO_DEFINE_CONST( LogFacility, ScriptSystem,		14 )
SYNKRO_DEFINE_CONST( LogFacility, SoundManager,		15 )
SYNKRO_DEFINE_CONST( LogFacility, UserInterface,	16 )
SYNKRO_DEFINE_CONST( LogFacility, ViewportManager,	17 )
SYNKRO_DEFINE_CONST( LogFacility, WindowSystem,		18 )


struct TypeDesc
{
	LogFacility	type;
	const Char*	name;
};

static TypeDesc _desc[] = 
{
	{ LogFacility::Default,				L"Default         " },
	{ LogFacility::AnimationSystem,		L"AnimationSystem " },
	{ LogFacility::AudioSystem,			L"AudioSystem     " },
	{ LogFacility::Console,				L"Console         " },
	{ LogFacility::Core,				L"Core            " },
	{ LogFacility::DatabaseSystem,		L"DatabaseSystem  " },
	{ LogFacility::GraphicsSystem,		L"GraphicsSystem  " },
	{ LogFacility::ImageManager,		L"ImageManager    " },
	{ LogFacility::InputSystem,			L"InputSystem     " },
	{ LogFacility::StreamSystem,		L"StreamSystem    " },
	{ LogFacility::MaterialManager,		L"MaterialManager " },
	{ LogFacility::NetworkSystem,		L"NetworkSystem   " },
	{ LogFacility::OverlayManager,		L"OverlayManager  " },
	{ LogFacility::SceneManager,		L"SceneManager    " },
	{ LogFacility::ScriptSystem,		L"ScriptSystem    " },
	{ LogFacility::SoundManager,		L"SoundManager    " },
	{ LogFacility::UserInterface,		L"UserInterface   " },
	{ LogFacility::ViewportManager,		L"ViewportManager " },
	{ LogFacility::WindowSystem,		L"WindowSystem    " },
};
static UInt _count = SizeOf( _desc );

lang::String LogFacility::ToString() const
{
	ENUM_TO_STRING()
}


} // diag


} // synkro
