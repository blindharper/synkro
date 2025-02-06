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
// Purpose: Virtual rendering window.
//==============================================================================
SYNKRO_INLINE Bool VirtualRenderWindow::Bind()
{
	SynkroProfile( "VirtualRenderWindow.Bind" );

	return _target->Bind();
}

SYNKRO_INLINE void VirtualRenderWindow::Clear()
{
	SynkroProfile( "VirtualRenderWindow.Clear" );

	_target->Clear();
}

SYNKRO_INLINE Bool VirtualRenderWindow::Present()
{
	SynkroProfile( "VirtualRenderWindow.Present" );

	return _target->Present();
}

SYNKRO_INLINE void VirtualRenderWindow::SetDefaultColor( const math::Vector4& color )
{
	_target->SetDefaultColor( color );
}

SYNKRO_INLINE void VirtualRenderWindow::GetDefaultColor( math::Vector4& color ) const
{
	_target->GetDefaultColor( color );
}

SYNKRO_INLINE img::PixelFormat VirtualRenderWindow::GetClientPixelFormat() const
{
	return _target->GetFormat();
}

SYNKRO_INLINE img::PixelFormat VirtualRenderWindow::GetPixelFormat() const
{
	return _target->GetFormat();
}

SYNKRO_INLINE UInt VirtualRenderWindow::GetWidth() const
{
	return _target->GetWidth();
}

SYNKRO_INLINE UInt VirtualRenderWindow::GetHeight() const
{
	return _target->GetHeight();
}

SYNKRO_INLINE UInt VirtualRenderWindow::GetSampleCount() const
{
	return _sampleCount;
}

SYNKRO_INLINE IGraphicsDevice* VirtualRenderWindow::GetDevice() const
{
	return (IGraphicsDevice*)_device;
}

SYNKRO_INLINE IRenderView* VirtualRenderWindow::GetView() const
{
	return (IRenderView*)(RenderView*)_views[0];
}

SYNKRO_INLINE IPlainRenderTexture* VirtualRenderWindow::GetTarget() const
{
	return _target;
}

SYNKRO_INLINE IOverlayRenderQueue* VirtualRenderWindow::GetOverlayQueue() const
{
	return _overlays;
}
