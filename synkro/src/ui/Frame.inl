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
// Purpose: Frame container implementation.
//==============================================================================
SYNKRO_INLINE UInt Frame::ID() const
{
	return _frameID;
}

SYNKRO_INLINE void Frame::Show( Bool show )
{
	// Call base implementation.
	FrameImpl<IFrame>::Show( show );

	_frame->Show( _visible );
}

SYNKRO_INLINE void Frame::ShowBorder( Bool show )
{
	// Call base implementation.
	FrameImpl<IFrame>::ShowBorder( show );

	_frame->ShowBorder( _borderVisible );
}

SYNKRO_INLINE void Frame::SetLocation( const lang::Point& location )
{
	// Call base implementation.
	FrameImpl<IFrame>::SetLocation( location );

	_frame->SetLocation( location );

	BaseAnchoredObjectImpl<BaseAnchoredObject, IFrame>::SaveAnchors();
}

SYNKRO_INLINE void Frame::SetAnchor( const Anchor& anchor )
{
	// Call base implementation.
	FrameImpl<IFrame>::SetAnchor( anchor );

	_frame->SetAnchor( anchor );

	BaseAnchoredObjectImpl<BaseAnchoredObject, IFrame>::SaveAnchors();
}

SYNKRO_INLINE void Frame::SetTheme( ITheme* theme )
{
	// Do nothing.
}

SYNKRO_INLINE void Frame::AddFrame( IFrame* frame )
{
	assert( frame != nullptr );

	_frames.Add( frame );
}

SYNKRO_INLINE void Frame::UpdateTabOrder()
{
	_activeWidgets.Sort();
}

SYNKRO_INLINE IFrame* Frame::GetInnerFrame() const
{
	return _frame;
}

SYNKRO_INLINE lang::Point Frame::ToLocation( IFrame* frame ) const
{
	lang::Point location;
	frame->GetLocation( location );
	return location;
}

SYNKRO_INLINE lang::Size Frame::ToSize( IFrame* frame ) const
{
	lang::Size size;
	frame->GetSize( size );
	return size;
}
