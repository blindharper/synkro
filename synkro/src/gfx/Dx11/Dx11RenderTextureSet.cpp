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
#include "config.h"
#include "Dx11RenderTextureSet.h"
#include "Dx11BaseRenderTexture.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Dx11RenderTextureSet::Dx11RenderTextureSet( Dx11Context* context, UInt size ) :
	_views( A(ID3D11RenderTargetView*) ),
	_context( context )
{
	_textures.SetSize( size );
}

void Dx11RenderTextureSet::Set( UInt index, IRenderTexture* texture )
{
	// Call base implementation.
	RenderTextureSetImpl<IRenderTextureSet>::Set( index, texture );

	if ( texture != nullptr )
	{
		Dx11BaseRenderTexture* tex = AsDx11BaseRenderTexture( texture );
		_views[index] = tex->AsDx11RenderTargetView();
	}
	else
	{
		_views[index] = nullptr;
	}
}


} // gfx


} // synkro
