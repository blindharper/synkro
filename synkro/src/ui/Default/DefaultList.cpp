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
// Purpose: Default list widget implementation.
//==============================================================================
#include "config.h"
#include "DefaultList.h"


//------------------------------------------------------------------------------

using namespace synkro::gfx;
using namespace synkro::lang;
using namespace synkro::math;
using namespace synkro::img;
using namespace synkro::io;
using namespace synkro::input;
using namespace synkro::over;

//------------------------------------------------------------------------------


namespace synkro
{


namespace ui
{


DefaultList::DefaultList( BaseUi* ui, IFrame* parent, const Point& location, const Size& size, UInt capacity ) :
	ListImpl<IList>( ui, parent, location, size ),
	_texts2( A(IText*) )
{
	Size sz;
	IFont* font = ui->GetFont();
	font->GetTextSize( L"A", sz );
	_itemHeight = sz.Height+4;

	// Setup list.
	_object = _ui->CreateObject( PrimitiveType::TriangleList, IndexType::Short, 16, 54, _zOrder+2 );
	_paramColor = _object->GetFragmentParameters()->GetParam( L"p_color" );
	SetColor( Color::White );
	SetIndicesCentered( _object );
	Rect listRect; _ui->Theme()->GetListRect( listRect );
	Rect listCenter; _ui->Theme()->GetListCenter( listCenter );
	SetTextureCoordinates( _object, listRect, listCenter );

	// Setup highlight.
	Color highlightColor; _ui->Theme()->GetWidgetColor( WidgetState::Normal, highlightColor );
	const Int top = _rect.Top + _selectedIndex*_itemHeight + 2;
	_highlight = _ui->CreateQuad( Order::High, Order::High, Point(_rect.Left+2, top), Size(_rect.Width()-4, _itemHeight), highlightColor );
	_highlight->Show( false );
	UpdateHighlight();

	// Setup texts.
	_texts = ui->CreateTextPool( font, (capacity > 0) ? capacity : 1000 );

	Update();
	Rect rect( _visibleRect );
	rect.Right -= 4;
	_texts->SetRect( rect );
	_texts->EnableRect( true );
}

void DefaultList::Show( Bool show )
{
	// Call base implementation.
	ListImpl<IList>::Show( show );

	_texts->Enable( show );
	_highlight->Show( show && (_selectedIndex != none) );
}

void DefaultList::AddItem( const ListItem& item )
{
	// Call base implementation.
	ListImpl<IList>::AddItem( item );

	const Int top = _rect.Top + (_items.Size()-1)*_itemHeight + 4;
	IText* txt = _texts->CreateText( Color::White, Point(_rect.Left+4, top), item.Text );
	_texts2.Add( txt );
}

void DefaultList::InsertItem( UInt index, const ListItem& item )
{
	// Call base implementation.
	ListImpl<IList>::InsertItem( index, item );

	// Append new item.
	const Int top = _rect.Top + (_items.Size() - 1)*_itemHeight+4;
	IText* txt = _texts->CreateText( Color::White, Point(_rect.Left+4, top), String::Empty );
	_texts2.Add( txt );

	// Move bottom items down.
	for ( UInt i = _texts2.Size()-1; i > index; --i )
	{
		_texts2[i]->SetText( _texts2[i-1]->GetText() );
	}

	// Set item text.
	_texts2[index]->SetText(item.Text);

	// Update selection, if needed.
	if (_selectedIndex != none)
	{
		if ( index <= _selectedIndex )
		{
			++_selectedIndex;
		}
		UpdateSelection(_selectedIndex);
	}
}

void DefaultList::SetItemText( UInt index, const String& text )
{
	// Call base implementation.
	ListImpl<IList>::SetItemText( index, text );

	_texts->GetText( index )->SetText( text );
}

void DefaultList::SelectItem( UInt index )
{
	// Call base implementation.
	ListImpl<IList>::SelectItem( index );

	UpdateSelection( index );
}

void DefaultList::RemoveItem( UInt index )
{
	// Call base implementation.
	ListImpl<IList>::RemoveItem( index );

	// Move bottom items up.
	for ( UInt i = index; i < _texts2.Size()-1; ++i )
	{
		_texts2[i]->SetText( _texts2[i+1]->GetText() );
	}
	// Remove last item.
	_texts2.LastValue()->SetText( String::Empty );
	_texts2.Remove( _texts2.Size()-1 );

	// Update selection, if needed.
	if ( _selectedIndex != none )
	{
		if ( (index <= _selectedIndex) && (_selectedIndex > 0) )
		{
			--_selectedIndex;
		}
		UpdateSelection( _selectedIndex );
	}
}

void DefaultList::Clear()
{
	// Call base implementation.
	ListImpl<IList>::Clear();

	for ( UInt i = 0; i < _texts2.Size(); ++i )
	{
		_texts2[i]->SetText( String::Empty );
		_texts2[i]->Release();
		_texts2.Remove( i );
	}

	UpdateSelection( none );
}

void DefaultList::ClearSelection()
{
	// Call base implementation.
	ListImpl<IList>::ClearSelection();

	UpdateSelection( none );
}

UInt DefaultList::GetItemAt( const Point& location ) const
{
	Rect rc;
	for ( UInt i = 0; i < _items.Size(); ++i )
	{
		const Int top = _rect.Top + i*_itemHeight;
		const Int bottom = _rect.Top + (i+1)*_itemHeight;
		rc.Set( _rect.Left, top, _rect.Left+CastInt(_size.Width), bottom );
		if ( rc.IsInside(location) )
			return i;
	}
	return none;
}

void DefaultList::Update()
{
	Rect listRect; _ui->Theme()->GetListRect( listRect );
	Rect listCenter; _ui->Theme()->GetListCenter( listCenter );
	SetPositions( _object, _rect.TopLeft(), _size, listRect, listCenter );
	UpdateSelection( _selectedIndex );
}

void DefaultList::UpdateSelection( const Point& location )
{
	Rect rc;
	_selectedIndex = none;
	for ( UInt i = 0; i < _items.Size(); ++i )
	{
		const Int top = _rect.Top + i*_itemHeight;
		const Int bottom = _rect.Top + (i+1)*_itemHeight;
		rc.Set( _rect.Left, top, _rect.Left+CastInt(_size.Width), bottom );
		const Bool inside = rc.IsInside( location );
		if ( inside )
		{
			_selectedIndex = i;
		}
		_texts->GetText( i )->SetColor( inside ? Color::Yellow : Color::White );
	}
	UpdateHighlight();
}

void DefaultList::UpdateSelection( UInt index )
{
	_selectedIndex = _items.IsEmpty() ? none : index;
	for ( UInt i = 0; i < _items.Size(); ++i )
	{
		const Bool selected = (i == index);
		_texts->GetText( i )->SetColor( selected ? Color::Yellow : Color::White );
	}
	UpdateHighlight();
}

void DefaultList::UpdateHighlight()
{
	if ( _selectedIndex != none )
	{
		const Int top = _rect.Top + _selectedIndex*_itemHeight + 2;
		_highlight->SetLocation( Point(_rect.Left+2, top) );
	}
	_highlight->Show( _selectedIndex != none );
}


} // ui


} // synkro
