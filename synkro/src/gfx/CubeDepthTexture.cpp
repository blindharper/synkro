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
#include "config.h"
#include "CubeDepthTexture.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


CubeDepthTexture::CubeDepthTexture( ICubeDepthTexture* texture ) :
	CubeDepthTextureImpl<ICubeDepthTexture>( texture->GetLength(), texture->GetFormat(), texture->GetDefaultStencil() ),
	_texture( texture )
{
	_resource = _texture;
}


} // gfx


} // synkro
