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
// Purpose: Label widget implementation.
//==============================================================================
SYNKRO_INLINE UInt Label::ID() const
{
	return _widgetID;
}

SYNKRO_INLINE void Label::Show( Bool show )
{
	// Call base implementation.
	WidgetImpl<ILabel>::Show( show );

	if ( _back != nullptr )
	{
		_back->Show( show );
	}
}

SYNKRO_INLINE void Label::SetOpacity( Float opacity )
{
	// Call base implementation.
	WidgetImpl<ILabel>::SetOpacity( opacity );

	if ( _back != nullptr )
	{
		_back->SetOpacity( opacity );
	}
}

SYNKRO_INLINE void Label::SetAnchor( const Anchor& anchor )
{
	// Call base implementation.
	WidgetImpl<ILabel>::SetAnchor( anchor );
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
}

SYNKRO_INLINE void Label::SetTabOrder( UInt order )
{
	// Do nothing since label is not tabbable.
}

SYNKRO_INLINE ILabel* Label::AsLabel() const
{
	return (ILabel*)this;
}

SYNKRO_INLINE void Label::SetBackColor( const img::Color& color )
{
	_backColor = color;
	if ( _back != nullptr )
	{
		_back->SetColor( _backColor );
	}
}

SYNKRO_INLINE void Label::SetTextAlign( const Alignment& align )
{
	if ( align != _align )
	{
		_align = align;
		Update();
	}
}

SYNKRO_INLINE void Label::SetText( const lang::String& text )
{
	_text->SetText( text );
	Update();
}

SYNKRO_INLINE Bool Label::IsTransparent() const
{
	return _transparent;
}

SYNKRO_INLINE void Label::GetBackColor( img::Color& color ) const
{
	color = _backColor;
}

SYNKRO_INLINE Alignment Label::GetTextAlign() const
{
	return _align;
}

SYNKRO_INLINE lang::String Label::GetText() const
{
	return _text->GetText();
}

SYNKRO_INLINE void Label::SetTheme( ITheme* theme )
{
	// Call base implementation.
	BaseThemeWidgetImpl<BaseThemeWidget>::SetTheme( theme );

	_text->SetColor( _textColors[WidgetState::Normal] );
}

SYNKRO_INLINE void Label::UpdateRect()
{
	CalcRect();
	Update();
}
