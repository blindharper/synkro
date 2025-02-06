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
// Purpose: DX11 linear rendering texture implementation.
//==============================================================================
SYNKRO_INLINE Bool Dx11LinearRenderTexture::Bind()
{
	ID3D11DepthStencilView* dsv = nullptr;
	Dx11Lock( _context );
	_context->OMGetRenderTargets( 0, nullptr, &dsv );
	_context->OMSetRenderTargets( 1, &_rtv, dsv );
	return true;
}

SYNKRO_INLINE void Dx11LinearRenderTexture::Clear()
{
	Dx11Lock( _context );
	_context->ClearRenderTargetView( _rtv, &_defaultColor.x );
}
