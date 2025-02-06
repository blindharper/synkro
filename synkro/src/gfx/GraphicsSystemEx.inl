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
// Purpose: Extended graphics system.
//=============================================================================
SYNKRO_INLINE IProgram* GraphicsSystemEx::GetProgram( const lang::String& name ) const
{
	SynkroCall( "GraphicsSystemEx.GetProgram", name );

	return _device->GetProgram( name );
}

SYNKRO_INLINE UInt GraphicsSystemEx::GetTotalDeviceCount() const
{
	return _graphicsSystem->GetTotalDeviceCount();
}

SYNKRO_INLINE void GraphicsSystemEx::GetDeviceDesc( UInt index, GraphicsDeviceDesc& desc ) const
{
	_graphicsSystem->GetDeviceDesc( index, desc );
}

SYNKRO_INLINE lang::String GraphicsSystemEx::GetName() const
{
	return _graphicsSystem->GetName();
}

SYNKRO_INLINE UInt GraphicsSystemEx::GetDeviceCount() const
{
	return _devices.Size();
}

SYNKRO_INLINE IGraphicsDeviceEx* GraphicsSystemEx::GetDevice( UInt index ) const
{
	assert( index < _devices.Size() );

	if ( index >= _devices.Size() )
		throw lang::OutOfRangeException( index, _devices.Size() );

	return _devices[index];
}

SYNKRO_INLINE IGraphicsDeviceEx* GraphicsSystemEx::GetDevice() const
{
	return _device;
}

SYNKRO_INLINE UInt GraphicsSystemEx::GetFrameWindowCount() const
{
	return _device->_frameWindows.Size();
}

SYNKRO_INLINE IFrameRenderWindowEx* GraphicsSystemEx::GetFrameWindow( UInt index ) const
{
	assert( index < _device->_frameWindows.Size() );

	if ( index >= _device->_frameWindows.Size() )
		throw lang::OutOfRangeException( index, _device->_frameWindows.Size() );

	return _device->_frameWindows[index];
}

SYNKRO_INLINE UInt GraphicsSystemEx::GetViewWindowCount() const
{
	return _device->_viewWindows.Size();
}

SYNKRO_INLINE IViewRenderWindowEx* GraphicsSystemEx::GetViewWindow( UInt index ) const
{
	assert( index < _device->_viewWindows.Size() );

	if ( index >= _device->_viewWindows.Size() )
		throw lang::OutOfRangeException( index, _device->_viewWindows.Size() );

	return _device->_viewWindows[index];
}

SYNKRO_INLINE UInt GraphicsSystemEx::GetVirtualWindowCount() const
{
	return _virtualWindows.Size();
}

SYNKRO_INLINE IVirtualRenderWindow* GraphicsSystemEx::GetVirtualWindow( UInt index ) const
{
	assert( index < _virtualWindows.Size() );

	if ( index >= _virtualWindows.Size() )
		throw lang::OutOfRangeException( index, _virtualWindows.Size() );

	return _virtualWindows[index];
}

SYNKRO_INLINE void GraphicsSystemEx::GetStats( GraphicsStats& stats ) const
{
	stats = _stats;
}

SYNKRO_INLINE void GraphicsSystemEx::SetProgramCache( io::IStreamDirectory* programCache )
{
	_programCache = programCache;
}
