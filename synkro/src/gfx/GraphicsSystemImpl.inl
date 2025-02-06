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
// Purpose: Generic graphics system implementation.
//=============================================================================
template <class T>
SYNKRO_INLINE GraphicsSystemImpl<T>::GraphicsSystemImpl( const lang::String& name, win::IWindowSystemEx* windowSystem, diag::ILog* log ) :
	_name( name ),
	_devices( A(GraphicsDeviceDesc) ),
	_windowSystem( windowSystem ),
	Logger( log, diag::LogFacility::GraphicsSystem )
{
}

template <class T>
SYNKRO_INLINE GraphicsSystemImpl<T>::~GraphicsSystemImpl()
{
}

template <class T>
SYNKRO_INLINE Bool GraphicsSystemImpl<T>::Update( Double delta )
{
	return true;
}

template <class T>
SYNKRO_INLINE UInt GraphicsSystemImpl<T>::GetTotalDeviceCount() const
{
	return _devices.Size();
}

template <class T>
SYNKRO_INLINE void GraphicsSystemImpl<T>::GetDeviceDesc( UInt index, GraphicsDeviceDesc& desc ) const
{
	assert( index < _devices.Size() );

	if ( index >= _devices.Size() )
		throw lang::OutOfRangeException( index, _devices.Size() );

	desc = _devices[index];
}

template <class T>
SYNKRO_INLINE lang::String GraphicsSystemImpl<T>::GetName() const
{
	return _name;
}
