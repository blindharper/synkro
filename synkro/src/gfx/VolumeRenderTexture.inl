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
// Purpose: Logical volume rendering texture.
//==============================================================================
SYNKRO_INLINE IRenderTexture* VolumeRenderTexture::AsRenderTexture() const
{
	return (IRenderTexture*)this;
}

SYNKRO_INLINE Bool VolumeRenderTexture::Bind()
{
	return _texture->Bind();
}

SYNKRO_INLINE void VolumeRenderTexture::Clear()
{
	_texture->Clear();
}

SYNKRO_INLINE Bool VolumeRenderTexture::Present()
{
	return _texture->Present();
}

SYNKRO_INLINE void VolumeRenderTexture::SetDefaultColor( const math::Vector4& color )
{
	_texture->SetDefaultColor( color );
}

SYNKRO_INLINE void VolumeRenderTexture::GetDefaultColor( math::Vector4& color ) const
{
	_texture->GetDefaultColor( color );
}

SYNKRO_INLINE img::PixelFormat VolumeRenderTexture::GetFormat() const
{
	return _texture->GetFormat();
}

SYNKRO_INLINE Bool VolumeRenderTexture::GetData( UInt element, UInt* width, UInt* height, UInt* depth, UInt* stride, UInt* sliceStride, img::PixelFormat* format, Byte** data, UInt* size )
{
	return _texture->GetData( element, width, height, depth, stride, sliceStride, format, data, size );
}

SYNKRO_INLINE UInt VolumeRenderTexture::GetWidth() const
{
	return _texture->GetWidth();
}

SYNKRO_INLINE UInt VolumeRenderTexture::GetHeight() const
{
	return _texture->GetHeight();
}

SYNKRO_INLINE UInt VolumeRenderTexture::GetDepth() const
{
	return _texture->GetDepth();
}
