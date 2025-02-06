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
// Purpose: Logical accordion container.
//==============================================================================
#ifndef _SYNKRO_UI_ACCORDION_
#define _SYNKRO_UI_ACCORDION_


#include "config.h"
#include "FrameImpl.h"
#include <ui/IAccordion.h>
#include "BaseWidget.h"
#include "BaseFrame.h"
#include "BaseAnchoredObjectImpl.h"
#include "BaseUiEx.h"
#include <ui/UiListener.h>


namespace synkro
{


namespace ui
{


// Accordion container implementation.
class Accordion :
	public FrameImpl<IAccordion>,
	public BaseFrame,
	public BaseAnchoredObjectImpl<BaseAnchoredObject, IFrame>,
	public UiListener
{
public:
	// Constructor.
	Accordion( BaseUiEx* ui, UInt id, IFrame* parent, IAccordion* accordion );

	// IObject methods.
	UInt													ID() const;

	// IFrame methods.
	void													Show( Bool show );
	void													ShowBorder( Bool show );
	void													SetLocation( const lang::Point& location );
	void													SetSize( const lang::Size& size );
	void													SetAnchor( const Anchor& anchor );
	IAccordion*												AsAccordion() const;

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

	// UiListener methods.
	Bool													OnUiClick( IWidget* sender );
	Bool													OnUiDoubleClick( IWidget* sender );
	Bool													OnUiValueChanged( IWidget* sender );

private:
	struct ActiveItem
	{
		ActiveItem( IWidget* widget ) :
			Widget( widget )
		{
		}

		ActiveItem()
		{
		}

		Bool operator<( const ActiveItem& other ) const
		{
			return this->Widget->GetTabOrder() < other.Widget->GetTabOrder();
		}

		Bool operator==( const ActiveItem& other ) const
		{
			return this->Widget == other.Widget;
		}

		IWidget*	Widget;
	};

	BaseUiEx*												_ui;
	P(IAccordion)											_accordion;
	UInt													_accordionID;
	lang::Vector<ActiveItem>								_activeWidgets;

	lang::Point												ToLocation( IAccordion* accordion ) const;
	lang::Size												ToSize( IAccordion* accordion ) const;
	UInt													GetWidgetIndex( IWidget* widget ) const;
};


#include "Accordion.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_ACCORDION_
