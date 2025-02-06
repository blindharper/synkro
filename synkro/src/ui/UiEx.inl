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
// Purpose: Extended user interface.
//==============================================================================
SYNKRO_INLINE void UiEx::SetTheme( ITheme* theme )
{
	_ui->SetTheme( theme );
	_cursor->SetTheme( theme );
}

SYNKRO_INLINE void UiEx::SetBackColor( const img::Color& color )
{
	_ui->SetBackColor( color );
}

SYNKRO_INLINE ITheme* UiEx::GetTheme() const
{
	return _ui->GetTheme();
}

SYNKRO_INLINE void UiEx::GetBackColor( img::Color& color ) const
{
	_ui->GetBackColor( color );
}

SYNKRO_INLINE ICursor* UiEx::GetCursor() const
{
	return _cursor;
}

SYNKRO_INLINE ThemeName UiEx::GetThemeName() const
{
	return _themeName;
}

SYNKRO_INLINE Bool UiEx::IsVisible() const
{
	return _visible;
}

SYNKRO_INLINE Bool UiEx::IsEnabled() const
{
	return _enabled;
}

SYNKRO_INLINE over::IFont* UiEx::GetFont() const
{
	return _font;
}

SYNKRO_INLINE ITheme* UiEx::GetThemeEx() const
{
	return _theme;
}

SYNKRO_INLINE Frame* UiEx::GetParentFrame( IFrame* parent )
{
	return (parent != nullptr) ? (Frame*)parent : _root;
}
