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
// Purpose: Extended frame rendering window.
//==============================================================================
SYNKRO_INLINE Bool FrameRenderWindow::Bind()
{
	SynkroProfile( "FrameRenderWindow.Bind" );

	return _window->Bind();
}

SYNKRO_INLINE void FrameRenderWindow::Clear()
{
	SynkroProfile( "FrameRenderWindow.Clear" );

	_window->Clear();
}

SYNKRO_INLINE Bool FrameRenderWindow::Present()
{
	SynkroProfile( "FrameRenderWindow.Present" );

	return _window->Present();
}

SYNKRO_INLINE void FrameRenderWindow::SetDefaultColor( const math::Vector4& color )
{
	_window->SetDefaultColor( color );
}

SYNKRO_INLINE void FrameRenderWindow::GetDefaultColor( math::Vector4& color ) const
{
	_window->GetDefaultColor( color );
}

SYNKRO_INLINE img::PixelFormat FrameRenderWindow::GetClientPixelFormat() const
{
	return _window->GetClientPixelFormat();
}

SYNKRO_INLINE img::PixelFormat FrameRenderWindow::GetPixelFormat() const
{
	return _window->GetPixelFormat();
}

SYNKRO_INLINE UInt FrameRenderWindow::GetWidth() const
{
	return _window->GetWidth();
}

SYNKRO_INLINE UInt FrameRenderWindow::GetHeight() const
{
	return _window->GetHeight();
}

SYNKRO_INLINE UInt FrameRenderWindow::GetSampleCount() const
{
	return _sampleCount;
}

SYNKRO_INLINE IGraphicsDevice* FrameRenderWindow::GetDevice() const
{
	return (IGraphicsDevice*)_device;
}

SYNKRO_INLINE void FrameRenderWindow::GetDisplayMode( DisplayMode& displayMode ) const
{
	_window->GetDisplayMode( displayMode );
}

SYNKRO_INLINE win::IFrameWindow* FrameRenderWindow::GetWindow() const
{
	return _window->GetWindow();
}

SYNKRO_INLINE void FrameRenderWindow::SetTarget( IPlainRenderTexture* target )
{
	_target = target;
}

SYNKRO_INLINE UInt FrameRenderWindow::GetViewCount() const
{
	return _views.Size();
}

SYNKRO_INLINE IRenderView* FrameRenderWindow::GetView( UInt index ) const
{
	assert( index < _views.Size() );

	if ( index >= _views.Size() )
		throw lang::OutOfRangeException( index, _views.Size() );

	return (IRenderView*)_views[index].AsPtr();
}

SYNKRO_INLINE IPlainRenderTexture* FrameRenderWindow::GetTarget() const
{
	return _target;
}

SYNKRO_INLINE IOverlayRenderQueue* FrameRenderWindow::GetOverlayQueue() const
{
	return _overlays;
}
