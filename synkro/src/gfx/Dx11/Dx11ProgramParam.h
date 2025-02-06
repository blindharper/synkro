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
#ifndef _SYNKRO_GFX_DX11PROGRAMPARAM_
#define _SYNKRO_GFX_DX11PROGRAMPARAM_


#include "config.h"
#include <gfx/ProgramParamEx.h>
#undef new
#include "Dx11.h"
#define new SYNKRO_NEW


namespace synkro
{


namespace gfx
{


// DX11 program parameter.
class Dx11ProgramParam :
	public ProgramParamEx
{
public:
	// Constructors.
	Dx11ProgramParam( const lang::String& name );
	Dx11ProgramParam();

	ID3D11Buffer*											Buffer;
	UInt													BufferOffset;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11PROGRAMPARAM_
