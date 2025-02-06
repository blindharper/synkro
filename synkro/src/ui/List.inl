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
// Purpose: Logical list widget.
//==============================================================================
SYNKRO_INLINE void List::SetLocation( const lang::Point& location )
{
	// Call base implementation.
	WidgetWrapperImpl<IList>::SetLocation( location );
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
}

SYNKRO_INLINE void List::SetSize( const lang::Size& size )
{
	// Call base implementation.
	WidgetWrapperImpl<IList>::SetSize( size );
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
}

SYNKRO_INLINE void List::SetAnchor( const Anchor& anchor )
{
	// Call base implementation.
	WidgetWrapperImpl<IList>::SetAnchor( anchor );	
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
}

SYNKRO_INLINE IList* List::AsList() const
{
	return (IList*)this;
}
