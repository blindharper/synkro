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
// Purpose: Extended network system.
//=============================================================================
SYNKRO_INLINE UInt NetworkSystemEx::GetTotalDeviceCount() const
{
	return _networkSystem->GetTotalDeviceCount();
}

SYNKRO_INLINE void NetworkSystemEx::GetDeviceDesc( UInt index, NetworkDeviceDesc& desc ) const
{
	_networkSystem->GetDeviceDesc( index, desc );
}

SYNKRO_INLINE UInt NetworkSystemEx::GetDeviceCount() const
{
	return _devices.Size();
}

SYNKRO_INLINE INetworkDeviceEx* NetworkSystemEx::GetDevice( UInt index ) const
{
	assert( index < _devices.Size() );

	if ( index >= _devices.Size() )
		throw lang::OutOfRangeException( index, _devices.Size() );

	return _devices[index];
}

SYNKRO_INLINE INetworkDeviceEx* NetworkSystemEx::GetDevice() const
{
	return (_devices.Size() > 0) ? _devices[0] : nullptr;
}
