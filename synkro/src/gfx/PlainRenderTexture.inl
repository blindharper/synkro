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
// Purpose: Logical plain rendering texture.
//==============================================================================
SYNKRO_INLINE IRenderTexture* PlainRenderTexture::AsRenderTexture() const
{
	return (IRenderTexture*)this;
}

SYNKRO_INLINE Bool PlainRenderTexture::Bind()
{
	SynkroProfile( "PlainRenderTexture.Bind" );

	return _texture->Bind();
}

SYNKRO_INLINE void PlainRenderTexture::Clear()
{
	SynkroProfile( "PlainRenderTexture.Clear" );

	_texture->Clear();
}

SYNKRO_INLINE Bool PlainRenderTexture::Present()
{
	SynkroProfile( "PlainRenderTexture.Present" );

	return _texture->Present();
}

SYNKRO_INLINE void PlainRenderTexture::SetDefaultColor( const math::Vector4& color )
{
	_texture->SetDefaultColor( color );
}

SYNKRO_INLINE void PlainRenderTexture::GetDefaultColor( math::Vector4& color ) const
{
	_texture->GetDefaultColor( color );
}

SYNKRO_INLINE img::PixelFormat PlainRenderTexture::GetFormat() const
{
	return _texture->GetFormat();
}

SYNKRO_INLINE Bool PlainRenderTexture::GetData( UInt* width, UInt* height, UInt* stride, img::PixelFormat* format, Byte** data, UInt* size )
{
	return _texture->GetData( width, height, stride, format, data, size );
}

SYNKRO_INLINE IPlainDepthTexture* PlainRenderTexture::GetDepthTexture() const
{
	return _depthTexture;
}

SYNKRO_INLINE UInt PlainRenderTexture::GetWidth() const
{
	return _texture->GetWidth();
}

SYNKRO_INLINE UInt PlainRenderTexture::GetHeight() const
{
	return _texture->GetHeight();
}
