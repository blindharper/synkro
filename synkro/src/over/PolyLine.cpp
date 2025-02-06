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
// Purpose: PolyLine implementation.
//==============================================================================
#include "config.h"
#include "PolyLine.h"
#include <gfx/IOverlayRenderQueue.h>
#include <gfx/IGraphicsSystemEx.h>
#include <gfx/IGraphicsDeviceEx.h>
#include <gfx/IProgramStage.h>
#include <gfx/IProgram.h>
#include <gfx/IPrimitiveEx.h>
#include <gfx/IVector4Stream.h>
#include <lang/Vector.h>
#include <math/Math.h>


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


PolyLine::PolyLine( IOverlayRenderQueue* queue, IGraphicsSystemEx* graphicsSystem, IBlendStateSet* blendStates, UInt pointCount, UInt width, const Color& color ) :
	_blendStates( blendStates ),
	_paramColor( nullptr ),
	_color( Color::White ),
	_opacity( 0.0f ),
	_groupOrder( Order::Normal ),
	_order( Order::Normal ),
	_pointCount( pointCount ),
	_width( width )
{
	IProgram* program = graphicsSystem->GetProgram( L"overlay.monochrome" );
	_fragmentParams = program->GetFragmentStage()->GetParameters()->Clone( this->ID(), true );
	_paramColor = _fragmentParams->GetParam( L"p_color" );

	IPrimitive* data = graphicsSystem->GetDevice()->CreatePrimitive( program, DataUsage::Dynamic, DataAccess::WriteOnly, PrimitiveType::LineList, IndexType::None, 2*_pointCount*_width, 0, 0, 0, true, false );
	_polyline = queue->CreateObject( data );
	_polyline->SetOrder( Order::GetValue(_groupOrder, _order) );
	_polyline->SetBlendStates( _blendStates );
	_polyline->SetFragmentParameters( _fragmentParams );

	SetOpacity( 1.0f );
	SetColor( color );
}

PolyLine::PolyLine( IOverlayRenderQueue* queue, IGraphicsSystemEx* graphicsSystem, IBlendStateSet* blendStates, UInt pointCount, UInt width ) :
	_blendStates( blendStates ),
	_paramColor( nullptr ),
	_color( Color::White ),
	_opacity( 0.0f ),
	_groupOrder( Order::Normal ),
	_order( Order::Normal ),
	_pointCount( pointCount ),
	_width( width )
{
	IProgram* program = graphicsSystem->GetProgram( L"overlay.colored" );
	IPrimitive* data = graphicsSystem->GetDevice()->CreatePrimitive( program, DataUsage::Dynamic, DataAccess::WriteOnly, PrimitiveType::LineList, IndexType::None, 2*_pointCount*_width, 0, 0, 0, true, false );
	_polyline = queue->CreateObject( data );
	_polyline->SetOrder( Order::GetValue(_groupOrder, _order) );
	_polyline->SetBlendStates( _blendStates );

	SetOpacity( 1.0f );
	SetColor( Color::White );
}

void PolyLine::SetPositions( const Point* positions )
{
	P(IVector4Stream) stream = (IVector4Stream*)_polyline->GetData()->GetVertexStream( DataStream::Position2D, 0 );
	if ( (stream != nullptr) && stream->Open(OpenMode::Write) )
	{
		Vector<Vector4> data( A(Vector4) );
		for ( UInt i = 0; i < _pointCount-1; ++i )
		{
			const Float startX = CastFloat(positions[i].X);
			const Float startY = CastFloat(positions[i].Y);
			const Float endX = CastFloat(positions[i+1].X);
			const Float endY = CastFloat(positions[i+1].Y);
			const Float tan = (endX != startX) ? (endY-startY)/(endX-startX) : Math::MaxFloat;
			const Float angle = Math::ToDegrees( Math::Atan(tan) );
			if ( Math::Abs(angle) <= 45.0f )
			{
				const Float startY0 = startY-_width/2;
				const Float endY0 = endY-_width/2;
				for ( UInt k = 0; k < _width; ++k )
				{
					data.Add( Vector4(startX, startY0+k, 0.0f, 1.0f) );
					data.Add( Vector4(endX, endY0+k, 0.0f, 1.0f) );
				}
			}
			else
			{
				const Float startX0 = startX-_width/2;
				const Float endX0 = endX-_width/2;
				for ( UInt k = 0; k < _width; ++k )
				{
					data.Add( Vector4(startX0+k, startY, 0.0f, 1.0f) );
					data.Add( Vector4(endX0+k, endY, 0.0f, 1.0f) );
				}
			}
		}
		stream->Write( data.Begin(), data.Size() );
		stream->Close();
	}
}

void PolyLine::SetColors( const Color* colors )
{
	if ( _fragmentParams != nullptr )
	{
		_fragmentParams->Set( _paramColor, ToVector(colors[0], _opacity) );
	}
	else
	{
		P(IVector4Stream) stream = (IVector4Stream*)_polyline->GetData()->GetVertexStream( DataStream::Color, 0 );
		if ( (stream != nullptr) && stream->Open(OpenMode::Write) )
		{
			Vector<Vector4> data( A(Vector4) );
			for ( UInt i = 0; i < _pointCount-1; ++i )
			{
				for ( UInt k = 0; k < _width; ++k )
				{
					data.Add( ToVector(colors[i], _opacity) );
					data.Add( ToVector(colors[i+1], _opacity) );
				}
			}
			stream->Write( data.Begin(), data.Size() );
			stream->Close();
		}
	}
}

void PolyLine::SetColor( const Color& color )
{
	if ( color != _color )
	{
		if ( _fragmentParams != nullptr )
		{
			_fragmentParams->Set( _paramColor, ToVector(color, _opacity) );
		}
		else
		{
			P(IVector4Stream) stream = (IVector4Stream*)_polyline->GetData()->GetVertexStream( DataStream::Color, 0 );
			if ( (stream != nullptr) && stream->Open(OpenMode::Write) )
			{
				stream->Set( ToVector(color, _opacity), _pointCount*_width );
				stream->Close();
			}
		}
		_color = color;
	}
}

void PolyLine::SetOpacity( Float opacity )
{
	if ( opacity != _opacity )
	{
		if ( _fragmentParams != nullptr )
		{
			_fragmentParams->Set( _paramColor, ToVector(_color, opacity) );
		}
		_opacity = opacity;
	}
}


} // over


} // synkro
