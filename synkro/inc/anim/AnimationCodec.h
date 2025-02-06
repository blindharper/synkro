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
// Purpose: Defines animation codec types.
//==============================================================================
#ifndef _SYNKRO_ANIM_ANIMATIONCODEC_
#define _SYNKRO_ANIM_ANIMATIONCODEC_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace anim
{


/**
 * Animation codec types.
 */
SYNKRO_ENUM_BEGIN( AnimationCodec )
	/** Unknown codec. */
	SYNKRO_ENUM_CONST( AnimationCodec, Unknown )

	/** Custom codec. */
	SYNKRO_ENUM_CONST( AnimationCodec, Custom )

	/** Binary animation codec. */
	SYNKRO_ENUM_CONST( AnimationCodec, Bin )

	/** Sql-based animation codec. */
	SYNKRO_ENUM_CONST( AnimationCodec, Sql )

	/** Xml-based animation codec. */
	SYNKRO_ENUM_CONST( AnimationCodec, Xml )

	/** Creates animation codec type from string. */
	AnimationCodec( const lang::String& type );

	/** Converts animation codec type to string. */
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // anim


} // synkro


#endif // _SYNKRO_ANIM_ANIMATIONCODEC_
