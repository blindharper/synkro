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
// Purpose: Default edit widget implementation.
//==============================================================================
SYNKRO_INLINE void DefaultEdit::Activate( Bool activate )
{
	// Call base implementation.
	WidgetImpl<IEdit>::Activate( activate );

	WidgetState state = activate ? WidgetState::Active : WidgetState::Normal;
	_text->SetColor( _textColors[state] );
}

SYNKRO_INLINE void DefaultEdit::Enable( Bool enable )
{
	// Call base implementation.
	WidgetImpl<IEdit>::Enable( enable );

	WidgetState state = _enabled ? WidgetState::Normal : WidgetState::Disabled;
	_text->SetColor( _textColors[state] );
}

SYNKRO_INLINE void DefaultEdit::SetLocation( const lang::Point& location )
{
	// Call base implementation.
	WidgetImpl<IEdit>::SetLocation( location );

	Update();
}

SYNKRO_INLINE void DefaultEdit::SetSize( const lang::Size& size )
{
	// Call base implementation.
	WidgetImpl<IEdit>::SetSize( size );

	Update();
}

SYNKRO_INLINE void DefaultEdit::Clear()
{
	SetText( lang::String::Empty );
}

SYNKRO_INLINE void DefaultEdit::SetText( const lang::String& text )
{
	_text->SetText( text );
}

SYNKRO_INLINE void DefaultEdit::SetStyle( const EditStyle& style )
{
	_style = style;
}

SYNKRO_INLINE void DefaultEdit::SetValue( Float value )
{
	// Do nothing.
}

SYNKRO_INLINE void DefaultEdit::SetMinValue( Float minValue )
{
	_minValue = minValue;
}

SYNKRO_INLINE void DefaultEdit::SetMaxValue( Float maxValue )
{
	_maxValue = maxValue;
}

SYNKRO_INLINE void DefaultEdit::SetMaxLength( UInt maxLength )
{
	_maxLength = maxLength;
	if ( _maxLength > 0 )
	{
		lang::String text = _text->GetText();
		text = text.Substring( 0, _maxLength );
		_text->SetText( text );
	}
}

SYNKRO_INLINE void DefaultEdit::SetScrollOffset( UInt offset )
{
	_scrollOffset = offset;
	_text->SetLocation( lang::Point(_rect.Left+2-CastInt(offset), _rect.Top+6) );
}

SYNKRO_INLINE Bool DefaultEdit::IsEmpty() const
{
	return GetText().IsEmpty();
}

SYNKRO_INLINE lang::String DefaultEdit::GetText() const
{
	return _text->GetText();
}

SYNKRO_INLINE EditStyle DefaultEdit::GetStyle() const
{
	return _style;
}

SYNKRO_INLINE Float DefaultEdit::GetValue() const
{
	return 0.0f;
}

SYNKRO_INLINE Float DefaultEdit::GetMinValue() const
{
	return _minValue;
}

SYNKRO_INLINE Float DefaultEdit::GetMaxValue() const
{
	return _maxValue;
}

SYNKRO_INLINE UInt DefaultEdit::GetMaxLength() const
{
	return _maxLength;
}

SYNKRO_INLINE UInt DefaultEdit::GetScrollOffset() const
{
	return _scrollOffset;
}

SYNKRO_INLINE void DefaultEdit::SetTheme( ITheme* theme )
{
	// Call base implementation.
	BaseThemeWidgetImpl<BaseThemeWidget>::SetTheme( theme );

	_object->SetFragmentResources( theme->GetResources() );
	const WidgetState state = _enabled ? WidgetState::Normal : WidgetState::Disabled;
	SetColor( _widgetColors[state], true );
	_text->SetColor( _textColors[state] );
}

SYNKRO_INLINE void DefaultEdit::UpdateRect()
{
	CalcRect();
	Update();
}
