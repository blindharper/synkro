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
SYNKRO_INLINE void PlainDepthTexture::Clear()
{
	SynkroProfile( "PlainDepthTexture.Clear" );

	return _texture->Clear();
}

SYNKRO_INLINE void PlainDepthTexture::SetDefaultDepth( Float depth )
{
	_texture->SetDefaultDepth( depth );
}

SYNKRO_INLINE void PlainDepthTexture::SetDefaultStencil( Byte stencil )
{
	_texture->SetDefaultStencil( stencil );
}
