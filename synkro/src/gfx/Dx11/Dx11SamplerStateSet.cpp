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
// Purpose: DX11 sampler state set implementation.
//==============================================================================
#include "config.h"
#include "Dx11SamplerStateSet.h"
#include <gfx/ProgramStageTypeConst.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Dx11SamplerStateSet::Dx11SamplerStateSet( Dx11Context* context, ID3D11ShaderReflection* reflect, const ProgramStageType& type, UINT startSlot ) :
	SamplerStateSetImpl<ISamplerStateSet>( type ),
	_samplers( A(ID3D11SamplerState*) ),
	_startSlot( startSlot ),
	_context( context )
{
	D3D11_SHADER_DESC desc;
	reflect->GetDesc( &desc );
	for ( UINT i = 0; i < desc.BoundResources; ++i )
	{
		D3D11_SHADER_INPUT_BIND_DESC paramDesc;
		reflect->GetResourceBindingDesc( i, &paramDesc );
		switch ( paramDesc.Type )
		{
			case D3D10_SIT_SAMPLER:
				_states.Add( new Dx11SamplerState(_context.Device()) );
				_samplers.Add( nullptr );
				break;

			default:
				break;
		}
	}
}

Dx11SamplerStateSet::Dx11SamplerStateSet( const Dx11SamplerStateSet& other ) :
	SamplerStateSetImpl<ISamplerStateSet>( other._type ),
	_samplers( other._samplers ),
	_startSlot( other._startSlot ),
	_context( &other._context )
{
	for ( UInt i = 0; i < other._states.Size(); ++i )
	{
		_states.Add( ((Dx11SamplerState*)other._states[i].AsPtr())->Clone() );
	}
}

void Dx11SamplerStateSet::Bind()
{
	for ( UInt i = 0; i < _states.Size(); ++i )
	{
		_samplers[i] = ((Dx11SamplerState*)_states[i].AsPtr())->GetState();
	}

	if ( _states.Size() > 0 )
	{
		Dx11Lock( _context );
		switch ( _type )
		{
			case PROGRAM_STAGE_TYPE_VERTEX:
				_context->VSSetSamplers( _startSlot, _states.Size(), _samplers.Begin() );
				break;

			case PROGRAM_STAGE_TYPE_HULL:
				_context->HSSetSamplers( _startSlot, _states.Size(), _samplers.Begin() );
				break;

			case PROGRAM_STAGE_TYPE_DOMAIN:
				_context->DSSetSamplers( _startSlot, _states.Size(), _samplers.Begin() );
				break;

			case PROGRAM_STAGE_TYPE_GEOMETRY:
				_context->GSSetSamplers( _startSlot, _states.Size(), _samplers.Begin() );
				break;

			case PROGRAM_STAGE_TYPE_FRAGMENT:
				_context->PSSetSamplers( _startSlot, _states.Size(), _samplers.Begin() );
				break;
		}
	}
}

ISamplerStateSet* Dx11SamplerStateSet::Clone( UInt ownerID ) const
{
	return new Dx11SamplerStateSet( *this );
}


} // gfx


} // synkro
