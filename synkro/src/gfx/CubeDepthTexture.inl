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
// Purpose: Logical cube depth texture.
//==============================================================================
SYNKRO_INLINE IDepthTexture* CubeDepthTexture::AsDepthTexture() const
{
	return (IDepthTexture*)this;
}

SYNKRO_INLINE void CubeDepthTexture::Clear()
{
	return _texture->Clear();
}

SYNKRO_INLINE void CubeDepthTexture::SetDefaultDepth( Float depth )
{
	_texture->SetDefaultDepth( depth );
}

SYNKRO_INLINE void CubeDepthTexture::SetDefaultStencil( Byte stencil )
{
	_texture->SetDefaultStencil( stencil );
}

SYNKRO_INLINE Bool CubeDepthTexture::BindFace( const CubeFace& face )
{
	return _texture->BindFace( face );
}
