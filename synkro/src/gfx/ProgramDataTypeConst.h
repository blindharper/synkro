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
// Purpose: Defines program data type constant values.
//==============================================================================
#ifndef _SYNKRO_GFX_PROGRAMDATATYPECONST_
#define _SYNKRO_GFX_PROGRAMDATATYPECONST_


#include "config.h"


namespace synkro
{


namespace gfx
{


// Program data type constant values.
enum ProgramDataTypeConst
{
	PROGRAM_DATA_TYPE_UNKNOWN				= 0,
	PROGRAM_DATA_TYPE_BOOL					= 1,
	PROGRAM_DATA_TYPE_INT					= 2,
	PROGRAM_DATA_TYPE_FLOAT					= 3,
	PROGRAM_DATA_TYPE_VECTOR2				= 4,
	PROGRAM_DATA_TYPE_VECTOR3				= 5,
	PROGRAM_DATA_TYPE_VECTOR4				= 6,
	PROGRAM_DATA_TYPE_MATRIX3X3				= 7,
	PROGRAM_DATA_TYPE_MATRIX4X4				= 8,
	PROGRAM_DATA_TYPE_MATRIX4X4_TRANSPOSED	= 9,
	PROGRAM_DATA_TYPE_STRUCTURE				= 10,
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_PROGRAMDATATYPECONST_
