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
// Purpose: Generic network system implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE NetworkSystemImpl<T>::NetworkSystemImpl( diag::ILog* log ) :
	_devices( A(NetworkDeviceDesc) ),
	Logger( log, diag::LogFacility::NetworkSystem )
{
}

template <class T>
SYNKRO_INLINE NetworkSystemImpl<T>::~NetworkSystemImpl()
{
	_devices.Clear();
}

template <class T>
SYNKRO_INLINE UInt NetworkSystemImpl<T>::GetTotalDeviceCount() const
{
	return _devices.Size();
}

template <class T>
SYNKRO_INLINE void NetworkSystemImpl<T>::GetDeviceDesc( UInt index, NetworkDeviceDesc& desc ) const
{
	assert( index < _devices.Size() );

	if ( index >= _devices.Size() )
		throw lang::OutOfRangeException( index, _devices.Size() );

	desc = _devices[index];
}
