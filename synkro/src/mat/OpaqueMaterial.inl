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
// Purpose: Opaque material implementation.
//==============================================================================
SYNKRO_INLINE IOpaqueMaterial* OpaqueMaterial::AsOpaque() const
{
	return (IOpaqueMaterial*)this;
}

SYNKRO_INLINE void OpaqueMaterial::SetTwoSided( Bool twoSided )
{
	_twoSided = twoSided;
	if ( _rasterizerState != nullptr )
	{
		_rasterizerState->SetCullMode( _twoSided ? gfx::CullMode::None : gfx::CullMode::Back );
	}
}

SYNKRO_INLINE void OpaqueMaterial::SetWireframe( Bool wireframe )
{
	_wireframe = wireframe;
	if ( _rasterizerState != nullptr )
	{
		_rasterizerState->SetFillMode( _wireframe ? gfx::FillMode::Wireframe : gfx::FillMode::Solid );
	}
}

SYNKRO_INLINE Bool OpaqueMaterial::IsTwoSided() const
{
	return (_rasterizerState->GetCullMode() == gfx::CullMode::None);
}

SYNKRO_INLINE Bool OpaqueMaterial::IsWireframe() const
{
	return (_rasterizerState->GetFillMode() == gfx::FillMode::Wireframe);
}

SYNKRO_INLINE IOpaqueMaterial* OpaqueMaterial::Clone() const
{
	return new OpaqueMaterial( *this );
}
