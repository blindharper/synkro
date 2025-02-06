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
// Purpose: Default switch widget implementation.
//==============================================================================
SYNKRO_INLINE void DefaultSwitch::Enable( Bool enable )
{
	// Call base implementation.
	WidgetImpl<ISwitch>::Enable( enable );

	WidgetState state = _enabled ? WidgetState::Normal : WidgetState::Disabled;
	SetColor( _widgetColors[state] );
	_text->SetColor( _textColors[state] );
}

SYNKRO_INLINE void DefaultSwitch::SetLocation( const lang::Point& location )
{
	// Call base implementation.
	WidgetImpl<ISwitch>::SetLocation( location );

	Update();
}

SYNKRO_INLINE void DefaultSwitch::SetSize( const lang::Size& size )
{
	// Call base implementation.
	WidgetImpl<ISwitch>::SetSize( size );

	Update();
}

SYNKRO_INLINE void DefaultSwitch::Turn( Bool on )
{
	if ( on != _on )
	{
		_on = on;
		Update();
	}
}

SYNKRO_INLINE void DefaultSwitch::SetText( const lang::String& text )
{
	_text->SetText( text );
}

SYNKRO_INLINE Bool DefaultSwitch::IsOn() const
{
	return _on;
}

SYNKRO_INLINE Bool DefaultSwitch::IsHighlighted() const
{
	return _highlighted;
}

SYNKRO_INLINE lang::String DefaultSwitch::GetText() const
{
	return _text->GetText();
}

SYNKRO_INLINE void DefaultSwitch::UpdateRect()
{
	CalcRect();
	Update();
}
