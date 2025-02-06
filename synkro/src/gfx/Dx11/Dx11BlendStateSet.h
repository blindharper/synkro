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
// Purpose: Implements DX11 based blend state set.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11BLENDSTATESET_
#define _SYNKRO_GFX_DX11BLENDSTATESET_


#include "config.h"
#include <gfx/BlendStateSetImpl.h>
#include <gfx/IBlendStateSet.h>
#undef new
#include "Dx11.h"
#define new SYNKRO_NEW


namespace synkro
{


namespace gfx
{


// DX11 based blend state set implementation.
class Dx11BlendStateSet :
	public BlendStateSetImpl<IBlendStateSet>
{
public:
	// Constructors & destructor.
	Dx11BlendStateSet( Dx11Context* context );
	Dx11BlendStateSet( const Dx11BlendStateSet& other );
	~Dx11BlendStateSet();

	// IRenderState methods.
	void													Bind();

	// IBlendStateSet methods.
	IBlendStateSet*											Clone() const;

private:
	Dx11Context												_context;
	ID3D11BlendState*										_state;
	FLOAT													_factors[4];

	Bool													IsDirty();
	void													ResetDirty();
	void													Destroy();
	void													Prepare();
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11BLENDSTATESET_
