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
// Purpose: Default user interface.
//==============================================================================
SYNKRO_INLINE Bool DefaultUi::Update( Double delta )
{
	return true;
}

SYNKRO_INLINE void DefaultUi::SetBackColor( const img::Color& color )
{
	_backColor = color;
}

SYNKRO_INLINE ITheme* DefaultUi::GetTheme() const
{
	return _theme;
}

SYNKRO_INLINE void DefaultUi::GetBackColor( img::Color& color ) const
{
	color = _backColor;
}

SYNKRO_INLINE WidgetEffect* DefaultUi::CreateEffect( gfx::IOverlayRenderObject* widget, gfx::IOverlayRenderObject* widget2, over::IText* text )
{
	return new WidgetEffect( widget, widget2, text, _animationSystem, nullptr );
}

SYNKRO_INLINE over::ITextPool* DefaultUi::CreateTextPool( over::IFont* font, UInt capacity )
{
	return _overlay->CreateTextPool( font, over::Order::High, over::Order::Highest, capacity );
}

SYNKRO_INLINE over::ISprite* DefaultUi::CreateSprite( img::IImage* image, const lang::Point& location, const lang::Size& size )
{
	return _overlay->CreateSprite( image, location, size );
}

SYNKRO_INLINE over::IQuad* DefaultUi::CreateQuad( const over::Order& groupOrder, const over::Order& order, const lang::Point& location, const lang::Size& size, const img::Color& color )
{
	return _overlay->CreateQuad( groupOrder, order, location, size, color );
}

SYNKRO_INLINE over::IFont* DefaultUi::GetFont() const
{
	return _font;
}

SYNKRO_INLINE ITheme* DefaultUi::Theme() const
{
	return _theme;
}
