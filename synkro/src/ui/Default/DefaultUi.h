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
// Purpose: Default user interface.
//==============================================================================
#ifndef _SYNKRO_UI_DEFAULTUI_
#define _SYNKRO_UI_DEFAULTUI_


#include "config.h"
#include <core/ObjectImpl.h>
#include <ui/IUi.h>
#include <ui/ITheme.h>
#include <over/IOverlayManager.h>
#include <over/IOverlay.h>
#include <gfx/IBlendStateSet.h>
#include <gfx/IBlendState.h>
#include "DefaultFrame.h"
#include <ui/BaseUi.h>


namespace synkro
{


namespace ui
{


// Default user interface.
class DefaultUi :
	public core::ObjectImpl<IUi>,
	public BaseUi,
	public Logger
{
public:
	// Constructor.
	DefaultUi( gfx::IGraphicsSystemEx* graphicsSystem, anim::IAnimationSystem* animationSystem, over::IOverlayManager* overlayManager, ITheme* theme, diag::ILog* log );

	// ISystem methods.
	Bool													Update( Double delta );

	// IUi methods.
	IFrame*													CreateFrame( IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size, Bool showBorder );
	IAccordion*												CreateAccordion( IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size );
	IAngle*													CreateAngle( IFrame* parent, UInt id, const lang::Point& location, const img::Color& color );
	IButton*												CreateButton( IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size, const lang::String& text, const img::Color& color );
	IDropList*												CreateDropList( IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size, UInt capacity );
	IEdit*													CreateEdit( IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size, const lang::String& text, const EditStyle& style );
	IList*													CreateList( IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size, UInt capacity );
	IOption*												CreateOption( IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size, const lang::String& text, Bool selected, const img::Color& color );
	IProgress*												CreateProgress( IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size, const ProgressType& type, const img::Color& color );
	ISlider*												CreateSlider( IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size, const Orientation& orientation, UInt minPosition, UInt maxPosition, const img::Color& color );
	ISwitch*												CreateSwitch( IFrame* parent, UInt id, const lang::Point& location, UInt width, const lang::String& text, Bool on, const img::Color& color );
	void													SetTheme( ITheme* theme );
	void													SetBackColor( const img::Color& color );
	ITheme*													GetTheme() const;
	void													GetBackColor( img::Color& color ) const;

	// BaseUi methods.
	gfx::IOverlayRenderObject*								CreateObject( const gfx::PrimitiveType& type, const gfx::IndexType& indexType, UInt vertexCount, UInt indexCount, UInt order );
	gfx::IOverlayRenderObject*								CreateLineObject( const gfx::PrimitiveType& type, UInt vertexCount, UInt order );
	gfx::IRect*												CreateScissorRect( Int left, Int top, Int right, Int bottom );
	WidgetEffect*											CreateEffect( gfx::IOverlayRenderObject* widget, gfx::IOverlayRenderObject* widget2, over::IText* text );
	over::ITextPool*										CreateTextPool( over::IFont* font, UInt capacity );
	over::ISprite*											CreateSprite( img::IImage* image, const lang::Point& location, const lang::Size& size );
	over::IQuad*											CreateQuad( const over::Order& groupOrder, const over::Order& order, const lang::Point& location, const lang::Size& size, const img::Color& color );
	over::IFont*											GetFont() const;
	ITheme*													Theme() const;

private:
	gfx::IGraphicsSystemEx*									_graphicsSystem;
	anim::IAnimationSystem*									_animationSystem;
	over::IOverlayManager*									_overlayManager;
	over::IOverlay*											_overlay;
	P(gfx::IBlendStateSet)									_blendStates;
	ITheme*													_theme;
	over::IFont*											_font;
	P(DefaultFrame)											_root;
	img::Color												_backColor;
};


#include "DefaultUi.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_DEFAULTUI_
