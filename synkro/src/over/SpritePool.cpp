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
// Purpose: Sprite pool implementation.
//==============================================================================
#include "config.h"
#include "SpritePool.h"
#include "PoolSprite.h"
#include <gfx/IOverlayRenderQueue.h>
#include <gfx/IProgramStage.h>
#include <gfx/IProgram.h>
#include <gfx/IPrimitiveEx.h>
#include <gfx/IVector4Stream.h>
#include <gfx/IRenderWindow.h>
#include <math/Math.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
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


SpritePool::SpritePool( IOverlayRenderQueue* queue, IContext* context, IBlendStateSet* blendStates, IImage* image, const Order& groupOrder, const Order& order, UInt capacity ) :
	_sprites( A(P(PoolSprite)), capacity ),
	_context( context ),
	_blendStates( blendStates ),
	_image( image ),
	_rectEnabled( false ),
	_groupOrder( groupOrder ),
	_order( order ),
	_dirty( true )
{
	IProgram* program = _context->GetGraphicsSystem()->GetProgram( L"overlay.textured.colored" );
	_resources = program->GetFragmentStage()->GetResources()->Clone( this->ID() );
	_image->Prepare( queue->GetWindow()->GetPixelFormat(), 1 );
	_resources->Set( 0, _image->AsResource() );

	IPrimitive* data = _context->GetGraphicsSystem()->GetDevice()->CreatePrimitive( program, DataUsage::Dynamic, DataAccess::WriteOnly, PrimitiveType::TriangleList, IndexType::None, 6*capacity, 0, 0, 0, true, false );
	_pool = queue->CreateObject( data );
	_pool->SetBlendStates( _blendStates );
	_pool->SetFragmentResources( _resources );
	_pool->SetOrder( Order::GetValue(_groupOrder, _order) );
	_pool->SetElementCount( 0 );
}

ISprite* SpritePool::CreateSprite( const Point& location, const Size& size, const RectF& frame )
{
	assert( _sprites.Size() < _sprites.Capacity() );

	if ( _sprites.Size() >= _sprites.Capacity() )
		throw InvalidOperationException( L"Pool capacity is exceeded." );

	return new PoolSprite( this, _context, location, size, frame, true );
}

ISprite* SpritePool::CreateSprite( const Point& location, const RectF& frame )
{
	return CreateSprite( location, Size(), frame );
}

void SpritePool::AddSprite( PoolSprite* sprite )
{
	_sprites.Add( sprite );
}

void SpritePool::RemoveSprite( PoolSprite* sprite )
{
	_sprites.Remove( sprite );
}

void SpritePool::Update()
{
	if ( !_dirty )
		return;

	P(IVector4Stream) streamPositions = (IVector4Stream*)_pool->GetData()->GetVertexStream( DataStream::Position2D, 0 );
	if ( !streamPositions->Open(OpenMode::Write) )
		return;

	P(IVector4Stream) streamColor = (IVector4Stream*)_pool->GetData()->GetVertexStream( DataStream::Color, 0 );
	if ( !streamColor->Open(OpenMode::Write) )
		return;

	P(IVector2Stream) streamFrame = (IVector2Stream*)_pool->GetData()->GetVertexStream( DataStream::TexCoord2D, 0 );
	if ( !streamFrame->Open(OpenMode::Write) )
		return;

	Bool dirty = false;
	UInt index = 0;
	for ( UInt i = 0; i < _sprites.Size(); ++i )
	{
		PoolSprite* sprite = _sprites[i];
		if ( dirty || sprite->_dirty )
		{
			SetPositions( streamPositions, index, sprite->_location, sprite->_center, sprite->_centerEnabled, sprite->_size, sprite->_orientation, sprite->_stretched );
			SetOpacity( streamColor, index, sprite->_opacity );
			SetFrame( streamFrame, index, sprite->_frame );
			sprite->_dirty = false;
			dirty = true;
			++index;
		}
	}

	if ( streamPositions != nullptr )
		streamPositions->Close();

	if ( streamColor != nullptr )
		streamColor->Close();

	if ( streamFrame != nullptr )
		streamFrame->Close();

	_dirty = false;
}

void SpritePool::SetPositions( IVector4Stream* stream, UInt idx, const Point& location, const Point& center, Bool centerEnabled, const Size& size, Float angle, Bool stretched )
{
	const Float left = CastFloat(location.X);
	const Float top = CastFloat(location.Y);
	const Float width = stretched ? CastFloat(size.Width) : CastFloat(_image->GetWidth());
	const Float height = stretched ? CastFloat(size.Height) : CastFloat(_image->GetHeight());

	// Set positions.
	Vector4 pos[] =
	{
		Vector4( left,			top,		0.0f, 1.0f ),
		Vector4( left,			top+height,	0.0f, 1.0f ),
		Vector4( left+width,	top,		0.0f, 1.0f ),
		Vector4( left,			top+height,	0.0f, 1.0f ),
		Vector4( left+width,	top,		0.0f, 1.0f ),
		Vector4( left+width,	top+height,	0.0f, 1.0f ),
	};

	// Apply rotation, if needed.
	if ( angle != 0.0f )
	{
		const Float x0 = centerEnabled ? center.X : pos[0].x + 0.5f*width;
		const Float y0 = centerEnabled ? center.Y : pos[0].y + 0.5f*height;
		const Float s = Math::Sin( angle );
		const Float c = Math::Cos( angle );

		for ( UInt i = 0; i < 6; ++i )
		{
			const Float x1 = pos[i].x;
			const Float y1 = pos[i].y;
			pos[i].x = (x1 - x0)*c - (y1 - y0)*s + x0;
			pos[i].y = (x1 - x0)*s + (y1 - y0)*c + y0;
		}
	}

	stream->SetPosition( idx*6 );
	stream->Write( pos, 6 );
}

void SpritePool::SetFrame( IVector2Stream* stream, UInt idx, const RectF& frame )
{
	Vector2 coords[] = 
	{
		Vector2( frame.Left, frame.Top ),
		Vector2( frame.Left, frame.Bottom ),
		Vector2( frame.Right, frame.Top ),
		Vector2( frame.Left, frame.Bottom ),
		Vector2( frame.Right, frame.Top ),
		Vector2( frame.Right, frame.Bottom ),
	};
	stream->SetPosition( idx*6 );
	stream->Write( coords, 6 );
}


} // over


} // synkro
