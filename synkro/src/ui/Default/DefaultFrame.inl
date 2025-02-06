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
// Purpose: Default frame container implementation.
//==============================================================================
SYNKRO_INLINE void DefaultFrame::SetLocation( const lang::Point& location )
{
	// Call base implementation.
	FrameImpl<IFrame>::SetLocation( location );

	UpdateRect();
}

SYNKRO_INLINE void DefaultFrame::SetSize( const lang::Size& size )
{
	// Call base implementation.
	FrameImpl<IFrame>::SetSize( size );

	UpdateRect();
}

SYNKRO_INLINE void DefaultFrame::AddWidget( IWidget* widget )
{
	assert( widget != nullptr );

	_widgets.Add( widget );
}

SYNKRO_INLINE void DefaultFrame::AddFrame( IFrame* frame )
{
	assert( frame != nullptr );

	_frames.Add( frame );
}

SYNKRO_INLINE void DefaultFrame::OnOptionSelected( BaseOption* option )
{
	// Do nothing.
}

SYNKRO_INLINE void DefaultFrame::UpdateTabOrder()
{
	// Do nothing.
}

SYNKRO_INLINE IWidget* DefaultFrame::GetNextWidget( IWidget* widget ) const
{
	return nullptr;
}

SYNKRO_INLINE IWidget* DefaultFrame::GetPrevWidget( IWidget* widget ) const
{
	return nullptr;
}

SYNKRO_INLINE IFrame* DefaultFrame::GetInnerFrame() const
{
	return nullptr;
}
