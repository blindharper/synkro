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
// Purpose: Logical network peer implementation.
//==============================================================================
SYNKRO_INLINE UInt NetworkPeer::Send( INetworkPeer* peer, const NetworkMessage* message, UInt size )
{
	return _peer->Send( ((NetworkPeer*)peer)->_peer, message, size );
}

SYNKRO_INLINE UInt NetworkPeer::Receive( UInt* address, UShort* port, NetworkMessage* message, UInt size )
{
	return _peer->Receive( address, port, message, size );
}

SYNKRO_INLINE UShort NetworkPeer::GetPort() const
{
	return _peer->GetPort();
}
