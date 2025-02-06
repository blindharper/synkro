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
// Purpose: Defines theme resource reader.
//==============================================================================
#include "config.h"
#include "ThemeReader.h"
#include <io/IStreamDirectory.h>
#include <io/Path.h>


//------------------------------------------------------------------------------

using namespace synkro::img;
using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace ui
{


ThemeReader::ThemeReader( IStreamDirectory* directory ) :
	_rd( GetManifest(directory), true ),
	_parserRect( L"{0},{1},{2},{3}" )
{
	// Read <themes> tag.
	if ( !_rd.Read() || (!_rd.GetName().EqualsTo(L"themes", true)) )
		throw Exception( L"Bad theme resource. Missing <themes> tag." );
}

Bool ThemeReader::Read()
{
	if ( _rd.Read() && _rd.GetName().EqualsTo(L"theme", true) && _rd.IsStart() )
	{
		ReadTheme();
		return true;
	}

	return false;
}

String ThemeReader::GetName() const
{
	return _name;
}

String ThemeReader::GetImage() const
{
	return _image;
}

String ThemeReader::GetAlpha() const
{
	return _alpha;
}

Rect ThemeReader::GetCursorRect() const
{
	return _rects[THEME_CURSOR];
}

Rect ThemeReader::GetAngleRect() const
{
	return _rects[THEME_ANGLE_RECT];
}

Rect ThemeReader::GetAngleThumb() const
{
	return _rects[THEME_ANGLE_THUMB];
}

Rect ThemeReader::GetButtonRect() const
{
	return _rects[THEME_BUTTON_RECT];
}

Rect ThemeReader::GetButtonCenter() const
{
	return _rects[THEME_BUTTON_CENTER];
}

Rect ThemeReader::GetEditRect() const
{
	return _rects[THEME_EDIT_RECT];
}

Rect ThemeReader::GetEditCenter() const
{
	return _rects[THEME_EDIT_CENTER];
}

Rect ThemeReader::GetListRect() const
{
	return _rects[THEME_LIST_RECT];
}

Rect ThemeReader::GetListCenter() const
{
	return _rects[THEME_LIST_CENTER];
}

Rect ThemeReader::GetOptionRect( Bool selected ) const
{
	return _rects[selected ? THEME_OPTION_ON_RECT : THEME_OPTION_OFF_RECT];
}

Rect ThemeReader::GetOptionCenter( Bool selected ) const
{
	return _rects[selected ? THEME_OPTION_ON_CENTER : THEME_OPTION_OFF_CENTER];
}

Rect ThemeReader::GetProgressEmptyRect() const
{
	return _rects[THEME_PROGRESS_EMPTY_RECT];
}

Rect ThemeReader::GetProgressEmptyCenter() const
{
	return _rects[THEME_PROGRESS_EMPTY_CENTER];
}

Rect ThemeReader::GetProgressFilledRect() const
{
	return _rects[THEME_PROGRESS_FILLED_RECT];
}

Rect ThemeReader::GetProgressFilledCenter() const
{
	return _rects[THEME_PROGRESS_FILLED_CENTER];
}

Rect ThemeReader::GetSliderRect( const Orientation& orientation ) const
{
	return _rects[(orientation == Orientation::Horizontal) ? THEME_SLIDER_HORZ_RECT : THEME_SLIDER_VERT_RECT];
}

Rect ThemeReader::GetSliderCenter( const Orientation& orientation ) const
{
	return _rects[(orientation == Orientation::Horizontal) ? THEME_SLIDER_HORZ_CENTER : THEME_SLIDER_VERT_CENTER];
}

Rect ThemeReader::GetSliderThumb( const Orientation& orientation ) const
{
	return _rects[(orientation == Orientation::Horizontal) ? THEME_SLIDER_HORZ_THUMB : THEME_SLIDER_VERT_THUMB];
}

Rect ThemeReader::GetSwitchRect( Bool on ) const
{
	return _rects[on ? THEME_SWITCH_ON_RECT : THEME_SWITCH_OFF_RECT];
}

Rect ThemeReader::GetSwitchCenter( Bool on ) const
{
	return _rects[on ? THEME_SWITCH_ON_CENTER : THEME_SWITCH_OFF_CENTER];
}

Rect ThemeReader::GetRect( const String& rect ) const
{
	if ( (rect == String::Null) )
		return Rect();

	Int left = 0; Int top = 0; Int right = 0; Int bottom = 0;
	_parserRect.Map( left, top, right, bottom );
	if ( !_parserRect.ParseText(rect) )
		return Rect();

	return Rect( left, top, right, bottom );
}

IStream* ThemeReader::GetManifest( IStreamDirectory* directory )
{
	assert( directory != nullptr );

	// Get 'manifest.xml' file.
	IStream* stream = directory->GetStream( L"manifest.xml" );
	if ( stream == nullptr )
		throw Exception( "Bad theme resource. Missing 'manifest.xml' file." );

	return stream;
}

void ThemeReader::ReadTheme()
{
	_name = _rd.GetAttributeValue( L"name" );
	_image = _rd.GetAttributeValue( L"image" );
	_alpha = _rd.GetAttributeValue( L"alpha" );

	while ( _rd.Read() && !(_rd.GetName().EqualsTo(L"theme", true) && _rd.IsEnd()) )
	{
		if ( _rd.GetName().EqualsTo(L"cursor", true) )
		{
			ReadCursor();
		}
		else if ( _rd.GetName().EqualsTo(L"angle", true) )
		{
			ReadAngle();
		}
		else if ( _rd.GetName().EqualsTo(L"button", true) )
		{
			ReadButton();
		}
		else if ( _rd.GetName().EqualsTo(L"edit", true) )
		{
			ReadEdit();
		}
		else if ( _rd.GetName().EqualsTo(L"list", true) )
		{
			ReadList();
		}
		else if ( _rd.GetName().EqualsTo(L"option", true) )
		{
			ReadOption();
		}
		else if ( _rd.GetName().EqualsTo(L"progress", true) )
		{
			ReadProgress();
		}
		else if ( _rd.GetName().EqualsTo(L"slider", true) )
		{
			ReadSlider();
		}
		else if ( _rd.GetName().EqualsTo(L"switch", true) )
		{
			ReadSwitch();
		}
	}
}

void ThemeReader::ReadCursor()
{
	ReadRect( THEME_CURSOR, L"rect" );
}

void ThemeReader::ReadAngle()
{
	ReadRect( THEME_ANGLE_RECT, L"rect" );
	ReadRect( THEME_ANGLE_THUMB, L"thumb" );
}

void ThemeReader::ReadButton()
{
	ReadRect( THEME_BUTTON_RECT, L"rect" );
	ReadRect( THEME_BUTTON_CENTER, L"center" );
}

void ThemeReader::ReadEdit()
{
	ReadRect( THEME_EDIT_RECT, L"rect" );
	ReadRect( THEME_EDIT_CENTER, L"center" );
}

void ThemeReader::ReadList()
{
	ReadRect( THEME_LIST_RECT, L"rect" );
	ReadRect( THEME_LIST_CENTER, L"center" );
}

void ThemeReader::ReadOption()
{
	ReadRect( THEME_OPTION_OFF_RECT, L"offrect" );
	ReadRect( THEME_OPTION_OFF_CENTER, L"offcenter" );
	ReadRect( THEME_OPTION_ON_RECT, L"onrect" );
	ReadRect( THEME_OPTION_ON_CENTER, L"oncenter" );
}

void ThemeReader::ReadProgress()
{
	ReadRect( THEME_PROGRESS_EMPTY_RECT, L"emptyrect" );
	ReadRect( THEME_PROGRESS_EMPTY_CENTER, L"emptycenter" );
	ReadRect( THEME_PROGRESS_FILLED_RECT, L"filledrect" );
	ReadRect( THEME_PROGRESS_FILLED_CENTER, L"filledcenter" );
}

void ThemeReader::ReadSlider()
{
	Orientation orientation( _rd.GetAttributeValue(L"orientation") );
	ReadRect( (orientation == Orientation::Horizontal) ? THEME_SLIDER_HORZ_RECT : THEME_SLIDER_VERT_RECT, L"rect" );
	ReadRect( (orientation == Orientation::Horizontal) ? THEME_SLIDER_HORZ_CENTER : THEME_SLIDER_VERT_CENTER, L"center" );
	ReadRect( (orientation == Orientation::Horizontal) ? THEME_SLIDER_HORZ_THUMB : THEME_SLIDER_VERT_THUMB, L"thumb" );
}

void ThemeReader::ReadSwitch()
{
	ReadRect( THEME_SWITCH_OFF_RECT, L"offrect" );
	ReadRect( THEME_SWITCH_OFF_CENTER, L"offcenter" );
	ReadRect( THEME_SWITCH_ON_RECT, L"onrect" );
	ReadRect( THEME_SWITCH_ON_CENTER, L"oncenter" );
}

void ThemeReader::ReadRect( UInt index, const String& attribute )
{
	_rects[index] = GetRect( _rd.GetAttributeValue(attribute) );
}


} // ui


} // synkro
