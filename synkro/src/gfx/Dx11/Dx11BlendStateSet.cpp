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
#include "config.h"
#include "Dx11BlendStateSet.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Dx11BlendStateSet::Dx11BlendStateSet( Dx11Context* context ) :
	BlendStateSetImpl<IBlendStateSet>( D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT ),
	_context( context ),
	_state( nullptr )
{
	_factors[0] = 1.0f;
	_factors[1] = 1.0f;
	_factors[2] = 1.0f;
	_factors[3] = 1.0f;

	for ( UInt i = 0; i < _states.Capacity(); ++i )
	{
		_states.Add( new BlendStateEx() );
	}
}

Dx11BlendStateSet::Dx11BlendStateSet( const Dx11BlendStateSet& other ) :
	BlendStateSetImpl<IBlendStateSet>( D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT ),
	_context( &other._context ),
	_state( nullptr )
{
	_alphaToCoverageEnabled = other._alphaToCoverageEnabled;
	_factors[0] = other._factors[0];
	_factors[1] = other._factors[1];
	_factors[2] = other._factors[2];
	_factors[3] = other._factors[3];

	for ( UInt i = 0; i < other._states.Size(); ++i )
	{
		_states.Add( ((BlendStateEx*)other._states[i].AsPtr())->Clone() );
	}
}

Dx11BlendStateSet::~Dx11BlendStateSet()
{
	Destroy();
}

void Dx11BlendStateSet::Bind()
{
	if ( IsDirty() )
	{
		Destroy();
		Prepare();
		ResetDirty();
	}

	Dx11Lock( _context );
	_context->OMSetBlendState( _state, _factors, 0xffffffff );
}

IBlendStateSet* Dx11BlendStateSet::Clone() const
{
	return new Dx11BlendStateSet( *this );
}

Bool Dx11BlendStateSet::IsDirty()
{
	if ( _dirty )
		return true;

	for ( UInt i = 0; i < _states.Size(); ++i )
	{
		if ( ((BlendStateEx*)_states[i].AsPtr())->IsDirty() )
			return true;
	}

	return false;
}

void Dx11BlendStateSet::ResetDirty()
{
	_dirty = false;
	for ( UInt i = 0; i < _states.Size(); ++i )
	{
		((BlendStateEx*)_states[i].AsPtr())->ResetDirty();
	}
}

void Dx11BlendStateSet::Destroy()
{
	SafeRelease( _state );
}

void Dx11BlendStateSet::Prepare()
{
	D3D11_BLEND_DESC desc;
	desc.IndependentBlendEnable = TRUE;
	desc.AlphaToCoverageEnable = (BOOL)_alphaToCoverageEnabled;
	for ( UInt i = 0; i < _states.Size(); ++i )
	{
		desc.RenderTarget[i].BlendEnable			= (BOOL)_states[i]->IsEnabled();
		desc.RenderTarget[i].BlendOp				= Dx11::Convert( _states[i]->GetColorOperation() );
		desc.RenderTarget[i].SrcBlend				= Dx11::Convert( _states[i]->GetColorSrcMode() );
		desc.RenderTarget[i].DestBlend				= Dx11::Convert( _states[i]->GetColorDstMode() );
		desc.RenderTarget[i].BlendOpAlpha			= Dx11::Convert( _states[i]->GetAlphaOperation() );
		desc.RenderTarget[i].SrcBlendAlpha			= Dx11::Convert( _states[i]->GetAlphaSrcMode() );
		desc.RenderTarget[i].DestBlendAlpha			= Dx11::Convert( _states[i]->GetAlphaDstMode() );
		desc.RenderTarget[i].RenderTargetWriteMask	= Dx11::Convert( _states[i]->GetWriteChannels() );
	}

	HRESULT hr = S_OK;
	Dx11Lock( _context );
	if ( FAILED(hr = _context.Device()->CreateBlendState(&desc, &_state)) )
		throw GraphicsException( Str::BlendStateCreateFail, String::Format(Str::CallFail, L"ID3D11Device::CreateBlendState()"), Dx11::ToString(hr) );
}


} // gfx


} // synkro
