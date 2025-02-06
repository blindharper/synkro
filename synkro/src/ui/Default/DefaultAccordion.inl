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
// Purpose: Default accordion container implementation.
//==============================================================================
SYNKRO_INLINE UInt DefaultAccordion::GetPanelCount() const
{
	return _frames.Size();
}

SYNKRO_INLINE IFrame* DefaultAccordion::GetPanel( UInt index ) const
{
	assert( index < _frames.Size() );

	// TODO:
	return _frames[index];
}

SYNKRO_INLINE lang::String DefaultAccordion::GetPanelText( UInt index ) const
{
	assert( index < _widgets.Size() );

	// TODO:
	return _widgets[index]->AsButton()->GetText().Substring( 1 );
}

SYNKRO_INLINE Bool DefaultAccordion::IsPanelExpanded( UInt index ) const
{
	assert( index < _frames.Size() );

	// TODO:
	return _frames[index]->IsVisible();
}
