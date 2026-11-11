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
// Purpose: DX12 graphics device implementation.
//==============================================================================
#include "config.h"
#include "Dx12GraphicsDevice.h"
#include "Dx12.h"
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


Dx12GraphicsDevice::Dx12GraphicsDevice( /*IDXGIFactory1* factory, IDXGIAdapter1* adapter, */GraphicsDeviceDesc& desc, ILog* log) :
	GraphicsDeviceImpl<IGraphicsDevice>( desc, log ),
	_level( D3D_FEATURE_LEVEL_11_0 )/*,
	_factory( factory )*/
{
	/*HRESULT hr = S_OK;
	UINT flags = 0;

#ifdef SYNKRO_DEBUG
	flags |= D3D12_CREATE_DEVICE_DEBUG;
#endif // SYNKRO_DEBUG

	// Create device.
	hr = S_OK;
	if ( (Dx12::CreateDevice == nullptr) || FAILED(hr = Dx12::CreateDevice(adapter, Dx12::Convert(desc.Type), (HMODULE)nullptr, flags, nullptr, 0, D3D12_SDK_VERSION, &_device, &_level, &_context)) )
		throw GraphicsException( Str::GraphicsDeviceFail, String::Format(Str::CallFail, L"D3D12CreateDevice()"), Dx12::ToString(hr) );

	LogInfo( MessagePriority::Normal, Formatter::Format(L"Device feature level: 0x{0,x}", _level) );

	if ( (_level != D3D_FEATURE_LEVEL_12_1) && (_level != D3D_FEATURE_LEVEL_12_0) )
		throw GraphicsException( Str::GraphicsDeviceFail, String::Format(Str::CallFail, L"D3D12CreateDevice()"), Dx12::ToString(hr) );

	// Init default states.
	_blendStates		= new Dx12BlendStateSet( this );
	_depthStencilState	= new Dx12DepthStencilState( this );
	_rasterizerState	= new Dx12RasterizerState( this );*/
}

IFrameRenderWindow* Dx12GraphicsDevice::CreateRenderWindow( IFrameWindow* window, const DisplayMode& displayMode, Bool vsync, UInt sampleCount, UInt sampleQuality )
{
	return nullptr; // TODO: return new Dx12FrameRenderWindow( _factory, this, window, displayMode, vsync, sampleCount, sampleQuality );
}

IViewRenderWindow* Dx12GraphicsDevice::CreateRenderWindow( IViewWindow* window, const PixelFormat& format, Bool vsync, UInt sampleCount, UInt sampleQuality )
{
	return nullptr; // TODO: return new Dx12ViewRenderWindow( _factory, this, window, format, vsync, sampleCount, sampleQuality );
}

IRenderTextureSet* Dx12GraphicsDevice::CreateRenderTextures( UInt size )
{
	return nullptr; // TODO: return new Dx12RenderTextureSet( this, size );
}

ILinearRenderTexture* Dx12GraphicsDevice::CreateRenderTexture( UInt length, const PixelFormat& format )
{
	return nullptr; // TODO: return new Dx12LinearRenderTexture( this, length, format );
}

IPlainRenderTexture* Dx12GraphicsDevice::CreateRenderTexture( UInt width, UInt height, const PixelFormat& format, UInt sampleCount, UInt sampleQuality )
{
	return nullptr; // TODO: return new Dx12PlainRenderTexture( this, width, height, format, sampleCount, sampleQuality );
}

ICubeRenderTexture* Dx12GraphicsDevice::CreateRenderTexture( UInt length, const PixelFormat& format, UInt sampleCount, UInt sampleQuality )
{
	return nullptr; // TODO: return new Dx12CubeRenderTexture( this, length, format, sampleCount, sampleQuality );
}

IVolumeRenderTexture* Dx12GraphicsDevice::CreateRenderTexture( UInt width, UInt height, UInt depth, const PixelFormat& format )
{
	return nullptr; // TODO: return new Dx12VolumeRenderTexture( this, width, height, depth, format );
}

IPlainDepthTexture* Dx12GraphicsDevice::CreateDepthTexture( UInt width, UInt height, const PixelFormat& colorFormat, const DepthFormat& format, Bool stencil, UInt sampleCount, UInt sampleQuality )
{
	return nullptr; // TODO: return new Dx12PlainDepthTexture( this, width, height, format, stencil, sampleCount, sampleQuality );
}

ICubeDepthTexture* Dx12GraphicsDevice::CreateDepthTexture( UInt length, const PixelFormat& colorFormat, const DepthFormat& format, Bool stencil, UInt sampleCount, UInt sampleQuality )
{
	return nullptr; // TODO: return new Dx12CubeDepthTexture( this, length, format, stencil, sampleCount, sampleQuality );
}

ILinearTexture* Dx12GraphicsDevice::CreateTexture( const DataUsage& usage, UInt length, const PixelFormat& format, UInt levelCount, UInt elementCount )
{
	return nullptr; // TODO: return new Dx12LinearTexture( this, usage, length, format, levelCount, elementCount );
}

IPlainTexture* Dx12GraphicsDevice::CreateTexture( const DataUsage& usage, UInt width, UInt height, const PixelFormat& format, UInt levelCount, UInt elementCount )
{
	return nullptr; // TODO: return new Dx12PlainTexture( this, usage, width, height, format, levelCount, elementCount );
}

ICubeTexture* Dx12GraphicsDevice::CreateTexture( const DataUsage& usage, UInt length, const PixelFormat& format, UInt levelCount )
{
	return nullptr; // TODO: return new Dx12CubeTexture( this, usage, length, format, levelCount );
}

IVolumeTexture* Dx12GraphicsDevice::CreateTexture( const DataUsage& usage, UInt width, UInt height, UInt depth, const PixelFormat& format, UInt levelCount )
{
	return nullptr; // TODO: return new Dx12VolumeTexture( this, usage, width, height, depth, format, levelCount );
}

ITypedBuffer* Dx12GraphicsDevice::CreateTypedBuffer( const DataUsage& usage, const ProgramDataType& dataType, UInt count )
{
	return nullptr; // TODO: return new Dx12TypedBuffer( this, usage, dataType, count );
}

IStructuredBuffer* Dx12GraphicsDevice::CreateStructuredBuffer( const DataUsage& usage, UInt stride, UInt count )
{
	return nullptr; // TODO: return new Dx12StructuredBuffer( this, usage, stride, count );
}

IPrimitive* Dx12GraphicsDevice::CreatePrimitive( IProgram* program, const DataUsage& usage, const DataAccess& access, const PrimitiveType& type, const IndexType& indexType, UInt vertexCount, UInt indexCount, UInt instanceCount, UInt pointCount, Bool interleaved, Bool adjacency )
{
	return nullptr; // TODO: return new Dx12Primitive( this, program, usage, access, type, indexType, vertexCount, indexCount, instanceCount, pointCount, interleaved, adjacency );
}

IProgram* Dx12GraphicsDevice::CreateProgram( IProgram* parent, IDataFormat* inputFormat, IDataFormat* outputFormat, io::IStream* vertexProgram, io::IStream* hullProgram, io::IStream* domainProgram, io::IStream* geometryProgram, io::IStream* pixelProgram )
{
	/*if ( (_programDir==nullptr)&&(vertexProgram->GetDirectory()->GetStream(L"scene.vsh")!=nullptr) )
	{
		_programDir = vertexProgram->GetDirectory();
	}*/
	return nullptr; // TODO: return new Dx12Program( this, parent, inputFormat, outputFormat, vertexProgram, hullProgram, domainProgram, geometryProgram, pixelProgram );
}

IRect* Dx12GraphicsDevice::CreateScissorRect( Int left, Int top, Int right, Int bottom )
{
	return nullptr; // TODO: return new Dx12ScissorRect( this, left, top, right, bottom );
}

Bool Dx12GraphicsDevice::IsSupported( const PixelFormat& format ) const
{
	/*UINT support;
	_device->CheckFormatSupport( DxGi::Convert(format), &support );
	UINT flags = D3D12_FORMAT_SUPPORT_TEXTURE1D | D3D12_FORMAT_SUPPORT_TEXTURE2D | D3D12_FORMAT_SUPPORT_TEXTURE3D | D3D12_FORMAT_SUPPORT_TEXTURECUBE;
	return (support & flags) != 0;*/
	return true;
}


} // gfx


} // synkro
