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
// Purpose: DX11 frame rendering window implementation.
//==============================================================================
SYNKRO_INLINE Bool Dx11FrameRenderWindow::Bind()
{
	HRESULT hr = _swapChain->Present( 0, DXGI_PRESENT_TEST );
	switch ( hr )
	{
		case DXGI_ERROR_DEVICE_REMOVED:
			return false;
	}

	Dx11Lock( _context );
	_context->OMSetRenderTargets( 1, &_rtv, nullptr );
	_context->RSSetViewports( 1, &_viewport );

	return true;
}

SYNKRO_INLINE void Dx11FrameRenderWindow::Clear()
{
	Dx11Lock( _context );
	_context->ClearRenderTargetView( _rtv, &_defaultColor.x );
}

SYNKRO_INLINE Bool Dx11FrameRenderWindow::Present()
{
	return SUCCEEDED( _swapChain->Present(_syncInterval, 0) );
}
