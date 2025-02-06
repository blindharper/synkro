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
// Purpose: Generic theme widget implementation.
//=============================================================================
template <class T>
SYNKRO_INLINE BaseThemeWidgetImpl<T>::BaseThemeWidgetImpl( const img::Color& color ) :
	_theme( nullptr ),
	_customColor( color )
{
	SetDefaults();
}

template <class T>
SYNKRO_INLINE BaseThemeWidgetImpl<T>::BaseThemeWidgetImpl() :
	_theme( nullptr ),
	_customColor( img::Color::Transparent )
{
	SetDefaults();
}

template <class T>
SYNKRO_INLINE BaseThemeWidgetImpl<T>::~BaseThemeWidgetImpl()
{
}

template <class T>
SYNKRO_INLINE void BaseThemeWidgetImpl<T>::SetTheme( ITheme* theme )
{
	_theme = theme;

	SetColors( WidgetState::Normal );
	SetColors( WidgetState::Active );
	SetColors( WidgetState::Hovered );
	SetColors( WidgetState::Disabled );

	if ( _customColor != img::Color::Transparent )
	{
		_widgetColors[WidgetState::Normal] = _customColor;
		_widgetColors[WidgetState::Active] = _customColor*1.4f;
		_widgetColors[WidgetState::Hovered] = _customColor*1.5f;
	}
}

template <class T>
SYNKRO_INLINE void BaseThemeWidgetImpl<T>::SetDefaults()
{
	_widgetColors[WidgetState::Normal] = img::Color::White;
	_widgetColors[WidgetState::Active] = img::Color::White*1.4f;
	_widgetColors[WidgetState::Hovered] = img::Color::White*1.5f;
	_widgetColors[WidgetState::Disabled] = img::Color::Gray;

	_textColors[WidgetState::Normal] = img::Color::White;
	_textColors[WidgetState::Active] = img::Color::White*1.4f;
	_textColors[WidgetState::Hovered] = img::Color::Yellow;
	_textColors[WidgetState::Disabled] = img::Color::Gray;
}

template <class T>
SYNKRO_INLINE void BaseThemeWidgetImpl<T>::SetColors( const WidgetState& state )
{
	_theme->GetWidgetColor( state, _widgetColors[state] );
	_theme->GetTextColor( state, _textColors[state] );
}
