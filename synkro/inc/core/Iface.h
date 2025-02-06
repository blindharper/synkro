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
// Purpose: Defines Synkro interface types.
//==============================================================================
#ifndef _SYNKRO_CORE_IFACE_
#define _SYNKRO_CORE_IFACE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace core
{


/**
 * Synkro interface types.
 */
SYNKRO_ENUM_BEGIN( Iface )
	/** Unknown interface. */
	SYNKRO_ENUM_CONST( Iface, Unknown )

	/** anim::IAnimationCodec interface. */
	SYNKRO_ENUM_CONST( Iface, AnimationCodec )

	/** anim::IAnimationTrack interface. */
	SYNKRO_ENUM_CONST( Iface, AnimationTrack )

	/** audio::IAudioSystem interface. */
	SYNKRO_ENUM_CONST( Iface, AudioSystem )

	/** cons::IConsoleCommand interface. */
	SYNKRO_ENUM_CONST( Iface, ConsoleCommand )

	/** db::IDatabaseSystem interface. */
	SYNKRO_ENUM_CONST( Iface, DatabaseSystem )

	/** gfx::IGraphicsSystem interface. */
	SYNKRO_ENUM_CONST( Iface, GraphicsSystem )

	/** io::IStreamSystem interface. */
	SYNKRO_ENUM_CONST( Iface, StreamSystem )

	/** io::IStreamDirectory interface. */
	SYNKRO_ENUM_CONST( Iface, StreamDirectory )

	/** img::IImageCodec interface. */
	SYNKRO_ENUM_CONST( Iface, ImageCodec )

	/** input::IInputSystem interface. */
	SYNKRO_ENUM_CONST( Iface, InputSystem )

	/** net::INetworkSystem interface. */
	SYNKRO_ENUM_CONST( Iface, NetworkSystem )

	/** scene::IMeshBuilder interface. */
	SYNKRO_ENUM_CONST( Iface, MeshBuilder )

	/** scene::IMeshCodec interface. */
	SYNKRO_ENUM_CONST( Iface, MeshCodec )

	/** view::IViewportFilter interface. */
	SYNKRO_ENUM_CONST( Iface, ViewportFilter )

	/** script::IScriptSystem interface. */
	SYNKRO_ENUM_CONST( Iface, ScriptSystem )

	/** scene::IScene interface. */
	SYNKRO_ENUM_CONST( Iface, Scene )

	/** sound::ISoundCodec interface. */
	SYNKRO_ENUM_CONST( Iface, SoundCodec )

	/** ui::IUi interface. */
	SYNKRO_ENUM_CONST( Iface, Ui )

	/** win::IWindowSystem interface. */
	SYNKRO_ENUM_CONST( Iface, WindowSystem )
SYNKRO_ENUM_END()


} // core


} // synkro


#endif // _SYNKRO_CORE_IFACE_
