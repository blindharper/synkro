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
// Purpose: Defines image type.
//==============================================================================
#ifndef _SYNKRO_IMG_IMAGETYPE_
#define _SYNKRO_IMG_IMAGETYPE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace img
{


/**
 * Image type.
 */
SYNKRO_ENUM_BEGIN( ImageType )
	/** Untyped image. */
	SYNKRO_ENUM_CONST( ImageType, Unknown )

	/** 1-dimensional image. */
	SYNKRO_ENUM_CONST( ImageType, Linear )

	/** 2-dimensional image. */
	SYNKRO_ENUM_CONST( ImageType, Plain )

	/** Cubic image. */
	SYNKRO_ENUM_CONST( ImageType, Cube )

	/** 3-dimensional image. */
	SYNKRO_ENUM_CONST( ImageType, Volume )
SYNKRO_ENUM_END()


} // img


} // synkro


#endif // _SYNKRO_IMG_IMAGETYPE_
