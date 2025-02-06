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
// Purpose: Generic database query implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE DatabaseQueryImpl<T>::DatabaseQueryImpl( IDataTable* table ) :
	_table( table ),
	_dirty( true )
{
}

template <class T>
SYNKRO_INLINE DatabaseQueryImpl<T>::~DatabaseQueryImpl()
{
}

template <class T>
SYNKRO_INLINE void DatabaseQueryImpl<T>::Execute()
{
	throw lang::NotSupportedException();
}

template <class T>
SYNKRO_INLINE void DatabaseQueryImpl<T>::Reset()
{
	// Do nothing.
}
