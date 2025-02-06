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
// Purpose: DXGI API.
//==============================================================================
#include "config.h"
#include <gfx/Dx/DxGi.h>


//------------------------------------------------------------------------------

using namespace synkro::img;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


const DXGI_FORMAT DxGi::Convert( const IndexType& type )
{
		 if ( type == IndexType::Short )		return DXGI_FORMAT_R16_UINT;
	else if ( type == IndexType::Long )			return DXGI_FORMAT_R32_UINT;
	else										return DXGI_FORMAT_UNKNOWN;
}

const DXGI_FORMAT DxGi::Convert( const PixelFormat& fmt )
{
		 if ( fmt == PixelFormat::R32G32B32A32F )	return DXGI_FORMAT_R32G32B32A32_FLOAT;
	else if ( fmt == PixelFormat::R32G32F )			return DXGI_FORMAT_R32G32_FLOAT;
	else if ( fmt == PixelFormat::R16G16B16A16F )	return DXGI_FORMAT_R16G16B16A16_FLOAT;
	else if ( fmt == PixelFormat::R16G16B16A16 )	return DXGI_FORMAT_R16G16B16A16_UNORM;
	else if ( fmt == PixelFormat::R32F )			return DXGI_FORMAT_R32_FLOAT;
	else if ( fmt == PixelFormat::R16G16F )			return DXGI_FORMAT_R16G16_FLOAT;
	else if ( fmt == PixelFormat::R10G10B10A2 )		return DXGI_FORMAT_R10G10B10A2_UNORM;
	else if ( fmt == PixelFormat::R16G16 )			return DXGI_FORMAT_R16G16_UNORM;
	else if ( fmt == PixelFormat::R8G8B8A8 )		return DXGI_FORMAT_R8G8B8A8_UNORM;
	else if ( fmt == PixelFormat::R8G8B8X8 )		return DXGI_FORMAT_R8G8B8A8_UNORM;
	else if ( fmt == PixelFormat::B8G8R8A8 )		return DXGI_FORMAT_B8G8R8A8_UNORM;
	else if ( fmt == PixelFormat::R8G8B8 )			return DXGI_FORMAT_R8G8B8A8_UNORM;
	else if ( fmt == PixelFormat::R5G6B5 )			return DXGI_FORMAT_B5G6R5_UNORM;
	else if ( fmt == PixelFormat::R16F )			return DXGI_FORMAT_R16_FLOAT;
	else if ( fmt == PixelFormat::R5G5B5A1 )		return DXGI_FORMAT_B5G5R5A1_UNORM;
	else if ( fmt == PixelFormat::R5G5B5X1 )		return DXGI_FORMAT_B5G5R5A1_UNORM;
	else if ( fmt == PixelFormat::R4G4B4A4 )		return DXGI_FORMAT_R8G8B8A8_UNORM;
	else if ( fmt == PixelFormat::R4G4B4X4 )		return DXGI_FORMAT_R8G8B8A8_UNORM;
	else if ( fmt == PixelFormat::R3G3B2A8 )		return DXGI_FORMAT_R8G8B8A8_UNORM;
	else if ( fmt == PixelFormat::R3G3B2 )			return DXGI_FORMAT_R8G8B8A8_UNORM;
	else if ( fmt == PixelFormat::R8 )				return DXGI_FORMAT_R8_UNORM;
	else if ( fmt == PixelFormat::A8 )				return DXGI_FORMAT_A8_UNORM;
	else if ( fmt == PixelFormat::BC1 )				return DXGI_FORMAT_BC1_UNORM;
	else if ( fmt == PixelFormat::BC2 )				return DXGI_FORMAT_BC2_UNORM;
	else if ( fmt == PixelFormat::BC3 )				return DXGI_FORMAT_BC3_UNORM;
	else if ( fmt == PixelFormat::BC4 )				return DXGI_FORMAT_BC4_UNORM;
	else if ( fmt == PixelFormat::BC5 )				return DXGI_FORMAT_BC5_UNORM;
	else											return DXGI_FORMAT_UNKNOWN;
}

const DXGI_FORMAT DxGi::Convert( const DepthFormat& fmt, Bool stencil )
{
		 if ( fmt == DepthFormat::D32F )		return stencil ? DXGI_FORMAT_D32_FLOAT_S8X24_UINT : DXGI_FORMAT_D32_FLOAT;
	else if ( fmt == DepthFormat::D24 )			return DXGI_FORMAT_D24_UNORM_S8_UINT;
	else if ( fmt == DepthFormat::D16 )			return DXGI_FORMAT_D16_UNORM;
	else										return DXGI_FORMAT_UNKNOWN;
}

const DXGI_FORMAT DxGi::Convert( const ProgramDataType& type )
{
		 if ( type == ProgramDataType::Float )					return DXGI_FORMAT_R32_FLOAT;
	else if ( type == ProgramDataType::Int )					return DXGI_FORMAT_R8G8B8A8_UINT;
	else if ( type == ProgramDataType::Vector2 )				return DXGI_FORMAT_R32G32_FLOAT;
	else if ( type == ProgramDataType::Vector3 )				return DXGI_FORMAT_R32G32B32_FLOAT;
	else if ( type == ProgramDataType::Vector4 )				return DXGI_FORMAT_R32G32B32A32_FLOAT;
	else if ( type == ProgramDataType::Matrix4x4 )				return DXGI_FORMAT_R32G32B32A32_FLOAT;
	else if ( type == ProgramDataType::Matrix4x4Transposed )	return DXGI_FORMAT_R32G32B32A32_FLOAT;
	else														return DXGI_FORMAT_UNKNOWN;
}

PixelFormat DxGi::Convert( DXGI_FORMAT format )
{
	switch ( format )
	{
		case DXGI_FORMAT_R32G32B32A32_FLOAT:		return PixelFormat::R32G32B32A32F;
		case DXGI_FORMAT_R32G32_FLOAT:				return PixelFormat::R32G32F;
		case DXGI_FORMAT_R16G16B16A16_FLOAT:		return PixelFormat::R16G16B16A16F;
		case DXGI_FORMAT_R32_FLOAT:					return PixelFormat::R32F;
		case DXGI_FORMAT_R16G16_FLOAT:				return PixelFormat::R16G16F;
		case DXGI_FORMAT_R8G8B8A8_UNORM:			return PixelFormat::B8G8R8A8;
		case DXGI_FORMAT_B8G8R8A8_UNORM:			return PixelFormat::R8G8B8A8;
		case DXGI_FORMAT_B5G5R5A1_UNORM:			return PixelFormat::R5G5B5A1;
		case DXGI_FORMAT_B5G6R5_UNORM:				return PixelFormat::R5G6B5;
		case DXGI_FORMAT_R16_FLOAT:					return PixelFormat::R16F;
		case DXGI_FORMAT_A8_UNORM:					return PixelFormat::A8;
		default:									return PixelFormat::Unknown;
	}
}

const Char* DxGi::ToString( HRESULT hr )
{
	switch ( hr )
	{
		case S_OK:										return L"S_OK";
		case DXGI_ERROR_INVALID_CALL:					return L"DXGI_ERROR_INVALID_CALL";
		case DXGI_ERROR_NOT_FOUND:						return L"DXGI_ERROR_NOT_FOUND";
		case DXGI_ERROR_MORE_DATA:						return L"DXGI_ERROR_MORE_DATA";
		case DXGI_ERROR_UNSUPPORTED:					return L"DXGI_ERROR_UNSUPPORTED";
		case DXGI_ERROR_DEVICE_REMOVED:					return L"DXGI_ERROR_DEVICE_REMOVED";
		case DXGI_ERROR_DEVICE_HUNG:					return L"DXGI_ERROR_DEVICE_HUNG";
		case DXGI_ERROR_DEVICE_RESET:					return L"DXGI_ERROR_DEVICE_RESET";
		case DXGI_ERROR_WAS_STILL_DRAWING:				return L"DXGI_ERROR_WAS_STILL_DRAWING";
		case DXGI_ERROR_FRAME_STATISTICS_DISJOINT:		return L"DXGI_ERROR_FRAME_STATISTICS_DISJOINT";
		case DXGI_ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE:	return L"DXGI_ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE";
		case DXGI_ERROR_DRIVER_INTERNAL_ERROR:			return L"DXGI_ERROR_DRIVER_INTERNAL_ERROR";
		case DXGI_ERROR_NONEXCLUSIVE:					return L"DXGI_ERROR_NONEXCLUSIVE";
		case DXGI_ERROR_NOT_CURRENTLY_AVAILABLE:		return L"DXGI_ERROR_NOT_CURRENTLY_AVAILABLE";
		case DXGI_ERROR_REMOTE_CLIENT_DISCONNECTED:		return L"DXGI_ERROR_REMOTE_CLIENT_DISCONNECTED";
		case DXGI_ERROR_REMOTE_OUTOFMEMORY:				return L"DXGI_ERROR_REMOTE_OUTOFMEMORY";
		default:										return L"UNKNOWN";
	}
}

const Char* DxGi::ToString( DXGI_FORMAT format )
{
	switch ( format )
	{
		case DXGI_FORMAT_R32G32B32A32_TYPELESS:			return L"DXGI_FORMAT_R32G32B32A32_TYPELESS";
		case DXGI_FORMAT_R32G32B32A32_FLOAT:			return L"DXGI_FORMAT_R32G32B32A32_FLOAT";
		case DXGI_FORMAT_R32G32B32A32_UINT:				return L"DXGI_FORMAT_R32G32B32A32_UINT";
		case DXGI_FORMAT_R32G32B32A32_SINT:				return L"DXGI_FORMAT_R32G32B32A32_SINT";
		case DXGI_FORMAT_R32G32B32_TYPELESS:			return L"DXGI_FORMAT_R32G32B32_TYPELESS";
		case DXGI_FORMAT_R32G32B32_FLOAT:				return L"DXGI_FORMAT_R32G32B32_FLOAT";
		case DXGI_FORMAT_R32G32B32_UINT:				return L"DXGI_FORMAT_R32G32B32_UINT";
		case DXGI_FORMAT_R32G32B32_SINT:				return L"DXGI_FORMAT_R32G32B32_SINT";
		case DXGI_FORMAT_R16G16B16A16_TYPELESS:			return L"DXGI_FORMAT_R16G16B16A16_TYPELESS";
		case DXGI_FORMAT_R16G16B16A16_FLOAT:			return L"DXGI_FORMAT_R16G16B16A16_FLOAT";
		case DXGI_FORMAT_R16G16B16A16_UNORM:			return L"DXGI_FORMAT_R16G16B16A16_UNORM";
		case DXGI_FORMAT_R16G16B16A16_UINT:				return L"DXGI_FORMAT_R16G16B16A16_UINT";
		case DXGI_FORMAT_R16G16B16A16_SNORM:			return L"DXGI_FORMAT_R16G16B16A16_SNORM";
		case DXGI_FORMAT_R16G16B16A16_SINT:				return L"DXGI_FORMAT_R16G16B16A16_SINT";
		case DXGI_FORMAT_R32G32_TYPELESS:				return L"DXGI_FORMAT_R32G32_TYPELESS";
		case DXGI_FORMAT_R32G32_FLOAT:					return L"DXGI_FORMAT_R32G32_FLOAT";
		case DXGI_FORMAT_R32G32_UINT:					return L"DXGI_FORMAT_R32G32_UINT";
		case DXGI_FORMAT_R32G32_SINT:					return L"DXGI_FORMAT_R32G32_SINT";
		case DXGI_FORMAT_R32G8X24_TYPELESS:				return L"DXGI_FORMAT_R32G8X24_TYPELESS";
		case DXGI_FORMAT_D32_FLOAT_S8X24_UINT:			return L"DXGI_FORMAT_D32_FLOAT_S8X24_UINT";
		case DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS:		return L"DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS";
		case DXGI_FORMAT_X32_TYPELESS_G8X24_UINT:		return L"DXGI_FORMAT_X32_TYPELESS_G8X24_UINT";
		case DXGI_FORMAT_R10G10B10A2_TYPELESS:			return L"DXGI_FORMAT_R10G10B10A2_TYPELESS";
		case DXGI_FORMAT_R10G10B10A2_UNORM:				return L"DXGI_FORMAT_R10G10B10A2_UNORM";
		case DXGI_FORMAT_R10G10B10A2_UINT:				return L"DXGI_FORMAT_R10G10B10A2_UINT";
		case DXGI_FORMAT_R11G11B10_FLOAT:				return L"DXGI_FORMAT_R11G11B10_FLOAT";
		case DXGI_FORMAT_R8G8B8A8_TYPELESS:				return L"DXGI_FORMAT_R8G8B8A8_TYPELESS";
		case DXGI_FORMAT_R8G8B8A8_UNORM:				return L"DXGI_FORMAT_R8G8B8A8_UNORM";
		case DXGI_FORMAT_R8G8B8A8_UNORM_SRGB:			return L"DXGI_FORMAT_R8G8B8A8_UNORM_SRGB";
		case DXGI_FORMAT_R8G8B8A8_UINT:					return L"DXGI_FORMAT_R8G8B8A8_UINT";
		case DXGI_FORMAT_R8G8B8A8_SNORM:				return L"DXGI_FORMAT_R8G8B8A8_SNORM";
		case DXGI_FORMAT_R8G8B8A8_SINT:					return L"DXGI_FORMAT_R8G8B8A8_SINT";
		case DXGI_FORMAT_R16G16_TYPELESS:				return L"DXGI_FORMAT_R16G16_TYPELESS";
		case DXGI_FORMAT_R16G16_FLOAT:					return L"DXGI_FORMAT_R16G16_FLOAT";
		case DXGI_FORMAT_R16G16_UNORM:					return L"DXGI_FORMAT_R16G16_UNORM";
		case DXGI_FORMAT_R16G16_UINT:					return L"DXGI_FORMAT_R16G16_UINT";
		case DXGI_FORMAT_R16G16_SNORM:					return L"DXGI_FORMAT_R16G16_SNORM";
		case DXGI_FORMAT_R16G16_SINT:					return L"DXGI_FORMAT_R16G16_SINT";
		case DXGI_FORMAT_R32_TYPELESS:					return L"DXGI_FORMAT_R32_TYPELESS";
		case DXGI_FORMAT_D32_FLOAT:						return L"DXGI_FORMAT_D32_FLOAT";
		case DXGI_FORMAT_R32_FLOAT:						return L"DXGI_FORMAT_R32_FLOAT";
		case DXGI_FORMAT_R32_UINT:						return L"DXGI_FORMAT_R32_UINT";
		case DXGI_FORMAT_R32_SINT:						return L"DXGI_FORMAT_R32_SINT";
		case DXGI_FORMAT_R24G8_TYPELESS:				return L"DXGI_FORMAT_R24G8_TYPELESS";
		case DXGI_FORMAT_D24_UNORM_S8_UINT:				return L"DXGI_FORMAT_D24_UNORM_S8_UINT";
		case DXGI_FORMAT_R24_UNORM_X8_TYPELESS:			return L"DXGI_FORMAT_R24_UNORM_X8_TYPELESS";
		case DXGI_FORMAT_X24_TYPELESS_G8_UINT:			return L"DXGI_FORMAT_X24_TYPELESS_G8_UINT";
		case DXGI_FORMAT_R8G8_TYPELESS:					return L"DXGI_FORMAT_R8G8_TYPELESS";
		case DXGI_FORMAT_R8G8_UNORM:					return L"DXGI_FORMAT_R8G8_UNORM";
		case DXGI_FORMAT_R8G8_UINT:						return L"DXGI_FORMAT_R8G8_UINT";
		case DXGI_FORMAT_R8G8_SNORM:					return L"DXGI_FORMAT_R8G8_SNORM";
		case DXGI_FORMAT_R8G8_SINT:						return L"DXGI_FORMAT_R8G8_SINT";
		case DXGI_FORMAT_R16_TYPELESS:					return L"DXGI_FORMAT_R16_TYPELESS";
		case DXGI_FORMAT_R16_FLOAT:						return L"DXGI_FORMAT_R16_FLOAT";
		case DXGI_FORMAT_D16_UNORM:						return L"DXGI_FORMAT_D16_UNORM";
		case DXGI_FORMAT_R16_UNORM:						return L"DXGI_FORMAT_R16_UNORM";
		case DXGI_FORMAT_R16_UINT:						return L"DXGI_FORMAT_R16_UINT";
		case DXGI_FORMAT_R16_SNORM:						return L"DXGI_FORMAT_R16_SNORM";
		case DXGI_FORMAT_R16_SINT:						return L"DXGI_FORMAT_R16_SINT";
		case DXGI_FORMAT_R8_TYPELESS:					return L"DXGI_FORMAT_R8_TYPELESS";
		case DXGI_FORMAT_R8_UNORM:						return L"DXGI_FORMAT_R8_UNORM";
		case DXGI_FORMAT_R8_UINT:						return L"DXGI_FORMAT_R8_UINT";
		case DXGI_FORMAT_R8_SNORM:						return L"DXGI_FORMAT_R8_SNORM";
		case DXGI_FORMAT_R8_SINT:						return L"DXGI_FORMAT_R8_SINT";
		case DXGI_FORMAT_A8_UNORM:						return L"DXGI_FORMAT_A8_UNORM";
		case DXGI_FORMAT_R1_UNORM:						return L"DXGI_FORMAT_R1_UNORM";
		case DXGI_FORMAT_R9G9B9E5_SHAREDEXP:			return L"DXGI_FORMAT_R9G9B9E5_SHAREDEXP";
		case DXGI_FORMAT_R8G8_B8G8_UNORM:				return L"DXGI_FORMAT_R8G8_B8G8_UNORM";
		case DXGI_FORMAT_G8R8_G8B8_UNORM:				return L"DXGI_FORMAT_G8R8_G8B8_UNORM";
		case DXGI_FORMAT_BC1_TYPELESS:					return L"DXGI_FORMAT_BC1_TYPELESS";
		case DXGI_FORMAT_BC1_UNORM:						return L"DXGI_FORMAT_BC1_UNORM";
		case DXGI_FORMAT_BC1_UNORM_SRGB:				return L"DXGI_FORMAT_BC1_UNORM_SRGB";
		case DXGI_FORMAT_BC2_TYPELESS:					return L"DXGI_FORMAT_BC2_TYPELESS";
		case DXGI_FORMAT_BC2_UNORM:						return L"DXGI_FORMAT_BC2_UNORM";
		case DXGI_FORMAT_BC2_UNORM_SRGB:				return L"DXGI_FORMAT_BC2_UNORM_SRGB";
		case DXGI_FORMAT_BC3_TYPELESS:					return L"DXGI_FORMAT_BC3_TYPELESS";
		case DXGI_FORMAT_BC3_UNORM:						return L"DXGI_FORMAT_BC3_UNORM";
		case DXGI_FORMAT_BC3_UNORM_SRGB:				return L"DXGI_FORMAT_BC3_UNORM_SRGB";
		case DXGI_FORMAT_BC4_TYPELESS:					return L"DXGI_FORMAT_BC4_TYPELESS";
		case DXGI_FORMAT_BC4_UNORM:						return L"DXGI_FORMAT_BC4_UNORM";
		case DXGI_FORMAT_BC4_SNORM:						return L"DXGI_FORMAT_BC4_SNORM";
		case DXGI_FORMAT_BC5_TYPELESS:					return L"DXGI_FORMAT_BC5_TYPELESS";
		case DXGI_FORMAT_BC5_UNORM:						return L"DXGI_FORMAT_BC5_UNORM";
		case DXGI_FORMAT_BC5_SNORM:						return L"DXGI_FORMAT_BC5_SNORM";
		case DXGI_FORMAT_B5G6R5_UNORM:					return L"DXGI_FORMAT_B5G6R5_UNORM";
		case DXGI_FORMAT_B5G5R5A1_UNORM:				return L"DXGI_FORMAT_B5G5R5A1_UNORM";
		case DXGI_FORMAT_B8G8R8A8_UNORM:				return L"DXGI_FORMAT_B8G8R8A8_UNORM";
		case DXGI_FORMAT_B8G8R8X8_UNORM:				return L"DXGI_FORMAT_B8G8R8X8_UNORM";
		case DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM:	return L"DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM";
		case DXGI_FORMAT_B8G8R8A8_TYPELESS:				return L"DXGI_FORMAT_B8G8R8A8_TYPELESS";
		case DXGI_FORMAT_B8G8R8A8_UNORM_SRGB:			return L"DXGI_FORMAT_B8G8R8A8_UNORM_SRGB";
		case DXGI_FORMAT_B8G8R8X8_TYPELESS:				return L"DXGI_FORMAT_B8G8R8X8_TYPELESS";
		case DXGI_FORMAT_B8G8R8X8_UNORM_SRGB:			return L"DXGI_FORMAT_B8G8R8X8_UNORM_SRGB";
		case DXGI_FORMAT_BC6H_TYPELESS:					return L"DXGI_FORMAT_BC6H_TYPELESS";
		case DXGI_FORMAT_BC6H_UF16:						return L"DXGI_FORMAT_BC6H_UF16";
		case DXGI_FORMAT_BC6H_SF16:						return L"DXGI_FORMAT_BC6H_SF16";
		case DXGI_FORMAT_BC7_TYPELESS:					return L"DXGI_FORMAT_BC7_TYPELESS";
		case DXGI_FORMAT_BC7_UNORM:						return L"DXGI_FORMAT_BC7_UNORM";
		case DXGI_FORMAT_BC7_UNORM_SRGB:				return L"DXGI_FORMAT_BC7_UNORM_SRGB";
		default:										return L"DXGI_FORMAT_UNKNOWN";
	}
}


} // gfx


} // synkro
