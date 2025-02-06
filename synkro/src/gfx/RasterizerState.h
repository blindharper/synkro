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
// Purpose: Logical rasterizer state.
//==============================================================================
#ifndef _SYNKRO_GFX_RASTERIZERSTATE_
#define _SYNKRO_GFX_RASTERIZERSTATE_


#include "config.h"
#include <core/ObjectImpl.h>
#include <gfx/IRasterizerState.h>


namespace synkro
{


namespace gfx
{


// Program's immediate rasterizer state.
class RasterizerState :
	public core::ObjectImpl<IRasterizerState>
{
public:
	// Constructors.
	RasterizerState( IRasterizerState* state );
	RasterizerState( const RasterizerState& other );

	// IRenderState methods.
	void													Bind();

	// IRasterizerState methods.
	void													SetCullMode( const CullMode& cull );
	void													SetFillMode( const FillMode& fill );
	void													SetDepthBias( Float bias );
	void													SetDepthBiasClamp( Float clamp );
	void													SetSlopeScaledDepthBias( Float bias );
	void													EnableScissor( Bool enable );
	void													EnableMultisample( Bool enable );
	void													EnableAntialiasing( Bool enable );
	CullMode												GetCullMode() const;
	FillMode												GetFillMode() const;
	Float													GetDepthBias() const;
	Float													GetDepthBiasClamp() const;
	Float													GetSlopeScaledDepthBias() const;
	Bool													IsScissorEnabled() const;
	Bool													IsMultisampleEnabled() const;
	Bool													IsAntialiasingEnabled() const;
	IRasterizerState*										Clone() const;

private:
	P(IRasterizerState)										_state;
	Bool													_readonly;
	
	void													PreventModify();
};


#include "RasterizerState.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_RASTERIZERSTATE_
