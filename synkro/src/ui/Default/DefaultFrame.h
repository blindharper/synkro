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
// Purpose: Default frame container implementation.
//==============================================================================
#ifndef _SYNKRO_UI_DEFAULTFRAME_
#define _SYNKRO_UI_DEFAULTFRAME_


#include "config.h"
#include <ui/FrameImpl.h>
#include <gfx/IOverlayRenderObject.h>
#include <gfx/IParameterSet.h>
#include <gfx/ProgramParam.h>
#include <lang/Vector.h>
#include <ui/BaseWidget.h>
#include <ui/BaseFrame.h>
#include <ui/BaseUi.h>


namespace synkro
{


namespace ui
{


// Default frame container implementation.
class DefaultFrame :
	public FrameImpl<IFrame>,
	public BaseFrame
{
public:
	// Constructor.
	DefaultFrame( BaseUi* ui, IFrame* parent, const lang::Point& location, const lang::Size& size, Bool showBorder );

	// IFrame methods.
	void													Show( Bool show );
	void													ShowBorder( Bool show );
	void													SetLocation( const lang::Point& location );
	void													SetSize( const lang::Size& size );

	// BaseFrame methods.
	void													SetTheme( ITheme* theme );
	void													AddWidget( IWidget* widget );
	void													AddFrame( IFrame* frame );
	void													OnOptionSelected( BaseOption* option );
	void													UpdateTabOrder();
	IWidget*												GetNextWidget( IWidget* widget ) const;
	IWidget*												GetPrevWidget( IWidget* widget ) const;
	IFrame*													GetInnerFrame() const;

	// Other methods.
	void													UpdateRect();

private:
	BaseUi*													_ui;
	P(gfx::IOverlayRenderObject)							_border;
	gfx::ProgramParam*										_paramColor;
	P(gfx::IRect)											_scissorRect;

	void													Update();
};


#include "DefaultFrame.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_DEFAULTFRAME_
