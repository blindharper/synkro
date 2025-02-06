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
#ifndef _SYNKRO_GFX_DX11GRAPHICSDEVICE_
#define _SYNKRO_GFX_DX11GRAPHICSDEVICE_


#include "config.h"
#include <lang/Map.h>
#include <gfx/GraphicsDeviceImpl.h>
#undef new
#include <d3d11.h>
#include "Dx11Context.h"
#define new SYNKRO_NEW


namespace synkro
{


namespace gfx
{


// DirectX 11 rendering device implementation.
class Dx11GraphicsDevice :
	public GraphicsDeviceImpl<IGraphicsDevice>,
	public Dx11Context
{
public:
	// Constructor.
	Dx11GraphicsDevice( IDXGIFactory1* factory, IDXGIAdapter1* adapter, GraphicsDeviceDesc& desc, diag::ILog* log );

	// IGraphicsDevice methods.
	IFrameRenderWindow*										CreateRenderWindow( win::IFrameWindow* window, const DisplayMode& displayMode, Bool vsync, UInt sampleCount, UInt sampleQuality );
	IViewRenderWindow*										CreateRenderWindow( win::IViewWindow* window, const img::PixelFormat& format, Bool vsync, UInt sampleCount, UInt sampleQuality );
	IRenderTextureSet*										CreateRenderTextures( UInt size );
	ILinearRenderTexture*									CreateRenderTexture( UInt length, const img::PixelFormat& format );
	IPlainRenderTexture*									CreateRenderTexture( UInt width, UInt height, const img::PixelFormat& format, UInt sampleCount, UInt sampleQuality );
	ICubeRenderTexture*										CreateRenderTexture( UInt length, const img::PixelFormat& format, UInt sampleCount, UInt sampleQuality );
	IVolumeRenderTexture*									CreateRenderTexture( UInt width, UInt height, UInt depth, const img::PixelFormat& format );
	IPlainDepthTexture*										CreateDepthTexture( UInt width, UInt height, const img::PixelFormat& colorFormat, const DepthFormat& format, Bool stencil, UInt sampleCount, UInt sampleQuality );
	ICubeDepthTexture*										CreateDepthTexture( UInt length, const img::PixelFormat& colorFormat, const DepthFormat& format, Bool stencil, UInt sampleCount, UInt sampleQuality );
	ILinearTexture*											CreateTexture( const DataUsage& usage, UInt length, const img::PixelFormat& format, UInt levelCount, UInt elementCount );
	IPlainTexture*											CreateTexture( const DataUsage& usage, UInt width, UInt height, const img::PixelFormat& format, UInt levelCount, UInt elementCount );
	ICubeTexture*											CreateTexture( const DataUsage& usage, UInt length, const img::PixelFormat& format, UInt levelCount );
	IVolumeTexture*											CreateTexture( const DataUsage& usage, UInt width, UInt height, UInt depth, const img::PixelFormat& format, UInt levelCount );
	ITypedBuffer*											CreateTypedBuffer( const DataUsage& usage, const ProgramDataType& dataType, UInt count );
	IStructuredBuffer*										CreateStructuredBuffer( const DataUsage& usage, UInt stride, UInt count );
	IPrimitive*												CreatePrimitive( IProgram* program, const DataUsage& usage, const DataAccess& access, const PrimitiveType& type, const IndexType& indexType, UInt vertexCount, UInt indexCount, UInt instanceCount, UInt pointCount, Bool interleaved, Bool adjacency );
	IProgram*												CreateProgram( IProgram* parent, IDataFormat* inputFormat, IDataFormat* outputFormat, io::IStream* vertexProgram, io::IStream* hullProgram, io::IStream* domainProgram, io::IStream* geometryProgram, io::IStream* pixelProgram );
	IRect*													CreateScissorRect( Int left, Int top, Int right, Int bottom );
	Bool													IsSupported( const img::PixelFormat& format ) const;

private:
	friend class Dx11FrameRenderWindow;
	friend class Dx11ViewRenderWindow;
	friend class Dx11Program;

	D3D_FEATURE_LEVEL										_level;
	IDXGIFactory1*											_factory;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11GRAPHICSDEVICE_
