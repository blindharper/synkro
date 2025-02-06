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
#ifndef _SYNKRO_OVER_SPRITE_
#define _SYNKRO_OVER_SPRITE_


#include "config.h"
#include <core/ObjectImpl.h>
#include <core/IContext.h>
#include <over/ISprite.h>
#include <over/ISpriteAnimationController.h>
#include <gfx/IGraphicsSystemEx.h>
#include <gfx/IGraphicsDeviceEx.h>
#include <gfx/IOverlayRenderObject.h>
#include <gfx/IParameterSet.h>
#include <gfx/IBlendState.h>
#include <gfx/IBlendStateSet.h>
#include <gfx/IRect.h>
#include <img/IImage.h>


namespace synkro
{


namespace over
{


// Sprite implementation.
class Sprite :
	public core::ObjectImpl<ISprite>
{
public:
	// Constructor.
	Sprite( core::IContext* context, gfx::IOverlayRenderQueue* queue, gfx::IBlendStateSet* blendStates, img::IImage* image, const Order& groupOrder, const Order& order, const lang::Point& location, const lang::Size& size, Bool stretched );

	// ISprite methods.
	ISpriteAnimationController*								CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );
	void													Show( Bool show );
	void													Stretch( Bool stretch );
	void													EnableRect( Bool enable );
	void													EnableCenter( Bool enable );
	void													SetRect( const lang::Rect& rect );
	void													SetCenter( const lang::Point& center );
	void													SetLocation( const lang::Point& location );
	void													SetLocationX( Int x );
	void													SetLocationY( Int y );
	void													SetSize( const lang::Size& size );
	void													SetOrientation( Float orientation );
	void													SetOpacity( Float opacity );
	void													SetFrame( const lang::RectF& frame );
	void													SetGroupOrder( const Order& order );
	void													SetOrder( const Order& order );
	Bool													IsVisible() const;
	Bool													IsStretched() const;
	Bool													IsRectEnabled() const;
	Bool													IsCenterEnabled() const;
	void													GetRect( lang::Rect& rect ) const;
	void													GetCenter( lang::Point& center ) const;
	void													GetLocation( lang::Point& location ) const;
	void													GetSize( lang::Size& size ) const;
	Float													GetOrientation() const;
	Float													GetOpacity() const;
	void													GetFrame( lang::RectF& frame ) const;
	Order													GetGroupOrder() const;
	Order													GetOrder() const;
	img::IImage*											GetImage() const;

private:
	core::IContext*											_context;
	P(gfx::IOverlayRenderObject)							_sprite;
	P(ISpriteAnimationController)							_ctrlAnimation;
	P(gfx::IBlendStateSet)									_blendStates;
	P(gfx::IParameterSet)									_fragmentParams;
	gfx::ProgramParam*										_paramColor;
	P(gfx::IResourceSet)									_resources;
	P(img::IImage)											_image;
	P(gfx::IRect)											_scissor;
	lang::Rect												_rect;
	Bool													_rectEnabled;
	lang::Point												_center;
	Bool													_centerEnabled;
	lang::Point												_location;
	lang::Size												_size;
	Float													_orientation;
	Float													_opacity;
	lang::RectF												_frame;
	Order													_groupOrder;
	Order													_order;
	Bool													_stretched;

	void													SetPositions( const lang::Point& location, const lang::Size& size, Float angle );
};


#include "Sprite.inl"


} // over


} // synkro


#endif // _SYNKRO_OVER_SPRITE_
