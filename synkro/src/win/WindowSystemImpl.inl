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
// Purpose: Generic window system implementation.
//=============================================================================
template <class T>
SYNKRO_INLINE WindowSystemImpl<T>::WindowSystemImpl( diag::ILog* log ) :
	_monitors( A(P(IMonitor)) ),
	_monitor( nullptr ),
	Logger( log, diag::LogFacility::WindowSystem )
{
}

template <class T>
SYNKRO_INLINE WindowSystemImpl<T>::~WindowSystemImpl()
{
}

template <class T>
SYNKRO_INLINE Bool WindowSystemImpl<T>::Update( Double delta )
{
	return true;
}

template <class T>
SYNKRO_INLINE UInt WindowSystemImpl<T>::GetMonitorCount() const
{
	return _monitors.Size();
}

template <class T>
SYNKRO_INLINE IMonitor* WindowSystemImpl<T>::GetMonitor( UInt index ) const
{
	assert( index < _monitors.Size() );

	if ( index >= _monitors.Size() )
		throw lang::OutOfRangeException( index, _monitors.Size() );

	return _monitors[index];
}

template <class T>
SYNKRO_INLINE IMonitor* WindowSystemImpl<T>::GetMonitor() const
{
	return _monitor;
}
