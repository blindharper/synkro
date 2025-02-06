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
// Purpose: Generic INSERT query implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE InsertQueryImpl<T>::InsertQueryImpl( IDataTable* table ) :
	DatabaseQueryImpl<T>( table ),
	_values( A(ValueEntry) )
{
}

template <class T>
SYNKRO_INLINE InsertQueryImpl<T>::~InsertQueryImpl()
{
}

template <class T>
SYNKRO_INLINE void InsertQueryImpl<T>::Reset()
{
	_values.Clear();
	_dirty = true;
}

template <class T>
SYNKRO_INLINE void InsertQueryImpl<T>::SetValue( const lang::String& column, const lang::Variant& value )
{
	if ( !_values.ContainsKey(column) )
	{
		_dirty = true;
	}
	_values[column] = value;
}
