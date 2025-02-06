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
#ifndef _SYNKRO_OVER_OVERLAY_
#define _SYNKRO_OVER_OVERLAY_


#include "config.h"
#include <lang/Map.h>
#include <lang/Vector.h>
#include <core/ObjectImpl.h>
#include <core/IContext.h>
#include <over/IOverlay.h>
#include <over/IFont.h>
#include <over/IText.h>
#include <gfx/Ndc.h>
#include <gfx/IPlainRenderMap.h>
#include <gfx/IOverlayRenderQueue.h>
#include <gfx/IGraphicsSystemEx.h>
#include <gfx/IRenderWindow.h>
#include <img/IImageManager.h>
#include <io/IStreamDirectory.h>
#include "BaseOverlayManager.h"
#include "SpritePool.h"
#include "TextPool.h"
#include "Quad.h"


namespace synkro
{


namespace over
{


// Overlay implementation.
class Overlay :
	public core::ObjectImpl<IOverlay>
{
public:
	// Constructors.
	Overlay( BaseOverlayManager* overlayManager, gfx::IRenderWindow* window, gfx::IOverlayRenderQueue* queue, core::IContext* context );
	Overlay( BaseOverlayManager* overlayManager, img::IImage* image, core::IContext* context );

	// IOverlay methods.
	IPolyLine*												CreatePolyLine( UInt pointCount, UInt width, const img::Color& color );
	IPolyLine*												CreatePolyLine( UInt pointCount, UInt width );
	IQuad*													CreateQuad( const Order& groupOrder, const Order& order, const lang::Point& location, const lang::Size& size, const img::Color& color );
	IQuad*													CreateQuad( const lang::Point& location, const lang::Size& size, const img::Color& color );
	ISpritePool*											CreateSpritePool( img::IImage* image, const Order& groupOrder, const Order& order, UInt capacity );
	ISprite*												CreateSprite( img::IImage* image, const Order& groupOrder, const Order& order, const lang::Point& location, const lang::Size& size );
	ISprite*												CreateSprite( img::IImage* image, const Order& groupOrder, const Order& order, const lang::Point& location );
	ISprite*												CreateSprite( img::IImage* image, const lang::Point& location, const lang::Size& size );
	ISprite*												CreateSprite( img::IImage* image, const lang::Point& location );
	ITextPool*												CreateTextPool( IFont* font, const Order& groupOrder, const Order& order, UInt capacity );
	IFont*													GetFont( const lang::String& name ) const;
	gfx::IRenderWindow*										GetRenderWindow() const;

	// Other methods.
	void													Update();
	void													Finalize();
	Bool													Call( BaseSpritePool* pool );

private:
	friend class FontEx;

	typedef lang::MapPair<lang::String, P(IFont)>			FontEntry;

	mutable lang::MapCI<lang::String, P(IFont)>				_fonts;
	lang::Vector<BaseSpritePool*>							_spritePools;
	lang::Vector<TextPool*>									_textPools;
	lang::Vector<Quad*>										_quads;
	BaseOverlayManager*										_overlayManager;
	gfx::IRenderWindow*										_window;
	P(img::IImage)											_image;
	P(gfx::IOverlayRenderQueue)								_queue;
	P(gfx::IPlainRenderMap)									_renderMap;
	core::IContext*											_context;
	gfx::IProgram*											_fontProgram;
	P(gfx::IBlendStateSet)									_blendStates;
	gfx::Ndc												_ndc;
	UInt													_windowWidth;
	UInt													_windowHeight;
};


#include "Overlay.inl"


} // over


} // synkro


#endif // _SYNKRO_OVER_OVERLAY_
