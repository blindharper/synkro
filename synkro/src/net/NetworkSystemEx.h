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
#ifndef _SYNKRO_NET_NETWORKSYSTEMEX_
#define _SYNKRO_NET_NETWORKSYSTEMEX_


#include "config.h"
#include <core/ObjectImpl.h>
#include <net/INetworkSystemEx.h>
#include <lang/Map.h>
#include "NetworkDevice.h"


namespace synkro
{


namespace net
{


// Extended network system.
class NetworkSystemEx :
	public core::ObjectImpl<INetworkSystemEx>,
	public Logger
{
public:
	// Constructor & destructor.
	NetworkSystemEx( diag::ILog* log );
	~NetworkSystemEx();

	// ISystem methods.
	Bool													Update( Double delta );

	// INetworkSystem methods.
	INetworkDevice*											CreateRemoteDevice( UInt address );
	INetworkDevice*											CreateDevice( UInt index );
	UInt													GetTotalDeviceCount() const;
	void													GetDeviceDesc( UInt index, NetworkDeviceDesc& desc ) const;

	// INetworkSystemEx methods.
	UInt													GetDeviceCount() const;
	INetworkDeviceEx*										GetDevice( UInt index ) const;
	INetworkDeviceEx*										GetDevice() const;

	// Other methods.
	void													ListenEvent( INetworkDevice* device, NetworkListener* listener, UShort type );
	void													Listen( NetworkListener* listener, UInt device, UShort port );
	void													Initialize( INetworkSystemFactory* factory );
	void													Finalize();

private:
	struct NetworkEvent
	{
		NetworkEvent( UInt device, UShort type ) :
			Device( device ),
			Port( 0 ),
			Type( type )
		{
		}

		NetworkEvent() :
			Device( 0 ),
			Port( 0 ),
			Type( 0 )
		{
		}

		UInt	Device;
		UShort	Port;
		UShort	Type;
	};

	struct NetworkListenerDesc
	{
		NetworkListenerDesc( NetworkListener* listener ) :
			Events( A(NetworkEvent) ),
			Listener( listener )
		{
		}

		NetworkListenerDesc() :
			Events( A(NetworkEvent) ),
			Listener( nullptr )
		{
		}

		lang::Vector<NetworkEvent>	Events;
		NetworkListener*			Listener;
	};

	typedef lang::MapPair<UInt, P(NetworkDevice)>			DeviceEntry;

	INetworkSystemFactory*									_factory;
	P(INetworkSystem)										_networkSystem;
	lang::Map<UInt, P(NetworkDevice)>						_remoteDevices;
	lang::Vector<P(NetworkDevice)>							_devices;
	lang::Vector<NetworkListenerDesc>						_listeners;

	NetworkListenerDesc*									GetListener( NetworkListener* listener );
};


#include "NetworkSystemEx.inl"


} // net


} // synkro


#endif // _SYNKRO_NET_NETWORKSYSTEMEX_
