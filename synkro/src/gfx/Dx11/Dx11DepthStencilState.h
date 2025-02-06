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
// Purpose: DX11 based depth-stencil state implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11DEPTHSTENCILSTATE_
#define _SYNKRO_GFX_DX11DEPTHSTENCILSTATE_


#include "config.h"
#include <gfx/DepthStencilStateImpl.h>
#include <gfx/IDepthStencilState.h>
#undef new
#include "Dx11.h"
#define new SYNKRO_NEW


namespace synkro
{


namespace gfx
{


// DX11 based depth-stencil state implementation.
class Dx11DepthStencilState :
	public DepthStencilStateImpl<IDepthStencilState>
{
public:
	// Constructors & destructor.
	Dx11DepthStencilState( Dx11Context* context );
	Dx11DepthStencilState( const Dx11DepthStencilState& other );
	~Dx11DepthStencilState();

	// IDepthStencilState methods.
	void													Bind();
	IDepthStencilState*										Clone() const;

private:
	Dx11Context												_context;
	ID3D11DepthStencilState*								_state;

	void													Destroy();
	void													Prepare();
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11DEPTHSTENCILSTATE_
