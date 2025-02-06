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
// Purpose: Defines text editor widget.
//==============================================================================
#ifndef _SYNKRO_UI_IEDIT_
#define _SYNKRO_UI_IEDIT_


#include "config.h"
#include <ui/IWidget.h>
#include <ui/EditStyle.h>


namespace synkro
{


namespace ui
{


/**
 * Text editor widget.
 */
iface IEdit :
	public IWidget
{
public:
	/**
	 * Resets widget content.
	 */
	virtual void											Clear() = 0;

	/**
	 * Sets the text that is displayed in the editor.
	 * @param text Editor text.
	 */
	virtual void											SetText( const lang::String& text ) = 0;

	/**
	 * Sets widget style.
	 * @param style Character style.
	 */
	virtual void											SetStyle( const EditStyle& style ) = 0;

	/**
	 * Sets numeric value. Only valid for numeric edit.
	 * @param value New numeric value.
	 * @exception InvalidOperationException Edit is not numeric.
	 */
	virtual void											SetValue( Float value ) = 0;

	/**
	 * Sets minimum numeric value. Only valid for numeric edit.
	 * @param minValue The minimum allowed numeric value.
	 * @exception InvalidOperationException Edit is not numeric.
	 */
	virtual void											SetMinValue( Float minValue ) = 0;

	/**
	 * Sets maximum numeric value. Only valid for numeric edit.
	 * @param maxValue The maximum allowed numeric value.
	 * @exception InvalidOperationException Edit is not numeric.
	 */
	virtual void											SetMaxValue( Float maxValue ) = 0;

	/**
	 * Sets maximum text length.
	 * @param maxLength The maximum allowed text length. Set to 0 to remove length limit.
	 */
	virtual void											SetMaxLength( UInt maxLength ) = 0;

	/**
	 * Sets horizontal scrolling. Non-zero offset makes text scroll to the left.
	 * @param offset Scroll offset.
	 */
	virtual void											SetScrollOffset( UInt offset ) = 0;

	/**
	 * Tests widget content for emptiness.
	 */
	virtual Bool											IsEmpty() const = 0;

	/**
	 * Retrieves editor text.
	 */
	virtual lang::String									GetText() const = 0;

	/**
	 * Retrieves widget style.
	 */
	virtual EditStyle										GetStyle() const = 0;

	/**
	 * Retrieves numeric value. Only valid for numeric edit.
	 * @exception InvalidOperationException Edit is not numeric.
	 */
	virtual Float											GetValue() const = 0;

	/**
	 * Retrieves minimum numeric value. Only valid for numeric edit.
	 * @exception InvalidOperationException Edit is not numeric.
	 */
	virtual Float											GetMinValue() const = 0;

	/**
	 * Retrieves maximum numeric value. Only valid for numeric edit.
	 * @exception InvalidOperationException Edit is not numeric.
	 */
	virtual Float											GetMaxValue() const = 0;

	/**
	 * Retrieves maximum text length.
	 */
	virtual UInt											GetMaxLength() const = 0;

	/**
	 * Retrieves horizontal scrolling.
	 */
	virtual UInt											GetScrollOffset() const = 0;
};


} // ui


} // synkro


#endif // _SYNKRO_UI_IEDIT_
