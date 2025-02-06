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
// Purpose: DX11 based rendering texture set implementation.
//==============================================================================
SYNKRO_INLINE Bool Dx11RenderTextureSet::Bind()
{
	Dx11Lock( _context );
	_context->OMSetRenderTargets( _views.Size(), _views.Begin(), nullptr );
	return true;
}

SYNKRO_INLINE void Dx11RenderTextureSet::Clear()
{
	Dx11Lock( _context );
	_context->ClearRenderTargetView( _views[0], &_defaultColor.x );
}
