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
#include "Text.h"
#include "TextAnimationController.h"
#include "FontEx.h"


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


Text::Text( BaseTextPool* pool, BaseFont* font, IContext* context, IOverlayRenderQueue* queue, const Order& groupOrder, const Order& order, const Point& location, const String& text, const ColorGradient& gradient ) :	
	BaseTextImpl<BaseText>( pool ),
	_context( context ),
	_font( font ),
	_rectEnabled( false ),
	_desc( text, location, gradient ),
	_groupOrder( groupOrder ),
	_order( order )
{
	UInt capacity = _font->GetTextCapacity( _desc.Text );
	_text = _font->CreateText( queue, (capacity > 0) ? capacity : 1, Order::GetValue(_groupOrder, _order) );
	Update();
}

ITextAnimationController* Text::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new TextAnimationController( this, _context->GetAnimationSystem(), animation, listener) : _ctrlAnimation;
}

void Text::Wrap( Bool wrap )
{
	if ( wrap != _desc.Wrapped )
	{
		_desc.Wrapped = wrap;
		Update();
	}
}

void Text::EnableCenter( Bool enable )
{
	if ( enable != _desc.CenterEnabled )
	{
		_desc.CenterEnabled = enable;
		Update();
	}
}

void Text::SetCenter( const Point& center )
{
	if ( center != _desc.Center )
	{
		_desc.Center = center;
		Update();
	}
}

void Text::SetLocation( const Point& location )
{
	if ( location != _desc.Location )
	{		
		_desc.Location = location;
		Update();
	}
}

void Text::SetLocationX( Int x )
{
	if ( x != _desc.Location.X )
	{		
		_desc.Location.X = x;
		Update();
	}
}

void Text::SetLocationY( Int y )
{
	if ( y != _desc.Location.Y )
	{		
		_desc.Location.Y = y;
		Update();
	}
}

void Text::SetOrientation( Float orientation )
{
	if ( orientation != _desc.Orientation )
	{
		_desc.Orientation = orientation;
		Update();
	}
}

void Text::SetScale( Float scale )
{
	if ( scale != _desc.Scale )
	{
		_desc.Scale = scale;
		Update();
	}
}

void Text::SetGradient( const ColorGradient& gradient )
{
	if ( gradient != _desc.Gradient )
	{
		_desc.Gradient = gradient;
		Update();
	}
}

void Text::SetColor( const Color& color )
{
	if ( color != _desc.Color )
	{
		LOCK( _mutex );

		_desc.Gradient.Start = _desc.Gradient.End = _desc.Color = color;
		_font->UpdateColor( _text, _desc.Color, _desc.Opacity );
	}
}

void Text::SetOpacity( Float opacity )
{
	if ( opacity != _desc.Opacity )
	{
		LOCK( _mutex );

		_desc.Opacity = opacity;
		_font->UpdateColor( _text, _desc.Color, _desc.Opacity );
	}
}

void Text::SetText( const String& text )
{
	assert( text != String::Null );

	if ( text != _desc.Text )
	{
		LOCK( _mutex );

		_desc.Text = text;
		UInt capacity = _font->GetTextCapacity( _desc.Text );
		UInt cnt = 6*capacity;
		if ( cnt > _text->GetElementCount() )
		{
			_text->GetData()->Resize( cnt, 0, 0 );
		}
		_text->SetElementCount( cnt );
		Update();
	}
}

void Text::Update()
{
	LOCK( _mutex );

	TextBuffer buffer( _text );
	_font->DrawText( buffer, _desc, 0 );
}


} // over


} // synkro
