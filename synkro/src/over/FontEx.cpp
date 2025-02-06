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
// Purpose: Overlay font implementation.
//==============================================================================
#include "config.h"
#include "FontEx.h"
#include "Overlay.h"
#include "Text.h"
#include <img/IImage.h>
#include <gfx/IProgram.h>
#include <gfx/IProgramStage.h>
#include <gfx/IVector2Stream.h>
#include <gfx/IVector3Stream.h>
#include <gfx/IVector4Stream.h>
#include <gfx/IParameterSet.h>
#include <gfx/IViewRenderWindowEx.h>
#include <gfx/IFrameRenderWindowEx.h>
#include <lang/GradientTypeConst.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace over
{


FontEx::FontEx( FontTemplate* temp, Overlay* overlay ) :
	_frames( A(P(IImage)) ),
	_texts( A(BaseText*) ),
	_template( temp ),
	_overlay( overlay ),
	_language( temp->_language ),
	_family( temp->_family ),
	_style( temp->_style ),
	_size( temp->_size ),
	_dh( 0.0f )
{
	_dh = _template->_imageHeight*_template->_glyphs[L'0'].Height();
	_resources = _overlay->_fontProgram->GetFragmentStage()->GetResources()->Clone( this->ID() );
	for ( UInt i = 0; i < _template->_images.Size(); ++i )
	{
		PixelFormat format = _overlay->GetRenderWindow()->GetPixelFormat();
		IImage* frame = (_template->_images[i]->GetFormat() != format) ? _template->_images[i]->Clone( format ) : _template->_images[i];
		frame->Prepare( format, 1 );
		_frames.Add( frame );
	}
	SetFrame( 0 );
}

IText* FontEx::CreateText( const ColorGradient& gradient, const Point& location, const String& text, const Order& groupOrder, const Order& order )
{
	return new Text( this, this, _overlay->_context, _overlay->_queue, groupOrder, order, location, text, gradient );
}

IText* FontEx::CreateText( const ColorGradient& gradient, const Point& location, const String& text )
{
	return CreateText( gradient, location, text, Order::Normal, Order::Normal );
}

IText* FontEx::CreateText( const Color& color, const Point& location, const String& text, const Order& groupOrder, const Order& order )
{
	return CreateText( ColorGradient(GradientType::Horizontal, color, color), location, text, groupOrder, order );
}

IText* FontEx::CreateText( const Color& color, const Point& location, const String& text )
{
	return CreateText( color, location, text, Order::Normal, Order::Normal );
}

void FontEx::GetTextSize( const String& text, Size& size ) const
{
	_template->GetTextSize( text, size );
}

void FontEx::AddText( BaseText* text )
{
	_texts.Add( text );
}

void FontEx::RemoveText( BaseText* text )
{
	_texts.Remove( text );
}

void FontEx::InvalidateTexts()
{
	// Do nothing.
}

void FontEx::Update()
{
	_texts.Each( *this );
}

void FontEx::SetFrame( UInt frame )
{
	assert( frame < _frames.Size() );
	
	_resources->Set( 0, _frames[frame]->AsResource() );
}

UInt FontEx::GetTextCapacity( const String& text )
{
	UInt glyphCount = 0;
	const UInt length = text.Length();
	for ( UInt i = 0; i < length; ++i )
	{
		if ( _template->_glyphs.ContainsKey(text[i]) )
		{
			++glyphCount;
		}
	}
	return glyphCount;
}

IOverlayRenderObject* FontEx::CreateText( IOverlayRenderQueue* queue, UInt capacity, UInt order )
{
	IPrimitive* data = _overlay->_context->GetGraphicsSystem()->GetDevice()->CreatePrimitive( _overlay->_fontProgram, DataUsage::Dynamic, DataAccess::WriteOnly, PrimitiveType::TriangleList, IndexType::None, 6*capacity, 0, 0, 0, true, false );
	IOverlayRenderObject* obj = queue->CreateObject( data );
	obj->EnableSmoothing( _size > 13 );
	obj->SetBlendStates( _overlay->_blendStates );
	obj->SetFragmentResources( _resources );
	obj->SetOrder( order );
	return obj;
}

UInt FontEx::DrawText( const TextBuffer& buffer, const TextDesc& desc, UInt start )
{
	if ( !buffer.IsValid() || desc.Text.IsEmpty() || desc.Text.IsNull() )
		return 0;	

	// Fill data streams.
	Float x = desc.Location.X;
	Float y = desc.Location.Y;
	Size size; GetTextSize( desc.Text, size );
	buffer.StreamPosition->SetPosition( start*6 );
	buffer.StreamTexCoord->SetPosition( start*6 );
	buffer.StreamColor->SetPosition( start*6 );
	UInt glyphCount = 0;
	Vector4 colors[6];

	const UInt length = desc.Text.Length();
	const Float x0 = desc.CenterEnabled ? desc.Center.X : x + 0.5f*desc.Scale*size.Width;
	const Float y0 = desc.CenterEnabled ? desc.Center.Y : y + 0.5f*desc.Scale*size.Height;
	const Float x00 = desc.CenterEnabled ? desc.Center.X : x;
	const Float y00 = desc.CenterEnabled ? desc.Center.Y : y;
	const Float s = Math::Sin( desc.Orientation );
	const Float c = Math::Cos( desc.Orientation );
	Double d1 = 0.0; Float r1 = 0.0f; Float g1 = 0.0f; Float b1 = 0.0f; Float a1 = 0.0f;
	Double d2 = 0.0; Float r2 = 0.0f; Float g2 = 0.0f; Float b2 = 0.0f; Float a2 = 0.0f;
	Char ch = L'\0';

	for ( UInt i = 0; i < length; ++i )
	{
		ch = desc.Text[i];
		a1 = desc.Opacity;
		a2 = desc.Opacity;
		if ( _template->_glyphs.ContainsKey(ch) )
		{
			++glyphCount;
			const RectF glyph = _template->_glyphs[ch];
			const Float dx = _template->_imageWidth * glyph.Width();
			const Float dy = _template->_imageHeight * glyph.Height();

			// Set positions.
			Vector4 pos[] =
			{
				Vector4( x,		y,		0.0f, 1.0f ),
				Vector4( x+dx,	y,		0.0f, 1.0f ),
				Vector4( x+dx,	y+dy,	0.0f, 1.0f ),
				Vector4( x,		y,		0.0f, 1.0f ),
				Vector4( x+dx,	y+dy,	0.0f, 1.0f ),
				Vector4( x,		y+dy,	0.0f, 1.0f ),
			};
			if ( desc.Scale != 1.0f )
			{
				pos[5].x = pos[3].x = pos[0].x = x00 + desc.Scale*(pos[0].x-x00);
				pos[3].y = pos[1].y = pos[0].y = y00 + desc.Scale*(pos[0].y-y00);
				pos[4].x = pos[2].x = pos[1].x = x00 + desc.Scale*(pos[1].x-x00);
				pos[5].y = pos[4].y = pos[2].y = y00 + desc.Scale*(pos[2].y-y00);
			}
			if ( desc.Orientation != 0.0f )
			{
				for ( UInt i = 0; i < 6; ++i )
				{
					const Float x1 = pos[i].x;
					const Float y1 = pos[i].y;
					pos[i].x = (x1 - x0)*c - (y1 - y0)*s + x0;
					pos[i].y = (x1 - x0)*s + (y1 - y0)*c + y0;
				}
			}
			buffer.StreamPosition->Write( pos, 6 );

			// Set texture coordinates.
			Vector2 coords[] = 
			{
				Vector2( glyph.Left,	glyph.Top ),
				Vector2( glyph.Right,	glyph.Top ),
				Vector2( glyph.Right,	glyph.Bottom ),
				Vector2( glyph.Left,	glyph.Top ),
				Vector2( glyph.Right,	glyph.Bottom ),
				Vector2( glyph.Left,	glyph.Bottom ),
			};
			buffer.StreamTexCoord->Write( coords, 6 );

			// Set colors.
			if ( desc.Gradient.Start != desc.Gradient.End )
			{
				switch ( desc.Gradient.Type )
				{
					case GRADIENT_TYPE_HORIZONTAL:
						d1 = (x-desc.Location.X)/size.Width;
						r1 = Lerp( desc.Gradient.Start.R, desc.Gradient.End.R, d1 );
						g1 = Lerp( desc.Gradient.Start.G, desc.Gradient.End.G, d1 );
						b1 = Lerp( desc.Gradient.Start.B, desc.Gradient.End.B, d1 );

						d2 = (x+dx-desc.Location.X)/size.Width;
						r2 = Lerp( desc.Gradient.Start.R, desc.Gradient.End.R, d2 );
						g2 = Lerp( desc.Gradient.Start.G, desc.Gradient.End.G, d2 );
						b2 = Lerp( desc.Gradient.Start.B, desc.Gradient.End.B, d2 );

						colors[0] = Vector4( r1, g1, b1, a1 );
						colors[1] = Vector4( r2, g2, b2, a2 );
						colors[2] = Vector4( r2, g2, b2, a2 );
						colors[3] = Vector4( r1, g1, b1, a1 );
						colors[4] = Vector4( r2, g2, b2, a2 );
						colors[5] = Vector4( r1, g1, b1, a1 );
						break;

					case GRADIENT_TYPE_VERTICAL:
						d1 = (y-desc.Location.Y)/size.Height;
						r1 = Lerp( desc.Gradient.Start.R, desc.Gradient.End.R, d1 );
						g1 = Lerp( desc.Gradient.Start.G, desc.Gradient.End.G, d1 );
						b1 = Lerp( desc.Gradient.Start.B, desc.Gradient.End.B, d1 );

						d2 = (y+dy-desc.Location.Y)/size.Height;
						r2 = Lerp( desc.Gradient.Start.R, desc.Gradient.End.R, d2 );
						g2 = Lerp( desc.Gradient.Start.G, desc.Gradient.End.G, d2 );
						b2 = Lerp( desc.Gradient.Start.B, desc.Gradient.End.B, d2 );

						colors[0] = Vector4( r1, g1, b1, a1 );
						colors[1] = Vector4( r1, g1, b1, a1 );
						colors[2] = Vector4( r2, g2, b2, a2 );
						colors[3] = Vector4( r1, g1, b1, a1 );
						colors[4] = Vector4( r2, g2, b2, a2 );
						colors[5] = Vector4( r2, g2, b2, a2 );
						break;
				}
				buffer.StreamColor->Write( colors, 6 );
			}
			else
			{
				Vector4 col = ToVector( desc.Gradient.Start, desc.Opacity );
				colors[0] = col;
				colors[1] = col;
				colors[2] = col;
				colors[3] = col;
				colors[4] = col;
				colors[5] = col;
				buffer.StreamColor->Write( colors, 6 );
			}

			// Advance to next character.
			x += dx;

			// Handle text wrapping.
			if ( desc.Wrapped && !desc.Rect.IsEmpty() )
			{
				if ( x >= desc.Rect.Right )
				{
					x = desc.Location.X;
					y += CastFloat(size.Height);
				}
				if ( y >= desc.Rect.Bottom )
					break;
			}
		}
		else
		{
			// Handle whitespace characters.
			switch ( ch )
			{
				case L'\t':
					// Treat 2/10 (20%) of text height as space width.
					x += _dh*0.2f*8.0f;
					break;

				case L'\r':
					x = desc.Location.X;
					break;

				case L'\n':
					y += _dh;
					break;

				default:
					x += _dh*0.2f;
					break;
			}
		}
	}

	return glyphCount;
}

void FontEx::UpdateColor( IOverlayRenderObject* obj, const Color& color, Float opacity )
{
	P(IVector4Stream) streamColor = (IVector4Stream*)obj->GetData()->GetVertexStream( DataStream::Color, 0 );
	if ( streamColor->Open(OpenMode::Write) )
	{
		streamColor->SetPosition( 0 );
		streamColor->Set( ToVector(color, opacity), obj->GetElementCount() );
		streamColor->Close();
	}
}


} // over


} // synkro
