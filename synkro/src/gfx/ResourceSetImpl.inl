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
// Purpose: Generic resource set implementation.
//==============================================================================
template <class T, class R>
SYNKRO_INLINE ResourceSetImpl<T, R>::ResourceSetImpl( const ProgramStageType& type ) :
	_resources( A(R*) ),
	_type( type )
{
}

template <class T, class R>
SYNKRO_INLINE ResourceSetImpl<T, R>::~ResourceSetImpl()
{
}

template <class T, class R>
SYNKRO_INLINE void ResourceSetImpl<T, R>::Set( UInt index, IResource* resource )
{
	assert( index < _resources.Size() );

	if ( index >= _resources.Size() )
		throw lang::BadArgumentException( lang::String::Format(L"Bad resource index: {0}.", index), L"index" );

	_resources[index] = dynamic_cast<R*>( resource );
}

template <class T, class R>
SYNKRO_INLINE UInt ResourceSetImpl<T, R>::GetSize() const
{
	return _resources.Size();
}

template <class T, class R>
SYNKRO_INLINE IResource* ResourceSetImpl<T, R>::Get( UInt index ) const
{
	assert( index < _resources.Size() );

	if ( index >= _resources.Size() )
		throw lang::BadArgumentException( lang::String::Format(L"Bad resource index: {0}.", index), L"index" );

	return (IResource*)(_resources[index]);
}
