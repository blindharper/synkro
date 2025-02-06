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
// Purpose: User interface cursor implementation.
//==============================================================================
#ifndef _SYNKRO_UI_CURSOR_
#define _SYNKRO_UI_CURSOR_


#include "config.h"
#include <core/ObjectImpl.h>
#include <ui/ICursor.h>
#include <ui/ITheme.h>
#include "BaseUiEx.h"
#include <gfx/IOverlayRenderObject.h>
#include <gfx/IParameterSet.h>
#include <internal/ToVector.h>


namespace synkro
{


namespace ui
{


// UI cursor implementation.
class Cursor :
	public core::ObjectImpl<ICursor>
{
public:
	// Constructor.
	Cursor( BaseUiEx* ui );

	// ICursor methods.
	void													Show( Bool show );
	void													SetLocation( const lang::Point& location );
	void													SetType( const CursorType& type );
	Bool													IsVisible() const;
	CursorType												GetType() const;
	void													GetLocation( lang::Point& location ) const;

	// Other methods.
	void													SetTheme( ITheme* theme );

private:
	BaseUiEx*												_ui;
	CursorType												_type;
	lang::Point												_location;
	Float													_width;
	Float													_height;
	P(gfx::IOverlayRenderObject)							_object;
	gfx::ProgramParam*										_paramColor;

	void													UpdateTextureCoordinates();
	void													SetColor( const img::Color& color );
};


#include "Cursor.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_CURSOR_
