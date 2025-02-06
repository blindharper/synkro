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
#include "config.h"
#include "Accordion.h"
#include "Button.h"
#include "Frame.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace ui
{


Accordion::Accordion( BaseUiEx* ui, UInt id, IFrame* parent, IAccordion* accordion ) :
	FrameImpl<IAccordion>( parent, ToLocation(accordion), ToSize(accordion) ),
	BaseAnchoredObjectImpl<BaseAnchoredObject, IFrame>( accordion ),
	_ui( ui ),
	_accordion( accordion ),
	_accordionID( id ),
	_activeWidgets( A(ActiveItem) )
{
	if ( parent != nullptr )
	{
		((Frame*)parent)->AddFrame( this );
	}
	_borderVisible = accordion->IsBorderVisible();

	// Intercept header clicks.
	_ui->DoListen( this );
}

void Accordion::Show( Bool show )
{
	// Call base implementation.
	FrameImpl<IAccordion>::Show( show );

	_accordion->Show( _visible );
}

void Accordion::ShowBorder( Bool show )
{
	// Call base implementation.
	FrameImpl<IAccordion>::ShowBorder( show );

	_accordion->ShowBorder( _borderVisible );
}

void Accordion::SetLocation( const Point& location )
{
	// Call base implementation.
	FrameImpl<IAccordion>::SetLocation( location );

	_accordion->SetLocation( location );

	BaseAnchoredObjectImpl<BaseAnchoredObject, IFrame>::SaveAnchors();
}

void Accordion::SetSize( const Size& size )
{
	// Call base implementation.
	FrameImpl<IAccordion>::SetSize( size );

	_accordion->SetSize( size );

	BaseAnchoredObjectImpl<BaseAnchoredObject, IFrame>::SaveAnchors();
}

void Accordion::SetAnchor( const Anchor& anchor )
{
	// Call base implementation.
	FrameImpl<IAccordion>::SetAnchor( anchor );

	_accordion->SetAnchor( anchor );

	BaseAnchoredObjectImpl<BaseAnchoredObject, IFrame>::SaveAnchors();
}

IFrame* Accordion::CreatePanel( const String& text )
{
	IFrame* innerPanel = _accordion->CreatePanel( text );
	IFrame* panel = new Frame( innerPanel->ID(), this, innerPanel );

	IButton* hdr = _accordion->GetWidget( _accordion->GetWidgetCount()-1 )->AsButton();
	IButton* btn = new Button(_ui, hdr->ID(), panel, hdr);
	AddWidget( btn );
	btn->Show( true );

	AddFrame( panel );
	return panel;
}

void Accordion::SetTheme( ITheme* theme )
{
	// Do nothing.
}

void Accordion::AddWidget( IWidget* widget )
{
	assert( widget != nullptr );

	_widgets.Add( widget );

	if ( widget->GetTabOrder() != none )
	{
		widget->SetTabOrder( _activeWidgets.Size() );
		_activeWidgets.Add( widget );
	}
}

void Accordion::AddFrame( IFrame* frame )
{
	assert( frame != nullptr );

	_frames.Add( frame );
}

void Accordion::OnOptionSelected( BaseOption* option )
{
	for ( UInt i = 0; i < _widgets.Size(); ++i )
	{
		BaseOption* opt = AsBaseOption( _widgets[i].AsPtr() );
		if ( (opt != nullptr) && (opt != option) )
		{
			opt->Unselect();
		}
	}
}

void Accordion::UpdateTabOrder()
{
	_activeWidgets.Sort();
}

IWidget* Accordion::GetNextWidget( IWidget* widget ) const
{
	// Search widgets.
	UInt index = (_activeWidgets.Size() > 0) ? 0 : none;
	if ( widget != nullptr )
	{
		index = _activeWidgets.IndexOf( widget );
		if ( index != none )
		{
			widget = nullptr;
			++index;
		}
	}
	for ( ; index < _activeWidgets.Size(); ++index )
	{
		IWidget* w = _activeWidgets[index].Widget;
		if ( w->IsEnabled() && w->IsVisible() )
			return w;
	}

	// Search in children frames.
	for ( UInt i = 0; i < _frames.Size(); ++i )
	{
		BaseFrame* frame = AsBaseFrame( _frames[i].AsPtr() );
		IWidget* next = frame->GetNextWidget( widget );
		if ( next != nullptr )
			return next;
	}

	return nullptr;
}

IWidget* Accordion::GetPrevWidget( IWidget* widget ) const
{
	// Search widgets.
	UInt index = (_activeWidgets.Size() > 0) ? _activeWidgets.Size()-1 : none;
	if ( widget != nullptr )
	{
		index = _activeWidgets.IndexOf( widget );
		if ( index == 0 )
		{
			return nullptr;
		}
		else if ( index != none )
		{
			--index;
			IWidget* w = _activeWidgets[index].Widget;
			if ( w->IsEnabled() && w->IsVisible() )
				return w;
		}
		else
		{
			index = _activeWidgets.Size()-1;
		}
	}

	// Search in children frames.
	for ( UInt i = 0; i < _frames.Size(); ++i )
	{
		BaseFrame* frame = AsBaseFrame( _frames[_frames.Size()-1-i].AsPtr() );
		IWidget* prev = frame->GetPrevWidget( widget );
		if ( prev != nullptr )
			return prev;
	}

	for ( ; index >= 0; --index )
	{
		IWidget* w = _activeWidgets[index].Widget;
		if ( w->IsEnabled() && w->IsVisible() )
			return w;
	}

	return nullptr;
}

IFrame* Accordion::GetInnerFrame() const
{
	return _accordion;
}

Bool Accordion::OnUiClick( IWidget* sender )
{
	UInt index = GetWidgetIndex( sender );
	if ( index != none )
	{
		ExpandPanel( index, !IsPanelExpanded(index) );
		return true;
	}

	return false;
}

Bool Accordion::OnUiDoubleClick( IWidget* sender )
{
	return false;
}

Bool Accordion::OnUiValueChanged( IWidget* sender )
{
	return false;
}

UInt Accordion::GetWidgetIndex( IWidget* widget ) const
{
	for ( UInt i = 0; i < _widgets.Size(); ++i )
	{
		if ( _widgets[i] == widget )
			return i;
	}
	return none;
}


} // ui


} // synkro
