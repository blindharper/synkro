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
#include "config.h"
#include "Dx11RasterizerState.h"
#include "Dx11.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Dx11RasterizerState::Dx11RasterizerState( Dx11Context* context ) :
	_context( context ),
	_state( nullptr )
{
}

Dx11RasterizerState::Dx11RasterizerState( const Dx11RasterizerState& other ) :
	_context( &other._context ),
	_state( nullptr )
{
	_dirty					= true;
	_cull					= other._cull;
	_fill					= other._fill;
	_depthBias				= other._depthBias;
	_depthBiasClamp			= other._depthBiasClamp;
	_slopeScaledDepthBias	= other._slopeScaledDepthBias;
	_scissorEnabled			= other._scissorEnabled;
	_multisampleEnabled		= other._multisampleEnabled;
	_antialiasingEnabled	= other._antialiasingEnabled;
}

Dx11RasterizerState::~Dx11RasterizerState()
{
	Destroy();
}

void Dx11RasterizerState::Bind()
{
	if ( _dirty )
	{
		Destroy();
		Prepare();
		_dirty = false;
	}

	Dx11Lock( _context );
	_context->RSSetState( _state );
}

IRasterizerState* Dx11RasterizerState::Clone() const
{
	return new Dx11RasterizerState( *this );
}

void Dx11RasterizerState::Destroy()
{
	SafeRelease( _state );
}

void Dx11RasterizerState::Prepare()
{
	HRESULT hr = S_OK;

	D3D11_RASTERIZER_DESC desc;
	desc.FillMode				= Dx11::Convert( _fill );
	desc.CullMode				= Dx11::Convert( _cull );
	desc.FrontCounterClockwise	= FALSE;
	desc.DepthBias				= _depthBias;
	desc.DepthBiasClamp			= _depthBiasClamp;
	desc.SlopeScaledDepthBias	= _slopeScaledDepthBias;
	desc.DepthClipEnable		= TRUE;
	desc.ScissorEnable			= _scissorEnabled;
	desc.MultisampleEnable		= _multisampleEnabled;
	desc.AntialiasedLineEnable	= _antialiasingEnabled;

	if ( FAILED(hr = _context.Device()->CreateRasterizerState(&desc, &_state)) )
		throw GraphicsException( Str::RasterizerStateCreateFail, String::Format(Str::CallFail, L"ID3D11Device::CreateRasterizerState()"), Dx11::ToString(hr) );
}


} // gfx


} // synkro
