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
// Purpose: DX11 cube depth texture implementation.
//==============================================================================
SYNKRO_INLINE void Dx11CubeDepthTexture::Clear()
{
	Dx11Lock( _context );
	_context->ClearDepthStencilView( _dsv, _flags, _defaultDepth, _defaultStencil );
}
