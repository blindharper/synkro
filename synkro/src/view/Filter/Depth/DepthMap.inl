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
// Purpose: Depth map implementation.
//==============================================================================
SYNKRO_INLINE UInt DepthMap::GetWidth() const
{
	return _texture->GetWidth();
}

SYNKRO_INLINE UInt DepthMap::GetHeight() const
{
	return _texture->GetHeight();
}

SYNKRO_INLINE gfx::IResource* DepthMap::GetResource() const
{
	return _texture;
}

SYNKRO_INLINE gfx::IPlainDepthTexture* DepthMap::GetTexture() const
{
	return _texture;
}
