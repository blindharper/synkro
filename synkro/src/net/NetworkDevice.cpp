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
//==============================================================================
#include "config.h"
#include "NetworkDevice.h"
#include "NetworkPeer.h"
#include "NetworkSystemEx.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace net
{


MaxNetworkMessage::MaxNetworkMessage( UShort type ) :
	NetworkMessage( type )
{
}


//------------------------------------------------------------------------------


NetworkDevice::NetworkDevice( INetworkSystemEx* networkSystem, INetworkDevice* device, UInt index ) :
	_data( A(Byte) ),
	_ports( A(UShort) ),
	_events( A(DeviceEvent) ),
	_peers( A(P(NetworkPeer)) ),
	_networkSystem( networkSystem ),
	_device( device ),
	_index( index ),
	_buffer( 0 )
{
}

NetworkDevice::~NetworkDevice()
{
}

INetworkPeer* NetworkDevice::CreatePeer( UShort port )
{
	for ( UInt i = 0; i < _peers.Size(); ++i )
	{
		if ( _peers[i]->GetPort() == port )
			return _peers[i];
	}

	NetworkPeer* peer = new NetworkPeer( this, _device->CreatePeer(port) );
	_peers.Add( peer );
	return peer;
}

void NetworkDevice::ListenEvent( NetworkListener* listener, UShort type )
{
	assert( listener != nullptr );

	((NetworkSystemEx*)_networkSystem)->ListenEvent( this, listener, type );
}

void NetworkDevice::Update()
{
	// Remove old events.
	_events.Clear();
	_data.Clear();

	for ( UInt i = 0; i < _peers.Size(); ++i )
	{
		// Skip unknown ports.
		if ( !_ports.Contains(_peers[i]->GetPort()) )
			continue;

		UInt bytes = 0; UInt address = 0; UShort port = 0;
		while ( (bytes = _peers[i]->Receive( &address, &port, &_buffer, 1024)) > 0 )
		{
			// Record event.
			_events.Add( DeviceEvent(0, address, port, _data.Size(), bytes) );
			_data.Add( (const Byte*)&_buffer, bytes );
			_events[_events.Size()-1].Type = ((NetworkMessage*)&_data[_events[_events.Size()-1].Start])->Type;
		}
	}
}

void NetworkDevice::ListenPort( UShort port )
{
	if ( !_ports.Contains(port) )
		_ports.Add( port );
}

UInt NetworkDevice::GetNextEvent( UShort type, UInt event, UInt& address, UShort& port, NetworkMessage** message, UInt* size, Bool handle )
{
	if ( (event != none) && handle )
	{
		_events[event].Handled = handle;
	}

	for ( UInt i = (event != none) ? event+1 : 0; i < _events.Size(); ++i )
	{
		if ( (_events[i].Type != type) || _events[i].Handled )
			continue;

		address		= _events[i].Address;
		port		= _events[i].Port;
		*message	= (NetworkMessage*)&_data[_events[i].Start];
		*size		= _events[i].Size;
		return i;
	}

	return none;
}


} // net


} // synkro
