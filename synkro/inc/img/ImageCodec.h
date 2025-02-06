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
#ifndef _SYNKRO_IMG_IMAGECODEC_
#define _SYNKRO_IMG_IMAGECODEC_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace img
{


/**
 * Image codec types.
 */
SYNKRO_ENUM_BEGIN( ImageCodec )
	/** Unknown image codec. */
	SYNKRO_ENUM_CONST( ImageCodec, Unknown )

	/** Custom image codec. */
	SYNKRO_ENUM_CONST( ImageCodec, Custom )

	/** Bitmap image codec. */
	SYNKRO_ENUM_CONST( ImageCodec, Bmp )

	/** DDS image codec. */
	SYNKRO_ENUM_CONST( ImageCodec, Dds )

	/** JPEG image codec. */
	SYNKRO_ENUM_CONST( ImageCodec, Jpg )

	/** PNG image codec. */
	SYNKRO_ENUM_CONST( ImageCodec, Png )

	/** Targa image codec. */
	SYNKRO_ENUM_CONST( ImageCodec, Tga )

	/** Creates image codec type from string. */
	ImageCodec( const lang::String& type );

	/** Converts image codec type to string. */
	lang::String											ToString() const;

	/** Tests whether the given name has an extension corresponding to one of the image codecs. */
	static Bool												IsValid( const lang::String& name );
SYNKRO_ENUM_END()


} // img


} // synkro


#endif // _SYNKRO_IMG_IMAGECODEC_
