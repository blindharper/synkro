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
// Purpose: Logical button widget.
//==============================================================================
SYNKRO_INLINE void Button::SetLocation( const lang::Point& location )
{
	// Call base implementation.
	WidgetWrapperImpl<IButton>::SetLocation( location );
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
}

SYNKRO_INLINE void Button::SetSize( const lang::Size& size )
{
	// Call base implementation.
	WidgetWrapperImpl<IButton>::SetSize( size );
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
}

SYNKRO_INLINE void Button::SetAnchor( const Anchor& anchor )
{
	// Call base implementation.
	WidgetWrapperImpl<IButton>::SetAnchor( anchor );	
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
}

SYNKRO_INLINE IButton* Button::AsButton() const
{
	return (IButton*)this;
}

SYNKRO_INLINE void Button::Press( Bool press )
{
	_button->Press( press );
}

SYNKRO_INLINE void Button::Highlight( Bool highlight )
{
	_button->Highlight( highlight );
}

SYNKRO_INLINE void Button::SetText( const lang::String& text )
{
	_button->SetText( text );
}

SYNKRO_INLINE Bool Button::IsPressed() const
{
	return _button->IsPressed();
}

SYNKRO_INLINE Bool Button::IsHighlighted() const
{
	return _button->IsHighlighted();
}

SYNKRO_INLINE lang::String Button::GetText() const
{
	return _button->GetText();
}

SYNKRO_INLINE UiEvent Button::OnHotKey( const HotKey& hotkey )
{
	return IsHot(hotkey) ? UI_EVENT_CLICK : UI_EVENT_NONE;
}

SYNKRO_INLINE UiEvent Button::OnKeyDown( Double deltaTime, const input::Key& key, Bool alt, Bool shift, Bool control )
{
	if ( key == input::Key::Space )
	{
		_button->Press( true );
	}
	return UI_EVENT_NONE;
}

SYNKRO_INLINE UiEvent Button::OnKeyUp( const input::Key& key, Bool alt, Bool shift, Bool control )
{
	if ( key == input::Key::Space )
	{
		_button->Press( false );
		return UI_EVENT_CLICK;
	}
	return UI_EVENT_NONE;
}

SYNKRO_INLINE UiEvent Button::OnMouseEnter()
{
	_button->Highlight( true );
	return UI_EVENT_NONE;
}

SYNKRO_INLINE UiEvent Button::OnMouseLeave()
{
	_button->Highlight( false );
	return UI_EVENT_NONE;
}

SYNKRO_INLINE UiEvent Button::OnMouseDown( const lang::Point& location )
{
	_button->Press( true );
	return UI_EVENT_NONE;
}

SYNKRO_INLINE UiEvent Button::OnMouseUp()
{
	UiEvent event = (IsPressed() && IsHighlighted()) ? UI_EVENT_CLICK : UI_EVENT_NONE;
	Press( false );
	return event;
}
