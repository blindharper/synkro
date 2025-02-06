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
// Purpose: Logical switch widget.
//==============================================================================
SYNKRO_INLINE void Switch::SetLocation( const lang::Point& location )
{
	// Call base implementation.
	WidgetWrapperImpl<ISwitch>::SetLocation( location );
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
}

SYNKRO_INLINE void Switch::SetSize( const lang::Size& size )
{
	// Call base implementation.
	WidgetWrapperImpl<ISwitch>::SetSize( size );
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
}

SYNKRO_INLINE void Switch::SetAnchor( const Anchor& anchor )
{
	// Call base implementation.
	WidgetWrapperImpl<ISwitch>::SetAnchor( anchor );	
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
}

SYNKRO_INLINE ISwitch* Switch::AsSwitch() const
{
	return (ISwitch*)this;
}

SYNKRO_INLINE void Switch::Turn( Bool on )
{
	_switch->Turn( on );
}

SYNKRO_INLINE void Switch::Highlight( Bool highlight )
{
	_switch->Highlight( highlight );
}

SYNKRO_INLINE void Switch::SetText( const lang::String& text )
{
	_switch->SetText( text );
}

SYNKRO_INLINE Bool Switch::IsOn() const
{
	return _switch->IsOn();
}

SYNKRO_INLINE Bool Switch::IsHighlighted() const
{
	return _switch->IsHighlighted();
}

SYNKRO_INLINE lang::String Switch::GetText() const
{
	return _switch->GetText();
}

SYNKRO_INLINE UiEvent Switch::OnHotKey( const HotKey& hotkey )
{
	if ( IsHot(hotkey) )
	{
		_switch->Turn( !_switch->IsOn() );
		return UI_EVENT_VALUE_CHANGED;
	}
	return UI_EVENT_NONE;
}

SYNKRO_INLINE UiEvent Switch::OnKeyUp( const input::Key& key, Bool alt, Bool shift, Bool control )
{
	if ( key == input::Key::Space )
	{
		_switch->Turn( !_switch->IsOn() );
		return UI_EVENT_VALUE_CHANGED;
	}
	return UI_EVENT_NONE;
}

SYNKRO_INLINE UiEvent Switch::OnMouseEnter()
{
	_switch->Highlight( true );
	return UI_EVENT_NONE;
}

SYNKRO_INLINE UiEvent Switch::OnMouseLeave()
{
	_switch->Highlight( false );
	return UI_EVENT_NONE;
}

SYNKRO_INLINE UiEvent Switch::OnMouseUp()
{
	if ( IsHighlighted() )
	{
		_switch->Turn( !_switch->IsOn() );
		return UI_EVENT_VALUE_CHANGED;
	}
	return UI_EVENT_NONE;
}
