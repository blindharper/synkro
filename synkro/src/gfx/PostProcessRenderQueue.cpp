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
// Purpose: Post-processing rendering queue implementation.
//==============================================================================
#include "config.h"
#include "PostProcessRenderQueue.h"
#include "PostProcessRenderObject.h"
#include "RenderView.h"
#include "SamplerStateSet.h"
#include "ResourceSet.h"
#include "ParameterSet.h"
#include "Program.h"
#include <gfx/IRect.h>
#include <gfx/IProgramStage.h>
#include <gfx/IGraphicsDevice.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


PostProcessRenderItem::PostProcessRenderItem( PostProcessRenderObject* object ) :
	Object( object ),
	Program( (gfx::Program*)object->GetProgram() ),
	StencilState( nullptr ),
	FragmentParams( nullptr ),
	FragmentResources( nullptr ),
	FragmentSamplers( nullptr ),
	PassCount( 1 )
{
}

PostProcessRenderItem::PostProcessRenderItem() :
	Object( nullptr ),
	Program( nullptr ),
	StencilState( nullptr ),
	FragmentParams( nullptr ),
	FragmentResources( nullptr ),
	FragmentSamplers( nullptr ),
	PassCount( 1 )
{
}

Bool PostProcessRenderItem::operator<( const PostProcessRenderItem& other ) const
{
	return this->Object->GetOrder() < other.Object->GetOrder();
}

//------------------------------------------------------------------------------


PostProcessRenderQueue::PostProcessRenderQueue( IGraphicsDevice* device, RenderView* view, IProgram* programPass ) :
	_items( A(PostProcessRenderItem) ),
	_view( view ),
	_programPass( programPass ),
	_input( nullptr ),
	_dirty( true )
{
	// Initialize shared stuff.
	_blendStates = (BlendStateSet*)device->GetBlendStates()->Clone();
	_blendStates->Get(0)->Enable( false );

	_stencilState = (DepthStencilState*)device->GetDepthStencilState()->Clone();
	_stencilState->EnableDepth( false );
	_stencilState->EnableStencil( false );

	_rasterizerState = (RasterizerState*)device->GetRasterizerState()->Clone();
	_rasterizerState->SetFillMode( FillMode::Solid );
	_rasterizerState->SetCullMode( CullMode::Back );
	_rasterizerState->EnableScissor( false );

	_rasterizerStateScissor = (RasterizerState*)device->GetRasterizerState()->Clone();
	_rasterizerStateScissor->SetFillMode( FillMode::Solid );
	_rasterizerStateScissor->SetCullMode( CullMode::Back );
	_rasterizerStateScissor->EnableScissor( true );
}

IPostProcessRenderObject* PostProcessRenderQueue::CreateObject( IProgram* program )
{
	PostProcessRenderObject* object = new PostProcessRenderObject( this, program, _items.Size() );
	_items.Add( PostProcessRenderItem(object) );
	return object;
}

UInt PostProcessRenderQueue::Process( RenderChain* chain, IPlainRenderTexture* colorTarget )
{
	SynkroProfile( "PostProcessRenderQueue.Process" );

	RasterizerState* rasterizerState = nullptr;
	DepthStencilState* stencilState = nullptr;

	// Ignore empty queue.
	if ( _items.IsEmpty() )
		return 0;

	// Reset rendering stats.
	UInt primitiveCount = 0;

	// Re-sort "_items" by z-order.
	if ( _dirty )
	{
		_items.Sort();
		_dirty = false;
	}

	// Bind shared stuff.
	_view->GetQuadData()->GetInputBuffers()->Bind();
	_blendStates->Bind();
	_stencilState->Bind();

	for ( UInt i = 0; i < _items.Size(); ++i )
	{
		// Skip disabled items.
		if ( !_items[i].Object->IsEnabled() )
			continue;

		// Validate item if needed.
		if ( _items[i].Object->IsDirty() )
		{
			ValidateItem( _items[i] );
			_items[i].Object->ResetDirty();
		}

		// Bind constant stuff.
		_items[i].FragmentSamplers->Bind();
		if ( stencilState != _items[i].StencilState )
		{
			stencilState = _items[i].StencilState;
			stencilState->Bind();
		}

		// Determine input for the effect.
		IResource* input = (i == 0) ? _input : _items[i].Object->GetInput();
		IDepthTexture* inputDepthTexture = nullptr;

		// Draw passes.
		for ( UInt p = 0; p < _items[i].Object->GetPassCount(); ++p )
		{
			Bool bound = false;
			Bool lastPass = (p == _items[i].Object->GetPassCount() - 1);

			// Handle filter with scissor rectangle enabled.
			if ( lastPass && (_items[i].Object->GetScissorRect() != nullptr) )
			{
				_programPass->Bind();
				_rasterizerState->Bind();
				rasterizerState = _rasterizerState;
				if ( bound = chain->Begin(nullptr) )
				{
					IResource* inputPass = (i == 0) ? _input : _items[i].Object->GetInput();
					IResource* inputRes = (inputPass != nullptr) ? inputPass : chain->GetBackBuffer();
					inputDepthTexture = inputRes->AsDepthTexture();
					if ( inputDepthTexture != nullptr )
					{
						colorTarget->UnbindDepthTexture();
					}
					_items[i].FragmentResources->Set( 0, inputRes );
					_items[i].FragmentResources->SetDirty();
					_items[i].FragmentResources->Bind();
					primitiveCount += _view->GetQuadData()->Draw( 0, 4, 0, 0 );
					if ( inputDepthTexture != nullptr )
					{
						_items[i].FragmentResources->Unbind();
					}
					chain->Present();
				}
				_items[i].Object->GetScissorRect()->Bind();
			}
			_items[i].Program->Bind();
			_items[i].FragmentParams->Bind();

			// Bind states.
			if ( rasterizerState != _items[i].RasterizerState )
			{
				rasterizerState = _items[i].RasterizerState;
				rasterizerState->Bind();
			}

			if ( bound || chain->Begin(lastPass ? _items[i].Object->GetTarget() : nullptr) )
			{
				// Bind fragment stage stuff.
				if ( !bound )
				{
					IResource* inputRes = (input != nullptr) ? input : chain->GetBackBuffer();
					inputDepthTexture = inputRes->AsDepthTexture();
					if ( inputDepthTexture != nullptr )
					{
						colorTarget->UnbindDepthTexture();
					}
					_items[i].FragmentResources->Set( 0, inputRes );
					_items[i].FragmentResources->SetDirty();
					_items[i].FragmentResources->Bind();
				}
				input = nullptr;

				// Perform processing.
				primitiveCount += _view->GetQuadData()->Draw( 0, 4, 0, 0 );

				// Unbind resource from input as it will be used as rendering target.
				if ( inputDepthTexture != nullptr )
				{
					_items[i].FragmentResources->Unbind();
				}

				// Present rendering results to the current target.
				chain->End();
				bound = false;
			}
		}
		// Unbind resource from input as it will be used as rendering target.
		if ( inputDepthTexture == nullptr )
		{
			_items[i].FragmentResources->Unbind();
		}
	}

	return primitiveCount;
}

void PostProcessRenderQueue::Resize()
{
	for ( UInt i = 0; i < _items.Size(); ++i )
	{
		_items[i].FragmentResources->Set( 0, nullptr );
		_items[i].FragmentResources->SetDirty();
	}
}

Bool PostProcessRenderQueue::TargetExists( IPlainRenderTexture* target ) const
{
	if ( target != nullptr )
	{
		for ( UInt i = 0; i < _items.Size(); ++i )
		{
			if ( _items[i].Object->GetTarget() == target )
				return true;
		}
	}
	return false;
}

void PostProcessRenderQueue::ValidateItem( PostProcessRenderItem& item )
{
	PostProcessRenderObject* obj = item.Object;

	// Validate states.
	if ( obj->GetScissorRect() != nullptr )
		item.RasterizerState = (RasterizerState*)_rasterizerStateScissor;
	else
		item.RasterizerState = (RasterizerState*)_rasterizerState;

	if ( obj->GetStencilState() != nullptr )
		item.StencilState = (DepthStencilState*)obj->GetStencilState();
	else
		item.StencilState = _stencilState;

	// Validate fragment stage inputs.
	if ( obj->GetFragmentParameters() != nullptr )
		item.FragmentParams = (ParameterSet*)obj->GetFragmentParameters();
	else if ( obj->GetProgram() != nullptr )
		item.FragmentParams = (ParameterSet*)obj->GetProgram()->GetFragmentStage()->GetParameters();
	else
		item.FragmentParams = (ParameterSet*)obj->GetData()->GetProgram()->GetFragmentStage()->GetParameters();

	if ( obj->GetFragmentResources() != nullptr )
	{
		item.FragmentResources = (ResourceSet*)obj->GetFragmentResources();
	}
	else if ( item.FragmentResources == nullptr )
	{
		if ( obj->GetProgram() != nullptr )
			item.FragmentResources = (ResourceSet*)obj->GetProgram()->GetFragmentStage()->GetResources()->Clone( obj->ID() );
		else
			item.FragmentResources = (ResourceSet*)obj->GetData()->GetProgram()->GetFragmentStage()->GetResources()->Clone( obj->ID() );
	}

	if ( obj->GetFragmentSamplers() != nullptr )
		item.FragmentSamplers = (SamplerStateSet*)obj->GetFragmentSamplers();
	else if ( obj->GetProgram() != nullptr )
		item.FragmentSamplers = (SamplerStateSet*)obj->GetProgram()->GetFragmentStage()->GetSamplers();
	else
		item.FragmentSamplers = (SamplerStateSet*)obj->GetData()->GetProgram()->GetFragmentStage()->GetSamplers();
}


} // gfx


} // synkro
