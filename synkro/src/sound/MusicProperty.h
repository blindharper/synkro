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
// Purpose: Defines music property names.
//==============================================================================
#ifndef _SYNKRO_SOUND_MUSICPROPERTY_
#define _SYNKRO_SOUND_MUSICPROPERTY_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace sound
{


// Music property names.
SYNKRO_ENUM_BEGIN( MusicProperty )
	// Music volume.
	SYNKRO_ENUM_CONST( MusicProperty, Volume )

	// Music pan.
	SYNKRO_ENUM_CONST( MusicProperty, Pan )

	// Converts music property to string.
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // sound


} // synkro


#endif // _SYNKRO_SOUND_MUSICPROPERTY_
