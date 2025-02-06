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
// Purpose: DX11 based sampler state implementation.
//==============================================================================
#include "config.h"
#include "Dx11SamplerState.h"
#include "Dx11.h"
#include <float.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Dx11SamplerState::Dx11SamplerState( ID3D11Device* device ) :
	_device( device ),
	_state( nullptr )
{
}

Dx11SamplerState::Dx11SamplerState( const Dx11SamplerState& other ) :
	_device( other._device ),
	_state( nullptr )
{
	_dirty			= true;
	_filterMin		= other._filterMin;
	_filterMag		= other._filterMag;
	_filterMip		= other._filterMip;
	_anisotropy		= other._anisotropy;
	_addressU		= other._addressU;
	_addressV		= other._addressV;
	_addressW		= other._addressW;
	_borderColor	= other._borderColor;
}

Dx11SamplerState::~Dx11SamplerState()
{
	Destroy();
}

ISamplerState* Dx11SamplerState::Clone() const
{
	return new Dx11SamplerState( *this );
}

void Dx11SamplerState::Destroy()
{
	SafeRelease( _state );
}

void Dx11SamplerState::Prepare()
{
	HRESULT hr = S_OK;

	D3D11_SAMPLER_DESC desc;
	desc.Filter			= Dx11::Convert( _filterMin, _filterMag, _filterMip );
	desc.MaxAnisotropy	= (UINT)_anisotropy;
	desc.AddressU		= Dx11::Convert( _addressU );
	desc.AddressV		= Dx11::Convert( _addressV );
	desc.AddressW		= Dx11::Convert( _addressW );
	desc.BorderColor[0]	= _borderColor.x;
	desc.BorderColor[1]	= _borderColor.y;
	desc.BorderColor[2]	= _borderColor.z;
	desc.BorderColor[3]	= _borderColor.w;
	desc.MipLODBias		= 0.0f;
	desc.ComparisonFunc	= D3D11_COMPARISON_NEVER;
	desc.MinLOD			= 0.0f;
	desc.MaxLOD			= FLT_MAX;
	
	if ( FAILED(hr = _device->CreateSamplerState(&desc, &_state)) )
		throw GraphicsException( Str::SamplerStateCreateFail, String::Format(Str::CallFail, L"ID3D11Device::CreateSamplerState()"), Dx11::ToString(hr) );
}

ID3D11SamplerState* Dx11SamplerState::GetState()
{
	if ( _dirty )
	{
		Destroy();
		Prepare();
		_dirty = false;
	}

	return _state;
}


} // gfx


} // synkro
