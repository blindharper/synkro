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
// Purpose: Logical angle widget.
//==============================================================================
#ifndef _SYNKRO_UI_ANGLE_
#define _SYNKRO_UI_ANGLE_


#include "config.h"
#include "WidgetWrapperImpl.h"
#include <ui/IAngle.h>
#include "BaseWidgetImpl.h"
#include "BaseAnchoredObjectImpl.h"


namespace synkro
{


namespace ui
{


// Logical angle widget.
class Angle :
	public WidgetWrapperImpl<IAngle>,
	public BaseWidgetImpl<BaseWidget>,
	public BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>
{
public:
	// Constructor.
	Angle( BaseUiEx* ui, UInt id, IFrame* parent, IAngle* widget );

	// IWidget methods.
	void													Activate( Bool activate );
	void													SetLocation( const lang::Point& location );
	void													SetSize( const lang::Size& size );
	void													SetAnchor( const Anchor& anchor );
	IAngle*													AsAngle() const;

	// IAngle methods.
	void													Highlight( Bool highlight );
	void													SetValue( Float value );
	Float													GetValue() const;

	// BaseWidget methods.
	UiEvent													OnKeyDown( Double deltaTime, const input::Key& key, Bool alt, Bool shift, Bool control );
	UiEvent													OnMouseMove( const lang::Point& location );
	UiEvent													OnMouseScroll( Int delta );
	UiEvent													OnMouseEnter();
	UiEvent													OnMouseLeave();
	UiEvent													OnMouseDown( const lang::Point& location );
	UiEvent													OnMouseUp();

private:
	P(IAngle)												_angle;
	lang::Point												_cursor;
	lang::Point												_cursorOrg;
	Bool													_down;
	Bool													_moved;

	Bool													LocationToValue( const lang::Point& location );
	void													AdjustValue( Float delta );
};


#include "Angle.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_ANGLE_
