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
// Purpose: Generic frame rendering window implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE FrameRenderWindowImpl<T>::FrameRenderWindowImpl( IGraphicsDevice* device, win::IFrameWindow* window, UInt sampleCount ) :
	RenderWindowImpl<T>( device, window, img::PixelFormat::Unknown, sampleCount ),
	_window( window )
{
}

template <class T>
SYNKRO_INLINE FrameRenderWindowImpl<T>::~FrameRenderWindowImpl()
{
}

template <class T>
SYNKRO_INLINE void FrameRenderWindowImpl<T>::GetDisplayMode( DisplayMode& displayMode ) const
{
	displayMode = _displayMode;
}

template <class T>
SYNKRO_INLINE win::IFrameWindow* FrameRenderWindowImpl<T>::GetWindow() const
{
	return _window;
}
