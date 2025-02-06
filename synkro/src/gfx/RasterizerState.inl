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
SYNKRO_INLINE void RasterizerState::Bind()
{
	SynkroProfile( "RasterizerState.Bind" );

	_state->Bind();
}

SYNKRO_INLINE void RasterizerState::SetCullMode( const CullMode& cull )
{
	PreventModify();

	_state->SetCullMode( cull );
}

SYNKRO_INLINE void RasterizerState::SetFillMode( const FillMode& fill )
{
	PreventModify();

	_state->SetFillMode( fill );
}

SYNKRO_INLINE void RasterizerState::SetDepthBias( Float bias )
{
	PreventModify();

	_state->SetDepthBias( bias );
}

SYNKRO_INLINE void RasterizerState::SetDepthBiasClamp( Float clamp )
{
	PreventModify();

	_state->SetDepthBiasClamp( clamp );
}

SYNKRO_INLINE void RasterizerState::SetSlopeScaledDepthBias( Float bias )
{
	PreventModify();
	
	_state->SetSlopeScaledDepthBias( bias );
}

SYNKRO_INLINE void RasterizerState::EnableScissor( Bool enable )
{
	PreventModify();

	_state->EnableScissor( enable );
}

SYNKRO_INLINE void RasterizerState::EnableMultisample( Bool enable )
{
	PreventModify();

	_state->EnableMultisample( enable );
}

SYNKRO_INLINE void RasterizerState::EnableAntialiasing( Bool enable )
{
	PreventModify();

	_state->EnableAntialiasing( enable );
}

SYNKRO_INLINE CullMode RasterizerState::GetCullMode() const
{
	return _state->GetCullMode();
}

SYNKRO_INLINE FillMode RasterizerState::GetFillMode() const
{
	return _state->GetFillMode();
}

SYNKRO_INLINE Float RasterizerState::GetDepthBias() const
{
	return _state->GetDepthBias();
}

SYNKRO_INLINE Float RasterizerState::GetDepthBiasClamp() const
{
	return _state->GetDepthBiasClamp();
}

SYNKRO_INLINE Float RasterizerState::GetSlopeScaledDepthBias() const
{
	return _state->GetSlopeScaledDepthBias();
}

SYNKRO_INLINE Bool RasterizerState::IsScissorEnabled() const
{
	return _state->IsScissorEnabled();
}

SYNKRO_INLINE Bool RasterizerState::IsMultisampleEnabled() const
{
	return _state->IsMultisampleEnabled();
}

SYNKRO_INLINE Bool RasterizerState::IsAntialiasingEnabled() const
{
	return _state->IsAntialiasingEnabled();
}

SYNKRO_INLINE IRasterizerState* RasterizerState::Clone() const
{
	return new RasterizerState( *this );
}
