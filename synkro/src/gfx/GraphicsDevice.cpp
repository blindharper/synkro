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
#include "config.h"
#include "GraphicsDevice.h"
#include "GraphicsSystemEx.h"
#include "BlendStateSet.h"
#include "DepthStencilState.h"
#include "RasterizerState.h"


//------------------------------------------------------------------------------

using namespace synkro::diag;
using namespace synkro::img;
using namespace synkro::lang;
using namespace synkro::win;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


GraphicsDevice::GraphicsDevice( GraphicsSystemEx* graphicsSystem, IWindowSystemEx* windowSystem, IGraphicsDevice* device, UInt index, ILog* log ) :
	_formats( A(FormatEntry) ),
	_programs( A(ProgramEntry) ),
	_frameWindows( A(P(FrameRenderWindow)) ),
	_viewWindows( A(P(ViewRenderWindow)) ),
	_graphicsSystem( graphicsSystem ),
	_windowSystem( windowSystem ),
	_device( device ),
	_depthFormat( DepthFormat::Unknown ),
	_index( index ),
	Logger( log, LogFacility::GraphicsSystem )
{
	// Get default states.
	_blendStates = new BlendStateSet( _device->GetBlendStates() );
	_depthStencilState = new DepthStencilState( _device->GetDepthStencilState() );
	_rasterizerState = new RasterizerState( _device->GetRasterizerState() );

	// Dump device capabilities.
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Dumping graphics device capabilities...") );
	GraphicsDeviceDesc desc; _device->GetDesc( desc );
	DumpCapability( L"Geometry Stage", desc.GeometryStage );
	DumpCapability( L"Tesselation", desc.Tesselation );
	DumpCapability( L"Output Buffers", desc.OutputBuffer );
	DumpCapability( L"Render Target Count", desc.RenderTargetCount );
}

IFrameRenderWindow* GraphicsDevice::CreateRenderWindow( IFrameWindow* window, const DisplayMode& displayMode, Bool vsync, UInt sampleCount, UInt sampleQuality )
{
	for ( UInt i = 0; i < _frameWindows.Size(); ++i )
	{
		if ( _frameWindows[i]->GetWindow() == window )
			return _frameWindows[i];
	}

	IFrameRenderWindow* wnd = _device->CreateRenderWindow( window, displayMode, vsync, sampleCount, sampleQuality );
	FrameRenderWindow* frameWindow = new FrameRenderWindow( this, wnd, GetProgram(L"screen"), GetProgram(L"view"), sampleCount, _log );
	_frameWindows.Add( frameWindow );
	return frameWindow;
}

IViewRenderWindow* GraphicsDevice::CreateRenderWindow( IViewWindow* window, const PixelFormat& format, Bool vsync, UInt sampleCount, UInt sampleQuality )
{
	for ( UInt i = 0; i < _viewWindows.Size(); ++i )
	{
		if ( _viewWindows[i]->GetWindow() == window )
			return _viewWindows[i];
	}

	IViewRenderWindow* wnd = _device->CreateRenderWindow( window, format, vsync, sampleCount, sampleQuality );
	ViewRenderWindow* viewWindow = new ViewRenderWindow( this, wnd, GetProgram(L"screen"), GetProgram(L"view"), sampleCount );
	_viewWindows.Add( viewWindow );
	return viewWindow;
}

IRenderTextureSet* GraphicsDevice::CreateRenderTextures( UInt size )
{
	return _device->CreateRenderTextures( size );
}

ILinearRenderTexture* GraphicsDevice::CreateRenderTexture( UInt length, const PixelFormat& format )
{
	return new LinearRenderTexture( _device->CreateRenderTexture(length, format) );
}

IPlainRenderTexture* GraphicsDevice::CreateRenderTexture( UInt width, UInt height, const PixelFormat& format, UInt sampleCount, UInt sampleQuality )
{
	return new PlainRenderTexture( _device->CreateRenderTexture(width, height, format, sampleCount, sampleQuality) );
}

ICubeRenderTexture* GraphicsDevice::CreateRenderTexture( UInt length, const PixelFormat& format, UInt sampleCount, UInt sampleQuality )
{
	return new CubeRenderTexture( _device->CreateRenderTexture(length, format, sampleCount, sampleQuality) );
}

IVolumeRenderTexture* GraphicsDevice::CreateRenderTexture( UInt width, UInt height, UInt depth, const PixelFormat& format )
{
	return new VolumeRenderTexture( _device->CreateRenderTexture(width, height, depth, format) );
}

IPlainDepthTexture* GraphicsDevice::CreateDepthTexture( UInt width, UInt height, const PixelFormat& colorFormat, const DepthFormat& depthFormat, Bool stencil, UInt sampleCount, UInt sampleQuality )
{
	IPlainDepthTexture* texture = _device->CreateDepthTexture( width, height, colorFormat, depthFormat, stencil, sampleCount, sampleQuality );
	if ( texture != nullptr )
	{
		return new PlainDepthTexture( texture );
	}
	return nullptr;
}

ICubeDepthTexture* GraphicsDevice::CreateDepthTexture( UInt length, const PixelFormat& colorFormat, const DepthFormat& depthFormat, Bool stencil, UInt sampleCount, UInt sampleQuality )
{
	ICubeDepthTexture* texture = _device->CreateDepthTexture( length, colorFormat, depthFormat, stencil, sampleCount, sampleQuality );
	if ( texture != nullptr )
	{
		return new CubeDepthTexture( texture );
	}
	return nullptr;
}

ILinearTexture* GraphicsDevice::CreateTexture( const DataUsage& usage, UInt length, const PixelFormat& format, UInt levelCount, UInt elementCount )
{
	SynkroCall( "GraphicsDevice::CreateTexture", String::Format(L"length = {0}, format = {1}, levelCount = {2}, elementCount = {3}", length, format.ToString(), levelCount, elementCount) );

	return IsSupported(format) ? new LinearTexture( _device->CreateTexture(usage, length, format, levelCount, elementCount) ) : nullptr;
}

IPlainTexture* GraphicsDevice::CreateTexture( const DataUsage& usage, UInt width, UInt height, const PixelFormat& format, UInt levelCount, UInt elementCount )
{
	SynkroCall( "GraphicsDevice::CreateTexture", String::Format(L"width = {0}, height = {1}, format = {2}, levelCount = {3}, elementCount = {4}", width, height, format.ToString(), levelCount, elementCount) );

	return IsSupported(format) ? new PlainTexture( _device->CreateTexture(usage, width, height, format, levelCount, elementCount) ) : nullptr;
}

ICubeTexture* GraphicsDevice::CreateTexture( const DataUsage& usage, UInt length, const PixelFormat& format, UInt levelCount )
{
	SynkroCall( "GraphicsDevice::CreateTexture", String::Format(L"length = {0}, format = {1}, levelCount = {2}", length, format.ToString(), levelCount) );

	return IsSupported(format) ? new CubeTexture( _device->CreateTexture(usage, length, format, levelCount) ) : nullptr;
}

IVolumeTexture* GraphicsDevice::CreateTexture( const DataUsage& usage, UInt width, UInt height, UInt depth, const PixelFormat& format, UInt levelCount )
{
	SynkroCall( "GraphicsDevice::CreateTexture", String::Format(L"width = {0}, height = {1}, depth = {2}, format = {3}, levelCount = {4}", width, height, depth, format.ToString(), levelCount) );

	return IsSupported(format) ? new VolumeTexture( _device->CreateTexture(usage, width, height, depth, format, levelCount) ) : nullptr;
}

ITypedBuffer* GraphicsDevice::CreateTypedBuffer( const DataUsage& usage, const ProgramDataType& dataType, UInt count )
{
	SynkroCall( "GraphicsDevice::CreateTypedBuffer", String::Format(L"dataType = {0}, count = {1}", dataType.ToString(), count) );

	return new TypedBuffer( _device->CreateTypedBuffer(usage, dataType, count) );
}

IStructuredBuffer* GraphicsDevice::CreateStructuredBuffer( const DataUsage& usage, UInt stride, UInt count )
{
	SynkroCall( "GraphicsDevice::CreateStructuredBuffer", String::Format(L"stride = {0}, count = {1}", stride, count) );

	return new StructuredBuffer( _device->CreateStructuredBuffer(usage, stride, count) );
}

IPrimitive* GraphicsDevice::CreatePrimitive( IProgram* program, const DataUsage& usage, const DataAccess& access, const PrimitiveType& type, const IndexType& indexType, UInt vertexCount, UInt indexCount, UInt instanceCount, UInt pointCount, Bool interleaved, Bool adjacency )
{
	// If there's no hardware tesselation, treat patches as triangle lists.
	PrimitiveType primType = type;
	GraphicsDeviceDesc desc; _device->GetDesc( desc );
	if ( (primType == PrimitiveType::PatchList) && (pointCount == 3) && !desc.Tesselation )
	{
		primType = PrimitiveType::TriangleList;
		pointCount = 0;
	}
	return new Primitive( _device->CreatePrimitive( ((Program*)program)->_program, usage, access, primType, indexType, vertexCount, indexCount, instanceCount, pointCount, interleaved, adjacency), (Program*)program );
}

IProgram* GraphicsDevice::CreateProgram( IProgram* parent, IDataFormat* inputFormat, IDataFormat* outputFormat, io::IStream* vertexProgram, io::IStream* hullProgram, io::IStream* domainProgram, io::IStream* geometryProgram, io::IStream* pixelProgram )
{
	return _device->CreateProgram( parent, inputFormat, outputFormat, vertexProgram, hullProgram, domainProgram, geometryProgram, pixelProgram );
}

IRect* GraphicsDevice::CreateScissorRect( Int left, Int top, Int right, Int bottom )
{
	return new RectEx( _device->CreateScissorRect(left, top, right, bottom) );
}

void GraphicsDevice::DumpCapability( const String& name, Bool value )
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"{0}: {1}", name, value ? L"Yes" : L"No") );
}

void GraphicsDevice::DumpCapability( const String& name, UInt value )
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"{0}: {1}", name, value) );
}

IProgram* GraphicsDevice::GetProgram( const String& name ) const
{
	if ( !_programs.ContainsKey(name) )
	{
		IProgram* program = _graphicsSystem->LoadProgram( const_cast<GraphicsDevice*>(this), name );
		if ( program == nullptr )
			return nullptr;

		_programs[name] = program;
	}

	return _programs[name];
}


} // gfx


} // synkro
