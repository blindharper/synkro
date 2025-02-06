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
// Purpose: Quad implementation.
//==============================================================================
#include "config.h"
#include "Quad.h"
#include <gfx/IOverlayRenderQueue.h>
#include <gfx/IProgramStage.h>
#include <gfx/IProgram.h>
#include <gfx/IPrimitiveEx.h>
#include <gfx/IVector4Stream.h>


//------------------------------------------------------------------------------

using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace over
{


Quad::Quad( IOverlayRenderQueue* queue, IGraphicsSystemEx* graphicsSystem, IBlendStateSet* blendStates, const Order& groupOrder, const Order& order, const Point& location, const Size& size, const Color& color, Ndc* ndc ) :
	_graphicsSystem( graphicsSystem ),
	_blendStates( blendStates ),
	_paramOffset( nullptr ),
	_paramColor( nullptr ),
	_rectEnabled( false ),
	_color( Color::Black ),
	_opacity( 0.0f ),
	_groupOrder( groupOrder ),
	_order( order ),
	_ndc( ndc )
{
	IProgram* program = _graphicsSystem->GetProgram( "overlay.monochrome" );
	_vertexParams = program->GetVertexStage()->GetParameters()->Clone( this->ID(), true );
	_fragmentParams = program->GetFragmentStage()->GetParameters()->Clone( this->ID(), true );
	_paramOffset = _vertexParams->GetParam( L"p_offset" );
	_paramColor = _fragmentParams->GetParam( L"p_color" );

	IPrimitive* data = _graphicsSystem->GetDevice()->CreatePrimitive( program, DataUsage::Dynamic, DataAccess::WriteOnly, PrimitiveType::TriangleStrip, IndexType::None, 4, 0, 0, 0, true, false );
	_quad = queue->CreateObject( data );
	_quad->SetOrder( Order::GetValue(_groupOrder, _order) );
	_quad->SetBlendStates( _blendStates );
	_quad->SetVertexParameters( _vertexParams );
	_quad->SetFragmentParameters( _fragmentParams );

	SetLocation( location );
	SetSize( size );
	SetColor( color );
	SetOpacity( 1.0f );
}

void Quad::SetSize( const Size& size )
{
	if ( size != _size )
	{
		P(IVector4Stream) stream = (IVector4Stream*)_quad->GetData()->GetVertexStream( DataStream::Position2D, 0 );
		if ( (stream != nullptr) && stream->Open(OpenMode::Write) )
		{
			const Float width = CastFloat(size.Width);
			const Float height = CastFloat(size.Height);

			Vector4 pos[] =
			{
				Vector4( 0.0f,	0.0f,	0.0f, 1.0f ),
				Vector4( 0.0f,	height,	0.0f, 1.0f ),
				Vector4( width,	0.0f,	0.0f, 1.0f ),
				Vector4( width,	height,	0.0f, 1.0f ),
			};

			stream->Write( pos, 4 );
			stream->Close();
		}
		_size = size;
	}
}

void Quad::Update( Bool validateOffset )
{
	if ( validateOffset )
	{
		_vertexParams->Set( _paramOffset, _ndc->Convert(Vector2(CastFloat(_location.X), CastFloat(_location.Y))) );
	}
}


} // over


} // synkro
