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
// Purpose: Logical slider widget.
//==============================================================================
#ifndef _SYNKRO_UI_SLIDER_
#define _SYNKRO_UI_SLIDER_


#include "config.h"
#include "WidgetWrapperImpl.h"
#include <ui/ISlider.h>
#include "BaseWidgetImpl.h"
#include "BaseAnchoredObjectImpl.h"


namespace synkro
{


namespace ui
{


// Logical slider widget.
class Slider :
	public WidgetWrapperImpl<ISlider>,
	public BaseWidgetImpl<BaseWidget>,
	public BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>
{
public:
	// Constructor.
	Slider( BaseUiEx* ui, UInt id, IFrame* parent, ISlider* widget );

	// IWidget methods.
	void													Activate( Bool activate );
	void													SetLocation( const lang::Point& location );
	void													SetSize( const lang::Size& size );
	void													SetAnchor( const Anchor& anchor );
	ISlider*												AsSlider() const;

	// ISlider methods.
	void													Highlight( Bool highlight );
	void													SetMinPosition( UInt minPosition );
	void													SetMaxPosition( UInt maxPosition );
	void													SetPosition( UInt position );
	Orientation												GetOrientation() const;
	UInt													GetMinPosition() const;
	UInt													GetMaxPosition() const;
	UInt													GetPosition() const;
	void													GetThumbSize( lang::Size& size ) const;

	// BaseWidget methods.
	UiEvent													OnKeyDown( Double deltaTime, const input::Key& key, Bool alt, Bool shift, Bool control );
	UiEvent													OnMouseMove( const lang::Point& location );
	UiEvent													OnMouseScroll( Int delta );
	UiEvent													OnMouseEnter();
	UiEvent													OnMouseLeave();
	UiEvent													OnMouseDown( const lang::Point& location );
	UiEvent													OnMouseUp();

private:
	P(ISlider)												_slider;
	lang::Point												_cursor;
	lang::Point												_cursorOrg;
	Bool													_down;
	Bool													_moved;

	Bool													AdjustPercentage( Float delta );
};


#include "Slider.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_SLIDER_
