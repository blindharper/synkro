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
// Purpose: Logical depth-stencil state.
//==============================================================================
SYNKRO_INLINE void DepthStencilState::Bind()
{
	SynkroProfile( "DepthStencilState.Bind" );

	_state->Bind();
}

SYNKRO_INLINE void DepthStencilState::EnableDepth( Bool enable )
{
	PreventModify();

	_state->EnableDepth( enable );
}

SYNKRO_INLINE void DepthStencilState::EnableDepthWrite( Bool enable )
{
	PreventModify();

	_state->EnableDepthWrite( enable );
}

SYNKRO_INLINE void DepthStencilState::SetDepthFunction( const CompareFunction& function )
{
	PreventModify();

	_state->SetDepthFunction( function );
}

SYNKRO_INLINE void DepthStencilState::EnableStencil( Bool enable )
{
	PreventModify();

	_state->EnableStencil( enable );
}

SYNKRO_INLINE void DepthStencilState::SetReadMask( Byte mask )
{
	PreventModify();

	_state->SetReadMask( mask );
}

SYNKRO_INLINE void DepthStencilState::SetWriteMask( Byte mask )
{
	PreventModify();

	_state->SetWriteMask( mask );
}

SYNKRO_INLINE void DepthStencilState::SetReference( Byte reference )
{
	PreventModify();

	_state->SetReference( reference );
}

SYNKRO_INLINE void DepthStencilState::SetFailOperation( const StencilOperation& operation )
{
	PreventModify();

	_state->SetFailOperation( operation );
}

SYNKRO_INLINE void DepthStencilState::SetFrontFailOperation( const StencilOperation& operation )
{
	PreventModify();

	_state->SetFrontFailOperation( operation );
}

SYNKRO_INLINE void DepthStencilState::SetBackFailOperation( const StencilOperation& operation )
{
	PreventModify();

	_state->SetBackFailOperation( operation );
}

SYNKRO_INLINE void DepthStencilState::SetDepthFailOperation( const StencilOperation& operation )
{
	PreventModify();

	_state->SetDepthFailOperation( operation );
}

SYNKRO_INLINE void DepthStencilState::SetFrontDepthFailOperation( const StencilOperation& operation )
{
	PreventModify();

	_state->SetFrontDepthFailOperation( operation );
}

SYNKRO_INLINE void DepthStencilState::SetBackDepthFailOperation( const StencilOperation& operation )
{
	PreventModify();

	_state->SetBackDepthFailOperation( operation );
}

SYNKRO_INLINE void DepthStencilState::SetPassOperation( const StencilOperation& operation )
{
	PreventModify();

	_state->SetPassOperation( operation );
}

SYNKRO_INLINE void DepthStencilState::SetFrontPassOperation( const StencilOperation& operation )
{
	PreventModify();

	_state->SetFrontPassOperation( operation );
}

SYNKRO_INLINE void DepthStencilState::SetBackPassOperation( const StencilOperation& operation )
{
	PreventModify();

	_state->SetBackPassOperation( operation );
}

SYNKRO_INLINE void DepthStencilState::SetStencilFunction( const CompareFunction& function )
{
	PreventModify();

	_state->SetStencilFunction( function );
}

SYNKRO_INLINE void DepthStencilState::SetFrontStencilFunction( const CompareFunction& function )
{
	PreventModify();

	_state->SetFrontStencilFunction( function );
}

SYNKRO_INLINE void DepthStencilState::SetBackStencilFunction( const CompareFunction& function )
{
	PreventModify();

	_state->SetBackStencilFunction( function );
}

SYNKRO_INLINE Bool DepthStencilState::IsDepthEnabled() const
{
	return _state->IsDepthEnabled();
}

SYNKRO_INLINE Bool DepthStencilState::IsDepthWriteEnabled() const
{
	return _state->IsDepthWriteEnabled();
}

SYNKRO_INLINE CompareFunction DepthStencilState::GetDepthFunction() const
{
	return _state->GetDepthFunction();
}

SYNKRO_INLINE Bool DepthStencilState::IsStencilEnabled() const
{
	return _state->IsStencilEnabled();
}

SYNKRO_INLINE Byte DepthStencilState::GetReadMask() const
{
	return _state->GetReadMask();
}

SYNKRO_INLINE Byte DepthStencilState::GetWriteMask() const
{
	return _state->GetWriteMask();
}

SYNKRO_INLINE Byte DepthStencilState::GetReference() const
{
	return _state->GetReference();
}

SYNKRO_INLINE StencilOperation DepthStencilState::GetFrontFailOperation() const
{
	return _state->GetFrontFailOperation();
}

SYNKRO_INLINE StencilOperation DepthStencilState::GetBackFailOperation() const
{
	return _state->GetBackFailOperation();
}

SYNKRO_INLINE StencilOperation DepthStencilState::GetFrontDepthFailOperation() const
{
	return _state->GetFrontDepthFailOperation();
}

SYNKRO_INLINE StencilOperation DepthStencilState::GetBackDepthFailOperation() const
{
	return _state->GetBackDepthFailOperation();
}

SYNKRO_INLINE StencilOperation DepthStencilState::GetFrontPassOperation() const
{
	return _state->GetFrontPassOperation();
}

SYNKRO_INLINE StencilOperation DepthStencilState::GetBackPassOperation() const
{
	return _state->GetBackPassOperation();
}

SYNKRO_INLINE CompareFunction DepthStencilState::GetFrontStencilFunction() const
{
	return _state->GetFrontStencilFunction();
}

SYNKRO_INLINE CompareFunction DepthStencilState::GetBackStencilFunction() const
{
	return _state->GetBackStencilFunction();
}

SYNKRO_INLINE IDepthStencilState* DepthStencilState::Clone() const
{
	return new DepthStencilState( *this );
}
