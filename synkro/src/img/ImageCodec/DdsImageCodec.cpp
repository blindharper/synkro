//==============================================================================
// This file stream a part of the Synkro Project.
// 
// Copyright (c) Nobody. No rights reserved ;-7
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is allowed without any permission from the Synkro Project.
// Website: https://synkro.pro Email: mailto:blindharper70@gmail.com
//
// Purpose: Implements DDS image codec.
//==============================================================================
#include "config.h"
#include "DdsImageCodec.h"
#include "DdsImageCodecContext.h"
#include <internal/SizeOf.h>
#include <math/Math.h>
#include <d3d9.h>
#include <d3d10.h>


//------------------------------------------------------------------------------

using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


// "DDS "
#define DDS_MAGIC					0x20534444

// DDS_HEADER.dwFlags
#define DDSD_CAPS					0x00000001
#define DDSD_HEIGHT					0x00000002
#define DDSD_WIDTH					0x00000004
#define DDSD_PITCH					0x00000008
#define DDSD_PIXELFORMAT			0x00001000
#define DDSD_MIPMAPCOUNT			0x00020000
#define DDSD_LINEARSIZE				0x00080000
#define DDSD_DEPTH					0x00800000
#define DDSD_REQUIRED ( DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH | DDSD_PIXELFORMAT )

// DDS_HEADER.dwCaps2
#define DDSCAPS2_CUBEMAP			0x00000200
#define DDSCAPS2_CUBEMAP_POSITIVEX	0x00000400
#define DDSCAPS2_CUBEMAP_NEGATIVEX	0x00000800
#define DDSCAPS2_CUBEMAP_POSITIVEY	0x00001000
#define DDSCAPS2_CUBEMAP_NEGATIVEY	0x00002000
#define DDSCAPS2_CUBEMAP_POSITIVEZ	0x00004000
#define DDSCAPS2_CUBEMAP_NEGATIVEZ	0x00008000
#define DDS_CUBEMAP_ALLFACES ( DDSCAPS2_CUBEMAP_POSITIVEX | DDSCAPS2_CUBEMAP_NEGATIVEX |\
                               DDSCAPS2_CUBEMAP_POSITIVEY | DDSCAPS2_CUBEMAP_NEGATIVEY |\
                               DDSCAPS2_CUBEMAP_POSITIVEZ | DDSCAPS2_CUBEMAP_NEGATIVEZ )
#define DDSCAPS2_VOLUME				0x00200000

// DDS_PIXELFORMAT.dwFlags
#define DDPF_ALPHAPIXELS			0x00000001
#define DDPF_ALPHA					0x00000002
#define DDPF_FOURCC					0x00000004
#define DDPF_RGB					0x00000040
#define DDPF_LUMINANCE				0x00020000

struct DDS_PIXELFORMAT
{
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwFourCC;
    DWORD dwRGBBitCount;
    DWORD dwRBitMask;
    DWORD dwGBitMask;
    DWORD dwBBitMask;
    DWORD dwABitMask;
};

struct DDS_HEADER
{
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwHeight;
    DWORD dwWidth;
    DWORD dwLinearSize;
    DWORD dwDepth;
    DWORD dwMipMapCount;
    DWORD dwReserved1[11];
    DDS_PIXELFORMAT ddpf;
    DWORD dwCaps;
    DWORD dwCaps2;
    DWORD dwCaps3;
    DWORD dwCaps4;
    DWORD dwReserved2;
} hdr;

struct DDS_HEADER_DXT10
{
    DXGI_FORMAT dxgiFormat;
    D3D10_RESOURCE_DIMENSION resourceDimension;
    UINT miscFlag;
    UINT arraySize;
    UINT reserved;
};
DDS_HEADER_DXT10* hdr10 = nullptr; 


//------------------------------------------------------------------------------


namespace synkro
{


namespace img
{


struct FormatPair
{
	DXGI_FORMAT dxgiFormat;
	PixelFormat imgFormat;
};
static FormatPair _pairs[] =
{
	{ DXGI_FORMAT_R8G8B8A8_UNORM,		PixelFormat::R8G8B8A8 },
	{ DXGI_FORMAT_R32G32B32A32_FLOAT,	PixelFormat::R32G32B32A32F },
	{ DXGI_FORMAT_R32G32_FLOAT,			PixelFormat::R32G32F },
	{ DXGI_FORMAT_R16G16B16A16_UNORM,	PixelFormat::R16G16B16A16 },
	{ DXGI_FORMAT_R16G16B16A16_FLOAT,	PixelFormat::R16G16B16A16F },
	{ DXGI_FORMAT_R32_FLOAT,			PixelFormat::R32F },
	{ DXGI_FORMAT_R10G10B10A2_UNORM,	PixelFormat::R10G10B10A2 },
	{ DXGI_FORMAT_R16G16_FLOAT,			PixelFormat::R16G16F },
	{ DXGI_FORMAT_R16G16_UNORM,			PixelFormat::R16G16 },
	{ DXGI_FORMAT_R16_FLOAT,			PixelFormat::R16F },
	{ DXGI_FORMAT_B5G5R5A1_UNORM,		PixelFormat::R5G5B5A1 },
	{ DXGI_FORMAT_B5G6R5_UNORM,			PixelFormat::R5G6B5 },
	{ DXGI_FORMAT_A8_UNORM,				PixelFormat::A8 },
};
const UInt _pairCount = SizeOf( _pairs );

//------------------------------------------------------------------------------


DdsImageCodec::DdsImageCodec( Float quality ) :
	ImageCodecImpl<IImageCodec>( quality )
{
}

ImageCodecContext* DdsImageCodec::CreateContext()
{
	return new DdsImageCodecContext();
}

void DdsImageCodec::Save( ImageCodecContext* context )
{
	throw NotSupportedException( L"Method Save() is not implemented for DDS image codec." );
}

Bool DdsImageCodec::SupportsMipmaps() const
{
	return true;
}

void DdsImageCodec::BeginLoad( io::IStream* stream, ImageCodecContext* context )
{
	DdsImageCodecContext* ctx = (DdsImageCodecContext*)(ImageCodecContextEx*)context;

	// Read magic number.
	UInt magic;
	Read( context, stream, &magic, sizeof(UInt) );
	if ( magic != DDS_MAGIC )
		throw Exception( L"Bad DDS magic number." );

	// Read header.
	UInt bytesRead = Read( context, stream, &hdr, sizeof(hdr) );
	if ( bytesRead < sizeof(hdr) )
		throw Exception( L"DDS header is too short." );

	if ( hdr.dwSize != sizeof(DDS_HEADER) )
		throw Exception( L"Bad DDS header." );

	if ( hdr.ddpf.dwSize != sizeof(DDS_PIXELFORMAT) )
		throw Exception( L"Bad DDS header." );

	// Verify required flags.
	if ( (hdr.dwFlags & DDSD_REQUIRED) == 0 )
		throw Exception( L"Bad DDS file." );

	// Require that all cubemap faces are specified.
	if ( (hdr.dwCaps2 & DDSCAPS2_CUBEMAP) && ((hdr.dwCaps2 & DDS_CUBEMAP_ALLFACES) == 0) )
		throw Exception( L"DDS file is missing at least one of the cubemap faces." );

	// Read DX10 header, if available.
	DDS_HEADER_DXT10 tmp;
	if ( (hdr.ddpf.dwFlags & DDPF_FOURCC) && (hdr.ddpf.dwFourCC == MAKEFOURCC('D', 'X', '1', '0')) )
	{
		bytesRead = Read( context, stream, &tmp, sizeof(tmp) );
		if ( bytesRead < sizeof(tmp) )
			throw Exception( L"DDS header is too short." );

		hdr10 = &tmp;
	}

	// Get image properties.
	ctx->CellSize = 0;
	ctx->Width = hdr.dwWidth;
	ctx->Height = hdr.dwHeight;
	ctx->Depth = (hdr.dwFlags & DDSD_DEPTH) ? hdr.dwDepth : 1;
	ctx->Stride = (hdr.dwFlags & DDSD_PITCH) ? hdr.dwLinearSize : 0;
	ctx->ElementCount = (hdr10 != nullptr) ? hdr10->arraySize : 1;
	ctx->LevelCount = (hdr.dwFlags & DDSD_MIPMAPCOUNT) ? hdr.dwMipMapCount : 1;
	ctx->Size = ctx->Height * ctx->Stride;
	if ( hdr.dwFlags & DDSD_LINEARSIZE )
	{
		ctx->Size = hdr.dwLinearSize;
	}
	else if ( hdr.ddpf.dwFlags & DDPF_FOURCC )
	{
		ctx->Size = CastUInt(Math::Max(1.0f, CastFloat(ctx->Width*0.25f))) * CastUInt(Math::Max(1.0f, CastFloat(ctx->Height*0.25f))) * 8;
		if ( hdr.ddpf.dwFourCC == MAKEFOURCC('D', 'X', 'T', '1') )
		{
			ctx->Size *= 2;
		}
	}
	else if ( hdr.dwFlags & DDSD_PIXELFORMAT )
	{
		ctx->Stride = ctx->Width * (hdr.ddpf.dwRGBBitCount >> 3);
		ctx->Size = ctx->Stride * ctx->Height;
	}

	// Determine texture pixel format and create image.
	ctx->DstFormat = GetImageFormat( context );
	ctx->DstStride = ctx->Width * ctx->DstFormat.BytesPerPixel();
	ctx->SrcFormat = PixelFormat::Unknown;

	// Handle DX10-compatible formats.
	if ( hdr10 != nullptr )
	{
		for ( UInt i = 0; i < _pairCount; ++i )
		{
			if ( _pairs[i].dxgiFormat == hdr10->dxgiFormat )
			{
				ctx->SrcFormat = _pairs[i].imgFormat;
				break;
			}
		}
	}
	// Handle compressed formats.
	else if ( hdr.ddpf.dwFlags & DDPF_FOURCC )
	{
		switch ( hdr.ddpf.dwFourCC )
		{
		case MAKEFOURCC('D', 'X', 'T', '1'):
		case MAKEFOURCC('D', 'X', 'T', '2'):
			ctx->SrcFormat = PixelFormat::BC1;
			ctx->Stride = 2 * ctx->Width;
			ctx->CellSize = 8;
			break;

		case MAKEFOURCC('D', 'X', 'T', '3'):
			ctx->SrcFormat = PixelFormat::BC2;
			ctx->Stride = 4 * ctx->Width;
			ctx->CellSize = 16;
			break;

		case MAKEFOURCC('D', 'X', 'T', '4'):
		case MAKEFOURCC('D', 'X', 'T', '5'):
			ctx->SrcFormat = PixelFormat::BC3;
			ctx->Stride = 4 * ctx->Width;
			ctx->CellSize = 16;
			break;

		case D3DFMT_A16B16G16R16:
			ctx->SrcFormat = PixelFormat::R16G16B16A16;
			ctx->CellSize = 8;
			break;

		case D3DFMT_R16F:
			ctx->SrcFormat = PixelFormat::R16F;
			ctx->CellSize = 2;
			break;

		case D3DFMT_G16R16F:
			ctx->SrcFormat = PixelFormat::R16G16F;
			ctx->CellSize = 4;
			break;

		case D3DFMT_A16B16G16R16F:
			ctx->SrcFormat = PixelFormat::R16G16B16A16F;
			ctx->CellSize = 8;
			break;

		case D3DFMT_R32F:
			ctx->SrcFormat = PixelFormat::R32F;
			ctx->CellSize = 4;
			break;

		case D3DFMT_G32R32F:
			ctx->SrcFormat = PixelFormat::R32G32F;
			ctx->CellSize = 8;
			break;

		case D3DFMT_A32B32G32R32F:
			ctx->SrcFormat = PixelFormat::R32G32B32A32F;
			ctx->CellSize = 16;
			break;

		default:
			break;
		}
	}
	// Handle RGB(A) formats.
	else if ( hdr.ddpf.dwFlags & DDPF_RGB )
	{
		const UInt alpha = (hdr.ddpf.dwFlags & DDPF_ALPHAPIXELS) ? hdr.ddpf.dwABitMask : 0;
		ctx->SrcFormat = PixelFormat( hdr.ddpf.dwRBitMask, hdr.ddpf.dwGBitMask, hdr.ddpf.dwBBitMask, alpha );
	}
	if ( ctx->SrcFormat == PixelFormat::Unknown )
		throw Exception( L"Unsupported pixel format." );

	// Set destination format.
	if ( ctx->DstFormat == PixelFormat::Unknown )
	{
		ctx->DstFormat = ctx->SrcFormat;
	}
	SetImageFormat( context, ctx->DstFormat );
}

void DdsImageCodec::LoadSurface( io::IStream* stream, ImageCodecContext* context )
{
	DdsImageCodecContext* ctx = (DdsImageCodecContext*)(ImageCodecContextEx*)context;

	if ( (hdr.dwFlags & DDSD_DEPTH) && (hdr.dwCaps2 & DDSCAPS2_VOLUME) )
	{
		for ( UInt e = 0; e < ctx->Depth; ++e )
		{
			UInt w = ctx->Width; UInt h = ctx->Height; UInt str = ctx->Stride; UInt sz = ctx->Size;
			Byte* data = CreateSurface( context, w, h, str, nullptr, sz );
			Read( context, stream, data, ctx->Size );
			for ( UInt l = 1; l < ctx->LevelCount; ++l )
			{
				sz = GetNextLevel( w, h, str, ctx->CellSize, ctx->SrcFormat );
				data = CreateSurface( context, w, h, str, nullptr, sz );
				Read( context, stream, data, sz );
			}
		}
		SetImageType( context, ImageType::Volume );
	}
	else if ( hdr.dwCaps2 & DDSCAPS2_CUBEMAP )
	{
		for ( UInt f = 0; f < 6; ++f )
		{
			UInt w = ctx->Width; UInt h = ctx->Height; UInt str = ctx->Stride; UInt sz = ctx->Size;
			Byte* data = CreateSurface( context, w, h, str, nullptr, sz );
			Read( context, stream, data, ctx->Size );
			for ( UInt l = 1; l < ctx->LevelCount; ++l )
			{
				sz = GetNextLevel( w, h, str, ctx->CellSize, ctx->SrcFormat );
				data = CreateSurface( context, w, h, str, nullptr, sz );
				Read( context, stream, data, sz );
			}
		}
		SetImageType( context, ImageType::Cube );
	}
	else
	{
		// Allocate buffer for scanline.
		Vector<Byte> buffer( A(Byte), ctx->Stride );
		buffer.SetSize( ctx->Stride );
		Byte* scanline = buffer.Begin();

		for ( UInt e = 0; e < ctx->ElementCount; ++e )
		{
			UInt w = ctx->Width; UInt h = ctx->Height; UInt str = ctx->Stride; UInt sz = ctx->Size;
			Byte* data = CreateSurface( context, w, h, str, nullptr, sz );
			if ( ctx->DstFormat == ctx->SrcFormat )
			{
				Read( context, stream, data, ctx->Size );
			}
			else if ( ctx->SrcFormat.IsCompressed() )
			{
				// NB: Uncompress
			}
			else
			{
				for ( UInt j = 0; j < ctx->Height; ++j )
				{
					Read( context, stream, scanline, ctx->Stride );
					Byte* dstline = (Byte*)(data + j*ctx->DstStride);
					PixelFormatEx::CopyPixels( dstline, ctx->DstFormat, scanline, ctx->SrcFormat, ctx->Width );
				}
			}
			
			for ( UInt l = 1; l < ctx->LevelCount; ++l )
			{
				sz = GetNextLevel( w, h, str, ctx->CellSize, ctx->SrcFormat );
				data = CreateSurface( context, w, h, str, nullptr, sz );
				if ( ctx->DstFormat == ctx->SrcFormat )
				{
					Read( context, stream, data, sz );
				}
				else if ( ctx->SrcFormat.IsCompressed() )
				{
					// NB: Uncompress
				}
				else
				{
					// NB:
				}
			}
		}

		const ImageType type = ((hdr10 != nullptr) && (hdr10->resourceDimension == D3D10_RESOURCE_DIMENSION_TEXTURE1D)) ? ImageType::Linear : ImageType::Plain;
		SetImageType( context, type );
	}
}

void DdsImageCodec::SaveSurface( io::IStream* stream, const Byte* data, ImageCodecContext* context )
{
	// Do nothing.
}

UInt DdsImageCodec::GetNextLevel( UInt& width, UInt& height, UInt& stride, UInt cellSize, const PixelFormat& format )
{
	UInt size = 0; UInt w = width; UInt h = height;

	w = (w/2 < 1) ? 1 : w/2;
	h = (h/2 < 1) ? 1 : h/2;

	if ( format.IsCompressed() )
	{
		size = CastUInt( Math::Max(1.0f, CastFloat(w*0.25f)) ) * CastUInt( Math::Max(1.0f, CastFloat(h*0.25f)) );
		size *= cellSize;
	}
	else
	{
		size = w*h*format.BytesPerPixel();
	}

	width = w;
	height = h;
	stride = GetStride( w, format );

	return size;
}

UInt DdsImageCodec::GetStride( UInt width, const PixelFormat& format )
{
	UInt stride = 0;

	if ( format == PixelFormat::BC1 )
		stride = 2 * width;
	else if ( (format == PixelFormat::BC2) || (format == PixelFormat::BC3) )
		stride = 4 * width;
	else if ( !format.IsCompressed() )
		stride = format.BytesPerPixel() * width;

	stride = (stride+3) & ~3;
	return stride;
}


} // img


} // synkro
