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
// Purpose: Generic factory implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE FactoryImpl<T>::FactoryImpl( const Iface& ifaceID, const lang::Enum& classID ) :
	_ifaceID( ifaceID ),
	_classID( classID )
{
#ifdef SYNKRO_STATIC
	BaseFactory::Next = _Factories;
	BaseFactory::Fact = this;
	_Factories = this;
#endif // SYNKRO_STATIC
}

template <class T>
SYNKRO_INLINE FactoryImpl<T>::~FactoryImpl()
{
}

template <class T>
SYNKRO_INLINE Iface FactoryImpl<T>::GetIfaceID() const
{
	return _ifaceID;
}

template <class T>
SYNKRO_INLINE lang::Enum FactoryImpl<T>::GetClassID() const
{
	return _classID;
}
