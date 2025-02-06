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
// Purpose: DX11 API.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11_
#define _SYNKRO_GFX_DX11_


#include "config.h"
#include <gfx/ProgramStageType.h>
#include <gfx/CompareFunction.h>
#include <gfx/CubeFace.h>
#include <gfx/CullMode.h>
#include <gfx/FillMode.h>
#include <gfx/BlendMode.h>
#include <gfx/BlendOperation.h>
#include <gfx/StencilOperation.h>
#include <gfx/TextureAddress.h>
#include <gfx/TextureFilter.h>
#include <gfx/PrimitiveType.h>
#include <gfx/ProgramDataType.h>
#include <gfx/GraphicsDeviceType.h>
#include <gfx/IDataFormat.h>
#include <gfx/DepthFormat.h>
#include <gfx/IndexType.h>
#include <gfx/DataUsage.h>
#include <gfx/DataAccess.h>
#include <gfx/DataStream.h>
#include <gfx/MapMode.h>
#include <img/PixelChannel.h>
#include <img/PixelFormat.h>
#include <internal/SafeRelease.h>
#include <internal/Zero.h>
#include <d3d11.h>
#include <d3dcompiler.h>
#include "Dx11Context.h"
#undef new
#include <dx/d3dx11async.h>
#define new SYNKRO_NEW


typedef HRESULT (WINAPI *LPD3D11CREATEDEVICE)( IDXGIAdapter*, D3D_DRIVER_TYPE, HMODULE, UINT, D3D_FEATURE_LEVEL*, UINT, UINT, ID3D11Device**, D3D_FEATURE_LEVEL*, ID3D11DeviceContext** );
typedef HRESULT (WINAPI *LPD3DREFLECT)( LPCVOID, SIZE_T, REFIID, void** );
typedef HRESULT (WINAPI *LPD3D10CREATEBLOB)( SIZE_T, ID3D10Blob** );
typedef HRESULT (WINAPI *LPD3DCOMPILE)( LPCVOID, SIZE_T, LPCSTR, const D3D_SHADER_MACRO*, ID3DInclude*, LPCSTR, LPCSTR, UINT, UINT, ID3DBlob**, ID3DBlob** );


namespace synkro
{


namespace gfx
{


// DX11 API.
class Dx11
{
public:
	static const D3D_DRIVER_TYPE							Convert( const GraphicsDeviceType& type );
	static const D3D11_COMPARISON_FUNC						Convert( const CompareFunction& func );
	static const D3D11_TEXTURECUBE_FACE						Convert( const CubeFace& face );
	static const D3D11_CULL_MODE							Convert( const CullMode& cull );
	static const D3D11_FILL_MODE							Convert( const FillMode& fill );
	static const D3D11_BLEND								Convert( const BlendMode& blend );
	static const D3D11_BLEND_OP								Convert( const BlendOperation& operation );
	static const D3D11_PRIMITIVE_TOPOLOGY					Convert( const PrimitiveType& type, UInt pointCount, Bool adjacency );
	static const lang::String 								Convert( const DataStream& semantic );
	static const D3D11_STENCIL_OP							Convert( const StencilOperation& operation );
	static const D3D11_TEXTURE_ADDRESS_MODE					Convert( const TextureAddress& addr );
	static const D3D11_FILTER_TYPE							Convert( const TextureFilter& flt );
	static const D3D11_FILTER								Convert( const TextureFilter& min, const TextureFilter& mag, const TextureFilter& mip );
	static D3D11_USAGE										Convert( const DataUsage& usage );
	static UINT												Convert( const DataAccess& access );
	static D3D11_MAP										Convert( const MapMode& mode, Bool overwrite );
	static UINT8											Convert( const img::PixelChannel& channels );
	static UINT 											Convert( const IDataFormat* fmt, D3D11_INPUT_ELEMENT_DESC* decl, Bool interleaved );
	static UINT 											Convert( const IDataFormat* fmt, D3D11_SO_DECLARATION_ENTRY* decl, UINT& stride );
	static LPCSTR											Convert( const ProgramStageType& type, D3D_FEATURE_LEVEL level );
	static const Char*										ToString( HRESULT hr );

	static LPD3D11CREATEDEVICE								CreateDevice;
	static LPD3D10CREATEBLOB								CreateBlob;
	static LPD3DREFLECT										Reflect;
	static LPD3DCOMPILE										Compile;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11_
