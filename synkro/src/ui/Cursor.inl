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
// Purpose: User interface cursor implementation.
//==============================================================================
SYNKRO_INLINE void Cursor::Show( Bool show )
{
	_object->Enable( show );
}

SYNKRO_INLINE void Cursor::SetType( const CursorType& type )
{
	_type = type;
}

SYNKRO_INLINE Bool Cursor::IsVisible() const
{
	return _object->IsEnabled();
}

SYNKRO_INLINE CursorType Cursor::GetType() const
{
	return _type;
}

SYNKRO_INLINE void Cursor::GetLocation( lang::Point& location ) const
{
	location = _location;
}

SYNKRO_INLINE void Cursor::SetColor( const img::Color& color )
{
	_object->GetFragmentParameters()->Set( _paramColor, ToVector(color) );
}
