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
#ifndef _SYNKRO_DIAG_LOGFACILITY_
#define _SYNKRO_DIAG_LOGFACILITY_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace diag
{


/**
 * Log facility.
 */
SYNKRO_ENUM_BEGIN( LogFacility )
	/** Default facility. */
	SYNKRO_ENUM_CONST( LogFacility, Default )

	/** Animation system. */
	SYNKRO_ENUM_CONST( LogFacility, AnimationSystem )

	/** Audio system. */
	SYNKRO_ENUM_CONST( LogFacility, AudioSystem )

	/** Console. */
	SYNKRO_ENUM_CONST( LogFacility, Console )

	/** Core. */
	SYNKRO_ENUM_CONST( LogFacility, Core )

	/** Database system. */
	SYNKRO_ENUM_CONST( LogFacility, DatabaseSystem )

	/** Graphics system. */
	SYNKRO_ENUM_CONST( LogFacility, GraphicsSystem )

	/** Image manager. */
	SYNKRO_ENUM_CONST( LogFacility, ImageManager )

	/** Input system. */
	SYNKRO_ENUM_CONST( LogFacility, InputSystem )

	/** Stream system. */
	SYNKRO_ENUM_CONST( LogFacility, StreamSystem )

	/** Material manager. */
	SYNKRO_ENUM_CONST( LogFacility, MaterialManager )

	/** Network system. */
	SYNKRO_ENUM_CONST( LogFacility, NetworkSystem )

	/** Overlay manager. */
	SYNKRO_ENUM_CONST( LogFacility, OverlayManager )

	/** Scene manager. */
	SYNKRO_ENUM_CONST( LogFacility, SceneManager )

	/** Script system. */
	SYNKRO_ENUM_CONST( LogFacility, ScriptSystem )

	/** Sound manager. */
	SYNKRO_ENUM_CONST( LogFacility, SoundManager )

	/** User interface. */
	SYNKRO_ENUM_CONST( LogFacility, UserInterface )

	/** Viewport manager. */
	SYNKRO_ENUM_CONST( LogFacility, ViewportManager )

	/** Window system. */
	SYNKRO_ENUM_CONST( LogFacility, WindowSystem )

	/** Converts log facility to string. */
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // diag


} // synkro


#endif // _SYNKRO_DIAG_LOGFACILITY_
