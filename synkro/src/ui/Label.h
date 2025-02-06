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
// Purpose: Label widget implementation.
//==============================================================================
#ifndef _SYNKRO_UI_LABEL_
#define _SYNKRO_UI_LABEL_


#include "config.h"
#include "WidgetImpl.h"
#include <ui/ILabel.h>
#include "BaseUiEx.h"
#include "BaseThemeWidgetImpl.h"
#include "BaseThemeWidget.h"
#include "BaseAnchoredObjectImpl.h"


namespace synkro
{


namespace ui
{


// Label widget implementation.
class Label :
	public WidgetImpl<ILabel>,
	public BaseThemeWidgetImpl<BaseThemeWidget>,
	public BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>
{
public:
	// Constructor.
	Label( BaseUiEx* ui, IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size, const lang::String& text );

	// IObject methods.
	UInt													ID() const;

	// IWidget methods.
	void													Show( Bool show );
	void													SetOpacity( Float opacity );
	void													SetLocation( const lang::Point& location );
	void													SetSize( const lang::Size& size );
	void													SetAnchor( const Anchor& anchor );
	void													SetTabOrder( UInt order );
	ILabel*													AsLabel() const;

	// ILabel methods.
	void													SetTransparent( Bool transparent );
	void													SetBackColor( const img::Color& color );
	void													SetTextAlign( const Alignment& align );
	void													SetText( const lang::String& text );
	Bool													IsTransparent() const;
	void													GetBackColor( img::Color& color ) const;
	Alignment												GetTextAlign() const;
	lang::String											GetText() const;

	// BaseThemeWidget methods.
	void													SetTheme( ITheme* theme );
	void													UpdateRect();

private:
	BaseUiEx*												_uiEx;
	UInt													_widgetID;
	P(over::IQuad)											_back;
	img::Color												_backColor;
	Bool													_transparent;
	Alignment												_align;

	void													Update();
};


#include "Label.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_LABEL_
