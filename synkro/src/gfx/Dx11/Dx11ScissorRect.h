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
// Purpose: DX11 based scissor rectangle implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11SCISSORRECT_
#define _SYNKRO_GFX_DX11SCISSORRECT_


#include "config.h"
#include <gfx/RectImpl.h>
#include <gfx/IRect.h>
#undef new
#include "Dx11.h"
#define new SYNKRO_NEW


namespace synkro
{


namespace gfx
{


// DX11 based scissor rectangle.
class Dx11ScissorRect :
	public RectImpl<IRect>
{
public:
	// Constructor.
	Dx11ScissorRect( Dx11Context* context, Int left, Int top, Int right, Int bottom );

	// IRect methods.
	void													Bind();

private:
	Dx11Context												_context;
	D3D11_RECT												_rc;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11SCISSORRECT_
