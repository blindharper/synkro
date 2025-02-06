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
#ifndef _SYNKRO_OVER_TEXT_
#define _SYNKRO_OVER_TEXT_


#include "config.h"
#include <core/ObjectImpl.h>
#include <core/IContext.h>
#include <over/IText.h>
#include <over/ITextAnimationController.h>
#include <over/IFont.h>
#include <gfx/IGraphicsSystemEx.h>
#include <gfx/IGraphicsDeviceEx.h>
#include <gfx/IOverlayRenderObject.h>
#include <gfx/IRect.h>
#include "BaseFont.h"
#include "BaseTextPool.h"
#include "BaseTextImpl.h"
#include "BaseText.h"
#include <internal/Mutex.h>


namespace synkro
{


namespace over
{


// Overlay text implementation.
class Text :
	public core::ObjectImpl<IText>,
	public BaseTextImpl<BaseText>
{
public:
	// Constructor.
	Text( BaseTextPool* pool, BaseFont* font, core::IContext* context, gfx::IOverlayRenderQueue* queue, const Order& groupOrder, const Order& order, const lang::Point& location, const lang::String& text, const img::ColorGradient& gradient );

	// IText methods.
	ITextAnimationController*								CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );
	void													Show( Bool show );
	void													Clear();
	void													Wrap( Bool wrap );
	void													EnableRect( Bool enable );
	void													EnableCenter( Bool enable );
	void													SetRect( const lang::Rect& rect );
	void													SetCenter( const lang::Point& center );
	void													SetLocation( const lang::Point& location );	
	void													SetLocationX( Int x );
	void													SetLocationY( Int y );
	void													SetOrientation( Float orientation );
	void													SetScale( Float scale );
	void													SetGradient( const img::ColorGradient& gradient );
	void													SetColor( const img::Color& color );
	void													SetOpacity( Float opacity );
	void													SetGroupOrder( const Order& order );
	void													SetOrder( const Order& order );
	void													SetText( const lang::String& text );
	Bool													IsVisible() const;
	Bool													IsWrapped() const;
	Bool													IsRectEnabled() const;
	Bool													IsCenterEnabled() const;
	void													GetRect( lang::Rect& rect ) const;
	void													GetCenter( lang::Point& center ) const;
	void													GetLocation( lang::Point& location ) const;	
	Float													GetOrientation() const;
	Float													GetScale() const;
	void													GetGradient( img::ColorGradient& gradient ) const;
	void													GetColor( img::Color& color ) const;
	Float													GetOpacity() const;
	Order													GetGroupOrder() const;
	Order													GetOrder() const;	
	lang::String											GetText() const;
	IFont*													GetFont() const;

private:
	core::IContext*											_context;
	P(gfx::IOverlayRenderObject)							_text;
	P(ITextAnimationController)								_ctrlAnimation;
	P(gfx::IRect)											_scissor;
	BaseFont*												_font;
	Bool													_rectEnabled;
	TextDesc												_desc;
	Order													_groupOrder;
	Order													_order;
	Mutex													_mutex;

	void													Update();
};


#include "Text.inl"


} // over


} // synkro


#endif // _SYNKRO_OVER_TEXT_
