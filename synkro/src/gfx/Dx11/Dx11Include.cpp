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
#include "config.h"
#include "Dx11Include.h"
#include <io/IStream.h>
#include <io/BinaryReader.h>


//------------------------------------------------------------------------------

using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Dx11Include::Dx11Include( IStreamDirectory* dir ) :
	_data( A(Byte) ),
	_dir( dir )
{
}

HRESULT Dx11Include::Open( D3D10_INCLUDE_TYPE IncludeType, LPCSTR pFileName, LPCVOID pParentData, LPCVOID* ppData, UINT* pBytes )
{
	// Do not support system includes.
	if ( IncludeType == D3D10_INCLUDE_SYSTEM )
		return E_FAIL;

	// Try opening include file.
	P(io::IStream) streamInclude = _dir->GetStream( pFileName );
	if ( streamInclude == nullptr )
	{
		streamInclude = _dir->GetParent()->GetStream( pFileName );
		if ( streamInclude == nullptr )
			return E_FAIL;
	}

	// Read file contents.
	BinaryReader rd( streamInclude );
	rd.ReadBytes( _data );

	// Fill output parameters.
	*ppData = (void*)_data.Begin();
	*pBytes = _data.Size();

	// Signal success.
	return S_OK;
}

HRESULT Dx11Include::Close( LPCVOID pData )
{
	// Memory is automatically deallocated by ~Vector(), so do nothing here.

	return S_OK;
}


} // gfx


} // synkro
