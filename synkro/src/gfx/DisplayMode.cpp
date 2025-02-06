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
// Purpose: Defines display mode.
//==============================================================================
#include "config.h"
#include <gfx/DisplayMode.h>
#include <lang/OutOfRangeException.h>
#include <lang/Formatter.h>
#include <lang/Parser.h>
#include <math/Math.h>
#include <internal/SizeOf.h>
#include <internal/Sort.h>
#include <internal/Zero.h>
#include "AspectConst.h"
#include "DisplayModeFormatConst.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


static UInt GetW( const Aspect& aspect )
{
	switch ( aspect )
	{
		case ASPECT_2X1:	return 2;
		case ASPECT_3X2:	return 3;
		case ASPECT_4X3:	return 4;
		case ASPECT_5X4:	return 5;
		case ASPECT_8X5:	return 8;
		case ASPECT_16X9:	return 16;
	}
	return 0;
}

static UInt GetH( const Aspect& aspect )
{
	switch ( aspect )
	{
		case ASPECT_2X1:	return 1;
		case ASPECT_3X2:	return 2;
		case ASPECT_4X3:	return 3;
		case ASPECT_5X4:	return 4;
		case ASPECT_8X5:	return 5;
		case ASPECT_16X9:	return 9;
	}
	return 0;
}

static Float GetAspect( UInt width, UInt height )
{
	const Float aspect = CastFloat(width)/CastFloat(height);
	return 0.01f*Math::Round( 100.0f*aspect );
}

static Aspect CalculateAspect( UInt width, UInt height )
{
	if ( height == 0 )
		return Aspect::Unknown;

	const Float aspect = GetAspect( width, height );

	static Float aspects[] =
	{
		Math::MaxFloat,
		GetAspect(2, 1),
		GetAspect(3, 2),
		GetAspect(4, 3),
		GetAspect(5, 4),
		GetAspect(8, 5),
		GetAspect(16, 9),
	};

	UInt idxMin = 0;
	Float diffMin = Math::MaxFloat;
	constexpr UInt cnt = SizeOf( aspects );
	for ( UInt i = 1; i < cnt; ++i )
	{
		const Float diff = Math::Abs( aspects[i] - aspect );
		if ( diff < diffMin )
		{
			diffMin = diff;
			idxMin = i;
		}
	}

	return Aspect( idxMin );
}
	
class DisplayModeList
{
public:
	DisplayModeList() :
		_modeCount( 0 )
	{
		Zero( &_modes, 64*sizeof(DisplayMode) );
	}

	UInt GetSize()
	{
		if ( _modeCount == 0 )
			Init();

		return _modeCount;
	}

	const DisplayMode& GetMode( UInt index )
	{
		if ( _modeCount == 0 )
			Init();

		return _modes[index];
	}

private:
	void Init()
	{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
		DEVMODEW mode;
		Zero( &mode );
		mode.dmSize = sizeof(mode);
		mode.dmDriverExtra = 0;

		for ( DWORD iModeNum = 0; ::EnumDisplaySettings(nullptr, iModeNum, &mode) != FALSE; ++iModeNum )
		{
			if ( mode.dmBitsPerPel < 16 )
				continue;

			DisplayMode displayMode( CastUInt(mode.dmPelsWidth), CastUInt(mode.dmPelsHeight), CastUInt(mode.dmBitsPerPel), true );
			if ( !Exists(displayMode) )
				_modes[_modeCount++] = displayMode;
		}

		Sort( _modes, _modeCount );
#else

#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
	}

	Bool Exists( const DisplayMode mode )
	{
		for ( UInt i = 0; i < _modeCount; ++i )
		{
			if ( _modes[i] == mode )
				return true;
		}
		return false;
	}

	DisplayMode _modes[64];
	UInt _modeCount;
}_modes;


const DisplayMode DisplayMode::Minimum = _modes.GetMode( _modes.GetSize()-1 );
const DisplayMode DisplayMode::BelowMedium = _modes.GetMode( 3*_modes.GetSize()/4 );
const DisplayMode DisplayMode::Medium = _modes.GetMode( _modes.GetSize()/2 );
const DisplayMode DisplayMode::AboveMedium = _modes.GetMode( _modes.GetSize()/4 );
const DisplayMode DisplayMode::Maximum = _modes.GetMode( 0 );


DisplayMode::DisplayMode( UInt width, UInt height, UInt depth, Bool fullscreen ) :
	Width( width ),
	Height( height ),
	Depth( depth ),
	Fullscreen( fullscreen ),
	AspectRatio( CalculateAspect(width, height) )
{
}

DisplayMode::DisplayMode( const String& mode, Bool fullscreen ) :
	Fullscreen( fullscreen )
{
	Int w; Int h; Int d;
	if ( !Parser::Parse(mode, L"{0}x{1}x{2}", w, h, d) )
	{
		d = 32;
		if ( !Parser::Parse(mode, L"{0}x{1}", w, h) )
			throw Exception( String::Format(L"Bad display mode: {0}", mode) );
	}
	Width = CastUInt(w); Height = CastUInt(h); Depth = CastUInt(d);
	AspectRatio = CalculateAspect( Width, Height );
}

DisplayMode::DisplayMode( UInt width, UInt height ) :
	Width( width ),
	Height( height ),
	Depth( 32 ),
	Fullscreen( false ),
	AspectRatio( CalculateAspect(width, height) )
{
}

DisplayMode::DisplayMode() :
	Width( 0 ),
	Height( 0 ),
	Depth( 0 ),
	Fullscreen( false ),
	AspectRatio( Aspect::Unknown )
{
}

Bool DisplayMode::operator==( const DisplayMode& other ) const
{
	return (Width == other.Width) && (Height == other.Height) && (Depth == other.Depth) && (Fullscreen == other.Fullscreen);
}

Bool DisplayMode::operator!=( const DisplayMode& other ) const
{
	return !operator==( other );
}

UInt DisplayMode::Index() const
{
	for ( UInt i = 0; i < _modes.GetSize(); ++i )
	{
		const DisplayMode& mode = _modes.GetMode( i );
		if ( (Width == mode.Width) && (Height == mode.Height) )
			return i;
	}
	return none;
}

Float DisplayMode::AspectFactor() const
{
	return CastFloat(Width)/CastFloat(Height);
}

String DisplayMode::ToString( const DisplayModeFormat& format ) const
{
	switch ( format )
	{
		case DISPLAY_MODE_FORMAT_SHORT:
			return String::Format( L"{0}x{1}", Width, Height );

		case DISPLAY_MODE_FORMAT_LONG:
			return String::Format( L"{0}x{1}x{2}", Width, Height, Depth );

		case DISPLAY_MODE_FORMAT_ASPECT:
			return String::Format( L"{0}x{1}x{2} ({3}:{4})", Width, Height, Depth, GetW(AspectRatio), GetH(AspectRatio) );

		case DISPLAY_MODE_FORMAT_COMPLETE:
			return String::Format( L"{0}x{1}x{2} {3}", Width, Height, Depth, (Fullscreen ? L"fullscreen" : L"windowed") );
	}
	return String::Empty;
}

String DisplayMode::ToString() const
{
	return ToString( DisplayModeFormat::Long );
}

UInt DisplayMode::GetModeCount()
{
	return _modes.GetSize();
}

void DisplayMode::GetMode( UInt index, DisplayMode& mode )
{
	assert( index < GetModeCount() );

	if ( index >= GetModeCount() )
		throw OutOfRangeException( index, GetModeCount() );

	mode = _modes.GetMode( index );
}

UInt DisplayMode::GetModeCount( const Aspect& aspect )
{
	const UInt total = GetModeCount();
	UInt cnt = 0;
	DisplayMode mode;
	for ( UInt i = 0; i < total; ++i )
	{
		mode = _modes.GetMode( i );
		if ( mode.AspectRatio == aspect )
		{
			++cnt;
		}
	}
	return cnt;
}

void DisplayMode::GetMode( UInt index, const Aspect& aspect, DisplayMode& mode )
{
	UInt total = GetModeCount( aspect );

	assert( index < total );

	if ( index >= total )
		throw OutOfRangeException( index, total );

	UInt cnt = 0;
	DisplayMode m;
	total = GetModeCount();
	for ( UInt i = 0; i < total; ++i )
	{
		m = _modes.GetMode( i );
		if ( m.AspectRatio == aspect )
		{
			if ( cnt++ == index )
			{
				mode = m;
				break;
			}
		}
	}
}

Bool operator<( const DisplayMode& first, const DisplayMode& second )
{
	if ( (first.Width != second.Width) || (first.Height != second.Height) )
	{
		if ( first.Width != second.Width )
			return (first.Width >= second.Width);
		else
			return (first.Height >= second.Height);
	}
	else
	{
		return (first.Depth >= second.Depth);
	}
}


} // gfx


} // synkro
