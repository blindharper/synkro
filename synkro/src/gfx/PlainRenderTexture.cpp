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
// Purpose: Logical plain rendering texture.
//==============================================================================
#include "config.h"
#include "PlainRenderTexture.h"
#include "PlainDepthTexture.h"
#include <gfx/GraphicsException.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


PlainRenderTexture::PlainRenderTexture( IPlainRenderTexture* texture ) :
	_texture( texture )
{
	_resource = _texture;
}

void PlainRenderTexture::UnbindDepthTexture()
{
	_texture->UnbindDepthTexture();
}

void PlainRenderTexture::SetDepthTexture( IPlainDepthTexture* texture )
{
	if ( texture == nullptr )
	{
		_texture->SetDepthTexture( nullptr );
		_depthTexture = nullptr;
		return;
	}

	if ( (texture->GetWidth() != GetWidth()) || (texture->GetHeight() != GetHeight()) )
		throw GraphicsException( L"Depth texture has incompatible dimensions." );

	_texture->SetDepthTexture( ((PlainDepthTexture*)texture)->_texture );
	_depthTexture = texture;
}


} // gfx


} // synkro
