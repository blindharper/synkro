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
#ifndef _SYNKRO_OVER_POOLSPRITE_
#define _SYNKRO_OVER_POOLSPRITE_


#include "config.h"
#include <core/ObjectImpl.h>
#include <core/IContext.h>
#include <over/ISprite.h>
#include <over/ISpriteAnimationController.h>
#include <math/Math.h>
#include "BaseSpritePool.h"


namespace synkro
{


namespace over
{


// Pool sprite implementation.
class PoolSprite :
	public core::ObjectImpl<ISprite>
{
public:
	// Constructor & destructor.
	PoolSprite( BaseSpritePool* pool, core::IContext* context, const lang::Point& location, const lang::Size& size, const lang::RectF& frame, Bool stretched );
	~PoolSprite();

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
	friend class SpritePool;

	BaseSpritePool*											_pool;
	core::IContext*											_context;
	P(ISpriteAnimationController)							_ctrlAnimation;
	lang::Point												_location;
	lang::Point												_center;
	Bool													_centerEnabled;
	lang::Size												_size;
	Float													_orientation;
	lang::RectF												_frame;
	Float													_opacity;
	Bool													_stretched;
	Bool													_visible;
	Bool													_dirty;
};


#include "PoolSprite.inl"


} // over


} // synkro


#endif // _SYNKRO_OVER_POOLSPRITE_
