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
#include "config.h"
#include "NetworkSystemEx.h"
#include <net/INetworkSystemFactory.h>
#include <net/NetworkListener.h>
#include <core/Platform.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::diag;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace net
{


NetworkSystemEx::NetworkSystemEx( ILog* log ) :
	_factory( nullptr ),
	_networkSystem( nullptr ),
	_remoteDevices( A(DeviceEntry) ),
	_devices( A(P(NetworkDevice)) ),
	_listeners( A(NetworkListenerDesc) ),
	Logger( log, LogFacility::NetworkSystem )
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Creating network system...") );
}

NetworkSystemEx::~NetworkSystemEx()
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Destroying network system...") );
}

Bool NetworkSystemEx::Update( Double delta )
{
	SynkroProfile( "NetworkSystemEx.Update" );

	// Update logical devices.
	for ( UInt i = 0; i < _devices.Size(); ++i )
	{
		_devices[i]->Update();
	}

	// Update listeners in reverse order.
	UInt address; UShort port; NetworkMessage* data; UInt size;
	UInt cnt = _listeners.Size();
	for ( UInt i = 0; i < cnt; ++i )
	{
		UInt event = none; Bool handled = false;
		NetworkListenerDesc& desc = _listeners[cnt-1-i];
		for ( UInt e = 0; e < desc.Events.Size(); ++e )
		{
			UInt type = desc.Events[e].Type;
			NetworkDevice* device = _devices[desc.Events[e].Device];
			if ( (event = device->GetNextEvent(type, none, address, port, &data, &size, false)) != none )
			{
				do
				{
					// Notify listener.
					handled = desc.Listener->OnNetworkEvent( desc.Events[e].Device, type, address, port, data, size );
				}
				while( (event = device->GetNextEvent(type, event, address, port, &data, &size, handled)) != none );
			}
		}
	}

	// Prevent eating CPU time.
	Platform::Sleep( 0 );

	return true;
}

INetworkDevice* NetworkSystemEx::CreateRemoteDevice( UInt address )
{
	if ( !_remoteDevices.ContainsKey(address) )
	{
		_remoteDevices[address] = new NetworkDevice( this, _networkSystem->CreateRemoteDevice(address), none );
	}
	return _remoteDevices[address];
}

INetworkDevice* NetworkSystemEx::CreateDevice( UInt index )
{
	for ( UInt i = 0; _devices.Size(); ++i )
	{
		if ( _devices[i]->GetIndex() == index )
			return _devices[i];
	}

	NetworkDevice* device = new NetworkDevice( this, _networkSystem->CreateDevice(index), index );
	_devices.Add( device );
	return device;
}

void NetworkSystemEx::ListenEvent( INetworkDevice* device, NetworkListener* listener, UShort type )
{
	UInt index = ((NetworkDevice*)device)->GetIndex();
	NetworkListenerDesc* desc = GetListener( listener );
	for ( UInt i = 0; i < desc->Events.Size(); ++i )
	{
		if ( (desc->Events[i].Device == index) && (desc->Events[i].Type == type) )
			return;
	}
	desc->Events.Add( NetworkEvent(index, type) );
}

void NetworkSystemEx::Listen( NetworkListener* listener, UInt device, UShort port )
{
	assert( device < _devices.Size() );

	if ( device >= _devices.Size() )
		throw OutOfRangeException( device, _devices.Size() );

	// Find controller description.
	NetworkListenerDesc* ctrl = nullptr;
	for ( UInt i = 0; i < _listeners.Size(); ++i )
	{
		if ( _listeners[i].Listener == listener )
		{
			ctrl = &_listeners[i];
			break;
		}
	}
	if ( ctrl == nullptr )
	{
		_listeners.Add( NetworkListenerDesc(listener) );
		ctrl = _listeners.Last();
	}

	for ( UInt i = 0; i < ctrl->Events.Size(); ++i )
	{
		if ( (ctrl->Events[i].Device == device) && (ctrl->Events[i].Port == port) )
			return;
	}

	ctrl->Events.Add( NetworkEvent(device, port) );
	_devices[device]->ListenPort( port );
}

void NetworkSystemEx::Initialize( INetworkSystemFactory* factory )
{
	// Re-create network system, if needed.
	if ( factory != _factory )
	{
		_factory = factory;
		_networkSystem = nullptr;
		_networkSystem = factory->Create( _log );
	}
}

void NetworkSystemEx::Finalize()
{
	_devices.Clear();
}

NetworkSystemEx::NetworkListenerDesc* NetworkSystemEx::GetListener( NetworkListener* listener )
{
	NetworkListenerDesc* desc = nullptr;
	for ( UInt i = 0; i < _listeners.Size(); ++i )
	{
		if ( _listeners[i].Listener == listener )
		{
			desc = _listeners.Get( i );
			break;
		}
	}
	if ( desc == nullptr )
	{
		_listeners.Add( NetworkListenerDesc(listener) );
		desc = _listeners.Last();
	}
	return desc;
}


} // net


} // synkro
