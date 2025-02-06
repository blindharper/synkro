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
// Purpose: Extended graphics system.
//=============================================================================
#include "config.h"
#include "GraphicsSystemEx.h"
#include "SceneRenderQueue.h"
#include "OverlayRenderQueue.h"
#include "OverlayRenderMap.h"
#include "CubeRenderMap.h"
#include "PlainRenderMap.h"
#include "DataFormat.h"
#include "SamplerStateSet.h"
#include "SamplerState.h"
#include <gfx/IGraphicsSystemFactory.h>
#include <gfx/ProgramStageType.h>
#include <internal/SafeClose.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::diag;
using namespace synkro::img;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::win;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


GraphicsSystemEx::GraphicsSystemEx( ILog* log ) :
	_devices( A(P(GraphicsDevice)) ),
	_formats( A(FormatEntry) ),
	_types( A(TypeEntry) ),
	_programs( A(ProgramEntry) ),
	_maps( A(BaseRenderMap*) ),
	_virtualWindows( A(P(VirtualRenderWindow)) ),
	_windowSystem( nullptr ),
	_factory( nullptr ),
	_device( nullptr ),
	Logger( log, LogFacility::GraphicsSystem )
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Creating graphics system...") );

	RegisterDataType( L"Bool", ProgramDataType::Bool );
	RegisterDataType( L"Int", ProgramDataType::Int );
	RegisterDataType( L"Float", ProgramDataType::Float );
	RegisterDataType( L"Vector2", ProgramDataType::Vector2 );
	RegisterDataType( L"Vector3", ProgramDataType::Vector3 );
	RegisterDataType( L"Vector4", ProgramDataType::Vector4 );
	RegisterDataType( L"Matrix3x3", ProgramDataType::Matrix3x3 );
	RegisterDataType( L"Matrix4x4", ProgramDataType::Matrix4x4 );
	RegisterDataType( L"Matrix4x4Transposed", ProgramDataType::Matrix4x4Transposed );
}

GraphicsSystemEx::~GraphicsSystemEx()
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Destroying graphics system...") );
}

Bool GraphicsSystemEx::Update( Double delta )
{
	SynkroProfile( "GraphicsSystemEx.Update" );

	// Reset rendering statistics.
	_stats.ObjectCount = 0;
	_stats.PrimitiveCount = 0;
	_stats.StateChangeCount = 0;

	// Draw maps.
	for ( UInt i = 0; i < _maps.Size(); ++i )
	{
		_maps[i]->Draw();
	}

	// Draw virtual windows.
	for ( UInt i = 0; i < _virtualWindows.Size(); ++i )
	{
		VirtualRenderWindow* window = _virtualWindows[i];
		Draw( window, window, nullptr, delta, _stats );
	}

	// Draw frame windows.
	for ( UInt i = 0; i < _device->_frameWindows.Size(); ++i )
	{
		FrameRenderWindow* window = _device->_frameWindows[i];
		Draw( window, window, window->GetTarget(), delta, _stats );
	}

	// Draw view windows.
	for ( UInt i = 0; i < _device->_viewWindows.Size(); ++i )
	{
		ViewRenderWindow* window = _device->_viewWindows[i];
		Draw( window, window, nullptr, delta, _stats );
	}

	return true;
}

IGraphicsDevice* GraphicsSystemEx::CreateDevice( UInt index )
{
	assert( index < _graphicsSystem->GetTotalDeviceCount() );

	if ( index >= _graphicsSystem->GetTotalDeviceCount() )
		throw OutOfRangeException( index, _graphicsSystem->GetTotalDeviceCount() );

	for ( UInt i = 0; _devices.Size(); ++i )
	{
		if ( _devices[i]->GetIndex() == index )
			return _devices[i];
	}

	GraphicsDevice* device = new GraphicsDevice( this, _windowSystem, _graphicsSystem->CreateDevice(index), index, _log );
	_devices.Add( device );

	GraphicsDeviceDesc desc;
	device->GetDesc( desc );
	LogInfo( MessagePriority::Normal, Formatter::Format(L"Created graphics device {0,q}", desc.Name) );

	return device;
}

IDataFormatEx* GraphicsSystemEx::CreateDataFormat()
{
	return new DataFormat();
}

IOverlayRenderQueue* GraphicsSystemEx::CreateRenderQueue( UInt width, UInt height )
{
	return new OverlayRenderQueue( this->GetDevice(), width, height );
}

ISceneRenderQueue* GraphicsSystemEx::CreateRenderQueue()
{
	return new SceneRenderQueue( this );
}

IPlainRenderMap* GraphicsSystemEx::CreateRenderMap( IOverlayRenderQueue* queue, IPlainRenderTexture* target )
{
	assert( queue != nullptr );
	assert( target != nullptr );

	if ( queue == nullptr )
		throw BadArgumentException( L"Bad Argument", L"queue", L"nullptr" );

	if ( target == nullptr )
		throw BadArgumentException( L"Bad Argument", L"target", L"nullptr" );

	OverlayRenderMap* map = new OverlayRenderMap( queue, target );
	_maps.Add( map );
	return map;
}

IPlainRenderMap* GraphicsSystemEx::CreateRenderMap( ISceneRenderQueue* queue, IPlainRenderTexture* colorTarget, IPlainDepthTexture* depthTarget )
{
	assert( queue != nullptr );
	assert( colorTarget != nullptr );
	assert( depthTarget != nullptr );

	if ( queue == nullptr )
		throw BadArgumentException( L"Bad Argument", L"queue", L"nullptr" );

	if ( colorTarget == nullptr )
		throw BadArgumentException( L"Bad Argument", L"colorTarget", L"nullptr" );

	if ( depthTarget == nullptr )
		throw BadArgumentException( L"Bad Argument", L"depthTarget", L"nullptr" );

	PlainRenderMap* map = new PlainRenderMap( queue, colorTarget, depthTarget );
	_maps.Add( map );
	return map;
}

ICubeRenderMap* GraphicsSystemEx::CreateRenderMap( ISceneRenderQueue* queue, ICubeRenderTexture* colorTarget, ICubeDepthTexture* depthTarget )
{
	assert( queue != nullptr );
	assert( colorTarget != nullptr );
	assert( depthTarget != nullptr );

	if ( queue == nullptr )
		throw BadArgumentException( L"Bad Argument", L"queue", L"nullptr" );

	if ( colorTarget == nullptr )
		throw BadArgumentException( L"Bad Argument", L"colorTarget", L"nullptr" );

	if ( depthTarget == nullptr )
		throw BadArgumentException( L"Bad Argument", L"depthTarget", L"nullptr" );

	GraphicsDeviceDesc desc;
	_device->GetDesc( desc );
	CubeRenderMap* map = new CubeRenderMap( queue, colorTarget, depthTarget, desc.GeometryStage );
	_maps.Add( map );
	return map;
}

IVirtualRenderWindow* GraphicsSystemEx::CreateRenderWindow( UInt width, UInt height, const PixelFormat& format, UInt sampleCount, UInt sampleQuality )
{
	VirtualRenderWindow* window = new VirtualRenderWindow( _device, width, height, format, GetProgram(L"screen"), GetProgram(L"view"), sampleCount, sampleQuality );
	_virtualWindows.Add( window );
	return window;
}

void GraphicsSystemEx::Initialize( IGraphicsSystemFactory* factory, const GraphicsDeviceType& type, IWindowSystemEx* windowSystem )
{
	SynkroProfile( "GraphicsSystemEx.Initialize" );

	_windowSystem = windowSystem;

	// Dump display modes.
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Dumping display modes...") );
	for ( UInt i = 0; i < DisplayMode::GetModeCount(); ++i )
	{
		DisplayMode mode; DisplayMode::GetMode( i, mode );
		LogInfo( MessagePriority::Lowest, Formatter::Format(L"#{0}: {1}", i+1, mode.ToString(DisplayModeFormat::Aspect)) );
	}

	// Re-create graphics system, if needed.
	if ( factory != _factory )
	{
		_factory = factory;
		_graphicsSystem = nullptr;
		_graphicsSystem = factory->Create( windowSystem, _log );
	}                                                             
	
	// Find and initialize appropriate device.
	GraphicsDeviceDesc desc;
	for ( UInt i = 0; i < _graphicsSystem->GetTotalDeviceCount(); ++i )
	{
		_graphicsSystem->GetDeviceDesc( i, desc );
		const Bool found = ((type != GraphicsDeviceType::Unknown) && (desc.Type == type)) ||
						   ((type == GraphicsDeviceType::Unknown) && (desc.Type == GraphicsDeviceType::Hardware));
		if ( found )
		{
			_device = (GraphicsDevice*)CreateDevice( i );
			break;
		}
	}
}

void GraphicsSystemEx::Finalize()
{
	_virtualWindows.Clear();
	_maps.Clear();
	_programs.Clear();
	_formats.Clear();
	_devices.Clear();
}

void GraphicsSystemEx::RegisterDataType( const String& name, const ProgramDataType& type )
{
	_types[name] = type;
}

void GraphicsSystemEx::Init( const DepthFormat& depthFormat, const DisplayMode& displayMode, Bool vsync, UInt sampleCount )
{
	SynkroProfile( "GraphicsSystemEx.Init" );

	// Set depth buffer format for rendering windows.
	_device->SetDepthFormat( depthFormat );

	// Create rendering windows for all existing physical windows.
	for ( UInt i = 0; i < _windowSystem->GetFrameWindowCount(); ++i )
	{
		IFrameWindowEx* window = _windowSystem->GetFrameWindow( i );
		if ( window->IsRenderable() )
		{
			_device->CreateRenderWindow( window, displayMode, vsync, sampleCount, 0 );
		}
		else
		{
			for ( UInt j = 0; j < window->GetWindowCount(); ++j )
			{
				_device->CreateRenderWindow( window->GetWindow(j), PixelFormat::R8G8B8A8, vsync, sampleCount, 0 );
			}
		}
	}
}

void GraphicsSystemEx::AddProgramLibrary( IStreamDirectory* dir, const String& system )
{
	SynkroCall( "GraphicsSystemEx.AddProgramLibrary", system );

	SynkroProfile( "GraphicsSystemEx.AddProgramLibrary" );

	// Read program definition.
	GraphicsDeviceDesc desc; _device->GetDesc( desc );
	ProgramReader rd( dir, system );
	while ( rd.Read() )
	{
		SynkroProfile( "GraphicsSystemEx.AddProgramLibrary.0" );

		String programName = rd.GetName();
		if ( !_programs.ContainsKey(programName) )
		{
			LogInfo( MessagePriority::Lowest, Formatter::Format(L"Registering program '{0}'...", programName) );
			FormatDesc* formatDesc = rd.GetInputFormat();
			IDataFormat* inputFormat = AssembleDataFormat( formatDesc );
			formatDesc = rd.GetOutputFormat();
			IDataFormat* outputFormat = (formatDesc != nullptr) ? AssembleDataFormat( formatDesc ) : nullptr;
			ProgramDesc desc( rd.GetParent(), rd.GetVertexCodePath(), rd.GetHullCodePath(), rd.GetDomainCodePath(), rd.GetGeometryCodePath(), rd.GetFragmentCodePath(), dir, inputFormat, outputFormat );
			for ( UInt i = 0; i < rd.GetCapabilityCount(); ++i )
			{
				DeviceCapability cap( rd.GetCapabilityName(i), rd.GetCapabilityValue(i) );
				desc.Caps.Add( cap );
			}
			_programs[programName] = desc;
		}
	}
}

IProgram* GraphicsSystemEx::LoadProgram( GraphicsDevice* device, const String& name )
{
	SynkroCall( "GraphicsSystemEx.LoadProgram", name );

	SynkroProfile( "GraphicsSystemEx.LoadProgram" );

	if ( !_programs.ContainsKey(name) )
		return nullptr;

	LogInfo( MessagePriority::Low, Formatter::Format(L"Loading program '{0}'...", name) );

	// Verify device capabilities.
	GraphicsDeviceDesc caps;
	device->GetDesc( caps );
	ProgramDesc& desc = _programs[name];
	for ( UInt i = 0; i < desc.Caps.Size(); ++i )
	{
		UInt value = 0;
		DeviceCapability& cap = desc.Caps[i];
			 if ( cap.Name.EqualsTo(L"Tesselation") ) { value = CastUInt(caps.Tesselation); }
		else if ( cap.Name.EqualsTo(L"GeometryStage") ) { value = CastUInt(caps.GeometryStage); }
		else if ( cap.Name.EqualsTo(L"OutputBuffer") ) { value = CastUInt(caps.OutputBuffer); }
		else if ( cap.Name.EqualsTo(L"RenderTargetCount") ) { value = caps.RenderTargetCount; }
		else continue;
	
		// Make sure capability value is big enough.
		if ( value < cap.Value )
			return nullptr;
	}

	// Retrieve parent program.
	Program* parent = nullptr;
	if ( _programs.ContainsKey(desc.ParentName) )
	{
		parent = (Program*)this->GetProgram( desc.ParentName );
	}

	// Load compiled program from cache, if possible.
	IStreamDirectory* cache = (_programCache != nullptr) ? _programCache : desc.Resource;
	IStream* vertexProgram = LoadStream( desc.PathVertex, cache, desc.Resource );
	IStream* hullProgram = LoadStream( desc.PathHull, cache, desc.Resource );
	IStream* domainProgram = LoadStream( desc.PathDomain, cache, desc.Resource );
	IStream* geometryProgram = LoadStream( desc.PathGeometry, cache, desc.Resource );
	IStream* pixelProgram = LoadStream( desc.PathPixel, cache, desc.Resource );

	// Create program.
	IProgram* parentProgram = (parent != nullptr) ? parent->_program : nullptr;
	IProgram* program = device->CreateProgram( parentProgram, desc.InputFormat, desc.OutputFormat, vertexProgram, hullProgram, domainProgram, geometryProgram, pixelProgram );

	// Update cache with compiled version of the program, if it does not exist yet.
	if ( _programCache != nullptr )
	{
		DumpProgram( program, desc );
	}

	return new Program( program, parent );
}

void GraphicsSystemEx::DumpProgram( IProgram* program, const ProgramDesc& desc )
{
	SynkroCall( "GraphicsSystemEx.DumpProgram", String::Format(L"vertex = {0}, pixel = {1}", desc.PathVertex, desc.PathPixel) );

	IStream* vertexProgram = GetCacheStream( desc.PathVertex );
	IStream* hullProgram = GetCacheStream( desc.PathHull );
	IStream* domainProgram = GetCacheStream( desc.PathDomain );
	IStream* geometryProgram = GetCacheStream( desc.PathGeometry );
	IStream* pixelProgram = GetCacheStream( desc.PathPixel );
	program->Save( vertexProgram, hullProgram, domainProgram, geometryProgram, pixelProgram );
	SafeClose( vertexProgram );
	SafeClose( hullProgram );
	SafeClose( domainProgram );
	SafeClose( geometryProgram );
	SafeClose( pixelProgram );
}

IStream* GraphicsSystemEx::GetCacheStream( const String& name )
{
	IStream* stream = nullptr;
	if ( !name.IsEmpty() )
	{
		stream = _programCache->GetStream( name );
		stream = (stream == nullptr) ? _programCache->CreateStream( name ) : nullptr;
		if ( stream != nullptr )
		{
			stream->Open( OpenMode::Write );
		}
	}
	return stream;
}

IStream* GraphicsSystemEx::LoadStream( const String& name, IStreamDirectory* dir1, IStreamDirectory* dir2 )
{
	IStream* stream = dir1->GetStream( name );
	if ( (stream == nullptr) && (dir2 != dir1) )
	{
		stream = dir2->GetStream( name );
	}
	return stream;
}

IDataFormat* GraphicsSystemEx::AssembleDataFormat( const FormatDesc* format )
{
	// Assemble data format signature.
	AssembleSignature asmSign;
	format->VertexStreams.Each( asmSign );
	format->InstanceStreams.Each( asmSign );

	// Assemble data format, if needed.
	String sign = asmSign.Signature();
	if ( !_formats.ContainsKey(sign) )
	{
		IDataFormatEx* fmt = new DataFormat();
		format->VertexStreams.Each( AssembleFormat(this, fmt, true) );
		format->InstanceStreams.Each( AssembleFormat(this, fmt, false) );
		_formats[sign] = fmt;
	}

	return _formats[sign];
}

ProgramDataType GraphicsSystemEx::Convert( const String& type )
{
	return _types.ContainsKey(type) ? _types[type] : ProgramDataType::Unknown;
}

Bool GraphicsSystemEx::Draw( BaseRenderWindow* targetWindow, IRenderWindow* window, IPlainRenderTexture* target, Double delta, GraphicsStats& stats )
{
	SynkroProfile( "GraphicsSystemEx.Draw" );

	// Draw views to their internal targets.
	targetWindow->Draw( delta, stats );

	if ( target != nullptr )
	{
		IPlainRenderTexture* target0 = targetWindow->GetIntermediateTarget();
		if ( target0 != nullptr )
		{
			// Draw to one more intermediate target to prevent passed target flipping.
			if ( !target0->Bind() )
				return false;

			targetWindow->DrawLast();

			if ( !target0->Present() )
				return false;
		}

		// Bind intermediate target.
		if ( !target->Bind() )
			return false;

		// Perform drawing.
		( target0 != nullptr ) ? targetWindow->DrawScreen( target0 ) : targetWindow->DrawLast();

		// Present results to intermediate target.
		if ( !target->Present() )
			return false;
	}

	// Bind final target.
	if ( !window->Bind() )
		return false;

	// Clear target.
	window->Clear();

	// Draw overlays or window contents.
	(target != nullptr) ? targetWindow->DrawScreen( target ) : targetWindow->DrawLast();

	// Present results.
	return window->Present();
}


} // gfx


} // synkro
