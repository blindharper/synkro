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
// Purpose: Logical drop list widget.
//==============================================================================
#include "config.h"
#include "DropList.h"
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


DropList::DropList( BaseUiEx* ui, UInt id, IFrame* parent, IDropList* dropList ) :
	ListWrapperImpl<IDropList>( ui, id, parent, dropList ),
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>( dropList ),
	_dropList( dropList )
{
}

void DropList::Activate( Bool activate )
{
	// Call base implementation.
	WidgetWrapperImpl<IDropList>::Activate( activate );

	if ( activate )
	{
		const Key keys[] = { Key::Home, Key::Numpad7, Key::End, Key::Numpad1, Key::Up, Key::Down, Key::F4, Key::Return, Key::NumpadEnter };
		_ui->ListenKeyDown( keys, SizeOf(keys), true );
		_ui->ListenKeyPress();
	}
	else if ( _dropList->IsExpanded() )
	{
		_dropList->Expand( false );
	}
}

void DropList::SelectItem( UInt index )
{
	const UInt oldSelectedIndex = _dropList->GetSelectedItem();
	if ( index != oldSelectedIndex )
	{
		_dropList->SelectItem( index );
		_ui->FireEvent( UI_EVENT_VALUE_CHANGED, this );
	}
}

UiEvent DropList::OnKeyDown( Double deltaTime, const Key& key, Bool alt, Bool shift, Bool control )
{
	const Bool expanded = _dropList->IsExpanded();
	const UInt oldIndex = expanded ? _dropList->GetHighlightedItem() : _dropList->GetSelectedItem();
	UInt newIndex = none;

	switch ( key )
	{
		case KEY_HOME:
		case KEY_NUMPAD7:
			newIndex = 0;
			break;

		case KEY_END:
		case KEY_NUMPAD1:
			newIndex = _dropList->GetItemCount()-1;
			break;

		case KEY_UP:
			newIndex = ((oldIndex != none) && (oldIndex > 0)) ? oldIndex-1 : 0;
			break;

		case KEY_DOWN:
			newIndex = Min( oldIndex+1, _dropList->GetItemCount()-1 );
			break;

		case KEY_F4:
			_dropList->Expand( !_dropList->IsExpanded() );
			return UI_EVENT_NONE;

		case KEY_RETURN:
		case KEY_NUMPAD_ENTER:
			if ( expanded )
			{
				newIndex = _dropList->GetHighlightedItem();
				_dropList->Expand( false );
				if ( newIndex != _dropList->GetSelectedItem() )
				{
					_dropList->SelectItem( newIndex );
					return UI_EVENT_VALUE_CHANGED;
				}
			}
			return UI_EVENT_NONE;
	}

	if ( (newIndex != oldIndex) && (newIndex < _dropList->GetItemCount()) )
	{
		if ( expanded )
		{
			_dropList->HighlightItem( newIndex );
		}
		else
		{
			_dropList->SelectItem( newIndex );
			return UI_EVENT_VALUE_CHANGED;
		}
	}
	return UI_EVENT_NONE;
}

UiEvent DropList::OnKeyPress( Char key )
{
	String ch( key );
	UInt selectedIndex = _dropList->GetSelectedItem();
	if ( selectedIndex == none )
	{
		selectedIndex = 0;
	}
	const UInt index = _dropList->FindItem( ch, selectedIndex+1 );
	if ( index != none )
	{
		_dropList->SelectItem( index );
		return UI_EVENT_VALUE_CHANGED;
	}
	return UI_EVENT_NONE;
}

UiEvent DropList::OnMouseClick( const Point& location )
{
	const UInt index = _dropList->GetItemAt( location );
	if ( index != none )
	{
		_dropList->SelectItem( index );
		_dropList->Expand( false );
		return UI_EVENT_VALUE_CHANGED;
	}
	else
	{
		_dropList->Expand( !_dropList->IsExpanded() );
		return UI_EVENT_NONE;
	}
}

UiEvent DropList::OnMouseMove( const Point& location )
{
	const UInt index = _dropList->GetItemAt( location );
	if ( index != none )
	{
		_dropList->HighlightItem( index );
	}
	return UI_EVENT_NONE;
}


} // ui


} // synkro
