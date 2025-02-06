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
#ifndef _SYNKRO_GFX_DX11GRAPHICSSYSTEM_
#define _SYNKRO_GFX_DX11GRAPHICSSYSTEM_


#include "config.h"
#include <gfx/GraphicsSystemImpl.h>
#include <gfx/IGraphicsSystem.h>


struct IDXGIFactory1;
struct IDXGIAdapter1;


namespace synkro
{


namespace gfx
{


// DirectX 11 graphics system implementation.
class Dx11GraphicsSystem :
	public GraphicsSystemImpl<IGraphicsSystem>
{
public:
	// Constructor & destructor.
	Dx11GraphicsSystem( diag::ILog* log );
	~Dx11GraphicsSystem();

	// IGraphicsSystem methods.
	IGraphicsDevice*										CreateDevice( UInt index );

private:
	lang::Vector<IDXGIAdapter1*>							_adapters;
	HMODULE													_dllDxGi;
	HMODULE													_dllDx10;
	HMODULE													_dllDx11;
	HMODULE													_dllDComp;
	IDXGIFactory1*											_factory;

	HMODULE													LoadLib( const lang::String& lib, UInt version );
	FARPROC													GetEntryPoint( HMODULE module, const char* name );
	Bool													GetCaps( IDXGIAdapter1* adapter, GraphicsDeviceDesc& desc );
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11GRAPHICSSYSTEM_
