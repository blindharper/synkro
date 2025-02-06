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
// Purpose: Logical edit widget.
//==============================================================================
SYNKRO_INLINE void Edit::Enable( Bool enable )
{
	// Call base implementation.
	Bool wasEnabled = _edit->IsEnabled();
	WidgetWrapperImpl<IEdit>::Enable( enable );

	if ( wasEnabled && !enable )
	{
		_caretCtrl->Start( false );
		_caret->Show( false );
	}
}

SYNKRO_INLINE void Edit::SetLocation( const lang::Point& location )
{
	// Call base implementation.
	WidgetWrapperImpl<IEdit>::SetLocation( location );
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
	SetCaretPosition( _caretPos );
}

SYNKRO_INLINE void Edit::SetSize( const lang::Size& size )
{
	// Call base implementation.
	WidgetWrapperImpl<IEdit>::SetSize( size );
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
}

SYNKRO_INLINE void Edit::SetAnchor( const Anchor& anchor )
{
	// Call base implementation.
	WidgetWrapperImpl<IEdit>::SetAnchor( anchor );
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
}

SYNKRO_INLINE IEdit* Edit::AsEdit() const
{
	return (IEdit*)this;
}

SYNKRO_INLINE void Edit::Clear()
{
	_edit->Clear();
	CalcWidths();
	SetCaretPosition( 0 );
}

SYNKRO_INLINE void Edit::SetText( const lang::String& text )
{
	_edit->SetText( text );
	CalcWidths();
}

SYNKRO_INLINE void Edit::SetMaxLength( UInt maxLength )
{
	_edit->SetMaxLength( maxLength );
}

SYNKRO_INLINE void Edit::SetScrollOffset( UInt offset )
{
	_edit->SetScrollOffset( offset );
}

SYNKRO_INLINE Bool Edit::IsEmpty() const
{
	return _edit->IsEmpty();
}

SYNKRO_INLINE lang::String Edit::GetText() const
{
	return _edit->GetText();
}

SYNKRO_INLINE EditStyle Edit::GetStyle() const
{
	return _edit->GetStyle();
}

SYNKRO_INLINE Float Edit::GetMinValue() const
{
	VerifyNumeric();
	return _edit->GetMinValue();
}

SYNKRO_INLINE Float Edit::GetMaxValue() const
{
	VerifyNumeric();
	return _edit->GetMaxValue();
}

SYNKRO_INLINE UInt Edit::GetMaxLength() const
{
	return _edit->GetMaxLength();
}

SYNKRO_INLINE UInt Edit::GetScrollOffset() const
{
	return _edit->GetScrollOffset();
}

SYNKRO_INLINE UiEvent Edit::OnMouseDown( const lang::Point& location )
{
	SetCaretPosition( location );
	_edit->Activate( true );
	return UI_EVENT_NONE;
}
