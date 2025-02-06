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
// Purpose: Logical network device implementation.
//=============================================================================
#ifndef _SYNKRO_NET_NETWORKDEVICE_
#define _SYNKRO_NET_NETWORKDEVICE_


#include "config.h"
#include <lang/Vector.h>
#include <core/ObjectImpl.h>
#include <net/INetworkDeviceEx.h>
#include "NetworkPeer.h"


namespace synkro
{


namespace net
{


class MaxNetworkMessage :
	public NetworkMessage
{
public:
	MaxNetworkMessage( UShort type );

	Byte Data[1024];
};


// Logical device implementation.
class NetworkDevice :
	public core::ObjectImpl<INetworkDeviceEx>
{
public:
	// Constructor and destructor.
	NetworkDevice( INetworkSystemEx* networkSystem, INetworkDevice* device, UInt index );
	virtual ~NetworkDevice();

	// INetworkDevice methods.
	INetworkPeer*											CreatePeer( UShort port );
	void													GetDesc( NetworkDeviceDesc& desc ) const;

	// INetworkDeviceEx methods.
	void													ListenEvent( NetworkListener* listener, UShort type );

	// Other methods.
	void													Update();
	void													ListenPort( UShort port );
	UInt													GetNextEvent( UShort type, UInt event, UInt& address, UShort& port, NetworkMessage** message, UInt* size, Bool handle );
	UInt													GetIndex() const;

private:
	struct DeviceEvent
	{
		DeviceEvent( UShort type, UInt address, UShort port, UInt start, UInt size ) :
			Type( type ),
			Address( address ),
			Port( port ),
			Start( start ),
			Size( size ),
			Handled( false )
		{
		}

		DeviceEvent() :
			Type( 0 ),
			Address( 0 ),
			Port( 0 ),
			Start( 0 ),
			Size( 0 ),
			Handled( false )
		{
		}

		UShort	Type;
		UInt	Address;
		UShort	Port;
		UInt	Start;
		UInt	Size;
		Bool	Handled;
	};

	lang::Vector<Byte>										_data;
	lang::Vector<UShort>									_ports;
	lang::Vector<DeviceEvent>								_events;
	lang::Vector<P(NetworkPeer)>							_peers;
	INetworkSystemEx*										_networkSystem;
	P(INetworkDevice)										_device;
	UInt													_index;
	MaxNetworkMessage										_buffer;
};


#include "NetworkDevice.inl"


} // net


} // synkro


#endif // _SYNKRO_NET_NETWORKDEVICE_
