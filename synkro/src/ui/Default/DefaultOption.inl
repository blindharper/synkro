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
// Purpose: Default option widget implementation.
//==============================================================================
SYNKRO_INLINE void DefaultOption::Enable( Bool enable )
{
	// Call base implementation.
	WidgetImpl<IOption>::Enable( enable );

	WidgetState state = _enabled ? WidgetState::Normal : WidgetState::Disabled;
	SetColor( _widgetColors[state] );
	_text->SetColor( _textColors[state] );
}

SYNKRO_INLINE void DefaultOption::SetLocation( const lang::Point& location )
{
	// Call base implementation.
	WidgetImpl<IOption>::SetLocation( location );

	Update();
}

SYNKRO_INLINE void DefaultOption::SetSize( const lang::Size& size )
{
	// Call base implementation.
	WidgetImpl<IOption>::SetSize( size );

	Update();
}

SYNKRO_INLINE void DefaultOption::Select( Bool select )
{
	_selected = select;
	Update();
}

SYNKRO_INLINE void DefaultOption::SetText( const lang::String& text )
{
	_text->SetText( text );
}

SYNKRO_INLINE Bool DefaultOption::IsSelected() const
{
	return _selected;
}

SYNKRO_INLINE lang::String DefaultOption::GetText() const
{
	return _text->GetText();
}

SYNKRO_INLINE void DefaultOption::UpdateRect()
{
	CalcRect();
	Update();
}
