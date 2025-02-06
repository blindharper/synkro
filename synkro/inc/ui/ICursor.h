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
// Purpose: Defines user interface cursor.
//==============================================================================
#ifndef _SYNKRO_UI_ICURSOR_
#define _SYNKRO_UI_ICURSOR_


#include "config.h"
#include <core/IObject.h>
#include <lang/Point.h>
#include <ui/CursorType.h>


namespace synkro
{


namespace ui
{


/**
 * User interface cursor.
 */
iface ICursor :
	public core::IObject
{
public:
	/** 
	 * Sets cursor visibility.
	 * @param show Set to true to make cursor visible, set to false to hide it.
	 */
	virtual void											Show( Bool show ) = 0;

	/**
	 * Sets cursor location.
	 * @param location New cursor location.
	 */
	virtual void											SetLocation( const lang::Point& location ) = 0;

	/** 
	 * Sets cursor type.
	 * @param type New cursor type.
	 */
	virtual void											SetType( const CursorType& type ) = 0;

	/**
	 * Retrieves cursor visibility state.
	 * @return True if the cursor is visible, false otherwise.
	 */
	virtual Bool											IsVisible() const = 0;

	/**
	 * Retrieves cursor location.
	 * @param [out] location Cursor location.
	 */
	virtual void											GetLocation( lang::Point& location ) const = 0;

	/** 
	 * Retrieves current cursor type.
	 */
	virtual CursorType										GetType() const = 0;
};


} // ui


} // synkro


#endif // _SYNKRO_UI_ICURSOR_
