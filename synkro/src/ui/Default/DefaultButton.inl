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
// Purpose: Default button widget implementation.
//==============================================================================
SYNKRO_INLINE void DefaultButton::Enable( Bool enable )
{
	// Call base implementation.
	WidgetImpl<IButton>::Enable( enable );

	const WidgetState state = _enabled ? WidgetState::Normal : WidgetState::Disabled;
	SetColor( _widgetColors[state] );
	_text->SetColor( _textColors[state] );
}

SYNKRO_INLINE void DefaultButton::SetLocation( const lang::Point& location )
{
	// Call base implementation.
	WidgetImpl<IButton>::SetLocation( location );

	Update( 0 );
}

SYNKRO_INLINE void DefaultButton::SetSize( const lang::Size& size )
{
	// Call base implementation.
	WidgetImpl<IButton>::SetSize( size );

	Update( 0 );
}

SYNKRO_INLINE IButton* DefaultButton::AsButton() const
{
	return (IButton*)this;
}

SYNKRO_INLINE void DefaultButton::Press( Bool press )
{
	CalcRect();
	Update( _pressed = press ? PRESS_DELTA : 0 );
}

SYNKRO_INLINE void DefaultButton::SetText( const lang::String& text )
{
	_text->SetText( text );
	CenterText( 0 );
}

SYNKRO_INLINE Bool DefaultButton::IsPressed() const
{
	return _pressed;
}

SYNKRO_INLINE Bool DefaultButton::IsHighlighted() const
{
	return _highlighted;
}

SYNKRO_INLINE lang::String DefaultButton::GetText() const
{
	return _text->GetText();
}

SYNKRO_INLINE void DefaultButton::UpdateRect()
{
	CalcRect();
	Update( 0 );
}
