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
// Purpose: Logical linear texture.
//==============================================================================
#include "config.h"
#include "LinearTexture.h"


namespace synkro
{


namespace gfx
{


LinearTexture::LinearTexture( ILinearTexture* texture ) :
	LinearTextureImpl<ILinearTexture>( texture->GetLength(), texture->GetFormat(), texture->GetLevelCount(), texture->GetElementCount() ),
	_texture( texture )
{
	_resource = _texture;
}


} // gfx


} // synkro
