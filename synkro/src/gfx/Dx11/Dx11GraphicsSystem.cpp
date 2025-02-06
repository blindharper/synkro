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
// Purpose: DirectX 11 graphics system implementation.
//==============================================================================
#include "config.h"
#include "Dx11GraphicsSystem.h"
#include "Dx11GraphicsDevice.h"
#include "Dx11.h"
#include <gfx/Dx/DxGi.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::diag;
using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


// DXGI library name.
#define DXGI_DLL L"dxgi.dll"

// Direct3D 10 library name.
#define D3D10_DLL L"d3d10.dll"

// Direct3D 11 library name.
#define D3D11_DLL L"d3d11.dll"

// Direct3D compiler library name.
#define D3D_COMPILER_DLL L"d3dcompiler"


namespace synkro
{


namespace gfx
{


Dx11GraphicsSystem::Dx11GraphicsSystem( ILog* log ) :
	GraphicsSystemImpl<IGraphicsSystem>( L"Direct3D 11", nullptr, log ),
	_adapters( A(IDXGIAdapter1*) ),
	_dllDxGi( nullptr ),
	_dllDx11( nullptr ),
	_dllDComp( nullptr ),
	_factory( nullptr )
{
	HRESULT hr = S_OK;

	// Make sure DXGI is installed.
	if ( (_dllDxGi = ::LoadLibrary(DXGI_DLL)) == nullptr )
		throw GraphicsException( String::Format(Str::InitializeFail, L"DXGI"), String::Format(Str::NotFound, DXGI_DLL), String::Empty );

	// Initialize DXGI.
	LogInfo( MessagePriority::Lowest, Formatter::Format(Str::Initializing, L"DXGI") );
	LPCREATEDXGIFACTORY pCreateDXGIFactory = (LPCREATEDXGIFACTORY)::GetProcAddress( _dllDxGi, "CreateDXGIFactory1" );
	if ( (pCreateDXGIFactory == nullptr) || FAILED(hr = pCreateDXGIFactory(__uuidof(IDXGIFactory), (void**)(&_factory))) )
		throw GraphicsException( String::Format(Str::InitializeFail, L"DXGI"), DxGi::ToString(hr) );
	
	LogInfo( MessagePriority::Lowest, Formatter::Format(Str::Done) );

	// Make sure Direct3D 11 runtime is installed.
	LogInfo( MessagePriority::Lowest, Formatter::Format(Str::Initializing, L"Direct3D 11") );
	if ( (_dllDx11 = ::LoadLibrary(D3D11_DLL)) == nullptr )
		throw GraphicsException( String::Format(Str::InitializeFail, L"Direct3D 11"), String::Format(Str::NotFound, D3D11_DLL) );
	Dx11::CreateDevice = (LPD3D11CREATEDEVICE)::GetProcAddress( _dllDx11, "D3D11CreateDevice" );

	// Make sure Direct3D 10 runtime is installed.
	if ( (_dllDx10 = ::LoadLibrary(D3D10_DLL)) == nullptr )
		throw GraphicsException( String::Format(Str::InitializeFail, L"Direct3D 11"), String::Format(Str::NotFound, D3D10_DLL), String::Empty );

	// Make sure Direct3D compiler is installed.
	if ( (_dllDComp = LoadLib(D3D_COMPILER_DLL, 50)) == nullptr )
		throw GraphicsException( String::Format(Str::InitializeFail, L"Direct3D 11"), String::Format(Str::NotFound, D3D_COMPILER_DLL), String::Empty );

	// Find required entry points.
	Dx11::CreateBlob = (LPD3D10CREATEBLOB)GetEntryPoint( _dllDx10, "D3D10CreateBlob" );
	Dx11::Reflect = (LPD3DREFLECT)GetEntryPoint( _dllDComp, "D3DReflect" );
	Dx11::Compile = (LPD3DCOMPILE)GetEntryPoint(_dllDComp, "D3DCompile");

	// Find available hardware devices.
	UINT i = 0;
	IDXGIAdapter1* adapter = nullptr;
	while ( _factory->EnumAdapters(i++, (IDXGIAdapter**)&adapter) != DXGI_ERROR_NOT_FOUND )
	{
		DXGI_ADAPTER_DESC ad;
		adapter->GetDesc( &ad );
		GraphicsDeviceDesc desc( ad.Description, GraphicsDeviceType::Hardware );
		if ( GetCaps(adapter, desc) )
		{
			_devices.Add( desc );
			_adapters.Add( adapter );
		}
	}
	
	// Add software rasterizer.
	GraphicsDeviceDesc desc( L"Software Rasterizer", GraphicsDeviceType::Software );
	if ( GetCaps(nullptr, desc) )
	{
		_devices.Add( desc );
		_adapters.Add( nullptr );
	}
	
	// Add reference device.
	GraphicsDeviceDesc desc2( L"Reference Device", GraphicsDeviceType::Reference );
	if ( GetCaps(nullptr, desc2) )
	{
		_devices.Add( desc2 );
		_adapters.Add( nullptr );
	}

	LogInfo( MessagePriority::Lowest, Formatter::Format(Str::Done) );
}

Dx11GraphicsSystem::~Dx11GraphicsSystem()
{
	SafeRelease( _factory );

	for ( UInt i = 0; i < _adapters.Size(); ++i )
	{
		SafeRelease( _adapters[i] );
	}

	::FreeLibrary( _dllDComp );
	::FreeLibrary( _dllDx11 );
	::FreeLibrary( _dllDx10 );
	::FreeLibrary( _dllDxGi );
}

IGraphicsDevice* Dx11GraphicsSystem::CreateDevice( UInt index )
{
	return new Dx11GraphicsDevice( _factory, _adapters[index], _devices[index], _log );
}

HMODULE Dx11GraphicsSystem::LoadLib( const String& lib, UInt version )
{
	HMODULE module = nullptr;
	Char buf[32] = {};
	for ( UInt i = version; i > 0; --i )
	{
		String str = String::Format( L"{0}_{1}.dll", lib, i );
		str.GetChars( 0, 32, buf );
		if ( (module = ::LoadLibrary(buf)) != nullptr )
		{
			LogInfo( MessagePriority::Highest, Formatter::Format(L"Loaded {0}", str) );
			break;
		}
	}
	return module;
}

FARPROC Dx11GraphicsSystem::GetEntryPoint( HMODULE module, const char* name )
{
	FARPROC proc = ::GetProcAddress( module, name );
	if ( proc == nullptr )
		throw GraphicsException( String::Format(Str::InitializeFail, L"Direct3D 11"), String::Format(Str::NotFound, name), String::Empty );
	return proc;
}

Bool Dx11GraphicsSystem::GetCaps( IDXGIAdapter1* adapter, GraphicsDeviceDesc& desc )
{
	HRESULT hr = S_OK;
	UINT flags = 0;
	ID3D11Device* device = nullptr;
	ID3D11DeviceContext* context = nullptr;
	D3D_FEATURE_LEVEL level = D3D_FEATURE_LEVEL_11_0;

#ifdef SYNKRO_DEBUG
	flags |= D3D11_CREATE_DEVICE_DEBUG;
#endif // SYNKRO_DEBUG

	// Create device.
	hr = S_OK;
	if ( (Dx11::CreateDevice == nullptr) || FAILED(hr = Dx11::CreateDevice(adapter, Dx11::Convert(desc.Type), (HMODULE)nullptr, flags, nullptr, 0, D3D11_SDK_VERSION, &device, &level, &context)) )
		return false;

	// Get device capabilities.
	desc.LevelMajor			= (level & 0xf000) >> 12;
	desc.LevelMinor			= (level & 0x0f00) >> 8;
	desc.TopDown			= false;
	desc.Tesselation		= true;
	desc.GeometryStage		= true;
	desc.OutputBuffer		= true;
	desc.RenderTargetCount	= D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT;

	device->Release();
	context->Release();
	return true;
}


} // gfx


} // synkro
