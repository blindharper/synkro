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
// Purpose: DXGI API.
//==============================================================================
#ifndef _SYNKRO_GFX_DXGI_
#define _SYNKRO_GFX_DXGI_


#include "config.h"
#include <gfx/DepthFormat.h>
#include <gfx/IndexType.h>
#include <gfx/ProgramDataType.h>
#include <img/PixelFormat.h>
#include <dxgi.h>


typedef HRESULT (WINAPI* LPCREATEDXGIFACTORY)( REFIID, void** );


namespace synkro
{


namespace gfx
{


// DXGI API.
class DxGi
{
public:
	static const DXGI_FORMAT 								Convert( const IndexType& type );
	static const DXGI_FORMAT				 				Convert( const img::PixelFormat& fmt );
	static const DXGI_FORMAT								Convert( const DepthFormat& fmt, Bool stencil );
	static const DXGI_FORMAT 								Convert( const ProgramDataType& type );
	static img::PixelFormat									Convert( DXGI_FORMAT format );
	static const Char*										ToString( HRESULT hr );
	static const Char*										ToString( DXGI_FORMAT format );
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DXGI_
