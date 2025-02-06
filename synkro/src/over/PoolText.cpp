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
// Purpose: Overlay text implementation.
//==============================================================================
#include "config.h"
#include "PoolText.h"
#include "TextPool.h"
#include "TextAnimationController.h"


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace over
{


PoolText::PoolText( BaseTextPool* pool, IContext* context, const ColorGradient& gradient, const Point& location, const String& text ) :
	BaseTextImpl<BaseText>( pool ),
	_context( context ),
	_desc( text, location, gradient ),
	_visible( true ),
	_start( 0 ),
	_oldLength( 0 ),
	_glyphCount( 0 ),
	_dirty( true )
{
}

ITextAnimationController* PoolText::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new TextAnimationController( this, _context->GetAnimationSystem(), animation, listener) : _ctrlAnimation;
}

void PoolText::Show( Bool show )
{
	if ( show != _visible )
	{
		_visible = show;
		_dirty = true;
		_pool->InvalidateTexts();
	}
}

void PoolText::Wrap( Bool wrap )
{
	if ( wrap != _desc.Wrapped )
	{
		_desc.Wrapped = wrap;
		_dirty = true;
		_pool->InvalidateTexts();
	}
}

void PoolText::EnableRect( Bool enable )
{
	// Do nothing.
}

void PoolText::EnableCenter( Bool enable )
{
	if ( enable != _desc.CenterEnabled )
	{
		_desc.CenterEnabled = enable;
		_dirty = true;
		_pool->InvalidateTexts();
	}
}

void PoolText::SetRect( const Rect& rect )
{
	if ( rect != _desc.Rect )
	{
		_desc.Rect = rect;
		_dirty = true;
		_pool->InvalidateTexts();
	}
}

void PoolText::SetCenter( const Point& center )
{
	if ( center != _desc.Center )
	{
		_desc.Center = center;
		_dirty = true;
		_pool->InvalidateTexts();
	}
}

void PoolText::SetLocation( const Point& location )
{
	if ( location != _desc.Location )
	{
		_desc.Location = location;
		_dirty = true;
		_pool->InvalidateTexts();
	}
}

void PoolText::SetLocationX( Int x )
{
	if ( x != _desc.Location.X )
	{
		_desc.Location.X = x;
		_dirty = true;
		_pool->InvalidateTexts();
	}
}

void PoolText::SetLocationY( Int y )
{
	if ( y != _desc.Location.Y )
	{
		_desc.Location.Y = y;
		_dirty = true;
		_pool->InvalidateTexts();
	}
}

void PoolText::SetOrientation( Float orientation )
{
	if ( orientation != _desc.Orientation )
	{
		_desc.Orientation = orientation;
		_dirty = true;
		_pool->InvalidateTexts();
	}
}

void PoolText::SetScale( Float scale )
{
	if ( scale != _desc.Scale )
	{
		_desc.Scale = scale;
		_dirty = true;
		_pool->InvalidateTexts();
	}
}

void PoolText::SetGradient( const ColorGradient& gradient )
{
	if ( gradient != _desc.Gradient )
	{
		_desc.Gradient = gradient;
		_dirty = true;
		_pool->InvalidateTexts();
	}
}

void PoolText::SetColor( const Color& color )
{
	SetGradient( ColorGradient(_desc.Gradient.Type, color, color) );
}

void PoolText::SetOpacity( Float opacity )
{
	if ( opacity != _desc.Opacity )
	{
		_desc.Opacity = opacity;
		_dirty = true;
		_pool->InvalidateTexts();
	}
}

void PoolText::SetText( const String& text )
{
	assert( text != String::Null );

	if ( text != _desc.Text )
	{
		_desc.Text = text;
		_dirty = true;
		_pool->InvalidateTexts();
	}
}

Order PoolText::GetGroupOrder() const
{
	return dynamic_cast<TextPool*>(_pool)->GetGroupOrder();
}

Order PoolText::GetOrder() const
{
	return dynamic_cast<TextPool*>(_pool)->GetOrder();
}

IFont* PoolText::GetFont() const
{
	return dynamic_cast<TextPool*>(_pool)->GetFont();
}


} // over


} // synkro
