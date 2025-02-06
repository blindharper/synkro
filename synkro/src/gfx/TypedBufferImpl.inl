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
// Purpose: Generic typed buffer implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE TypedBufferImpl<T>::TypedBufferImpl( const ProgramDataType& dataType, UInt count ) :
	BufferImpl<T>( count ),
	_dataType( dataType )
{
}

template <class T>
SYNKRO_INLINE TypedBufferImpl<T>::~TypedBufferImpl()
{
}

template <class T>
SYNKRO_INLINE ProgramDataType TypedBufferImpl<T>::GetDataType() const
{
	return _dataType;
}

template <class T>
SYNKRO_INLINE ITypedBuffer* TypedBufferImpl<T>::AsTyped() const
{
	return (ITypedBuffer*)this;
}
