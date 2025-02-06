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
// Purpose: Logical volume texture.
//==============================================================================
SYNKRO_INLINE void VolumeTexture::GenerateLevels()
{
	_texture->GenerateLevels();
}

SYNKRO_INLINE Bool VolumeTexture::SetData( UInt element, UInt level, UInt width, UInt height, UInt stride, UInt sliceStride, const img::PixelFormat& format, const Byte* data )
{
	_dirty = true;
	return _texture->SetData( element, level, width, height, stride, sliceStride, format, data );
}
