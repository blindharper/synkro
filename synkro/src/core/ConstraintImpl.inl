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
// Purpose: Generic constraint implementation.
//==============================================================================
template <class T> 
SYNKRO_INLINE ConstraintImpl<T>::ConstraintImpl() :
	_enabled( true )
{
}

template <class T>
SYNKRO_INLINE ConstraintImpl<T>::~ConstraintImpl()
{
}

template <class T>
SYNKRO_INLINE void ConstraintImpl<T>::Enable( Bool enable )
{
	_enabled = enable;
}

template <class T>
SYNKRO_INLINE Bool ConstraintImpl<T>::IsEnabled() const
{
	return _enabled;
}
