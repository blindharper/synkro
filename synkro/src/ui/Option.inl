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
// Purpose: Logical option widget.
//==============================================================================
SYNKRO_INLINE void Option::SetLocation( const lang::Point& location )
{
	// Call base implementation.
	WidgetWrapperImpl<IOption>::SetLocation( location );
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
}

SYNKRO_INLINE void Option::SetSize( const lang::Size& size )
{
	// Call base implementation.
	WidgetWrapperImpl<IOption>::SetSize( size );
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
}

SYNKRO_INLINE void Option::SetAnchor( const Anchor& anchor )
{
	// Call base implementation.
	WidgetWrapperImpl<IOption>::SetAnchor( anchor );	
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
}

SYNKRO_INLINE IOption* Option::AsOption() const
{
	return (IOption*)this;
}

SYNKRO_INLINE void Option::Select( Bool select )
{
	if ( select )
	{
		AsBaseFrame( _parent )->OnOptionSelected( this );
		_option->Select( true );
	}
}

SYNKRO_INLINE void Option::Highlight( Bool highlight )
{
	_option->Highlight( highlight );
}

SYNKRO_INLINE void Option::SetText( const lang::String& text )
{
	_option->SetText( text );
}

SYNKRO_INLINE Bool Option::IsSelected() const
{
	return _option->IsSelected();
}

SYNKRO_INLINE lang::String Option::GetText() const
{
	return _option->GetText();
}

SYNKRO_INLINE UiEvent Option::OnHotKey( const HotKey& hotkey )
{
	return IsHot(hotkey) ? UI_EVENT_VALUE_CHANGED : UI_EVENT_NONE;
}

SYNKRO_INLINE UiEvent Option::OnKeyUp( const input::Key& key, Bool alt, Bool shift, Bool control )
{
	if ( key == input::Key::Space )
	{
		Select( true );
		return UI_EVENT_VALUE_CHANGED;
	}
	return UI_EVENT_NONE;
}

SYNKRO_INLINE UiEvent Option::OnMouseEnter()
{
	_option->Highlight( true );
	return UI_EVENT_NONE;
}

SYNKRO_INLINE UiEvent Option::OnMouseLeave()
{
	_option->Highlight( false );
	return UI_EVENT_NONE;
}

SYNKRO_INLINE UiEvent Option::OnMouseUp()
{
	Select( true );
	return UI_EVENT_VALUE_CHANGED;
}

SYNKRO_INLINE void Option::Unselect()
{
	_option->Select( false );
}
