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
// Purpose: Text pool.
//==============================================================================
#include "config.h"
#include "TextPool.h"
#include "TextPoolAnimationController.h"
#include "PoolText.h"
#include "BaseFont.h"
#include <over/IFont.h>
#include <gfx/IProgram.h>
#include <gfx/IProgramStage.h>


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


TextPool::TextPool( IContext* context, IOverlayRenderQueue* queue, IFont* font, const Order& groupOrder, const Order& order, UInt capacity, Ndc* ndc ) :
	_texts( A(PoolText*), capacity ),
	_texts2( A(P(PoolText)), capacity ),
	_dirtyTexts( A(UInt) ),
	_cleanTexts( A(UInt) ),
	_context( context ),
	_font( AsBaseFont(font) ),
	_rectEnabled( false ),
	_groupOrder( groupOrder ),
	_order( order ),
	_size( 0 ),
	_ndc( ndc ),
	_dirty( true )
{
	_pool = _font->CreateText( queue, capacity, Order::GetValue(_groupOrder, _order) );
	_vertexParams = _pool->GetProgram()->GetVertexStage()->GetParameters()->Clone( this->ID(), true );
	_paramOffset = _vertexParams->GetParam( L"p_offset" );
	_pool->SetVertexParameters( _vertexParams );
	_pool->SetElementCount( 0 );
}

ITextPoolAnimationController* TextPool::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new TextPoolAnimationController( this, _context->GetAnimationSystem(), animation, listener) : _ctrlAnimation;
}

IText* TextPool::CreateText( const ColorGradient& gradient, const Point& location, const String& text )
{
	assert( _texts.Size() < _texts.Capacity() );

	if ( _texts.Size() >= _texts.Capacity() )
		throw InvalidOperationException( L"Pool capacity is exceeded." );

	PoolText* txt = new PoolText( this, _context, gradient, location, text );

	UInt size = _font->GetTextCapacity( text );
	txt->_start = _size;
	txt->_oldLength = text.Length();
	txt->_glyphCount = size;
	_size += size;
	_dirty = true;
	return txt;
}

IText* TextPool::CreateText( const Color& color, const Point& location, const String& text )
{
	return CreateText( ColorGradient(GradientType::Horizontal, color, color), location, text );
}

IText* TextPool::CreateText( const Point& location, const String& text )
{
	return CreateText( Color::White, location, text );
}

void TextPool::AddText( BaseText* text )
{
	PoolText* txt = (PoolText*)text;
	_texts.Add( txt );
	_texts2.Add( txt );
}

void TextPool::RemoveText( BaseText* text )
{
	const UInt index = _texts.IndexOf( (PoolText*)text );
	if ( index != none )
	{
		_texts.Remove( index );
		_texts2.Remove( index );
	}
}

void TextPool::Update()
{
	for ( UInt i = 0; i < _texts.Size(); ++i )
	{
		_texts[i]->Update();
	}
}

void TextPool::Update( Bool validateOffset )
{
	if ( validateOffset )
	{
		_vertexParams->Set( _paramOffset, _ndc->Convert(Vector2(CastFloat(_offset.X), CastFloat(_offset.Y))) );
	}

	if ( _dirty )
	{
		// Relocate updated texts next to the end of buffer.
		if ( _texts.Size() > 1 )
		{
			for ( UInt i = 0; i < _texts.Size(); ++i )
			{
				if ( _texts[i]->GetText().Length() != _texts[i]->_oldLength )
				{
					_dirtyTexts.Add( i );
				}
				else
				{
					_cleanTexts.Add( i );
				}
			}
			if ( _cleanTexts.Size() > 1 )
			{
				UInt idxClean = _cleanTexts.LastValue();
				for ( UInt i = 0; i < _dirtyTexts.Size(); ++i )
				{
					const UInt idx = _dirtyTexts[i];
					if ( idx < idxClean )
					{
						_texts[idxClean]->_dirty = true;
						_texts.Swap( idx, idxClean );
						_texts[i]->_dirty = true;
					}
					if ( idxClean-- == 0 )
						break;
				}
			}
		}
		_dirtyTexts.Clear();
		_cleanTexts.Clear();

		UInt start = 0;
		TextBuffer buffer( _pool );
		Bool relocated = false;
		for ( UInt i = 0; i < _texts.Size(); ++i )
		{
			PoolText* text = _texts[i];
			if ( text->_oldLength != text->GetText().Length() )
			{
				relocated = true;
			}
			if ( text->_dirty || relocated )
			{
				text->_glyphCount = _font->DrawText( buffer, text->_desc, start );
				text->_oldLength = text->GetText().Length();
				text->_dirty = false;
			}
			start += text->_glyphCount;
		}
		_pool->SetElementCount( 6*start );
		_dirty = false;
	}
}


} // over


} // synkro
