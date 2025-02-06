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
// Purpose: Generic DELETE query implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE DeleteQueryImpl<T>::DeleteQueryImpl( IDataTable* table ) :
	DatabaseQueryImpl<T>( table )
{
}

template <class T>
SYNKRO_INLINE DeleteQueryImpl<T>::~DeleteQueryImpl()
{
}

template <class T>
SYNKRO_INLINE void DeleteQueryImpl<T>::Reset()
{
	SetFilter( nullptr );
}

template <class T>
SYNKRO_INLINE void DeleteQueryImpl<T>::SetFilter( IDataFilter* filter )
{
	if ( filter != _filter )
	{
		_filter = filter;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE IDataFilter* DeleteQueryImpl<T>::GetFilter() const
{
	return _filter;
}
