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
// Purpose: Generic network device implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE NetworkDeviceImpl<T>::NetworkDeviceImpl( const NetworkDeviceDesc& desc ) :
	_desc( desc )
{
}

template <class T>
SYNKRO_INLINE NetworkDeviceImpl<T>::~NetworkDeviceImpl()
{
}

template <class T>
SYNKRO_INLINE void NetworkDeviceImpl<T>::GetDesc( NetworkDeviceDesc& desc ) const
{
	desc = _desc;
}
