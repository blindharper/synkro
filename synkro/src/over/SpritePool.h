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
#ifndef _SYNKRO_OVER_SPRITEPOOL_
#define _SYNKRO_OVER_SPRITEPOOL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <core/IContext.h>
#include <over/ISpritePool.h>
#include <gfx/IGraphicsSystemEx.h>
#include <gfx/IGraphicsDeviceEx.h>
#include <gfx/IResourceSet.h>
#include <gfx/IOverlayRenderObject.h>
#include <gfx/IVector2Stream.h>
#include <gfx/IVector4Stream.h>
#include <gfx/IRect.h>
#include <img/IImage.h>
#include <lang/Size.h>
#include <lang/Vector.h>
#include "BaseSpritePool.h"


namespace synkro
{


namespace over
{


// Sprite pool implementation.
class SpritePool :
	public core::ObjectImpl<ISpritePool>,
	public BaseSpritePool
{
public:
	// Constructor.
	SpritePool( gfx::IOverlayRenderQueue* queue, core::IContext* context, gfx::IBlendStateSet* blendStates, img::IImage* image, const Order& groupOrder, const Order& order, UInt capacity );

	// ISpritePool methods.
	void													Enable( Bool enable );
	void													EnableRect( Bool enable );
	void													SetRect( const lang::Rect& rect );
	ISprite*												CreateSprite( const lang::Point& location, const lang::Size& size, const lang::RectF& frame );
	ISprite*												CreateSprite( const lang::Point& location, const lang::RectF& frame );
	Bool													IsEnabled() const;
	Bool													IsRectEnabled() const;
	UInt													GetCapacity() const;
	UInt													GetSpriteCount() const;
	ISprite*												GetSprite( UInt index ) const;
	void													GetRect( lang::Rect& rect ) const;
	Order													GetGroupOrder() const;
	Order													GetOrder() const;
	img::IImage*											GetImage() const;

	// BaseSpritePool methods.
	void													AddSprite( PoolSprite* sprite );
	void													RemoveSprite( PoolSprite* sprite );
	void													InvalidateSprites();
	void													Update();

private:
	lang::Vector<P(PoolSprite)>								_sprites;
	core::IContext*											_context;
	P(gfx::IOverlayRenderObject)							_pool;
	P(gfx::IRect)											_scissor;
	gfx::IBlendStateSet*									_blendStates;
	P(gfx::IResourceSet)									_resources;
	P(img::IImage)											_image;
	Bool													_rectEnabled;
	lang::Rect												_rect;
	Order													_groupOrder;
	Order													_order;
	Bool													_dirty;

	void													SetPositions( gfx::IVector4Stream* stream, UInt idx, const lang::Point& location, const lang::Point& center, Bool centerEnabled, const lang::Size& size, Float angle, Bool stretched );
	void													SetOpacity( gfx::IVector4Stream* stream, UInt idx, Float opacity );
	void													SetFrame( gfx::IVector2Stream* stream, UInt idx, const lang::RectF& frame );
};


#include "SpritePool.inl"


} // over


} // synkro


#endif // _SYNKRO_OVER_SPRITEPOOL_
