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
SYNKRO_INLINE void DefaultDropList::Activate( Bool activate )
{
	// Call base implementation.
	WidgetImpl<IDropList>::Activate( activate );

	img::Color color; _ui->Theme()->GetTextColor( activate ? WidgetState::Hovered : WidgetState::Normal, color );
	_text->SetColor( color );
	_arrow->SetColor( color );
}

SYNKRO_INLINE void DefaultDropList::Enable( Bool enable )
{
	// Call base implementation.
	WidgetImpl<IDropList>::Enable( enable );

	const WidgetState state = _enabled ? WidgetState::Normal : WidgetState::Disabled;
	SetColor( _widgetColors[state] );
	_text->SetColor( _textColors[state] );
	_arrow->SetColor( _textColors[state] );
}

SYNKRO_INLINE void DefaultDropList::SetLocation( const lang::Point& location )
{
	// Call base implementation.
	WidgetImpl<IDropList>::SetLocation( location );

	Update();
}

SYNKRO_INLINE void DefaultDropList::SetSize( const lang::Size& size )
{
	// Call base implementation.
	WidgetImpl<IDropList>::SetSize( size );

	Update();
}

SYNKRO_INLINE Bool DefaultDropList::IsExpanded() const
{
	return _expanded;
}

SYNKRO_INLINE UInt DefaultDropList::GetHighlightedItem() const
{
	return _highlightedIndex;
}

SYNKRO_INLINE UInt DefaultDropList::GetListHeight() const
{
	return _listHeight;
}

SYNKRO_INLINE lang::String DefaultDropList::GetText() const
{
	return (_selectedIndex != none) ? _items[_selectedIndex].Text : lang::String::Empty;
}

SYNKRO_INLINE void DefaultDropList::UpdateRect()
{
	CalcRect();
	Update();
}
