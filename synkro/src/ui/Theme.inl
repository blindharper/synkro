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
// Purpose: User interface theme.
//==============================================================================
SYNKRO_INLINE void Theme::SetWidgetColor( const WidgetState& state, const img::Color& color )
{
	_widgetColors[state] = color;
	_dirty = true;
}

SYNKRO_INLINE void Theme::SetTextColor( const WidgetState& state, const img::Color& color )
{
	_textColors[state] = color;
	_dirty = true;
}

SYNKRO_INLINE void Theme::GetCursorRect( lang::Rect& rect ) const
{
	rect = _rects[ThemeReader::THEME_CURSOR];
}

SYNKRO_INLINE void Theme::GetAngleRect( lang::Rect& rect ) const
{
	rect = _rects[ThemeReader::THEME_ANGLE_RECT];
}

SYNKRO_INLINE void Theme::GetAngleThumb( lang::Rect& rect ) const
{
	rect = _rects[ThemeReader::THEME_ANGLE_THUMB];
}

SYNKRO_INLINE void Theme::GetButtonRect( lang::Rect& rect ) const
{
	rect = _rects[ThemeReader::THEME_BUTTON_RECT];
}

SYNKRO_INLINE void Theme::GetButtonCenter( lang::Rect& rect ) const
{
	rect = _rects[ThemeReader::THEME_BUTTON_CENTER];
}

SYNKRO_INLINE void Theme::GetEditRect( lang::Rect& rect ) const
{
	rect = _rects[ThemeReader::THEME_EDIT_RECT];
}

SYNKRO_INLINE void Theme::GetEditCenter( lang::Rect& rect ) const
{
	rect = _rects[ThemeReader::THEME_EDIT_CENTER];
}

SYNKRO_INLINE void Theme::GetListRect( lang::Rect& rect ) const
{
	rect = _rects[ThemeReader::THEME_LIST_RECT];
}

SYNKRO_INLINE void Theme::GetListCenter( lang::Rect& rect ) const
{
	rect = _rects[ThemeReader::THEME_EDIT_CENTER];
}

SYNKRO_INLINE void Theme::GetOptionRect( Bool selected, lang::Rect& rect ) const
{
	rect = _rects[selected ? ThemeReader::THEME_OPTION_ON_RECT : ThemeReader::THEME_OPTION_OFF_RECT];
}

SYNKRO_INLINE void Theme::GetOptionCenter( Bool selected, lang::Rect& rect ) const
{
	rect = _rects[selected ? ThemeReader::THEME_OPTION_ON_CENTER : ThemeReader::THEME_OPTION_OFF_CENTER];
}

SYNKRO_INLINE void Theme::GetProgressEmptyRect( lang::Rect& rect ) const
{
	rect = _rects[ThemeReader::THEME_PROGRESS_EMPTY_RECT];
}

SYNKRO_INLINE void Theme::GetProgressEmptyCenter( lang::Rect& rect ) const
{
	rect = _rects[ThemeReader::THEME_PROGRESS_EMPTY_CENTER];
}

SYNKRO_INLINE void Theme::GetProgressFilledRect( lang::Rect& rect ) const
{
	rect = _rects[ThemeReader::THEME_PROGRESS_FILLED_RECT];
}

SYNKRO_INLINE void Theme::GetProgressFilledCenter( lang::Rect& rect ) const
{
	rect = _rects[ThemeReader::THEME_PROGRESS_FILLED_CENTER];
}

SYNKRO_INLINE void Theme::GetSliderRect( const Orientation& orientation, lang::Rect& rect ) const
{
	rect = _rects[(orientation == Orientation::Horizontal) ? ThemeReader::THEME_SLIDER_HORZ_RECT : ThemeReader::THEME_SLIDER_VERT_RECT];
}

SYNKRO_INLINE void Theme::GetSliderCenter( const Orientation& orientation, lang::Rect& rect ) const
{
	rect = _rects[(orientation == Orientation::Horizontal) ? ThemeReader::THEME_SLIDER_HORZ_CENTER : ThemeReader::THEME_SLIDER_VERT_CENTER];
}

SYNKRO_INLINE void Theme::GetSliderThumb( const Orientation& orientation, lang::Rect& rect ) const
{
	rect = _rects[(orientation == Orientation::Horizontal) ? ThemeReader::THEME_SLIDER_HORZ_THUMB : ThemeReader::THEME_SLIDER_VERT_THUMB];
}

SYNKRO_INLINE void Theme::GetSwitchRect( Bool on, lang::Rect& rect ) const
{
	rect = _rects[on ? ThemeReader::THEME_SWITCH_ON_RECT : ThemeReader::THEME_SWITCH_OFF_RECT];
}

SYNKRO_INLINE void Theme::GetSwitchCenter( Bool on, lang::Rect& rect ) const
{
	rect = _rects[on ? ThemeReader::THEME_SWITCH_ON_CENTER : ThemeReader::THEME_SWITCH_OFF_CENTER];
}

SYNKRO_INLINE void Theme::GetWidgetColor( const WidgetState& state, img::Color& color ) const
{
	color = _widgetColors[state];
}

SYNKRO_INLINE void Theme::GetTextColor( const WidgetState& state, img::Color& color ) const
{
	color = _textColors[state];
}

SYNKRO_INLINE gfx::IProgram* Theme::GetProgram() const
{
	return _program;
}

SYNKRO_INLINE gfx::IResourceSet* Theme::GetResources() const
{
	return _resources;
}

SYNKRO_INLINE void Theme::ToRectF( const lang::Rect& rect, lang::RectF& rectF ) const
{
	rectF.Left = CastFloat(rect.Left)/CastFloat(_image->GetWidth());
	rectF.Top = CastFloat(rect.Top)/CastFloat(_image->GetHeight());
	rectF.Right = CastFloat(rect.Right)/CastFloat(_image->GetWidth());
	rectF.Bottom = CastFloat(rect.Bottom)/CastFloat(_image->GetHeight());
}

SYNKRO_INLINE void Theme::Validate()
{
	_dirty = false;
}

SYNKRO_INLINE Bool Theme::IsDirty() const
{
	return _dirty;
}
