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
// Purpose: Generic base resource implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE BaseResourceImpl<T>::BaseResourceImpl() :
	_parents( A(ParentEntry) ),
	_resource( nullptr ),
	_dirty( true )
{
}

template <class T>
SYNKRO_INLINE BaseResourceImpl<T>::~BaseResourceImpl()
{
}

template <class T>
SYNKRO_INLINE void BaseResourceImpl<T>::AddParent( ResourceSet* parent )
{
	Pointer key = reinterpret_cast<Pointer>( parent );
	if ( !_parents.ContainsKey(key) )
	{
		_parents[key] = 0;
	}
	UInt refs = _parents[key];
	_parents[key] = refs+1;
}

template <class T>
SYNKRO_INLINE void BaseResourceImpl<T>::RemoveParent( ResourceSet* parent )
{
	Pointer key = reinterpret_cast<Pointer>( parent );
	if ( _parents.ContainsKey(key) )
	{
		UInt refs = _parents[key] - 1;
		_parents[key] = refs;
		if ( refs == 0 )
		{
			_parents.Remove( key );
		}
	}
}

template <class T>
SYNKRO_INLINE void BaseResourceImpl<T>::Invalidate()
{
	lang::MapIterator<Pointer, UInt> itParent = _parents.Begin();
	lang::MapIterator<Pointer, UInt> itParentEnd = _parents.End();
	for ( ; itParent != itParentEnd ; ++itParent )
	{
		ResourceSet* parent = reinterpret_cast<ResourceSet*>( itParent.Key() );
		parent->SetDirty();
	}
}

template <class T>
SYNKRO_INLINE IResource* BaseResourceImpl<T>::AsResource() const
{
	return _resource;
}
