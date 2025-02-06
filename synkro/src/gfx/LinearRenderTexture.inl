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
// Purpose: Logical linear rendering texture.
//==============================================================================
SYNKRO_INLINE IRenderTexture* LinearRenderTexture::AsRenderTexture() const
{
	return (IRenderTexture*)this;
}

SYNKRO_INLINE Bool LinearRenderTexture::Bind()
{
	return _texture->Bind();
}

SYNKRO_INLINE void LinearRenderTexture::Clear()
{
	_texture->Clear();
}

SYNKRO_INLINE Bool LinearRenderTexture::Present()
{
	return _texture->Present();
}

SYNKRO_INLINE void LinearRenderTexture::SetDefaultColor( const math::Vector4& color )
{
	_texture->SetDefaultColor( color );
}

SYNKRO_INLINE void LinearRenderTexture::GetDefaultColor( math::Vector4& color ) const
{
	_texture->GetDefaultColor( color );
}

SYNKRO_INLINE img::PixelFormat LinearRenderTexture::GetFormat() const
{
	return _texture->GetFormat();
}

SYNKRO_INLINE Bool LinearRenderTexture::GetData( UInt* length, img::PixelFormat* format, Byte** data, UInt* size )
{
	return _texture->GetData( length, format, data, size );
}

SYNKRO_INLINE UInt LinearRenderTexture::GetLength() const
{
	return _texture->GetLength();
}
