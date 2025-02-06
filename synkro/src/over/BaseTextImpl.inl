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
// Purpose: Generic base text implementation.
//=============================================================================
template <class T>
SYNKRO_INLINE BaseTextImpl<T>::BaseTextImpl( BaseTextPool* pool ) :
	_pool( pool )
{
	_pool->AddText( this );
}

template <class T>
SYNKRO_INLINE BaseTextImpl<T>::~BaseTextImpl()
{
	_pool->RemoveText( this );
}
	
template <class T>
SYNKRO_INLINE void BaseTextImpl<T>::Update()
{
}
