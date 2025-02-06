// This file is a part of the Synkro Framework.
// 
// Copyright (c) Nobody. No rights reserved ;-7
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is allowed without any permission from the Synkro Project.
// Website: https://synkro.pro Email: mailto:blindharper70@gmail.com
//
// Purpose: Label widget implementation.
//==============================================================================
#include "config.h"
#include "Label.h"
#include "Frame.h"
#include "AlignmentConst.h"


//------------------------------------------------------------------------------

using namespace synkro::img;
using namespace synkro::lang;
using namespace synkro::over;

//------------------------------------------------------------------------------


namespace synkro
{


namespace ui
{


Label::Label( BaseUiEx* ui, IFrame* parent, UInt id, const Point& location, const Size& size, const String& text ) :
	WidgetImpl<ILabel>( nullptr, ((Frame*)parent)->GetInnerFrame(), location, size ),
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>( this ),
	_uiEx( ui ),
	_widgetID( id ),
	_backColor( Color::Gray ),
	_transparent( true ),
	_align( Alignment::Center )
{
	_tabOrder = none;
	((Frame*)parent)->AddWidget( this );
	_text = _uiEx->GetFont()->CreateText( Color::White, _rect.TopLeft(), text );
	_text->EnableRect( true );
	Update();
}

void Label::SetLocation( const Point& location )
{
	// Call base implementation.
	WidgetImpl::SetLocation( location );

	if ( _back != nullptr )
	{
		_back->SetLocation( _rect.TopLeft() );
	}
	Update();

	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
}

void Label::SetSize( const Size& size )
{
	// Call base implementation.
	WidgetImpl::SetSize( size );

	if ( _back != nullptr )
	{
		_back->SetSize( _size );
	}
	Update();
	
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
}

void Label::SetTransparent( Bool transparent )
{
	_transparent = transparent;
	if ( !_transparent )
	{
		if ( _back == nullptr )
		{
			_back = _uiEx->CreateQuad( Order::Normal, Order::BelowNormal, _rect.TopLeft(), _size, _backColor );
			_back->EnableRect( true );
			Rect rc; _parent->GetRect( rc );
			_back->SetRect( rc );
		}
		_back->Show( true );
	}
	else
	{
		if ( _back != nullptr )
		{
			_back->Show( false );
		}
	}
}

void Label::Update()
{
	Point pt;

	if ( _align == Alignment::TopLeft )
	{
		pt = _rect.TopLeft();
	}
	else
	{
		const Rect rc = _rect.Deflated( 1, 1 );
		Size sz; _text->GetFont()->GetTextSize( _text->GetText(), sz );
		const Int dx = (rc.Width() - sz.Width) / 2L;
		const Int dy = (rc.Height() - sz.Height) / 2L;

		switch ( _align )
		{
			case ALIGNMENT_TOP:
				pt.Set( rc.Left+dx, rc.Top );
				break;

			case ALIGNMENT_TOP_RIGHT:
				pt.Set( rc.Right-sz.Width+1, rc.Top );
				break;

			case ALIGNMENT_LEFT:
				pt.Set( rc.Left, rc.Top+dy );
				break;

			case ALIGNMENT_CENTER:
				pt.Set( rc.Left+dx, rc.Top+dy );
				break;

			case ALIGNMENT_RIGHT:
				pt.Set( rc.Right-sz.Width+1, rc.Top+dy );
				break;

			case ALIGNMENT_BOTTOM_LEFT:
				pt.Set( rc.Left, rc.Bottom-sz.Height+1 );
				break;

			case ALIGNMENT_BOTTOM:
				pt.Set( rc.Left+dx, rc.Bottom-sz.Height+1 );
				break;

			case ALIGNMENT_BOTTOM_RIGHT:
				pt.Set( rc.Right-sz.Width+1, rc.Bottom-sz.Height+1 );
				break;
		}
	}

	Rect rc; _parent->GetRect( rc );
	_text->SetRect( rc );
	_text->SetLocation( pt );

	if ( _back != nullptr )
	{
		_back->SetRect( rc );
		_back->SetLocation( _rect.TopLeft() );
		_back->SetSize( Size(_rect.Width(), _rect.Height()) );
	}
}


} // ui


} // synkro
