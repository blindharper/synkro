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
// Purpose: Defines extended program parameter.
//==============================================================================
#ifndef _SYNKRO_GFX_PROGRAMPARAMEX_
#define _SYNKRO_GFX_PROGRAMPARAMEX_


#include "config.h"
#include <lang/String.h>
#include <gfx/ProgramParam.h>
#include <gfx/ProgramDataType.h>


namespace synkro
{


namespace gfx
{


// Extended program parameter.
class SYNKRO_API ProgramParamEx :
	public ProgramParam
{
public:
	// Constructors.
	ProgramParamEx( const lang::String& name );
	ProgramParamEx();

	UInt													ID;
	lang::String											Name;
	ProgramDataType											Type;
	UInt													Offset;
	UInt													Size;
	UInt													ElementCount;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_PROGRAMPARAMEX_
