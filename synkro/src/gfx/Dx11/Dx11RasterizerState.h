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
// Purpose: DX11 based rasterizer state implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11RASTERIZERSTATE_
#define _SYNKRO_GFX_DX11RASTERIZERSTATE_


#include "config.h"
#include <gfx/RasterizerStateImpl.h>
#include <gfx/IRasterizerState.h>
#undef new
#include "Dx11.h"
#define new SYNKRO_NEW

namespace synkro
{


namespace gfx
{


// DX11 based rasterizer state implementation.
class Dx11RasterizerState :
	public RasterizerStateImpl<IRasterizerState>
{
public:
	// Constructors & destructor.
	Dx11RasterizerState( Dx11Context* context );
	Dx11RasterizerState( const Dx11RasterizerState& other );
	~Dx11RasterizerState();

	// IRasterizerState methods.
	void													Bind();
	IRasterizerState*										Clone() const;

private:
	Dx11Context												_context;
	ID3D11RasterizerState*									_state;

	void													Destroy();
	void													Prepare();
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11RASTERIZERSTATE_
