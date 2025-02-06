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
// Purpose: DX11 graphics device implementation.
//==============================================================================
#include "config.h"
#include "Dx11GraphicsDevice.h"
#include "Dx11LinearRenderTexture.h"
#include "Dx11PlainRenderTexture.h"
#include "Dx11CubeRenderTexture.h"
#include "Dx11VolumeRenderTexture.h"
#include "Dx11RenderTextureSet.h"
#include "Dx11FrameRenderWindow.h"
#include "Dx11ViewRenderWindow.h"
#include "Dx11CubeDepthTexture.h"
#include "Dx11PlainDepthTexture.h"
#include "Dx11LinearTexture.h"
#include "Dx11PlainTexture.h"
#include "Dx11CubeTexture.h"
#include "Dx11VolumeTexture.h"
#include "Dx11BlendStateSet.h"
#include "Dx11DepthStencilState.h"
#include "Dx11RasterizerState.h"
#include "Dx11TypedBuffer.h"
#include "Dx11StructuredBuffer.h"
#include "Dx11Primitive.h"
#include "Dx11Program.h"
#include "Dx11ScissorRect.h"
#include "Dx11.h"
#include <gfx/Dx/DxGi.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::diag;
using namespace synkro::img;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::math;
using namespace synkro::win;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Dx11GraphicsDevice::Dx11GraphicsDevice( IDXGIFactory1* factory, IDXGIAdapter1* adapter, GraphicsDeviceDesc& desc, ILog* log ) :
	GraphicsDeviceImpl<IGraphicsDevice>( desc, log ),
	_level( D3D_FEATURE_LEVEL_11_0 ),
	_factory( factory )
{
	HRESULT hr = S_OK;
	UINT flags = 0;

#ifdef SYNKRO_DEBUG
	flags |= D3D11_CREATE_DEVICE_DEBUG;
#endif // SYNKRO_DEBUG

	// Create device.
	hr = S_OK;
	if ( (Dx11::CreateDevice == nullptr) || FAILED(hr = Dx11::CreateDevice(adapter, Dx11::Convert(desc.Type), (HMODULE)nullptr, flags, nullptr, 0, D3D11_SDK_VERSION, &_device, &_level, &_context)) )
		throw GraphicsException( Str::GraphicsDeviceFail, String::Format(Str::CallFail, L"D3D11CreateDevice()"), Dx11::ToString(hr) );

	LogInfo( MessagePriority::Normal, Formatter::Format(L"Device feature level: 0x{0,x}", _level) );

	if ( (_level != D3D_FEATURE_LEVEL_11_1) && (_level != D3D_FEATURE_LEVEL_11_0) )
		throw GraphicsException( Str::GraphicsDeviceFail, String::Format(Str::CallFail, L"D3D11CreateDevice()"), Dx11::ToString(hr) );

	// Init default states.
	_blendStates		= new Dx11BlendStateSet( this );
	_depthStencilState	= new Dx11DepthStencilState( this );
	_rasterizerState	= new Dx11RasterizerState( this );
}

IFrameRenderWindow* Dx11GraphicsDevice::CreateRenderWindow( IFrameWindow* window, const DisplayMode& displayMode, Bool vsync, UInt sampleCount, UInt sampleQuality )
{
	return new Dx11FrameRenderWindow( _factory, this, window, displayMode, vsync, sampleCount, sampleQuality );
}

IViewRenderWindow* Dx11GraphicsDevice::CreateRenderWindow( IViewWindow* window, const PixelFormat& format, Bool vsync, UInt sampleCount, UInt sampleQuality )
{
	return new Dx11ViewRenderWindow( _factory, this, window, format, vsync, sampleCount, sampleQuality );
}

IRenderTextureSet* Dx11GraphicsDevice::CreateRenderTextures( UInt size )
{
	return new Dx11RenderTextureSet( this, size );
}

ILinearRenderTexture* Dx11GraphicsDevice::CreateRenderTexture( UInt length, const PixelFormat& format )
{
	return new Dx11LinearRenderTexture( this, length, format );
}

IPlainRenderTexture* Dx11GraphicsDevice::CreateRenderTexture( UInt width, UInt height, const PixelFormat& format, UInt sampleCount, UInt sampleQuality )
{
	return new Dx11PlainRenderTexture( this, width, height, format, sampleCount, sampleQuality );
}

ICubeRenderTexture* Dx11GraphicsDevice::CreateRenderTexture( UInt length, const PixelFormat& format, UInt sampleCount, UInt sampleQuality )
{
	return new Dx11CubeRenderTexture( this, length, format, sampleCount, sampleQuality );
}

IVolumeRenderTexture* Dx11GraphicsDevice::CreateRenderTexture( UInt width, UInt height, UInt depth, const PixelFormat& format )
{
	return new Dx11VolumeRenderTexture( this, width, height, depth, format );
}

IPlainDepthTexture* Dx11GraphicsDevice::CreateDepthTexture( UInt width, UInt height, const PixelFormat& colorFormat, const DepthFormat& format, Bool stencil, UInt sampleCount, UInt sampleQuality )
{
	return new Dx11PlainDepthTexture( this, width, height, format, stencil, sampleCount, sampleQuality );
}

ICubeDepthTexture* Dx11GraphicsDevice::CreateDepthTexture( UInt length, const PixelFormat& colorFormat, const DepthFormat& format, Bool stencil, UInt sampleCount, UInt sampleQuality )
{
	return new Dx11CubeDepthTexture( this, length, format, stencil, sampleCount, sampleQuality );
}

ILinearTexture* Dx11GraphicsDevice::CreateTexture( const DataUsage& usage, UInt length, const PixelFormat& format, UInt levelCount, UInt elementCount )
{
	return new Dx11LinearTexture( this, usage, length, format, levelCount, elementCount );
}

IPlainTexture* Dx11GraphicsDevice::CreateTexture( const DataUsage& usage, UInt width, UInt height, const PixelFormat& format, UInt levelCount, UInt elementCount )
{
	return new Dx11PlainTexture( this, usage, width, height, format, levelCount, elementCount );
}

ICubeTexture* Dx11GraphicsDevice::CreateTexture( const DataUsage& usage, UInt length, const PixelFormat& format, UInt levelCount )
{
	return new Dx11CubeTexture( this, usage, length, format, levelCount );
}

IVolumeTexture* Dx11GraphicsDevice::CreateTexture( const DataUsage& usage, UInt width, UInt height, UInt depth, const PixelFormat& format, UInt levelCount )
{
	return new Dx11VolumeTexture( this, usage, width, height, depth, format, levelCount );
}

ITypedBuffer* Dx11GraphicsDevice::CreateTypedBuffer( const DataUsage& usage, const ProgramDataType& dataType, UInt count )
{
	return new Dx11TypedBuffer( this, usage, dataType, count );
}

IStructuredBuffer* Dx11GraphicsDevice::CreateStructuredBuffer( const DataUsage& usage, UInt stride, UInt count )
{
	return new Dx11StructuredBuffer( this, usage, stride, count );
}

IPrimitive* Dx11GraphicsDevice::CreatePrimitive( IProgram* program, const DataUsage& usage, const DataAccess& access, const PrimitiveType& type, const IndexType& indexType, UInt vertexCount, UInt indexCount, UInt instanceCount, UInt pointCount, Bool interleaved, Bool adjacency )
{
	return new Dx11Primitive( this, program, usage, access, type, indexType, vertexCount, indexCount, instanceCount, pointCount, interleaved, adjacency );
}

IProgram* Dx11GraphicsDevice::CreateProgram( IProgram* parent, IDataFormat* inputFormat, IDataFormat* outputFormat, io::IStream* vertexProgram, io::IStream* hullProgram, io::IStream* domainProgram, io::IStream* geometryProgram, io::IStream* pixelProgram )
{
	if ( (_programDir == nullptr) && (vertexProgram->GetDirectory()->GetStream(L"scene.vsh") != nullptr) )
	{
		_programDir = vertexProgram->GetDirectory();
	}
	return new Dx11Program( this, parent, inputFormat, outputFormat, vertexProgram, hullProgram, domainProgram, geometryProgram, pixelProgram );
}

IRect* Dx11GraphicsDevice::CreateScissorRect( Int left, Int top, Int right, Int bottom )
{
	return new Dx11ScissorRect( this, left, top, right, bottom );
}

Bool Dx11GraphicsDevice::IsSupported( const PixelFormat& format ) const
{
	UINT support;
	_device->CheckFormatSupport( DxGi::Convert(format), &support );
	UINT flags = D3D11_FORMAT_SUPPORT_TEXTURE1D | D3D11_FORMAT_SUPPORT_TEXTURE2D | D3D11_FORMAT_SUPPORT_TEXTURE3D | D3D11_FORMAT_SUPPORT_TEXTURECUBE;
	return (support & flags) != 0;
}


} // gfx


} // synkro
