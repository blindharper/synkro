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
// Purpose: Sprite implementation.
//==============================================================================
#include "config.h"
#include "Sprite.h"
#include "SpriteAnimationController.h"
#include <gfx/IRenderWindow.h>
#include <gfx/IOverlayRenderQueue.h>
#include <gfx/IProgramStage.h>
#include <gfx/IProgram.h>
#include <gfx/IResourceSet.h>
#include <gfx/IPrimitiveEx.h>
#include <gfx/IVector2Stream.h>
#include <gfx/IVector4Stream.h>
#include <math/Math.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::input;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace over
{


Sprite::Sprite( IContext* context, IOverlayRenderQueue* queue, IBlendStateSet* blendStates, IImage* image, const Order& groupOrder, const Order& order, const Point& location, const Size& size, Bool stretched ) :
	_context( context ),
	_blendStates( blendStates ),
	_paramColor( nullptr ),
	_groupOrder( groupOrder ),
	_order( order ),
	_image( image ),
	_rectEnabled( false ),
	_centerEnabled( false ),
	_location( location ),
	_size( size ),
	_orientation( 0.0f ),
	_opacity( 0.0f ),
	_stretched( stretched )
{
	assert( _image != nullptr );

	IProgram* program = _context->GetGraphicsSystem()->GetProgram( L"overlay.textured" );
	_fragmentParams = program->GetFragmentStage()->GetParameters()->Clone( this->ID(), true );
	_paramColor = _fragmentParams->GetParam( L"p_color" );
	_resources = program->GetFragmentStage()->GetResources()->Clone( this->ID() );
	_image->Prepare( queue->GetWindow()->GetPixelFormat(), 1 );
	_resources->Set( 0, _image->AsResource() );

	IPrimitive* data = _context->GetGraphicsSystem()->GetDevice()->CreatePrimitive( program, DataUsage::Dynamic, DataAccess::WriteOnly, PrimitiveType::TriangleStrip, IndexType::None, 4, 0, 0, 0, true, false );
	_sprite = queue->CreateObject( data );
	_sprite->SetOrder( Order::GetValue(_groupOrder, _order) );
	_sprite->SetBlendStates( _blendStates );
	_sprite->SetFragmentResources( _resources );
	_sprite->SetFragmentParameters( _fragmentParams );

	SetPositions( _location, _size, _orientation );
	SetFrame( RectF(0.0f, 0.0f, 1.0f, 1.0f) );
	SetOpacity( 1.0f );
}

ISpriteAnimationController* Sprite::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new SpriteAnimationController( this, _context->GetAnimationSystem(), animation, listener) : _ctrlAnimation;
}

void Sprite::SetLocation( const Point& location )
{
	if ( location != _location )
	{
		SetPositions( location, _size, _orientation );
		_location = location;
	}
}

void Sprite::SetLocationX( Int x )
{
	if ( x != _location.X )
	{
		_location.X = x;
		SetPositions( _location, _size, _orientation );
	}
}

void Sprite::SetLocationY( Int y )
{
	if ( y != _location.Y )
	{
		_location.Y = y;
		SetPositions( _location, _size, _orientation );
	}
}

void Sprite::SetSize( const Size& size )
{
	if ( size != _size )
	{
		SetPositions( _location, size, _orientation );
		_size = size;
	}
}

void Sprite::SetOrientation( Float orientation )
{
	if ( orientation != _orientation )
	{
		SetPositions( _location, _size, orientation );
		_orientation = orientation;
	}
}

void Sprite::SetFrame( const RectF& frame )
{
	if ( _frame != frame )
	{
		P(IVector2Stream) stream = (IVector2Stream*)_sprite->GetData()->GetVertexStream( DataStream::TexCoord2D, 0 );
		if ( (stream != nullptr) && stream->Open(OpenMode::Write) )
		{
			Vector2 coords[] = 
			{
				Vector2( frame.Left, frame.Top ),
				Vector2( frame.Left, frame.Bottom ),
				Vector2( frame.Right, frame.Top ),
				Vector2( frame.Right, frame.Bottom ),
			};
			stream->Write( coords, 4 );
			stream->Close();
		}
		_frame = frame;
	}
}

void Sprite::SetPositions( const Point& location, const Size& size, Float angle )
{
	const Float left = CastFloat(location.X);
	const Float top = CastFloat(location.Y);
	const Float width = _stretched ? CastFloat(size.Width) : CastFloat(_image->GetWidth());
	const Float height = _stretched ? CastFloat(size.Height) : CastFloat(_image->GetHeight());

	P(IVector4Stream) stream = (IVector4Stream*)_sprite->GetData()->GetVertexStream( DataStream::Position2D, 0 );
	if ( (stream != nullptr) && stream->Open(OpenMode::Write) )
	{
		// Set positions.
		Vector4 pos[] =
		{
			Vector4( left,			top,		0.0f, 1.0f ),
			Vector4( left,			top+height,	0.0f, 1.0f ),
			Vector4( left+width,	top,		0.0f, 1.0f ),
			Vector4( left+width,	top+height,	0.0f, 1.0f ),
		};

		// Apply rotation, if needed.
		if ( angle != 0.0f )
		{
			const Float x0 = _centerEnabled ? _center.X : pos[0].x + 0.5f*width;
			const Float y0 = _centerEnabled ? _center.Y : pos[0].y + 0.5f*height;
			const Float s = Math::Sin( angle );
			const Float c = Math::Cos( angle );

			for ( UInt i = 0; i < 4; ++i )
			{
				const Float x1 = pos[i].x;
				const Float y1 = pos[i].y;
				pos[i].x = (x1 - x0)*c - (y1 - y0)*s + x0;
				pos[i].y = (x1 - x0)*s + (y1 - y0)*c + y0;
			}
		}

		stream->Write( pos, 4 );
		stream->Close();
	}
}


} // over


} // synkro
