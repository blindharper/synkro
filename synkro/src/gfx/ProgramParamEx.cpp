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
#include "config.h"
#include "ProgramParamEx.h"


namespace synkro
{


namespace gfx
{


static UInt _programParamID = 0;


ProgramParamEx::ProgramParamEx( const lang::String& name ) :
	ID( ++_programParamID ),
	Name( name )
{
}

ProgramParamEx::ProgramParamEx() :
	ID( 0 ),
	Type( ProgramDataType::Unknown ),
	Offset( 0 ),
	Size( 0 ),
	ElementCount( 1 )
{
}


} // gfx


} // synkro
