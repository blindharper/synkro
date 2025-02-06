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
// Purpose: Logical graphics device.
//==============================================================================
#ifndef _SYNKRO_GFX_GRAPHICSDEVICE_
#define _SYNKRO_GFX_GRAPHICSDEVICE_


#include "config.h"
#include "Classes.h"
#include <gfx/IGraphicsDeviceEx.h>
#include <gfx/IBlendState.h>
#include <gfx/IDepthStencilState.h>
#include <gfx/IRasterizerState.h>
#include <win/IViewWindow.h>
#include <lang/Map.h>
#include <core/CallStack.h>
#include "Program.h"
#include "RenderView.h"
#include "DataFormat.h"
#include "Primitive.h"
#include "TypedBuffer.h"
#include "StructuredBuffer.h"
#include "LinearTexture.h"
#include "PlainTexture.h"
#include "CubeTexture.h"
#include "VolumeTexture.h"
#include "CubeDepthTexture.h"
#include "PlainDepthTexture.h"
#include "LinearRenderTexture.h"
#include "PlainRenderTexture.h"
#include "CubeRenderTexture.h"
#include "VolumeRenderTexture.h"
#include "FrameRenderWindow.h"
#include "ViewRenderWindow.h"


namespace synkro
{


namespace gfx
{


// Logical graphics device.
class GraphicsDevice :
	public core::ObjectImpl<IGraphicsDeviceEx>,
	public Logger
{
public:
	// Constructor.
	GraphicsDevice( GraphicsSystemEx* graphicsSystem, win::IWindowSystemEx* windowSystem, IGraphicsDevice* device, UInt index, diag::ILog* log );

	// IGraphicsDevice methods.
	IFrameRenderWindow*										CreateRenderWindow( win::IFrameWindow* window, const DisplayMode& displayMode, Bool vsync, UInt sampleCount, UInt sampleQuality );
	IViewRenderWindow*										CreateRenderWindow( win::IViewWindow* window, const img::PixelFormat& format, Bool vsync, UInt sampleCount, UInt sampleQuality );
	IRenderTextureSet*										CreateRenderTextures( UInt size );
	ILinearRenderTexture*									CreateRenderTexture( UInt length, const img::PixelFormat& format );
	IPlainRenderTexture*									CreateRenderTexture( UInt width, UInt height, const img::PixelFormat& format, UInt sampleCount, UInt sampleQuality );
	ICubeRenderTexture*										CreateRenderTexture( UInt length, const img::PixelFormat& format, UInt sampleCount, UInt sampleQuality );
	IVolumeRenderTexture*									CreateRenderTexture( UInt width, UInt height, UInt depth, const img::PixelFormat& format );
	IPlainDepthTexture*										CreateDepthTexture( UInt width, UInt height, const img::PixelFormat& colorFormat, const DepthFormat& depthFormat, Bool stencil, UInt sampleCount, UInt sampleQuality );
	ICubeDepthTexture*										CreateDepthTexture( UInt length, const img::PixelFormat& colorFormat, const DepthFormat& depthFormat, Bool stencil, UInt sampleCount, UInt sampleQuality );
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
	IBlendStateSet*											GetBlendStates() const;
	IDepthStencilState*										GetDepthStencilState() const;
	IRasterizerState*										GetRasterizerState() const;
	void													GetDesc( GraphicsDeviceDesc& desc ) const;

	// IGraphicsDeviceEx methods.
	IProgram*												GetProgram( const lang::String& name ) const;

	// Other methods.
	void													SetDepthFormat( const DepthFormat& depthFormat );
	DepthFormat												GetDepthFormat() const;
	UInt													GetIndex() const;

private:
	friend class GraphicsSystemEx;

	typedef lang::MapPair<img::PixelFormat, Bool>			FormatEntry;
	typedef lang::MapPair<lang::String, P(IProgram)>		ProgramEntry;

	mutable lang::Map<img::PixelFormat, Bool>				_formats;
	lang::Vector<P(FrameRenderWindow)>						_frameWindows;
	lang::Vector<P(ViewRenderWindow)>						_viewWindows;
	GraphicsSystemEx*										_graphicsSystem;
	win::IWindowSystemEx*									_windowSystem;
	P(IGraphicsDevice)										_device;
	P(IBlendStateSet)										_blendStates;
	P(IDepthStencilState)									_depthStencilState;
	P(IRasterizerState)										_rasterizerState;
	mutable lang::MapCI<lang::String, P(IProgram)>			_programs;
	DepthFormat												_depthFormat;
	UInt													_index;

	void													DumpCapability( const lang::String& name, Bool value );
	void													DumpCapability( const lang::String& name, UInt value );
};


#include "GraphicsDevice.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_GRAPHICSDEVICE_
