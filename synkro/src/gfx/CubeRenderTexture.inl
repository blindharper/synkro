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
// Purpose: Logical cube rendering texture.
//==============================================================================
SYNKRO_INLINE IRenderTexture* CubeRenderTexture::AsRenderTexture() const
{
	return (IRenderTexture*)this;
}

SYNKRO_INLINE Bool CubeRenderTexture::Bind()
{
	return _texture->Bind();
}

SYNKRO_INLINE void CubeRenderTexture::Clear()
{
	_texture->Clear();
}

SYNKRO_INLINE Bool CubeRenderTexture::Present()
{
	return _texture->Present();
}

SYNKRO_INLINE void CubeRenderTexture::SetDefaultColor( const math::Vector4& color )
{
	_texture->SetDefaultColor( color );
}

SYNKRO_INLINE void CubeRenderTexture::GetDefaultColor( math::Vector4& color ) const
{
	_texture->GetDefaultColor( color );
}

SYNKRO_INLINE img::PixelFormat CubeRenderTexture::GetFormat() const
{
	return _texture->GetFormat();
}

SYNKRO_INLINE Bool CubeRenderTexture::BindFace( const CubeFace& face )
{
	return _texture->BindFace( face );
}

SYNKRO_INLINE Bool CubeRenderTexture::GetData( const CubeFace& face, UInt* length, UInt* stride, img::PixelFormat* format, Byte** data, UInt* size )
{
	return _texture->GetData( face, length, stride, format, data, size );
}

SYNKRO_INLINE UInt CubeRenderTexture::GetLength() const
{
	return _texture->GetLength();
}
