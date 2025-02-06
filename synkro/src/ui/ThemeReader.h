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
#ifndef _SYNKRO_UI_THEMEREADER_
#define _SYNKRO_UI_THEMEREADER_


#include "config.h"
#include <io/XmlReader.h>
#include <ui/Orientation.h>
#include <lang/Vector.h>
#include <lang/Map.h>
#include <lang/Rect.h>
#include <lang/Formatter.h>
#include <lang/Parser.h>
#include <img/Color.h>


namespace synkro
{


namespace ui
{


// Theme resource reader.
class ThemeReader
{
public:
	// Widget parts identifiers.
	enum
	{
		THEME_CURSOR = 0,
		THEME_BUTTON_RECT,
		THEME_ANGLE_RECT,
		THEME_ANGLE_THUMB,
		THEME_BUTTON_CENTER,
		THEME_EDIT_RECT,
		THEME_EDIT_CENTER,
		THEME_LIST_RECT,
		THEME_LIST_CENTER,
		THEME_OPTION_OFF_RECT,
		THEME_OPTION_OFF_CENTER,
		THEME_OPTION_ON_RECT,
		THEME_OPTION_ON_CENTER,
		THEME_PROGRESS_EMPTY_RECT,
		THEME_PROGRESS_EMPTY_CENTER,
		THEME_PROGRESS_FILLED_RECT,
		THEME_PROGRESS_FILLED_CENTER,
		THEME_SLIDER_HORZ_RECT,
		THEME_SLIDER_HORZ_CENTER,
		THEME_SLIDER_HORZ_THUMB,
		THEME_SLIDER_VERT_RECT,
		THEME_SLIDER_VERT_CENTER,
		THEME_SLIDER_VERT_THUMB,
		THEME_SWITCH_OFF_RECT,
		THEME_SWITCH_OFF_CENTER,
		THEME_SWITCH_ON_RECT,
		THEME_SWITCH_ON_CENTER,
		THEME_RECT_COUNT,
	};

	// Creates a theme reader from the specified stream directory.
	ThemeReader( io::IStreamDirectory* directory );
	
	Bool													Read();

	lang::String											GetName() const;
	lang::String											GetImage() const;
	lang::String											GetAlpha() const;
	lang::Rect												GetCursorRect() const;
	lang::Rect												GetAngleRect() const;
	lang::Rect												GetAngleThumb() const;
	lang::Rect												GetButtonRect() const;
	lang::Rect												GetButtonCenter() const;
	lang::Rect												GetEditRect() const;
	lang::Rect												GetEditCenter() const;
	lang::Rect												GetListRect() const;
	lang::Rect												GetListCenter() const;
	lang::Rect												GetOptionRect( Bool selected ) const;
	lang::Rect												GetOptionCenter( Bool selected ) const;
	lang::Rect												GetProgressEmptyRect() const;
	lang::Rect												GetProgressEmptyCenter() const;
	lang::Rect												GetProgressFilledRect() const;
	lang::Rect												GetProgressFilledCenter() const;
	lang::Rect												GetSliderRect( const Orientation& orientation ) const;
	lang::Rect												GetSliderCenter( const Orientation& orientation ) const;
	lang::Rect												GetSliderThumb( const Orientation& orientation ) const;
	lang::Rect												GetSwitchRect( Bool on ) const;
	lang::Rect												GetSwitchCenter( Bool on ) const;

private:
	io::XmlReader											_rd;
	lang::String											_name;
	lang::String											_image;
	lang::String											_alpha;
	lang::Rect												_rects[THEME_RECT_COUNT];
	mutable lang::Parser									_parserRect;

	static io::IStream*										GetManifest( io::IStreamDirectory* directory );
	lang::Rect												GetRect( const lang::String& rect ) const;
	void													ReadTheme();
	void													ReadCursor();
	void													ReadAngle();
	void													ReadButton();
	void													ReadEdit();
	void													ReadList();
	void													ReadOption();
	void													ReadProgress();
	void													ReadSlider();
	void													ReadSwitch();
	void													ReadRect( UInt index, const lang::String& attribute );
};


} // ui


} // synkro


#endif // _SYNKRO_UI_THEMEREADER_
