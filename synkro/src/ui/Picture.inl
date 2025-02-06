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
// Purpose: Picture widget implementation.
//==============================================================================
SYNKRO_INLINE UInt Picture::ID() const
{
	return _widgetID;
}

SYNKRO_INLINE void Picture::Show( Bool show )
{
	// Call base implementation.
	WidgetImpl<IPicture>::Show( show );

	_picture->Show( show );
}

SYNKRO_INLINE void Picture::SetOpacity( Float opacity )
{
	// Call base implementation.
	WidgetImpl<IPicture>::SetOpacity( opacity );

	_picture->SetOpacity( opacity );
}

SYNKRO_INLINE void Picture::SetTabOrder( UInt order )
{
	// Do nothing since picture is not tabbable.
}

SYNKRO_INLINE IPicture* Picture::AsPicture() const
{
	return (IPicture*)this;
}

SYNKRO_INLINE img::IImage* Picture::GetImage() const
{
	return _picture->GetImage();
}

SYNKRO_INLINE void Picture::UpdateRect()
{
	CalcRect();
	_picture->SetLocation( _rect.TopLeft() );
}
