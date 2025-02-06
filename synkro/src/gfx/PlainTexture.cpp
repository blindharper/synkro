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
// Purpose: Logical plain texture.
//==============================================================================
#include "config.h"
#include "PlainTexture.h"


namespace synkro
{


namespace gfx
{


PlainTexture::PlainTexture( IPlainTexture* texture ) :
	PlainTextureImpl<IPlainTexture>( texture->GetWidth(), texture->GetHeight(), texture->GetFormat(), texture->GetLevelCount(), texture->GetElementCount() ),
	_texture( texture )
{
	_resource = _texture;
}


} // gfx


} // synkro
