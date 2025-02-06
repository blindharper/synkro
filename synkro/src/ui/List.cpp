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
// Purpose: Logical list widget.
//==============================================================================
#include "config.h"
#include "List.h"
#include <internal/Min.h>
#include <input/KeyConst.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::input;

//------------------------------------------------------------------------------


namespace synkro
{


namespace ui
{


List::List( BaseUiEx* ui, UInt id, IFrame* parent, IList* list ) :
	ListWrapperImpl<IList>( ui, id, parent, list ),
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>( list )
{
}

void List::Activate( Bool activate )
{
	// Call base implementation.
	ListWrapperImpl<IList>::Activate( activate );

	if ( activate )
	{
		const Key keys[] = { Key::Home, Key::Numpad7, Key::End, Key::Numpad1, Key::Up, Key::Down };
		_ui->ListenKeyDown( keys, SizeOf(keys), true );
		_ui->ListenKeyPress();
		_ui->ListenMouseDoubleClick(MouseButton::Left);
	}
}

UiEvent List::OnKeyDown( Double deltaTime, const Key& key, Bool alt, Bool shift, Bool control )
{
	UInt oldSelectedIndex = _list->GetSelectedItem();
	UInt selectedIndex = none;

	switch ( key )
	{
		case KEY_HOME:
		case KEY_NUMPAD7:
			selectedIndex = 0;
			break;

		case KEY_END:
		case KEY_NUMPAD1:
			selectedIndex = _list->GetItemCount()-1;
			break;

		case KEY_UP:
			if ((oldSelectedIndex != none) && (oldSelectedIndex > 0))
				selectedIndex = oldSelectedIndex-1;
			else
				selectedIndex = 0;
			break;

		case KEY_DOWN:
			selectedIndex = Min( oldSelectedIndex+1, _list->GetItemCount()-1 );
			break;
	}

	if ( selectedIndex != oldSelectedIndex )
	{
		if ( selectedIndex < _list->GetItemCount() )
		{
			_list->SelectItem( selectedIndex );
			return UI_EVENT_VALUE_CHANGED;
		}
	}
	return UI_EVENT_NONE;
}

UiEvent List::OnKeyPress( Char key )
{
	String ch( key );
	UInt selectedIndex = _list->GetSelectedItem();
	if ( selectedIndex == none )
	{
		selectedIndex = 0;
	}
	const UInt index = _list->FindItem( ch, selectedIndex+1 );
	if ( index != none )
	{
		_list->SelectItem( index );
		return UI_EVENT_VALUE_CHANGED;
	}
	return UI_EVENT_NONE;
}

UiEvent List::OnMouseClick( const Point& location )
{
	const UInt index = _list->GetItemAt( location );
	if ( index != none )
	{
		_list->SelectItem( index );
		return UI_EVENT_VALUE_CHANGED;
	}
	else
	{
		_list->ClearSelection();
		return UI_EVENT_VALUE_CHANGED;
	}
	return UI_EVENT_NONE;
}

UiEvent List::OnMouseDoubleClick( const Point& location )
{
	const UInt index = _list->GetItemAt( location );
	if ( index != none )
	{
		_list->SelectItem( index );
		return UI_EVENT_DOUBLE_CLICK;
	}
	return UI_EVENT_NONE;
}


} // ui


} // synkro
