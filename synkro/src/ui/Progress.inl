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
// Purpose: Logical progress widget.
//==============================================================================
SYNKRO_INLINE void Progress::SetLocation( const lang::Point& location )
{
	// Call base implementation.
	WidgetWrapperImpl<IProgress>::SetLocation( location );
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
}

SYNKRO_INLINE void Progress::SetSize( const lang::Size& size )
{
	// Call base implementation.
	WidgetWrapperImpl<IProgress>::SetSize( size );
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
}

SYNKRO_INLINE void Progress::SetAnchor( const Anchor& anchor )
{
	// Call base implementation.
	WidgetWrapperImpl<IProgress>::SetAnchor( anchor );
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
}

SYNKRO_INLINE IProgress* Progress::AsProgress() const
{
	return (IProgress*)this;
}

SYNKRO_INLINE void Progress::SetMaxValue( UInt value )
{
	if ( value < 1 )
	{
		value = 1;
	}
	if ( _progress->GetValue() > value )
	{
		_progress->SetValue( value );
	}
	_progress->SetMaxValue( value );
}

SYNKRO_INLINE void Progress::SetValue( UInt value )
{
	if ( value > _progress->GetMaxValue() )
	{
		value = _progress->GetMaxValue();
	}
	_progress->SetValue( value );
}

SYNKRO_INLINE void Progress::ShowText( Bool show )
{
	_progress->ShowText( show );
}

SYNKRO_INLINE ProgressType Progress::GetType() const
{
	return _progress->GetType();
}

SYNKRO_INLINE UInt Progress::GetMaxValue() const
{
	return _progress->GetMaxValue();
}

SYNKRO_INLINE UInt Progress::GetValue() const
{
	return _progress->GetValue();
}

SYNKRO_INLINE Bool Progress::IsTextVisible() const
{
	return _progress->IsTextVisible();
}
