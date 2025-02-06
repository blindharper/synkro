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
// Purpose: Overlay implementation.
//==============================================================================
#include "config.h"
#include "Overlay.h"
#include "PolyLine.h"
#include "Sprite.h"
#include "FontEx.h"
#include "TextPool.h"
#include <anim/IAnimationSystem.h>
#include <gfx/BlendState.h>
#include <gfx/RasterizerState.h>
#include <gfx/IGraphicsDevice.h>
#include <gfx/IFrameRenderWindowEx.h>
#include <gfx/IViewRenderWindowEx.h>
#include <gfx/IVirtualRenderWindow.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::input;
using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace over
{


Overlay::Overlay( BaseOverlayManager* overlayManager, IRenderWindow* window, IOverlayRenderQueue* queue, IContext* context ) :
	_overlayManager( overlayManager ),
	_fonts( A(FontEntry) ),
	_spritePools( A(BaseSpritePool*) ),
	_textPools( A(TextPool*) ),
	_quads( A(Quad*) ),
	_window( window ),
	_queue( queue ),
	_context( context ),
	_fontProgram( _overlayManager->GetFontProgram() ),
	_blendStates( _overlayManager->GetBlendStates() ),
	_ndc( _window, _window->GetWidth(), _window->GetHeight() )
{
	assert( _queue != nullptr );
}

Overlay::Overlay( BaseOverlayManager* overlayManager, IImage* image, IContext* context ) :
	_overlayManager( overlayManager ),
	_fonts( A(FontEntry) ),
	_spritePools( A(BaseSpritePool*) ),
	_textPools( A(TextPool*) ),
	_quads( A(Quad*) ),
	_window( nullptr ),
	_image( image ),
	_queue( nullptr ),
	_context( context ),
	_ndc( nullptr, _image->GetWidth(), _image->GetHeight() )
{
	_queue = _context->GetGraphicsSystem()->CreateRenderQueue( _image->GetWidth(), _image->GetHeight() );
	_renderMap = _context->GetGraphicsSystem()->CreateRenderMap( _queue, _image->AsPlainRenderTexture() );
	_fontProgram = _overlayManager->GetFontProgram();
	_blendStates = _overlayManager->GetBlendStates();
}

IPolyLine* Overlay::CreatePolyLine( UInt pointCount, UInt width, const Color& color )
{
	return new PolyLine( _queue, _context->GetGraphicsSystem(), _blendStates, pointCount, Clamp<UInt>(width, 1, width), color );
}

IPolyLine* Overlay::CreatePolyLine( UInt pointCount, UInt width )
{
	return new PolyLine( _queue, _context->GetGraphicsSystem(), _blendStates, pointCount, Clamp<UInt>(width, 1, width) );
}

IQuad* Overlay::CreateQuad( const Order& groupOrder, const Order& order, const Point& location, const Size& size, const Color& color )
{
	Quad* quad = new Quad( _queue, _context->GetGraphicsSystem(), _blendStates, groupOrder, order, location, size, color, &_ndc );
	_quads.Add( quad );
	return quad;
}

IQuad* Overlay::CreateQuad( const Point& location, const Size& size, const Color& color )
{
	return CreateQuad( Order::Normal, Order::Normal, location, size, color );
}

ISpritePool* Overlay::CreateSpritePool( IImage* image, const Order& groupOrder, const Order& order, UInt capacity )
{
	assert( image != nullptr );

	SpritePool* pool = new SpritePool( _queue, _context, _blendStates, image, groupOrder, order, capacity );
	_spritePools.Add( pool );
	return pool;
}

ISprite* Overlay::CreateSprite( IImage* image, const Order& groupOrder, const Order& order, const Point& location, const Size& size )
{
	assert( image != nullptr );

	return new Sprite( _context, _queue, _blendStates, image, groupOrder, order, location, size, true );
}

ISprite* Overlay::CreateSprite( IImage* image, const Order& groupOrder, const Order& order, const Point& location )
{
	assert( image != nullptr );

	return new Sprite( _context, _queue, _blendStates, image, groupOrder, order, location, Size(), false );
}

ISprite* Overlay::CreateSprite( IImage* image, const Point& location, const Size& size )
{
	return CreateSprite( image, Order::Normal, Order::Normal, location, size );
}

ISprite* Overlay::CreateSprite( IImage* image, const Point& location )
{
	return CreateSprite( image, Order::Normal, Order::Normal, location );
}

ITextPool* Overlay::CreateTextPool( IFont* font, const Order& groupOrder, const Order& order, UInt capacity )
{
	assert( font != nullptr );

	TextPool* pool = new TextPool( _context, _queue, font, groupOrder, order, capacity, &_ndc );
	_textPools.Add( pool );
	return pool;
}

IFont* Overlay::GetFont( const String& name ) const
{
	if ( !_fonts.ContainsKey(name) )
	{
		// Create font from template.
		_fonts[name] = _overlayManager->CreateFont( name, (IOverlay*)this );
	}
	return _fonts[name];
}

void Overlay::Update()
{
	Bool resized = false;
	if ( (_window->GetWidth() != _windowWidth) || (_window->GetHeight() != _windowHeight) )
	{
		resized = true;
		_ndc.Update();
		_windowWidth = _window->GetWidth();
		_windowHeight = _window->GetHeight();
	}

	_spritePools.Each( *this );

	MapIterator<lang::String, P(IFont)> itFont = _fonts.Begin();
	MapIterator<lang::String, P(IFont)> itFontEnd = _fonts.End();
	for ( ; itFont != itFontEnd ; ++itFont )
	{
		((BaseTextPool*)(FontEx*)(IFont*)itFont.Value())->Update();
	}

	for ( UInt i = 0; i < _textPools.Size(); ++i )
	{
		_textPools[i]->Update();
		_textPools[i]->Update( resized );
	}

	for ( UInt i = 0; i < _quads.Size(); ++i )
	{
		_quads[i]->Update( resized );
	}
}

void Overlay::Finalize()
{
	_fonts.Clear();
	_fontProgram = nullptr;
	_blendStates = nullptr;
}


} // over


} // synkro
