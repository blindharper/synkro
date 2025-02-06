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
// Purpose: Defines program data types.
//==============================================================================
#ifndef _SYNKRO_GFX_PROGRAMDATATYPE_
#define _SYNKRO_GFX_PROGRAMDATATYPE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace gfx
{


/**
 * Data types used as graphics program input and ouput.
 */
SYNKRO_ENUM_BEGIN( ProgramDataType )
	/** Unknown data type. */
	SYNKRO_ENUM_CONST( ProgramDataType, Unknown )

	/** Boolean value. */
	SYNKRO_ENUM_CONST( ProgramDataType, Bool )

	/** Whole number value. */
	SYNKRO_ENUM_CONST( ProgramDataType, Int )

	/** Floating-point value. */
	SYNKRO_ENUM_CONST( ProgramDataType, Float )

	/** 2-component floating-point value. */
	SYNKRO_ENUM_CONST( ProgramDataType, Vector2 )

	/** 3-component floating-point value. */
	SYNKRO_ENUM_CONST( ProgramDataType, Vector3 )

	/** 4-component floating-point value. */
	SYNKRO_ENUM_CONST( ProgramDataType, Vector4 )

	/** Row-major 3x3-matrix value. */
	SYNKRO_ENUM_CONST( ProgramDataType, Matrix3x3 )

	/** Row-major 4x4-matrix value. */
	SYNKRO_ENUM_CONST( ProgramDataType, Matrix4x4 )

	/** Column-major 4x4-matrix value. */
	SYNKRO_ENUM_CONST( ProgramDataType, Matrix4x4Transposed )

	/** Structure. */
	SYNKRO_ENUM_CONST( ProgramDataType, Structure )

	/**
	 * Retrieves data size, in bytes.
	 */
	UInt													Size() const;

	/** Converts program data type to string. */
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // gfx


} // synkro


#endif // _SYNKRO_GFX_PROGRAMDATATYPE_
