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
#include "config.h"
#include "Dx11.h"
#include <gfx/Dx/DxGi.h>
#include <dx/d3dx11core.h>
#include <gfx/DataStream.h>


//------------------------------------------------------------------------------

using namespace synkro::img;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


const D3D_DRIVER_TYPE Dx11::Convert( const GraphicsDeviceType& type )
{
	static D3D_DRIVER_TYPE consts[] = 
	{
		D3D_DRIVER_TYPE_NULL,
		// NB: The second parameter must be D3D_DRIVER_TYPE_UNKNOWN (see D3D11CreateDevice() in DirectX reference)
		D3D_DRIVER_TYPE_UNKNOWN, // D3D_DRIVER_TYPE_HARDWARE
		D3D_DRIVER_TYPE_WARP,
		D3D_DRIVER_TYPE_REFERENCE,
	};
	return consts[type];
}

const D3D11_COMPARISON_FUNC Dx11::Convert( const CompareFunction& func )
{
	static D3D11_COMPARISON_FUNC consts[] = 
	{
		D3D11_COMPARISON_NEVER,
		D3D11_COMPARISON_LESS,
		D3D11_COMPARISON_EQUAL,
		D3D11_COMPARISON_LESS_EQUAL,
		D3D11_COMPARISON_GREATER,
		D3D11_COMPARISON_NOT_EQUAL,
		D3D11_COMPARISON_GREATER_EQUAL,
		D3D11_COMPARISON_ALWAYS,
	};
	return consts[func];
}

const D3D11_TEXTURECUBE_FACE Dx11::Convert( const CubeFace& face )
{
	static D3D11_TEXTURECUBE_FACE consts[] = 
	{
		D3D11_TEXTURECUBE_FACE_POSITIVE_X,
		D3D11_TEXTURECUBE_FACE_NEGATIVE_X,
		D3D11_TEXTURECUBE_FACE_POSITIVE_Y,
		D3D11_TEXTURECUBE_FACE_NEGATIVE_Y,
		D3D11_TEXTURECUBE_FACE_POSITIVE_Z,
		D3D11_TEXTURECUBE_FACE_NEGATIVE_Z,
	};
	return consts[face];
}

const D3D11_CULL_MODE Dx11::Convert( const CullMode& cull )
{
	static D3D11_CULL_MODE consts[] =
	{
		D3D11_CULL_NONE,
		D3D11_CULL_NONE,
		D3D11_CULL_FRONT,
		D3D11_CULL_BACK,
	};
	return consts[cull];
}

const D3D11_FILL_MODE Dx11::Convert( const FillMode& fill )
{
	static D3D11_FILL_MODE consts[] =
	{
		D3D11_FILL_SOLID,
		D3D11_FILL_WIREFRAME,
		D3D11_FILL_SOLID,
	};
	return consts[fill];
}

const D3D11_BLEND Dx11::Convert( const BlendMode& blend )
{
	static D3D11_BLEND consts[] =
	{
		D3D11_BLEND_ZERO,
		D3D11_BLEND_ZERO,
		D3D11_BLEND_ONE,
		D3D11_BLEND_SRC_COLOR,
		D3D11_BLEND_INV_SRC_COLOR,
		D3D11_BLEND_SRC_ALPHA,
		D3D11_BLEND_INV_SRC_ALPHA,
		D3D11_BLEND_DEST_ALPHA,
		D3D11_BLEND_INV_DEST_ALPHA,
		D3D11_BLEND_DEST_COLOR,
		D3D11_BLEND_INV_DEST_COLOR,
		D3D11_BLEND_SRC_ALPHA_SAT,
	};
	return consts[blend];
}

const D3D11_BLEND_OP Dx11::Convert( const BlendOperation& operation )
{
	static D3D11_BLEND_OP consts[] =
	{
		D3D11_BLEND_OP_ADD,
		D3D11_BLEND_OP_ADD,
		D3D11_BLEND_OP_SUBTRACT,
		D3D11_BLEND_OP_REV_SUBTRACT,
		D3D11_BLEND_OP_MIN,
		D3D11_BLEND_OP_MAX,
	};
	return consts[operation];
}

const D3D11_PRIMITIVE_TOPOLOGY Dx11::Convert( const PrimitiveType& type, UInt pointCount, Bool adjacency )
{
	if ( adjacency )
	{
			 if ( type == PrimitiveType::LineList )			return D3D11_PRIMITIVE_TOPOLOGY_LINELIST_ADJ;
		else if ( type == PrimitiveType::LineStrip )		return D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ;
		else if ( type == PrimitiveType::TriangleList )		return D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ;
		else if ( type == PrimitiveType::TriangleStrip )	return D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ;
	}
	else if ( type == PrimitiveType::PatchList )
	{
		assert( pointCount > 0 );
		assert( pointCount <= 32 );

		static D3D11_PRIMITIVE_TOPOLOGY consts[] =
		{
			D3D11_PRIMITIVE_TOPOLOGY_UNDEFINED,
			D3D11_PRIMITIVE_TOPOLOGY_1_CONTROL_POINT_PATCHLIST,
			D3D11_PRIMITIVE_TOPOLOGY_2_CONTROL_POINT_PATCHLIST,
			D3D11_PRIMITIVE_TOPOLOGY_3_CONTROL_POINT_PATCHLIST,
			D3D11_PRIMITIVE_TOPOLOGY_4_CONTROL_POINT_PATCHLIST,
			D3D11_PRIMITIVE_TOPOLOGY_5_CONTROL_POINT_PATCHLIST,
			D3D11_PRIMITIVE_TOPOLOGY_6_CONTROL_POINT_PATCHLIST,
			D3D11_PRIMITIVE_TOPOLOGY_7_CONTROL_POINT_PATCHLIST,
			D3D11_PRIMITIVE_TOPOLOGY_8_CONTROL_POINT_PATCHLIST,
			D3D11_PRIMITIVE_TOPOLOGY_9_CONTROL_POINT_PATCHLIST,
			D3D11_PRIMITIVE_TOPOLOGY_10_CONTROL_POINT_PATCHLIST,
			D3D11_PRIMITIVE_TOPOLOGY_11_CONTROL_POINT_PATCHLIST,
			D3D11_PRIMITIVE_TOPOLOGY_12_CONTROL_POINT_PATCHLIST,
			D3D11_PRIMITIVE_TOPOLOGY_13_CONTROL_POINT_PATCHLIST,
			D3D11_PRIMITIVE_TOPOLOGY_14_CONTROL_POINT_PATCHLIST,
			D3D11_PRIMITIVE_TOPOLOGY_15_CONTROL_POINT_PATCHLIST,
			D3D11_PRIMITIVE_TOPOLOGY_16_CONTROL_POINT_PATCHLIST,
			D3D11_PRIMITIVE_TOPOLOGY_17_CONTROL_POINT_PATCHLIST,
			D3D11_PRIMITIVE_TOPOLOGY_18_CONTROL_POINT_PATCHLIST,
			D3D11_PRIMITIVE_TOPOLOGY_19_CONTROL_POINT_PATCHLIST,
			D3D11_PRIMITIVE_TOPOLOGY_20_CONTROL_POINT_PATCHLIST,
			D3D11_PRIMITIVE_TOPOLOGY_21_CONTROL_POINT_PATCHLIST,
			D3D11_PRIMITIVE_TOPOLOGY_22_CONTROL_POINT_PATCHLIST,
			D3D11_PRIMITIVE_TOPOLOGY_23_CONTROL_POINT_PATCHLIST,
			D3D11_PRIMITIVE_TOPOLOGY_24_CONTROL_POINT_PATCHLIST,
			D3D11_PRIMITIVE_TOPOLOGY_25_CONTROL_POINT_PATCHLIST,
			D3D11_PRIMITIVE_TOPOLOGY_26_CONTROL_POINT_PATCHLIST,
			D3D11_PRIMITIVE_TOPOLOGY_27_CONTROL_POINT_PATCHLIST,
			D3D11_PRIMITIVE_TOPOLOGY_28_CONTROL_POINT_PATCHLIST,
			D3D11_PRIMITIVE_TOPOLOGY_29_CONTROL_POINT_PATCHLIST,
			D3D11_PRIMITIVE_TOPOLOGY_30_CONTROL_POINT_PATCHLIST,
			D3D11_PRIMITIVE_TOPOLOGY_31_CONTROL_POINT_PATCHLIST,
			D3D11_PRIMITIVE_TOPOLOGY_32_CONTROL_POINT_PATCHLIST,
		};
		return consts[pointCount];
	}
	else
	{
		static D3D11_PRIMITIVE_TOPOLOGY consts[] =
		{
			D3D11_PRIMITIVE_TOPOLOGY_UNDEFINED,
			D3D11_PRIMITIVE_TOPOLOGY_POINTLIST,
			D3D11_PRIMITIVE_TOPOLOGY_LINELIST,
			D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP,
			D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
			D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP,
		};
		return consts[type];
	}
	return D3D11_PRIMITIVE_TOPOLOGY_UNDEFINED;
}

const String Dx11::Convert( const DataStream& semantic )
{
	static Char* consts[] =
	{
		L"",
		L"POSITION",
		L"POSITION",
		L"POSITION",
		L"NORMAL",
		L"COLOR",
		L"BONES",
		L"WEIGHTS",
		L"TEXCOORD",
		L"TEXCOORD",
		L"TRANSFORM",
		L"ID",
	};
	return consts[semantic];
}

const D3D11_STENCIL_OP Dx11::Convert( const StencilOperation& operation )
{
	static D3D11_STENCIL_OP consts[] =
	{
		D3D11_STENCIL_OP_KEEP,
		D3D11_STENCIL_OP_ZERO,
		D3D11_STENCIL_OP_INVERT,
		D3D11_STENCIL_OP_REPLACE,
		D3D11_STENCIL_OP_INCR_SAT,
		D3D11_STENCIL_OP_DECR_SAT,
		D3D11_STENCIL_OP_INCR,
		D3D11_STENCIL_OP_DECR,
	};
	return consts[operation];
}

const D3D11_TEXTURE_ADDRESS_MODE Dx11::Convert( const TextureAddress& addr )
{
	static D3D11_TEXTURE_ADDRESS_MODE consts[] =
	{
		D3D11_TEXTURE_ADDRESS_WRAP,
		D3D11_TEXTURE_ADDRESS_WRAP,
		D3D11_TEXTURE_ADDRESS_MIRROR,
		D3D11_TEXTURE_ADDRESS_CLAMP,
		D3D11_TEXTURE_ADDRESS_BORDER,
		D3D11_TEXTURE_ADDRESS_MIRROR_ONCE,
	};
	return consts[addr];
}

const D3D11_FILTER_TYPE Dx11::Convert( const TextureFilter& flt )
{
	static D3D11_FILTER_TYPE consts[] =
	{
		D3D11_FILTER_TYPE_POINT,
		D3D11_FILTER_TYPE_POINT,
		D3D11_FILTER_TYPE_LINEAR,
		D3D11_FILTER_TYPE_LINEAR,
		D3D11_FILTER_TYPE_LINEAR,
		D3D11_FILTER_TYPE_LINEAR,
	};
	return consts[flt];
}

const D3D11_FILTER Dx11::Convert( const TextureFilter& min, const TextureFilter& mag, const TextureFilter& mip )
{
	if ( (min == mag) && (mag == mip) )
	{
		if ( min == TextureFilter::Anisotropic )
			return D3D11_FILTER_ANISOTROPIC;
		else if ( min == TextureFilter::Linear )
			return D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	}
	else if ( min == mag )
	{
		if ( min == TextureFilter::Anisotropic )
			return D3D11_FILTER_ANISOTROPIC;
		else if ( min == TextureFilter::Linear )
			return D3D11_FILTER_MIN_MAG_LINEAR_MIP_POINT;
		else if ( min == TextureFilter::Point )
			return D3D11_FILTER_MIN_MAG_POINT_MIP_LINEAR;
	}
	else if ( min == mip )
	{
		if ( min == TextureFilter::Anisotropic )
			return D3D11_FILTER_ANISOTROPIC;
		else if ( min == TextureFilter::Linear )
			return D3D11_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR;
		else if ( min == TextureFilter::Point )
			return D3D11_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT;
	}
	else if ( mag == mip )
	{
		if ( mag == TextureFilter::Anisotropic )
			return D3D11_FILTER_ANISOTROPIC;
		else if ( mag == TextureFilter::Linear )
			return D3D11_FILTER_MIN_POINT_MAG_MIP_LINEAR;
		else if ( mag == TextureFilter::Point )
			return D3D11_FILTER_MIN_LINEAR_MAG_MIP_POINT;
	}

	return D3D11_FILTER_MIN_MAG_MIP_POINT;
}

D3D11_USAGE Dx11::Convert( const DataUsage& usage )
{
		 if ( usage == DataUsage::Static )	return D3D11_USAGE_IMMUTABLE;
	else if ( usage == DataUsage::Dynamic )	return D3D11_USAGE_DYNAMIC;
	else if ( usage == DataUsage::Stream )	return D3D11_USAGE_DYNAMIC;
	else									return D3D11_USAGE_DEFAULT;
}

UINT Dx11::Convert( const DataAccess& access )
{
	return (access == DataAccess::WriteOnly) ? D3D11_CPU_ACCESS_WRITE : D3D11_CPU_ACCESS_READ | D3D11_CPU_ACCESS_WRITE;
}

D3D11_MAP Dx11::Convert( const MapMode& mode, Bool overwrite )
{
	if ( mode == MapMode::Write )
		return overwrite ? D3D11_MAP_WRITE_DISCARD : D3D11_MAP_WRITE_NO_OVERWRITE;
	else
		return D3D11_MAP_READ;
}

UINT8 Dx11::Convert( const PixelChannel& channels )
{
	UINT8 mask = 0;

	if ( channels.IsSet(PixelChannel::Red) )	{ mask |= D3D11_COLOR_WRITE_ENABLE_RED; }
	if ( channels.IsSet(PixelChannel::Green) )	{ mask |= D3D11_COLOR_WRITE_ENABLE_GREEN; }
	if ( channels.IsSet(PixelChannel::Blue) )	{ mask |= D3D11_COLOR_WRITE_ENABLE_BLUE; }
	if ( channels.IsSet(PixelChannel::Alpha) )	{ mask |= D3D11_COLOR_WRITE_ENABLE_ALPHA; }

	return mask;
}

UINT Dx11::Convert( const IDataFormat* fmt, D3D11_INPUT_ELEMENT_DESC* decl, Bool interleaved )
{
	D3D11_INPUT_ELEMENT_DESC* p = decl;
	D3D11_INPUT_ELEMENT_DESC elem;
	UINT offset = 0;
	UINT slot = 0;

	UInt bufOffset = 0;
	static char buf[512];
	Zero( buf, 512 );

	for ( UInt i = 0; i < fmt->GetVertexStreamCount(); ++i )
	{
		const ProgramDataType type = fmt->GetVertexStreamDataType( i );
		if ( (type == ProgramDataType::Matrix4x4) || (type == ProgramDataType::Matrix4x4Transposed) )
		{
			// Split 4x4 Matrix stream into 4 Vector4 streams.
			for ( UInt j = 0; j < 4; ++j )
			{
				String semantic = Convert( fmt->GetVertexStreamType(i) );
				UInt bytes = semantic.GetBytes( buf+bufOffset, 512-bufOffset );
				LPCSTR semanticName = buf+bufOffset; UINT semanticIndex = 0;
				bufOffset += bytes+1;
				for ( const D3D11_INPUT_ELEMENT_DESC* e = decl ; e != p ; ++e )
				{
					if ( _strcmpi(e->SemanticName, semanticName) == 0 )
						++semanticIndex;
				}

				elem.SemanticName			= semanticName;
				elem.SemanticIndex			= semanticIndex;
				elem.Format					= DxGi::Convert( fmt->GetVertexStreamDataType(i) );
				elem.InputSlot				= slot;
				elem.AlignedByteOffset		= offset;
				elem.InputSlotClass			= D3D11_INPUT_PER_VERTEX_DATA;
				elem.InstanceDataStepRate	= 0;
				offset += ProgramDataType::Vector4.Size();
				*p++ = elem;
			}
		}
		else
		{
			String semantic = Convert( fmt->GetVertexStreamType(i) );
			UInt bytes = semantic.GetBytes( buf+bufOffset, 512-bufOffset );
			LPCSTR semanticName = buf+bufOffset; UINT semanticIndex = 0;
			bufOffset += bytes+1;
			for ( const D3D11_INPUT_ELEMENT_DESC* e = decl ; e != p ; ++e )
			{
				if ( _strcmpi(e->SemanticName, semanticName) == 0 )
					++semanticIndex;
			}

			elem.SemanticName			= semanticName;
			elem.SemanticIndex			= semanticIndex;
			elem.Format					= DxGi::Convert( fmt->GetVertexStreamDataType(i) );
			elem.InputSlot				= slot;
			elem.AlignedByteOffset		= interleaved ? offset : 0;
			elem.InputSlotClass			= D3D11_INPUT_PER_VERTEX_DATA;
			elem.InstanceDataStepRate	= 0;
			offset += fmt->GetVertexStreamDataType(i).Size();
			*p++ = elem;
		}

		if ( !interleaved )
		{
			++slot;
		}
	}

	offset = 0;
	for ( UInt i = 0; i < fmt->GetInstanceStreamCount(); ++i )
	{
		const ProgramDataType type = fmt->GetInstanceStreamDataType( i );
		if ( (type == ProgramDataType::Matrix4x4) || (type == ProgramDataType::Matrix4x4Transposed) )
		{
			// Split 4x4 Matrix stream into 4 Vector4 streams.
			for ( UInt j = 0; j < 4; ++j )
			{
				String semantic = Convert( fmt->GetInstanceStreamType(i) );
				UInt bytes = semantic.GetBytes( buf+bufOffset, 512-bufOffset );
				LPCSTR semanticName = buf+bufOffset; UINT semanticIndex = 0;
				bufOffset += bytes+1;
				for ( const D3D11_INPUT_ELEMENT_DESC* e = decl ; e != p ; ++e )
				{
					if ( _strcmpi(e->SemanticName, semanticName) == 0 )
						++semanticIndex;
				}

				elem.SemanticName			= semanticName;
				elem.SemanticIndex			= semanticIndex;
				elem.Format					= DxGi::Convert( fmt->GetInstanceStreamDataType(i) );
				elem.InputSlot				= interleaved ? 1 : slot;
				elem.AlignedByteOffset		= offset;
				elem.InputSlotClass			= D3D11_INPUT_PER_INSTANCE_DATA;
				elem.InstanceDataStepRate	= 1;
				offset += ProgramDataType::Vector4.Size();
				*p++ = elem;
			}
		}
		else
		{
			String semantic = Convert( fmt->GetInstanceStreamType(i) );
			UInt bytes = semantic.GetBytes( buf+bufOffset, 512-bufOffset );
			LPCSTR semanticName = buf+bufOffset; UINT semanticIndex = 0;
			bufOffset += bytes+1;
			for ( const D3D11_INPUT_ELEMENT_DESC* e = decl ; e != p ; ++e )
			{
				if ( _strcmpi(e->SemanticName, semanticName) == 0 )
					++semanticIndex;
			}

			elem.SemanticName			= semanticName;
			elem.SemanticIndex			= semanticIndex;
			elem.Format					= DxGi::Convert( fmt->GetInstanceStreamDataType(i) );
			elem.InputSlot				= interleaved ? 1 : slot;
			elem.AlignedByteOffset		= offset;
			elem.InputSlotClass			= D3D11_INPUT_PER_INSTANCE_DATA;
			elem.InstanceDataStepRate	= 1;
			offset += fmt->GetInstanceStreamDataType(i).Size();
			*p++ = elem;
		}
	}

	return p-decl;
}

UINT Dx11::Convert( const IDataFormat* fmt, D3D11_SO_DECLARATION_ENTRY* decl, UINT& stride )
{
	D3D11_SO_DECLARATION_ENTRY* p = decl;
	D3D11_SO_DECLARATION_ENTRY elem;
	UINT offset = 0;

	UInt bufOffset = 0;
	static char buf[512] = {};
	Zero( buf, 512 );

	for ( UInt i = 0; i < fmt->GetVertexStreamCount(); ++i )
	{
		const ProgramDataType type = fmt->GetVertexStreamDataType( i );
		String semantic = Convert( fmt->GetVertexStreamType(i) );
		const UInt bytes = semantic.GetBytes( buf+bufOffset, 512-bufOffset );
		LPCSTR semanticName = buf+bufOffset; UINT semanticIndex = 0;
		bufOffset += bytes+1;
		for ( const D3D11_SO_DECLARATION_ENTRY* e = decl ; e != p ; ++e )
		{
			if ( _strcmpi(e->SemanticName, semanticName) == 0 )
				++semanticIndex;
		}

		elem.SemanticName			= semanticName;
		elem.SemanticIndex			= semanticIndex;
		elem.StartComponent			= 0;
		elem.ComponentCount			= 4;
		elem.OutputSlot				= 0;
		offset += fmt->GetVertexStreamDataType(i).Size();
		*p++ = elem;
	}

	stride = offset;
	return p-decl;
}

LPCSTR Dx11::Convert( const ProgramStageType& type, D3D_FEATURE_LEVEL level )
{
	switch ( level )
	{
		case D3D_FEATURE_LEVEL_11_0:
		{
				 if ( type == ProgramStageType::Vertex )	return "vs_5_0";
			else if ( type == ProgramStageType::Hull )		return "hs_5_0";
			else if ( type == ProgramStageType::Domain )	return "ds_5_0";
			else if ( type == ProgramStageType::Geometry )	return "gs_5_0";
			else if ( type == ProgramStageType::Fragment )	return "ps_5_0";
		}
		break;

		case D3D_FEATURE_LEVEL_10_1:
		{
				 if ( type == ProgramStageType::Vertex )	return "vs_4_1";
			else if ( type == ProgramStageType::Geometry )	return "gs_4_1";
			else if ( type == ProgramStageType::Fragment )	return "ps_4_1";
		}
		break;

		case D3D_FEATURE_LEVEL_10_0:
		{
				 if ( type == ProgramStageType::Vertex )	return "vs_4_0";
			else if ( type == ProgramStageType::Geometry )	return "gs_4_0";
			else if ( type == ProgramStageType::Fragment )	return "ps_4_0";
		}
		break;

		case D3D_FEATURE_LEVEL_9_3:
		{
				 if ( type == ProgramStageType::Vertex )	return "vs_4_0_level_9_3";
			else if ( type == ProgramStageType::Fragment )	return "ps_4_0_level_9_3";
		}
		break;

		case D3D_FEATURE_LEVEL_9_2:
		case D3D_FEATURE_LEVEL_9_1:
		{
				 if ( type == ProgramStageType::Vertex )	return "vs_4_0_level_9_1";
			else if ( type == ProgramStageType::Fragment )	return "ps_4_0_level_9_1";
		}
		break;
	}

	return "";
}

const Char* Dx11::ToString( HRESULT hr )
{
	switch ( hr )
	{
		case S_OK:										return L"S_OK";
		case S_FALSE:									return L"S_FALSE";
		case D3D11_ERROR_FILE_NOT_FOUND:				return L"D3D11_ERROR_FILE_NOT_FOUND";
		case D3D11_ERROR_TOO_MANY_UNIQUE_STATE_OBJECTS:	return L"D3D11_ERROR_TOO_MANY_UNIQUE_STATE_OBJECTS";
		case D3DERR_INVALIDCALL:						return L"D3DERR_INVALIDCALL";
		case D3DERR_WASSTILLDRAWING:					return L"D3DERR_WASSTILLDRAWING";
		case E_FAIL:									return L"E_FAIL";
		case E_INVALIDARG:								return L"E_INVALIDARG";
		case E_NOINTERFACE:								return L"E_NOINTERFACE";
		case E_OUTOFMEMORY:								return L"E_OUTOFMEMORY";
		default:										return DxGi::ToString( hr );
	}
}

LPD3D11CREATEDEVICE Dx11::CreateDevice = nullptr;
LPD3D10CREATEBLOB Dx11::CreateBlob = nullptr;
LPD3DREFLECT Dx11::Reflect = nullptr;
LPD3DCOMPILE Dx11::Compile = nullptr;


} // gfx


} // synkro
