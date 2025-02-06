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
// Purpose: Defines DX11 program parameter.
//==============================================================================
#include "config.h"
#include "Dx11ProgramParam.h"


namespace synkro
{


namespace gfx
{


Dx11ProgramParam::Dx11ProgramParam( const lang::String& name ) :
	ProgramParamEx( name )
{
}

Dx11ProgramParam::Dx11ProgramParam() :
	Buffer( nullptr ),
	BufferOffset( 0 )
{
}


} // gfx


} // synkro
