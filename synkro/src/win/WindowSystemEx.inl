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
// Purpose: Implements extended window system.
//==============================================================================
SYNKRO_INLINE UInt WindowSystemEx::GetMonitorCount() const
{
	return _windowSystem->GetMonitorCount();
}

SYNKRO_INLINE IMonitor* WindowSystemEx::GetMonitor( UInt index ) const
{
	return _windowSystem->GetMonitor( index );
}

SYNKRO_INLINE IMonitor* WindowSystemEx::GetMonitor() const
{
	return _windowSystem->GetMonitor();
}

SYNKRO_INLINE UInt WindowSystemEx::GetFrameWindowCount() const
{
	return _frameWindows.Size();
}

SYNKRO_INLINE IFrameWindowEx* WindowSystemEx::GetFrameWindow( UInt index ) const
{
	assert( index < _frameWindows.Size() );

	if ( index >= _frameWindows.Size() )
		throw lang::OutOfRangeException( index, _frameWindows.Size() );

	return _frameWindows[index];
}

SYNKRO_INLINE IIconWindow* WindowSystemEx::GetIconWindow() const
{
	return _iconWindow;
}
