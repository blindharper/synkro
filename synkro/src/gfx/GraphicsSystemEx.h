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
#ifndef _SYNKRO_GFX_GRAPHICSSYSTEMEX_
#define _SYNKRO_GFX_GRAPHICSSYSTEMEX_


#include "config.h"
#include <lang/Convert.h>
#include <gfx/IGraphicsSystemEx.h>
#include <io/IStreamDirectory.h>
#include <win/IWindowSystemEx.h>
#include <win/IFrameWindowEx.h>
#include <win/IViewWindowEx.h>
#include "GraphicsDevice.h"
#include "VirtualRenderWindow.h"
#include "BaseRenderMap.h"
#include "Program.h"
#include "ProgramReader.h"


namespace synkro
{


namespace gfx
{


// Extended graphics system.
class GraphicsSystemEx :
	public core::ObjectImpl<IGraphicsSystemEx>,
	public Logger
{
public:
	// Constructor & destructor.
	GraphicsSystemEx( diag::ILog* log );
	~GraphicsSystemEx();

	// ISystem methods.
	Bool													Update( Double delta );

	// IGraphicsSystem methods.
	IGraphicsDevice*										CreateDevice( UInt index );
	UInt													GetTotalDeviceCount() const;
	void													GetDeviceDesc( UInt index, GraphicsDeviceDesc& desc ) const;
	lang::String											GetName() const;

	// IGraphicsSystemEx methods.
	IDataFormatEx*											CreateDataFormat();
	IOverlayRenderQueue*									CreateRenderQueue( UInt width, UInt height );
	ISceneRenderQueue*										CreateRenderQueue();
	IPlainRenderMap*										CreateRenderMap( IOverlayRenderQueue* queue, IPlainRenderTexture* target );
	IPlainRenderMap*										CreateRenderMap( ISceneRenderQueue* queue, IPlainRenderTexture* colorTarget, IPlainDepthTexture* depthTarget );
	ICubeRenderMap*											CreateRenderMap( ISceneRenderQueue* queue, ICubeRenderTexture* colorTarget, ICubeDepthTexture* depthTarget );
	IVirtualRenderWindow*									CreateRenderWindow( UInt width, UInt height, const img::PixelFormat& format, UInt sampleCount, UInt sampleQuality );
	IProgram*												GetProgram( const lang::String& name ) const;
	UInt													GetDeviceCount() const;
	IGraphicsDeviceEx*										GetDevice( UInt index ) const;
	IGraphicsDeviceEx*										GetDevice() const;
	UInt													GetFrameWindowCount() const;
	IFrameRenderWindowEx*									GetFrameWindow( UInt index ) const;
	UInt													GetViewWindowCount() const;
	IViewRenderWindowEx*									GetViewWindow( UInt index ) const;
	UInt													GetVirtualWindowCount() const;
	IVirtualRenderWindow*									GetVirtualWindow( UInt index ) const;
	void													GetStats( GraphicsStats& stats ) const;

	// Other methods.
	void													Initialize( IGraphicsSystemFactory* factory, const GraphicsDeviceType& type, win::IWindowSystemEx* windowSystem );
	void													Finalize();
	void													SetProgramCache( io::IStreamDirectory* programCache );
	void													RegisterDataType( const lang::String& name, const ProgramDataType& type );
	void													Init( const DepthFormat& depthFormat, const DisplayMode& displayMode, Bool vsync, UInt sampleCount );
	void													AddProgramLibrary( io::IStreamDirectory* dir, const lang::String& system );
	IProgram*												LoadProgram( GraphicsDevice* device, const lang::String& name );

private:
	friend class GraphicsDevice;
	friend class Viewport;

	class AssembleSignature
	{
	public:
		AssembleSignature() :
			_string( A(Char) )
		{
			_string.Clear();
		}

		Bool Call( const StreamDesc& stream )
		{
			if ( _string.Size() > 0 )
			{
				_string.Add( L'|' );
			}
			Append( stream.Name );
			_string.Add( L'.' );
			Append( stream.Type );
			return true;
		}

		lang::String Signature() const
		{
			if ( _string.Size() > 0 )
			{
				if ( _string.LastValue() != 0 )
				{
					_string.Add( 0 );
				}
				return lang::String( _string.Begin() );
			}
			return lang::String::Empty;
		}

	private:
		mutable lang::Vector<Char> _string;

		void Append( const lang::String& text )
		{
			for ( UInt i = 0; i < text.Length(); ++i )
			{
				_string.Add( text[i] );
			}
		}
	};

	class AssembleFormat
	{
	public:
		AssembleFormat( GraphicsSystemEx* graphicsSystem, IDataFormatEx* format, Bool vertex ) :
			_graphicsSystem( graphicsSystem ),
			_format( format ),
			_vertex( vertex )
		{
		}
		
		Bool Call( const StreamDesc& stream )
		{
			if ( _vertex )
				_format->AddVertexStream( stream.Name, _graphicsSystem->Convert(stream.Type) );
			else
				_format->AddInstanceStream( stream.Name, _graphicsSystem->Convert(stream.Type) );

			return true;
		}

	private:
		GraphicsSystemEx*	_graphicsSystem;
		IDataFormatEx*		_format;
		Bool				_vertex;
	};

	struct DeviceCapability
	{
		DeviceCapability( const lang::String& name, UInt value ) :
			Name( name ),
			Value( value )
		{
		}

		DeviceCapability()
		{
		}

		lang::String	Name;
		UInt			Value;
	};

	struct ProgramDesc
	{
		ProgramDesc( const lang::String& parentName, const lang::String& pathVertex, const lang::String& pathHull,
					 const lang::String& pathDomain, const lang::String& pathGeometry, const lang::String& pathPixel,
					 io::IStreamDirectory* resource, IDataFormat* inputFormat, IDataFormat* outputFormat ) :
			Caps( A(DeviceCapability) ),
			ParentName( parentName ),
			PathVertex( pathVertex ),
			PathHull( pathHull ),
			PathDomain( pathDomain ),
			PathGeometry( pathGeometry ),
			PathPixel( pathPixel ),
			Resource( resource ),
			InputFormat( inputFormat ),
			OutputFormat( outputFormat )
		{
		}

		ProgramDesc() :
			Caps( A(DeviceCapability) ),
			ParentName( lang::String::Null ),
			Resource( nullptr ),
			InputFormat( nullptr ),
			OutputFormat( nullptr )
		{
		}

		lang::Vector<DeviceCapability> Caps;
		lang::String			ParentName;
		lang::String			PathVertex;
		lang::String			PathHull;
		lang::String			PathDomain;
		lang::String			PathGeometry;
		lang::String			PathPixel;
		io::IStreamDirectory*	Resource;
		IDataFormat*			InputFormat;
		IDataFormat*			OutputFormat;
	};

	typedef lang::MapPair<lang::String, P(IDataFormat)>		FormatEntry;
	typedef lang::MapPair<lang::String, ProgramDataType>	TypeEntry;
	typedef lang::MapPair<lang::String, ProgramDesc>		ProgramEntry;

	IGraphicsSystemFactory*									_factory;
	win::IWindowSystemEx*									_windowSystem;
	P(IGraphicsSystem)										_graphicsSystem;
	GraphicsDevice*											_device;
	P(io::IStreamDirectory)									_programCache;
	lang::Vector<P(GraphicsDevice)>							_devices;
	lang::MapCI<lang::String, P(IDataFormat)>				_formats;
	lang::MapCI<lang::String, ProgramDataType>				_types;
	lang::MapCI<lang::String, ProgramDesc>					_programs;
	lang::Vector<BaseRenderMap*>							_maps;
	lang::Vector<P(VirtualRenderWindow)>					_virtualWindows;
	GraphicsStats											_stats;

	void													DumpProgram( IProgram* program, const ProgramDesc& desc );
	io::IStream*											GetCacheStream( const lang::String& name );
	io::IStream*											LoadStream( const lang::String& name, io::IStreamDirectory* dir1, io::IStreamDirectory* dir2 );
	IDataFormat*											AssembleDataFormat( const FormatDesc* format );
	ProgramDataType											Convert( const lang::String& type );
	Bool													Draw( BaseRenderWindow* targetWindow, IRenderWindow* window, IPlainRenderTexture* target, Double delta, GraphicsStats& stats );
};


#include "GraphicsSystemEx.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_GRAPHICSSYSTEMEX_
