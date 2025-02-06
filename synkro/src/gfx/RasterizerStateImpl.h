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
// Purpose: Generic rasterizer state implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_RASTERIZERSTATEIMPL_
#define _SYNKRO_GFX_RASTERIZERSTATEIMPL_


#include "config.h"
#include "RenderStateImpl.h"
#include <gfx/CullMode.h>
#include <gfx/FillMode.h>


namespace synkro
{


namespace gfx
{


// Generic rasterizer state implementation.
template <class T>
class RasterizerStateImpl :
	public RenderStateImpl<T>
{
public:
	// Constructor & destructor.
	RasterizerStateImpl();
	virtual ~RasterizerStateImpl();

	// IRasterizerState methods.
	virtual void											SetCullMode( const CullMode& cull );
	virtual void											SetFillMode( const FillMode& fill );
	virtual void											SetDepthBias( Float bias );
	virtual void											SetDepthBiasClamp( Float clamp );
	virtual void											SetSlopeScaledDepthBias( Float bias );
	virtual void											EnableScissor( Bool enable );
	virtual void											EnableMultisample( Bool enable );
	virtual void											EnableAntialiasing( Bool enable );
	virtual CullMode										GetCullMode() const;
	virtual FillMode										GetFillMode() const;
	virtual Float											GetDepthBias() const;
	virtual Float											GetDepthBiasClamp() const;
	virtual Float											GetSlopeScaledDepthBias() const;
	virtual Bool											IsScissorEnabled() const;
	virtual Bool											IsMultisampleEnabled() const;
	virtual Bool											IsAntialiasingEnabled() const;

protected:
	CullMode												_cull;
	FillMode												_fill;
	Float													_depthBias;
	Float													_depthBiasClamp;
	Float													_slopeScaledDepthBias;
	Bool													_scissorEnabled;
	Bool													_multisampleEnabled;
	Bool													_antialiasingEnabled;
};


#include "RasterizerStateImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_RASTERIZERSTATEIMPL_
