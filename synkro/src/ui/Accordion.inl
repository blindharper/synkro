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
// Purpose: Logical accordion container.
//==============================================================================
SYNKRO_INLINE UInt Accordion::ID() const
{
	return _accordionID;
}

SYNKRO_INLINE IAccordion* Accordion::AsAccordion() const
{
	return (IAccordion*)this;
}

SYNKRO_INLINE void Accordion::ExpandPanel( UInt index, Bool expand )
{
	_accordion->ExpandPanel( index, expand );
}

SYNKRO_INLINE UInt Accordion::GetPanelCount() const
{
	return _accordion->GetPanelCount();
}

SYNKRO_INLINE IFrame* Accordion::GetPanel( UInt index ) const
{
	return _accordion->GetPanel( index );
}

SYNKRO_INLINE lang::String Accordion::GetPanelText( UInt index ) const
{
	return _accordion->GetPanelText( index );
}

SYNKRO_INLINE Bool Accordion::IsPanelExpanded( UInt index ) const
{
	return _accordion->IsPanelExpanded( index );
}

SYNKRO_INLINE lang::Point Accordion::ToLocation( IAccordion* accordion ) const
{
	lang::Point location;
	accordion->GetLocation( location );
	return location;
}

SYNKRO_INLINE lang::Size Accordion::ToSize( IAccordion* accordion ) const
{
	lang::Size size;
	accordion->GetSize( size );
	return size;
}
