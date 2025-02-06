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
#ifndef _SYNKRO_OVER_TEXTPOOL_
#define _SYNKRO_OVER_TEXTPOOL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <core/IContext.h>
#include <over/ITextPool.h>
#include <over/ITextPoolAnimationController.h>
#include <over/IText.h>
#include <over/IFont.h>
#include <lang/Vector.h>
#include <gfx/IGraphicsSystemEx.h>
#include <gfx/IGraphicsDeviceEx.h>
#include <gfx/IOverlayRenderObject.h>
#include <gfx/IParameterSet.h>
#include <gfx/IRect.h>
#include <gfx/Ndc.h>
#include <internal/ToVector.h>
#include "PoolText.h"
#include "BaseFont.h"
#include "BaseTextPool.h"


namespace synkro
{


namespace over
{


// Text pool. Holds texts with the same font and z-order.
class TextPool :
	public core::ObjectImpl<ITextPool>,
	public BaseTextPool
{
public:
	// Constructor.
	TextPool( core::IContext* context, gfx::IOverlayRenderQueue* queue, IFont* font, const Order& groupOrder, const Order& order, UInt capacity, gfx::Ndc* ndc );

	// ITextPool methods.
	ITextPoolAnimationController*							CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );
	void													Enable( Bool enable );
	void													EnableRect( Bool enable );
	void													SetRect( const lang::Rect& rect );
	void													SetOffset( const lang::Point& offset );
	IText*													CreateText( const img::ColorGradient& gradient, const lang::Point& location, const lang::String& text );
	IText*													CreateText( const img::Color& color, const lang::Point& location, const lang::String& text );
	IText*													CreateText( const lang::Point& location, const lang::String& text );
	Bool													IsEnabled() const;
	Bool													IsRectEnabled() const;
	UInt													GetCapacity() const;
	UInt													GetTextCount() const;
	IText*													GetText( UInt index ) const;
	void													GetRect( lang::Rect& rect ) const;
	void													GetOffset( lang::Point& offset ) const;
	Order													GetGroupOrder() const;
	Order													GetOrder() const;
	IFont*													GetFont() const;

	// BaseTextPool methods.
	void													AddText( BaseText* text );
	void													RemoveText( BaseText* text );
	void													InvalidateTexts();
	void													Update();

	// Other methods.
	void													Update( Bool validateOffset );

private:
	lang::Vector<PoolText*>									_texts;
	lang::Vector<P(PoolText)>								_texts2;
	lang::Vector<UInt>										_dirtyTexts;
	lang::Vector<UInt>										_cleanTexts;
	core::IContext*											_context;
	P(gfx::IOverlayRenderObject)							_pool;
	P(gfx::IRect)											_scissor;
	P(ITextPoolAnimationController)							_ctrlAnimation;
	P(gfx::IParameterSet)									_vertexParams;
	gfx::ProgramParam*										_paramOffset;
	BaseFont*												_font;
	Bool													_rectEnabled;
	lang::Rect												_rect;
	lang::Point												_offset;
	Order													_groupOrder;
	Order													_order;
	UInt													_size;
	gfx::Ndc*												_ndc;
	Bool													_dirty;
};


#include "TextPool.inl"


} // over


} // synkro


#endif // _SYNKRO_OVER_TEXTPOOL_
