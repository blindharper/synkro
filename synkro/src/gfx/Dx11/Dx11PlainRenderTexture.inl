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
// Purpose: DX11 rendering plain texture implementation.
//==============================================================================
SYNKRO_INLINE Bool Dx11PlainRenderTexture::Bind()
{
	Dx11Lock( _context );
	_context->OMSetRenderTargets( 1, &_rtv, _dsv );
	_context->RSSetViewports( 1, &_viewport );
	return true;
}

SYNKRO_INLINE void Dx11PlainRenderTexture::Clear()
{
	Dx11Lock( _context );
	_context->ClearRenderTargetView( _rtv, &_defaultColor.x );
}

SYNKRO_INLINE Bool Dx11PlainRenderTexture::Present()
{
	Dx11Lock( _context );

	if ( _textureMS != nullptr )
	{
			_context->ResolveSubresource( _texture, 0, _textureMS, 0, DxGi::Convert(_format) );
	}

	_context->OMSetRenderTargets( 1, &_rtv, _dsv );
	return true;
}

SYNKRO_INLINE void Dx11PlainRenderTexture::UnbindDepthTexture()
{
	Dx11Lock( _context );
	ID3D11RenderTargetView* rtv;
	_context->OMGetRenderTargets( 1, &rtv, nullptr );
	_context->OMSetRenderTargets( 1, &rtv, nullptr );
}

SYNKRO_INLINE IPlainDepthTexture* Dx11PlainRenderTexture::GetDepthTexture() const
{
	return _depthTexture;
}
