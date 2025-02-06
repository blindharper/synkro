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
// Purpose: Generic base database query implementation.
//=============================================================================
template <class T>
SYNKRO_INLINE BaseDatabaseQueryImpl<T>::BaseDatabaseQueryImpl( IDataTable* table ) :
	_table( table )
{
}

template <class T>
SYNKRO_INLINE BaseDatabaseQueryImpl<T>::~BaseDatabaseQueryImpl()
{
}
	
template <class T>
SYNKRO_INLINE void BaseDatabaseQueryImpl<T>::ValidateColumn( const lang::String& name )
{
	TableColumn column;
	_table->GetColumn( name, column );
}

template <class T>
SYNKRO_INLINE void BaseDatabaseQueryImpl<T>::ValidateFilter( IDataFilter* filter )
{
	if ( filter->GetFirstFilter() != nullptr )
	{
		ValidateFilter( filter->GetFirstFilter() );
		ValidateFilter( filter->GetSecondFilter() );
	}
	else
	{
		ValidateColumn( filter->GetColumn() );
	}
}
