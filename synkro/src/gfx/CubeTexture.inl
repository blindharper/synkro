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
// Purpose: Logical cube texture.
//==============================================================================
SYNKRO_INLINE void CubeTexture::GenerateLevels()
{
	_texture->GenerateLevels();
}

SYNKRO_INLINE Bool CubeTexture::SetData( const CubeFace& face, UInt level, UInt length, UInt stride, const img::PixelFormat& format, const Byte* data )
{
	_dirty = true;
	return _texture->SetData( face, level, length, stride, format, data );
}
