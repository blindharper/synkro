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
// Purpose: Overlay font template.
//==============================================================================
#include "config.h"
#include "FontTemplate.h"
#include <img/PixelFormatEx.h>
#include <lang/Exception.h>
#include <internal/Zero.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::img;
using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace over
{


FontTemplate::FontTemplate( const Language& language, IImageManager* imageManager, const String& family, const FontStyle& style, UInt size ) :
	_glyphs( A(GlyphEntry) ),
	_images( A(P(IImage)) ),
	_resource( nullptr ),
	_imageManager( imageManager ),
	_language( language ),
	_family( family ),
	_style( style ),
	_size( size ),
	_imageWidth( 0 ),
	_imageHeight( 0 ),
	_dy( 0.0f )
{
}

FontTemplate::FontTemplate( const Language& language, IImageManager* imageManager, IStreamDirectory* resource, const String& image, const String& alpha ) :
	_glyphs( A(GlyphEntry) ),
	_images( A(P(IImage)) ),
	_resource( resource ),
	_imageManager( imageManager ),
	_language( language ),
	_imageName( image ),
	_alphaName( alpha ),
	_style( FontStyle::Normal ),
	_size( 0 ),
	_imageWidth( 0 ),
	_imageHeight( 0 ),
	_dy( 0.0f )
{
}

FontTemplate::FontTemplate() :
	_glyphs( A(GlyphEntry) ),
	_images( A(P(IImage)) ),
	_resource( nullptr ),
	_imageManager( nullptr ),
	_imageWidth( 0 ),
	_imageHeight( 0 ),
	_dy( 0.0f )
{
}

void FontTemplate::Prepare()
{
	if ( _glyphs.Size() != 0 )
		return;

	if ( _resource != nullptr )
	{
		IStreamDirectory* dir = _resource->GetDirectory( _imageName );
		IStream* streamAlpha = _resource->GetStream( _alphaName );
		if ( dir != nullptr )
		{
			for ( UInt i = 0; i < dir->GetStreamCount(); ++i )
			{
				_images.Add( LoadFontImage(dir->GetStream(i), streamAlpha) );
			}
		}
		else
		{
			_images.Add( LoadFontImage(_resource->GetStream(_imageName), streamAlpha) );
		}
		Prepare( _images[0] );
	}
	else
	{
		Prepare( _imageManager, _family, _style, _size );
	}
}

void FontTemplate::GetTextSize( const String& text, Size& size ) const
{
	Float width = 0.0f; Float height = 0.0f;
	Float x = 0.0f; Float y = 0.0f;
	
	for ( UInt i = 0; i < text.Length(); ++i )
	{
		const Char ch = text[i];
		if ( _glyphs.ContainsKey(ch) )
		{
			const RectF& rect = _glyphs[ch];
			x += _imageWidth * rect.Width();
			y = _dy;
			if ( y > height )
			{
				height = y;
			}
		}
		else
		{
			// Handle whitespace characters.
			switch ( ch )
			{
				case L'\t':
					x += _dy*0.2f*8.0f;
					break;

				case L'\r':
					x = 0.0f;
					break;

				case L'\n':
					height += _dy;
					break;

				default:
					x += _dy*0.2f;
					break;
			}
		}
		if ( x > width )
		{
			width = x;
		}
	}
	size.Width	= width;
	size.Height	= height;
}

void FontTemplate::Prepare( IImageManager* imageManager, const String& family, const FontStyle& style, UInt size )
{
	// Create in-memory texture.
	UInt width = 512;
	UInt height = 512;

	if ( size > 40 )
		width = height = 2048;
	else if ( size > 20 )
		width = height = 1024;

	_imageWidth = width;
	_imageHeight = height;

	// Create a new texture for the font.
	PixelFormat fmt = PixelFormat::R8G8B8A8;
	IImage* image = imageManager->CreateImage( fmt );
	if ( image == nullptr )
		throw Exception( L"Failed to create font texture." );

	image->AddElement( width, height, width*fmt.BytesPerPixel(), nullptr, width*height*fmt.BytesPerPixel() );

#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )

	// Prepare to create a bitmap.
	DWORD* pBitmapBits;
	BITMAPINFO bmi;
	Zero( &bmi.bmiHeader );
	bmi.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biWidth       =  (LONG)width;
	bmi.bmiHeader.biHeight      = -(LONG)height;
	bmi.bmiHeader.biPlanes      = 1;
	bmi.bmiHeader.biCompression = BI_RGB;
	bmi.bmiHeader.biBitCount    = 32;

	// Create a DC and a bitmap for the font
	HDC hDC = ::CreateCompatibleDC( nullptr );
	HBITMAP hbmBitmap = ::CreateDIBSection( hDC, &bmi, DIB_RGB_COLORS, (VOID**)&pBitmapBits, nullptr, 0 );
	::SetMapMode( hDC, MM_TEXT );

	// Create a font.
	Char name[260] = {};
	family.GetChars( 0, 260, name );
	const INT nHeight    = -::MulDiv( size, (INT)(::GetDeviceCaps(hDC, LOGPIXELSY)), 72 );
	const DWORD dwBold   = style.IsSet(FontStyle::Bold) ? FW_BOLD : FW_NORMAL;
	const DWORD dwItalic = style.IsSet(FontStyle::Italic) ? TRUE : FALSE;
	const DWORD dwUnderline = style.IsSet(FontStyle::Underline) ? TRUE : FALSE;
	const DWORD dwStrikeout = style.IsSet(FontStyle::Strikeout) ? TRUE : FALSE;
	HFONT hFont = ::CreateFontW( nHeight, 0, 0, 0, dwBold, dwItalic, dwUnderline, dwStrikeout, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, VARIABLE_PITCH, name );
	if ( hFont == nullptr )
		throw Exception( L"Failed to create font." );

	// Set text properties.
	::SelectObject( hDC, hbmBitmap );
	::SelectObject( hDC, hFont );
	::SetTextColor( hDC, RGB(255,255,255) );
	::SetBkColor( hDC, 0x00000000 );
	::SetTextAlign( hDC, TA_TOP );

	// Loop through all printable character and output them to the bitmap.
	// Meanwhile, keep track of the corresponding tex coords for each character.
	DWORD x = 0;
	DWORD y = 0;
	SIZE sz;

	const UInt cnt = _language.CharCount();
	for ( UInt i = 0; i < cnt; ++i )
	{
		const Char ch = _language.GetChar( i );
		::GetTextExtentPoint32( hDC, &ch, 1, &sz );

		if ( (x+sz.cx+2) > width )
		{
			x = 0;
			y += sz.cy+1;
		}

		::ExtTextOut( hDC, x, y, ETO_OPAQUE, nullptr, &ch, 1, nullptr );

		const RectF rc = RectF
		(
			CastFloat(x)/CastFloat(width), 
			CastFloat(y)/CastFloat(height), 
			CastFloat(x+sz.cx)/CastFloat(width),
			CastFloat(y+sz.cy)/CastFloat(height) 
		);
		_glyphs[ch] = rc;
		x += sz.cx+2;
	}

	UInt* p = (UInt*)image->GetElement();
	for ( UInt y = 0; y < height; ++y )
	{
		for ( UInt x = 0; x < width; ++x )
		{
			*p++ = (pBitmapBits[width*y + x] | 0xff000000);
		}
	}

	::DeleteObject( hbmBitmap );
	::DeleteDC( hDC );
	::DeleteObject( hFont );

#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS

	image->SetTransparentColor();
	_images.Add( image );

	_dy = _imageHeight*_glyphs['0'].Height();
}

void FontTemplate::Prepare( IImage* image )
{
	_imageWidth = image->GetWidth();
	_imageHeight = image->GetHeight();
	PixelFormatEx::ExtractGlyphs( image->GetElement(), image->GetFormat(), image->GetWidth(), image->GetHeight(), image->GetStride(), _language, _glyphs );
}

IImage* FontTemplate::LoadFontImage( IStream* streamImage, IStream* streamAlpha ) const
{
	PixelFormat format = PixelFormat::R8G8B8A8;
	IImage* imgImage = _imageManager->LoadImage( streamImage, format );
	if ( streamAlpha != nullptr )
	{
		format = PixelFormat::A8;
		IImage* imgAlpha = _imageManager->LoadImage( streamAlpha, format );
		imgImage->SetAlpha( imgAlpha );
	}
	else
	{
		imgImage->SetTransparentColor();
	}
	return imgImage;
}


} // over


} // synkro
