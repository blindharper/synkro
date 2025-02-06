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
#ifndef _SYNKRO_UI_THEME_
#define _SYNKRO_UI_THEME_


#include "config.h"
#include <core/ObjectImpl.h>
#include <ui/ITheme.h>
#include <ui/Orientation.h>
#include <img/IImage.h>
#include <gfx/IProgram.h>
#include <gfx/IResourceSet.h>
#include <lang/Vector.h>
#include "ThemeReader.h"


namespace synkro
{


namespace ui
{


// User interface theme.
class Theme :
	public core::ObjectImpl<ITheme>
{
public:
	// Constructors.
	Theme( const ThemeReader& rd, img::IImage* image, gfx::IProgram* program );
	Theme();

	// ITheme methods.
	void													SetWidgetColor( const WidgetState& state, const img::Color& color );
	void													SetTextColor( const WidgetState& state, const img::Color& color );
	void													GetCursorRect( lang::Rect& rect ) const;
	void													GetAngleRect( lang::Rect& rect ) const;
	void													GetAngleThumb( lang::Rect& rect ) const;
	void													GetButtonRect( lang::Rect& rect ) const;
	void													GetButtonCenter( lang::Rect& rect ) const;
	void													GetEditRect( lang::Rect& rect ) const;
	void													GetEditCenter( lang::Rect& rect ) const;
	void													GetListRect( lang::Rect& rect ) const;
	void													GetListCenter( lang::Rect& rect ) const;
	void													GetOptionRect( Bool selected, lang::Rect& rect ) const;
	void													GetOptionCenter( Bool selected, lang::Rect& rect ) const;
	void													GetProgressEmptyRect( lang::Rect& rect ) const;
	void													GetProgressEmptyCenter( lang::Rect& rect ) const;
	void													GetProgressFilledRect( lang::Rect& rect ) const;
	void													GetProgressFilledCenter( lang::Rect& rect ) const;
	void													GetSliderRect( const Orientation& orientation, lang::Rect& rect ) const;
	void													GetSliderCenter( const Orientation& orientation, lang::Rect& rect ) const;
	void													GetSliderThumb( const Orientation& orientation, lang::Rect& rect ) const;
	void													GetSwitchRect( Bool on, lang::Rect& rect ) const;
	void													GetSwitchCenter( Bool on, lang::Rect& rect ) const;
	void													GetWidgetColor( const WidgetState& state, img::Color& color ) const;
	void													GetTextColor( const WidgetState& state, img::Color& color ) const;
	gfx::IProgram*											GetProgram() const;
	gfx::IResourceSet*										GetResources() const;
	void													ToRectF( const lang::Rect& rect, lang::RectF& rectF ) const;

	// Other methods.
	void													Prepare();
	void													Validate();
	Bool													IsDirty() const;

private:
	img::Color												_widgetColors[4];
	img::Color												_textColors[4];
	P(img::IImage)											_image;
	P(gfx::IResourceSet)									_resources;
	gfx::IProgram*											_program;
	Bool													_dirty;
	lang::Rect												_rects[ThemeReader::THEME_RECT_COUNT];
};


#include "Theme.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_THEME_
