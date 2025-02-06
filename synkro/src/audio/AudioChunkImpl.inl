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
// Purpose: Generic audio buffer chunk implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE AudioChunkImpl<T>::AudioChunkImpl( UInt size ) :
	_size( size )
{
}

template <class T>
SYNKRO_INLINE UInt AudioChunkImpl<T>::GetSize() const
{
	return _size;
}
