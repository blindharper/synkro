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
// Purpose: Generic network peer implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE NetworkPeerImpl<T>::NetworkPeerImpl( INetworkDevice* device, UShort port ) :
	_device( device ),
	_port( port )
{
}

template <class T>
SYNKRO_INLINE NetworkPeerImpl<T>::~NetworkPeerImpl()
{
}

template <class T>
SYNKRO_INLINE INetworkDevice* NetworkPeerImpl<T>::GetDevice() const
{
	return _device;
}

template <class T>
SYNKRO_INLINE UShort NetworkPeerImpl<T>::GetPort() const
{
	return _port;
}
