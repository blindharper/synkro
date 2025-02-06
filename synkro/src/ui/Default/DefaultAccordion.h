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
// Purpose: Default accordion container implementation.
//==============================================================================
#ifndef _SYNKRO_UI_DEFAULTACCORDION_
#define _SYNKRO_UI_DEFAULTACCORDION_


#include "config.h"
#include <ui/FrameImpl.h>
#include <ui/IAccordion.h>
#include <ui/IButton.h>
#include <ui/BaseFrame.h>
#include <ui/BaseUi.h>
#include <gfx/IOverlayRenderObject.h>
#include <gfx/IParameterSet.h>
#include <gfx/ProgramParam.h>
#include <lang/Vector.h>


namespace synkro
{


namespace ui
{


// Default accordion container implementation.
class DefaultAccordion :
	public FrameImpl<IAccordion>,
	public BaseFrame
{
public:
	// Constructor.
	DefaultAccordion( BaseUi* ui, IFrame* parent, const lang::Point& location, const lang::Size& size);

	// IFrame methods.
	void													Show( Bool show );
	void													ShowBorder( Bool show );
	void													SetLocation( const lang::Point& location );
	void													SetSize( const lang::Size& size );

	// IAccordion methods.
	IFrame*													CreatePanel( const lang::String& text );
	void													ExpandPanel( UInt index, Bool expand );
	UInt													GetPanelCount() const;
	IFrame*													GetPanel( UInt index ) const;
	lang::String											GetPanelText( UInt index ) const;
	Bool													IsPanelExpanded( UInt index ) const;

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
	enum
	{
		BORDER_SIZE = 4,
		HEADER_HEIGHT = 20,
	};

	BaseUi*													_ui;
	P(gfx::IOverlayRenderObject)							_border;
	gfx::ProgramParam*										_paramColor;
	P(gfx::IRect)											_scissorRect;

	void													Arrange();
	void													Update();
};


#include "DefaultAccordion.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_DEFAULTACCORDION_
