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
// Purpose: Logical plain depth texture.
//==============================================================================
#include "config.h"
#include "PlainDepthTexture.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


PlainDepthTexture::PlainDepthTexture( IPlainDepthTexture* texture ) :
	PlainDepthTextureImpl<IPlainDepthTexture>( texture->GetWidth(), texture->GetHeight(), texture->GetFormat(), texture->HasStencil() ),
	_texture( texture )
{
	_resource = _texture;
}


} // gfx


} // synkro
