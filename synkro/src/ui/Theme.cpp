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
// Purpose: User interface theme.
//==============================================================================
#include "config.h"
#include "Theme.h"
#include <img/IImage.h>
#include <img/BaseImage.h>
#include <gfx/IProgramStage.h>


//------------------------------------------------------------------------------

using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace ui
{


Theme::Theme( const ThemeReader& rd, IImage* image, IProgram* program ) :
	_image( image ),
	_program( program )
{
	// Set default colors.
	_widgetColors[WidgetState::Normal] = Color::White;
	_widgetColors[WidgetState::Active] = Color::White*1.4f;
	_widgetColors[WidgetState::Hovered] = Color::White*1.5f;
	_widgetColors[WidgetState::Disabled] = Color::Gray;

	_textColors[WidgetState::Normal] = Color::White;
	_textColors[WidgetState::Active] = Color::White*1.4f;
	_textColors[WidgetState::Hovered] = Color::White*1.5f;
	_textColors[WidgetState::Disabled] = Color::Gray;

	// Read widget coordinates.
	_rects[ThemeReader::THEME_CURSOR] = rd.GetCursorRect();
	
	_rects[ThemeReader::THEME_ANGLE_RECT] = rd.GetAngleRect();
	_rects[ThemeReader::THEME_ANGLE_THUMB] = rd.GetAngleThumb();

	_rects[ThemeReader::THEME_BUTTON_RECT] = rd.GetButtonRect();
	_rects[ThemeReader::THEME_BUTTON_CENTER] = rd.GetButtonCenter();

	_rects[ThemeReader::THEME_EDIT_RECT] = rd.GetEditRect();
	_rects[ThemeReader::THEME_EDIT_CENTER] = rd.GetEditCenter();
	
	_rects[ThemeReader::THEME_LIST_RECT] = rd.GetListRect();
	_rects[ThemeReader::THEME_LIST_CENTER] = rd.GetListCenter();
	
	_rects[ThemeReader::THEME_OPTION_OFF_RECT] = rd.GetOptionRect( false );
	_rects[ThemeReader::THEME_OPTION_OFF_CENTER] = rd.GetOptionCenter( false );
	_rects[ThemeReader::THEME_OPTION_ON_RECT] = rd.GetOptionRect( true );
	_rects[ThemeReader::THEME_OPTION_ON_CENTER] = rd.GetOptionCenter( true );
	
	_rects[ThemeReader::THEME_PROGRESS_EMPTY_RECT] = rd.GetProgressEmptyRect();
	_rects[ThemeReader::THEME_PROGRESS_EMPTY_CENTER] = rd.GetProgressEmptyCenter();
	_rects[ThemeReader::THEME_PROGRESS_FILLED_RECT] = rd.GetProgressFilledRect();
	_rects[ThemeReader::THEME_PROGRESS_FILLED_CENTER] = rd.GetProgressFilledCenter();
	
	_rects[ThemeReader::THEME_SLIDER_HORZ_RECT] = rd.GetSliderRect( Orientation::Horizontal );
	_rects[ThemeReader::THEME_SLIDER_HORZ_CENTER] = rd.GetSliderCenter( Orientation::Horizontal );
	_rects[ThemeReader::THEME_SLIDER_HORZ_THUMB] = rd.GetSliderThumb( Orientation::Horizontal );
	_rects[ThemeReader::THEME_SLIDER_VERT_RECT] = rd.GetSliderRect( Orientation::Vertical );
	_rects[ThemeReader::THEME_SLIDER_VERT_CENTER] = rd.GetSliderCenter( Orientation::Vertical );
	_rects[ThemeReader::THEME_SLIDER_VERT_THUMB] = rd.GetSliderThumb( Orientation::Vertical );
	
	_rects[ThemeReader::THEME_SWITCH_OFF_RECT] = rd.GetSwitchRect( false );
	_rects[ThemeReader::THEME_SWITCH_OFF_CENTER] = rd.GetSwitchCenter( false );
	_rects[ThemeReader::THEME_SWITCH_ON_RECT] = rd.GetSwitchRect( true );
	_rects[ThemeReader::THEME_SWITCH_ON_CENTER] = rd.GetSwitchCenter( true );
}

Theme::Theme() :
	_program( nullptr )
{
}

void Theme::Prepare()
{
	if ( _resources == nullptr )
	{
		AsBaseImage( _image.AsPtr() )->SignalLoad();
		_image->Prepare( _image->GetFormat(), 1 );
		_resources = _program->GetFragmentStage()->GetResources()->Clone( _image->ID() );
		_resources->Set( 0, _image->AsResource() );
	}
}


} // ui


} // synkro
