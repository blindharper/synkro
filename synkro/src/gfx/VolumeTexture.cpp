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
#include "config.h"
#include "VolumeTexture.h"


namespace synkro
{


namespace gfx
{


VolumeTexture::VolumeTexture( IVolumeTexture* texture ) :
	VolumeTextureImpl<IVolumeTexture>( texture->GetWidth(), texture->GetHeight(), texture->GetDepth(), texture->GetFormat(), texture->GetLevelCount() ),
	_texture( texture )
{
	_resource = _texture;
}


} // gfx


} // synkro
