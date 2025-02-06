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
// Purpose: Generic view rendering window implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE ViewRenderWindowImpl<T>::ViewRenderWindowImpl( IGraphicsDevice* device, win::IViewWindow* window, const img::PixelFormat& format, UInt sampleCount ) :
	RenderWindowImpl<T>( device, window, format, sampleCount ),
	_window( window )
{
}

template <class T>
SYNKRO_INLINE ViewRenderWindowImpl<T>::~ViewRenderWindowImpl()
{
}

template <class T>
SYNKRO_INLINE win::IViewWindow* ViewRenderWindowImpl<T>::GetWindow() const
{
	return _window;
}
