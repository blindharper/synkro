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
// Purpose: Default drop list widget implementation.
//==============================================================================
#include "config.h"
#include "DefaultDropList.h"


//------------------------------------------------------------------------------

using namespace synkro::gfx;
using namespace synkro::lang;
using namespace synkro::img;
using namespace synkro::input;
using namespace synkro::over;

//------------------------------------------------------------------------------


namespace synkro
{


namespace ui
{


DefaultDropList::DefaultDropList( BaseUi* ui, IFrame* parent, const Point& location, const Size& size, UInt capacity ) :
	ListImpl<IDropList>( ui, parent, location, size ),
	_texts2( A(IText*) ),
	_highlightedIndex( none ),
	_expanded( false )
{
	Size sz;
	IFont* font = ui->GetFont();
	font->GetTextSize( L"A", sz );
	_itemHeight = sz.Height+4;

	// Setup text box.
	_object = _ui->CreateObject( PrimitiveType::TriangleList, IndexType::Short, 16, 54, _zOrder );
	_paramColor = _object->GetFragmentParameters()->GetParam( L"p_color" );
	SetIndicesCentered( _object );
	Rect rect; _ui->Theme()->GetEditRect( rect );
	Rect center; _ui->Theme()->GetEditCenter( center );
	SetTextureCoordinates( _object, rect, center );

	// Create button with arrow.
	_object2 = _ui->CreateObject( PrimitiveType::TriangleList, IndexType::Short, 16, 54, _zOrder );
	_paramColor2 = _object2->GetFragmentParameters()->GetParam( L"p_color" );
	SetIndicesCentered( _object2 );
	Rect rectButton; _ui->Theme()->GetButtonRect( rectButton );
	Rect centerButton; _ui->Theme()->GetButtonCenter( centerButton );
	SetTextureCoordinates( _object2, rectButton, centerButton );
	_arrow = _ui->GetFont()->CreateText(_textColors[WidgetState::Normal], Point(), L"▼", Order::Normal, Order::AboveNormal );
	_effect = _ui->CreateEffect( _object2, nullptr, _arrow );

	// Create item list.
	_object3 = _ui->CreateObject( PrimitiveType::TriangleList, IndexType::Short, 16, 54, _zOrder-2 );
	_paramColor3 = _object3->GetFragmentParameters()->GetParam( L"p_color" );
	SetIndicesCentered( _object3 );
	Rect rectList; _ui->Theme()->GetListRect( rectList );
	Rect centerList; _ui->Theme()->GetListCenter( centerList );
	SetTextureCoordinates( _object3, rectList, centerList );

	// Setup highlight.
	Color highlightColor; _ui->Theme()->GetWidgetColor( WidgetState::Normal, highlightColor );
	_highlight = _ui->CreateQuad( Order::Normal, Order::Highest, Point(0, 0), Size(_rect.Width()-4, _itemHeight), highlightColor );

	// Setup texts.
	_text = _ui->GetFont()->CreateText( Color::White, Point(), String::Empty, Order::Normal, Order::AboveNormal );
	_text->EnableRect( true );

	_texts = ui->CreateTextPool( font, (capacity > 0) ? capacity : 1000 );
	_texts->Enable( false );

	_collapsedSize = _size;

	SetListHeight( 1 );
	Expand( false );
	Update();
}

void DefaultDropList::Show( Bool show )
{
	// Call base implementation.
	ListImpl<IDropList>::Show( show );

	_arrow->Show( show );
	_texts->Enable( show && _expanded );
	_highlight->Show( show && _expanded );
	Expand( _expanded );
}

void DefaultDropList::AddItem( const ListItem& item )
{
	// Call base implementation.
	ListImpl<IDropList>::AddItem( item );

	const Int top = _rect.Top + _items.Size() * _itemHeight + 10;
	IText* txt = _texts->CreateText( Color::White, Point(_rect.Left+8, top), item.Text );
	_texts2.Add( txt );
}

void DefaultDropList::InsertItem( UInt index, const ListItem& item )
{
	// Call base implementation.
	ListImpl<IDropList>::InsertItem( index, item );
}

void DefaultDropList::SetItemText( UInt index, const String& text )
{
	// Call base implementation.
	ListImpl<IDropList>::SetItemText( index, text );

	_texts->GetText( index )->SetText( text );
}

void DefaultDropList::SelectItem( UInt index )
{
	// Call base implementation.
	ListImpl<IDropList>::SelectItem( index );

	_text->SetText( (index != none) ? _items[index].Text : String::Empty );

	UpdateSelection( index );
}

void DefaultDropList::RemoveItem( UInt index )
{
	// Call base implementation.
	ListImpl<IDropList>::RemoveItem( index );
}

void DefaultDropList::Clear()
{
	// Call base implementation.
	ListImpl<IDropList>::Clear();

	for ( UInt i = 0; i < _texts2.Size(); ++i )
	{
		_texts2[i]->Release();
	}
	_texts2.Clear();

	UpdateSelection( none );
}

UInt DefaultDropList::GetItemAt( const Point& location ) const
{
	if ( !IsExpanded() )
		return none;

	Rect rc;
	for ( UInt i = 0; i < _items.Size(); ++i )
	{
		const Int top = _rect.Top + (i+1)*_itemHeight + 8;
		const Int bottom = _rect.Top + (i+2)*_itemHeight + 8;
		rc.Set( _rect.Left, top, _rect.Left+CastInt(_size.Width), bottom );
		if ( rc.IsInside(location) )
			return i;
	}
	return none;
}

void DefaultDropList::Expand( Bool expand )
{
	_expanded = expand;
	_object3->Enable( expand );
	_texts->Enable( expand );
	
	UInt totalHeight = _collapsedSize.Height;
	if ( IsExpanded() )
	{
		totalHeight += _itemHeight * _listHeight + 4;
		_highlightedIndex = _selectedIndex;
	}
	else
	{
		_highlightedIndex = none;
	}

	// Call base implementation.
	WidgetImpl<IDropList>::SetSize( Size(_collapsedSize.Width, totalHeight) );

	Update();
}

void DefaultDropList::Highlight( Bool highlight )
{
	const WidgetState normal = _active ? WidgetState::Active : WidgetState::Normal;
	const WidgetState from = highlight ? normal : WidgetState::Hovered;
	const WidgetState to = highlight ? WidgetState::Hovered : normal;
	_effect->Fade( _widgetColors[from], _widgetColors[to], _textColors[from], _textColors[to] );
}

void DefaultDropList::HighlightItem( UInt index )
{
	if ( !_expanded )
		return;

	if ( index == none )
	{
		index = _selectedIndex;
	}
	if ( index != none )
	{
		const Int top = _rect.Top + (index + 1) * _itemHeight + 8;
		_highlight->SetLocation( Point(_rect.Left + 2, top) );
	}
	_highlightedIndex = index;
}

void DefaultDropList::SetListHeight( UInt height )
{
	if ( height != _listHeight )
	{
		_listHeight = height;
		Rect rectList; _ui->Theme()->GetListRect( rectList );
		Rect centerList; _ui->Theme()->GetListCenter( centerList );
		const Point locList = Point(_rect.Left, _rect.Top + _rect.Height());
		SetPositions( _object3, locList, Size(_size.Width, _itemHeight * _listHeight), rectList, centerList );
	}
}

void DefaultDropList::SetTheme( ITheme* theme )
{
	// Call base implementation.
	BaseThemeWidgetImpl<BaseThemeWidget>::SetTheme( theme );

	_object->SetFragmentResources( theme->GetResources() );
	_object2->SetFragmentResources( theme->GetResources() );
	_object3->SetFragmentResources( theme->GetResources() );

	const WidgetState state = _enabled ? WidgetState::Normal : WidgetState::Disabled;
	SetColor( _widgetColors[state], true );
	_arrow->SetColor( _textColors[state] );
}

void DefaultDropList::Update()
{
	Rect rectButton; _ui->Theme()->GetButtonRect( rectButton );
	Rect centerButton; _ui->Theme()->GetButtonCenter( centerButton );
	const Int height = _collapsedSize.Height;

	Rect rect; _ui->Theme()->GetEditRect( rect );
	Rect center; _ui->Theme()->GetEditCenter( center );
	SetPositions( _object, _rect.TopLeft(), Size(_collapsedSize.Width-height, _collapsedSize.Height), rect, center );
	
	const Point locButton = Point( _rect.Right-height, _rect.Top );
	SetPositions( _object2, locButton, Size(height, height), rectButton, centerButton );

	Rect rectList; _ui->Theme()->GetListRect( rectList );
	Rect centerList; _ui->Theme()->GetListCenter( centerList );
	const Point locList = Point( _rect.Left, _rect.Top+height );
	SetPositions( _object3, locList, Size(_size.Width, _itemHeight*_listHeight+6), rectList, centerList );

	_arrow->SetLocation( Point(locButton.X+7, locButton.Y+6) );
	_text->SetLocation( Point(_rect.Left+8, _rect.Top+6) );
	Rect rectText( _visibleRect );
	rectText.Right -= (height+8);
	_text->SetRect( rectText );

	for ( UInt i = 0; i < _texts2.Size(); ++i )
	{
		_texts2[i]->SetLocationX( _rect.Left+8 );
	}
	Rect rc( _visibleRect );
	rc.Right -= 4;
	_texts->SetRect( rc );
	_texts->EnableRect( true );

	UpdateHighlight();
}

void DefaultDropList::UpdateSelection( UInt index )
{
	_selectedIndex = index;
	for ( UInt i = 0; i < _items.Size(); ++i )
	{
		const Bool selected = (i == index);
		_texts->GetText( i )->SetColor( selected ? Color::Yellow : Color::White );
	}
	UpdateHighlight();
}

void DefaultDropList::UpdateHighlight()
{
	if ( _selectedIndex != none )
	{
		const Int top = _rect.Top + (_highlightedIndex+1) * _itemHeight + 10;
		_highlight->SetLocation( Point(_rect.Left + 2, top) );
	}
	_highlight->Show( IsExpanded() && (_highlightedIndex != none) );
}


} // ui


} // synkro
