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
// Purpose: Defines DX11 include file.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11INCLUDE_
#define _SYNKRO_GFX_DX11INCLUDE_


#include "config.h"
#include <lang/Vector.h>
#include <io/IStreamDirectory.h>
#undef new
#include "Dx11.h"
#define new SYNKRO_NEW


namespace synkro
{


namespace gfx
{


// DX11 include file.
class Dx11Include :
	public ID3D10Include
{
public:
	// Constructor.
	Dx11Include( io::IStreamDirectory* dir );

	// ID3D10Include methods.
	HRESULT	__stdcall										Open( D3D10_INCLUDE_TYPE IncludeType, LPCSTR pFileName, LPCVOID pParentData, LPCVOID* ppData, UINT* pBytes );
	HRESULT __stdcall										Close( LPCVOID pData );

private:
	lang::Vector<Byte>										_data;
	io::IStreamDirectory*									_dir;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11INCLUDE_
