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
// Purpose: Pool sprite implementation.
//==============================================================================
#include "config.h"
#include "PoolSprite.h"
#include "SpritePool.h"
#include "SpriteAnimationController.h"


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::img;
using namespace synkro::input;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace over
{


PoolSprite::PoolSprite( BaseSpritePool* pool, IContext* context, const Point& location, const Size& size, const RectF& frame, Bool stretched ) :
	_pool( pool ),
	_context( context ),
	_location( location ),
	_centerEnabled( false ),
	_size( size ),
	_orientation( 0.0f ),
	_frame( frame ),
	_opacity( 1.0f ),
	_stretched( stretched ),
	_visible( true ),
	_dirty( true )
{
	_pool->AddSprite( this );
}

PoolSprite::~PoolSprite()
{
	_pool->RemoveSprite( this );
}

ISpriteAnimationController* PoolSprite::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new SpriteAnimationController( this, _context->GetAnimationSystem(), animation, listener) : _ctrlAnimation;
}

void PoolSprite::Show( Bool show )
{
	if ( show != _visible )
	{
		_visible = show;
		_dirty = true;
		_pool->InvalidateSprites();
	}
}

void PoolSprite::Stretch( Bool stretch )
{
	if ( stretch != _stretched )
	{
		_stretched = stretch;
		_dirty = true;
		_pool->InvalidateSprites();
	}
}

void PoolSprite::EnableRect( Bool enable )
{
	// Do nothing.
}

void PoolSprite::EnableCenter( Bool enable )
{
	if ( enable != _centerEnabled )
	{
		_centerEnabled = enable;
		_dirty = true;
		_pool->InvalidateSprites();
	}
}

void PoolSprite::SetRect( const Rect& rect )
{
	// Do nothing.
}

void PoolSprite::SetCenter( const Point& center )
{
	if ( center != _center )
	{
		_center = center;
		_dirty = true;
		_pool->InvalidateSprites();
	}
}

void PoolSprite::SetLocation( const Point& location )
{
	if ( location != _location )
	{
		_location = location;
		_dirty = true;
		_pool->InvalidateSprites();
	}
}

void PoolSprite::SetLocationX( Int x )
{
	if ( x != _location.X )
	{
		_location.X = x;
		_dirty = true;
		_pool->InvalidateSprites();
	}
}

void PoolSprite::SetLocationY( Int y )
{
	if ( y != _location.Y )
	{
		_location.Y = y;
		_dirty = true;
		_pool->InvalidateSprites();
	}
}

void PoolSprite::SetSize( const Size& size )
{
	if ( size != _size )
	{
		_size = size;
		_dirty = true;
		_pool->InvalidateSprites();
	}
}

void PoolSprite::SetOrientation( Float orientation )
{
	if ( orientation != _orientation )
	{
		_orientation = orientation;
		_dirty = true;
		_pool->InvalidateSprites();
	}
}

void PoolSprite::SetOpacity( Float opacity )
{
	opacity = Math::Clamp( opacity, 0.0f, 1.0f );

	if ( opacity != _opacity )
	{
		_opacity = opacity;
		_dirty = true;
		_pool->InvalidateSprites();
	}
}

void PoolSprite::SetFrame( const RectF& frame )
{
	if ( frame != _frame )
	{
		_frame = frame;
		_dirty = true;
		_pool->InvalidateSprites();
	}
}

Order PoolSprite::GetGroupOrder() const
{
	return dynamic_cast<SpritePool*>(_pool)->GetGroupOrder();
}

Order PoolSprite::GetOrder() const
{
	return dynamic_cast<SpritePool*>(_pool)->GetOrder();
}

IImage* PoolSprite::GetImage() const
{
	return dynamic_cast<SpritePool*>(_pool)->GetImage();
}


} // over


} // synkro
