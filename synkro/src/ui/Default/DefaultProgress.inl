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
// Purpose: Default progress widget implementation.
//==============================================================================
SYNKRO_INLINE void DefaultProgress::SetLocation( const lang::Point& location )
{
	// Call base implementation.
	WidgetImpl<IProgress>::SetLocation( location );

	Update();
}

SYNKRO_INLINE void DefaultProgress::SetSize( const lang::Size& size )
{
	// Call base implementation.
	WidgetImpl<IProgress>::SetSize( size );

	Update();
}

SYNKRO_INLINE ProgressType DefaultProgress::GetType() const
{
	return _type;
}

SYNKRO_INLINE UInt DefaultProgress::GetMaxValue() const
{
	return _maxValue;
}

SYNKRO_INLINE UInt DefaultProgress::GetValue() const
{
	return _value;
}

SYNKRO_INLINE Bool DefaultProgress::IsTextVisible() const
{
	return _textVisible;
}

SYNKRO_INLINE void DefaultProgress::UpdateRect()
{
	CalcRect();
	Update();
}

SYNKRO_INLINE void DefaultProgress::PrintValue()
{
	if ( _text != nullptr )
	{
		const UInt percent = CastUInt( (CastFloat(_value)*100.0f/CastFloat(_maxValue)) );
		_text->SetText( lang::String::Format(L"{0}%", percent) );
	}
}
