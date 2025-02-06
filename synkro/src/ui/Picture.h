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
// Purpose: Picture widget implementation.
//==============================================================================
#ifndef _SYNKRO_UI_PICTURE_
#define _SYNKRO_UI_PICTURE_


#include "config.h"
#include "WidgetImpl.h"
#include <ui/IPicture.h>
#include "BaseUiEx.h"
#include "BaseThemeWidgetImpl.h"
#include "BaseThemeWidget.h"
#include "BaseAnchoredObjectImpl.h"
#include <over/ISprite.h>


namespace synkro
{


namespace ui
{


// Picture widget implementation.
class Picture :
	public WidgetImpl<IPicture>,
	public BaseThemeWidgetImpl<BaseThemeWidget>,
	public BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>
{
public:
	// Constructor.
	Picture( BaseUiEx* ui, IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size, img::IImage* image );

	// IObject methods.
	UInt													ID() const;

	// IWidget methods.
	void													Show( Bool show );
	void													SetOpacity( Float opacity );
	void													SetLocation( const lang::Point& location );
	void													SetSize( const lang::Size& size );
	void													SetAnchor( const Anchor& anchor );
	void													SetTabOrder( UInt order );
	IPicture*												AsPicture() const;

	// IPicture methods.
	img::IImage*											GetImage() const;

	// BaseThemeWidget methods.
	void													UpdateRect();

private:
	UInt													_widgetID;
	P(over::ISprite)										_picture;
};


#include "Picture.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_PICTURE_
