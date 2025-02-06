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
// Purpose: Extended view rendering window.
//==============================================================================
SYNKRO_INLINE Bool ViewRenderWindow::Bind()
{
	SynkroProfile( "ViewRenderWindow.Bind" );

	return _window->Bind();
}

SYNKRO_INLINE void ViewRenderWindow::Clear()
{
	SynkroProfile( "ViewRenderWindow.Clear" );

	_window->Clear();
}

SYNKRO_INLINE Bool ViewRenderWindow::Present()
{
	SynkroProfile( "ViewRenderWindow.Present" );

	return _window->Present();
}

SYNKRO_INLINE void ViewRenderWindow::SetDefaultColor( const math::Vector4& color )
{
	_window->SetDefaultColor( color );
}

SYNKRO_INLINE void ViewRenderWindow::GetDefaultColor( math::Vector4& color ) const
{
	_window->GetDefaultColor( color );
}

SYNKRO_INLINE img::PixelFormat ViewRenderWindow::GetClientPixelFormat() const
{
	return _window->GetClientPixelFormat();
}

SYNKRO_INLINE img::PixelFormat ViewRenderWindow::GetPixelFormat() const
{
	return _window->GetPixelFormat();
}

SYNKRO_INLINE UInt ViewRenderWindow::GetWidth() const
{
	return _window->GetWidth();
}

SYNKRO_INLINE UInt ViewRenderWindow::GetHeight() const
{
	return _window->GetHeight();
}

SYNKRO_INLINE UInt ViewRenderWindow::GetSampleCount() const
{
	return _sampleCount;
}

SYNKRO_INLINE IGraphicsDevice* ViewRenderWindow::GetDevice() const
{
	return (IGraphicsDevice*)_device;
}

SYNKRO_INLINE win::IViewWindow* ViewRenderWindow::GetWindow() const
{
	return _window->GetWindow();
}

SYNKRO_INLINE IRenderView* ViewRenderWindow::GetView() const
{
	return (IRenderView*)(RenderView*)_views[0];
}

SYNKRO_INLINE IOverlayRenderQueue* ViewRenderWindow::GetOverlayQueue() const
{
	return _overlays;
}
