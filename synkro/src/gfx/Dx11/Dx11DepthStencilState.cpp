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
// Purpose: DX11 based depth-stencil state implementation.
//==============================================================================
#include "config.h"
#include "Dx11DepthStencilState.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Dx11DepthStencilState::Dx11DepthStencilState( Dx11Context* context ) :
	_context( context ),
	_state( nullptr )
{
}

Dx11DepthStencilState::Dx11DepthStencilState( const Dx11DepthStencilState& other ) :
	_context( &other._context ),
	_state( nullptr )
{
	_dirty					= true;
	_depthEnabled			= other._depthEnabled;
	_depthWriteEnabled		= other._depthWriteEnabled;
	_depthFunction			= other._depthFunction;
	_stencilEnabled			= other._stencilEnabled;
	_maskRead				= other._maskRead;
	_maskWrite				= other._maskWrite;
	_reference				= other._reference;
	_frontFailOp			= other._frontFailOp;
	_frontDepthFailOp		= other._frontDepthFailOp;
	_frontPassOp			= other._frontPassOp;
	_frontStencilFunction	= other._frontStencilFunction;
	_backFailOp				= other._backFailOp;
	_backDepthFailOp		= other._backDepthFailOp;
	_backPassOp				= other._backPassOp;
	_backStencilFunction	= other._backStencilFunction;
}

Dx11DepthStencilState::~Dx11DepthStencilState()
{
	Destroy();
}

void Dx11DepthStencilState::Bind()
{
	if ( _dirty )
	{
		Destroy();
		Prepare();
		_dirty = false;
	}

	Dx11Lock( _context );
	_context->OMSetDepthStencilState( _state, (UINT)_reference );
}

IDepthStencilState* Dx11DepthStencilState::Clone() const
{
	return new Dx11DepthStencilState( *this );
}

void Dx11DepthStencilState::Destroy()
{
	SafeRelease( _state );
}

void Dx11DepthStencilState::Prepare()
{
	HRESULT hr = S_OK;

	D3D11_DEPTH_STENCIL_DESC desc;
	desc.DepthEnable					= _depthEnabled ? TRUE : FALSE;
	desc.DepthWriteMask					= _depthWriteEnabled ? D3D11_DEPTH_WRITE_MASK_ALL : D3D11_DEPTH_WRITE_MASK_ZERO;
	desc.DepthFunc						= Dx11::Convert( _depthFunction );
	desc.StencilEnable					= _stencilEnabled ? TRUE : FALSE;
	desc.StencilReadMask				= _maskRead;
	desc.StencilWriteMask				= _maskWrite;
	desc.FrontFace.StencilFailOp		= Dx11::Convert( _frontFailOp );
	desc.FrontFace.StencilDepthFailOp	= Dx11::Convert( _frontDepthFailOp );
	desc.FrontFace.StencilPassOp		= Dx11::Convert( _frontPassOp );
	desc.FrontFace.StencilFunc			= Dx11::Convert( _frontStencilFunction );
	desc.BackFace.StencilFailOp			= Dx11::Convert( _backFailOp );
	desc.BackFace.StencilDepthFailOp	= Dx11::Convert( _backDepthFailOp );
	desc.BackFace.StencilPassOp			= Dx11::Convert( _backPassOp );
	desc.BackFace.StencilFunc			= Dx11::Convert( _backStencilFunction );

	if ( FAILED(hr = _context.Device()->CreateDepthStencilState(&desc, &_state)) )
		throw GraphicsException( Str::DepthStencilStateCreateFail, String::Format(Str::CallFail, L"ID3D11Device::CreateDepthStencilState()"), Dx11::ToString(hr) );
}


} // gfx


} // synkro
