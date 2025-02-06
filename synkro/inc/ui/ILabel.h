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
// Purpose: Defines label widget.
//==============================================================================
#ifndef _SYNKRO_UI_ILABEL_
#define _SYNKRO_UI_ILABEL_


#include "config.h"
#include <ui/IWidget.h>
#include <ui/Alignment.h>
#include <img/Color.h>


namespace synkro
{


namespace ui
{


/**
 * Label widget.
 */
iface ILabel :
	public IWidget
{
public:
	/**
	 * Turns background transparency on or off.
	 * @param transparent True to make label background transparent, false to make it opaque.
	 */
	virtual void											SetTransparent( Bool transparent ) = 0;

	/**
	 * Sets background color.
	 * @param color Label background color.
	 */
	virtual void											SetBackColor( const img::Color& color ) = 0;

	/**
	 * Sets text alignment within the label.
	 * @param align Text alignment.
	 */
	virtual void											SetTextAlign( const Alignment& align ) = 0;

	/**
	 * Sets the text that is displayed on the label.
	 * @param text Label text.
	 */
	virtual void											SetText( const lang::String& text ) = 0;

	/**
	 * Retrieves background transparency status.
	 */
	virtual Bool											IsTransparent() const = 0;

	/**
	 * Retrieves background color.
	 * @param [out] color Color value.
	 */
	virtual void											GetBackColor( img::Color& color ) const = 0;

	/**
	 * Retrieves text alignment.
	 */
	virtual Alignment										GetTextAlign() const = 0;

	/**
	 * Retrieves label text.
	 */
	virtual lang::String									GetText() const = 0;
};


} // ui


} // synkro


#endif // _SYNKRO_UI_ILABEL_
