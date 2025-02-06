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
// Purpose: Logical drop list widget.
//==============================================================================
SYNKRO_INLINE void DropList::SetLocation( const lang::Point& location )
{
	// Call base implementation.
	WidgetWrapperImpl<IDropList>::SetLocation( location );
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
}

SYNKRO_INLINE void DropList::SetSize( const lang::Size& size )
{
	// Call base implementation.
	WidgetWrapperImpl<IDropList>::SetSize( size );
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
}

SYNKRO_INLINE void DropList::SetAnchor( const Anchor& anchor )
{
	// Call base implementation.
	WidgetWrapperImpl<IDropList>::SetAnchor( anchor );	
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
}

SYNKRO_INLINE IDropList* DropList::AsDropList() const
{
	return (IDropList*)this;
}

SYNKRO_INLINE void DropList::Expand( Bool expand )
{
	_dropList->Expand( expand );
}

SYNKRO_INLINE void DropList::Highlight( Bool highlight )
{
	_dropList->Highlight( highlight );
}

SYNKRO_INLINE void DropList::HighlightItem( UInt index )
{
	_dropList->HighlightItem( index );
}

SYNKRO_INLINE void DropList::SetListHeight( UInt height )
{
	_dropList->SetListHeight( height );
}

SYNKRO_INLINE Bool DropList::IsExpanded() const
{
	return _dropList->IsExpanded();
}

SYNKRO_INLINE UInt DropList::GetHighlightedItem() const
{
	return _dropList->GetHighlightedItem();
}

SYNKRO_INLINE UInt DropList::GetListHeight() const
{
	return _dropList->GetListHeight();
}

SYNKRO_INLINE lang::String DropList::GetText() const
{
	return _dropList->GetText();
}

SYNKRO_INLINE UiEvent DropList::OnMouseEnter()
{
	_dropList->Highlight( true );
	return UI_EVENT_NONE;
}

SYNKRO_INLINE UiEvent DropList::OnMouseLeave()
{
	_dropList->Highlight( false );
	_dropList->HighlightItem( none );
	return UI_EVENT_NONE;
}
