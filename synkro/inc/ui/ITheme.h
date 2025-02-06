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
// Purpose: Defines user interface theme.
//==============================================================================
#ifndef _SYNKRO_UI_ITHEME_
#define _SYNKRO_UI_ITHEME_


#include "config.h"
#include <core/IObject.h>
#include <lang/Rect.h>
#include <lang/RectF.h>
#include <img/Color.h>
#include <ui/Orientation.h>
#include <ui/WidgetState.h>


namespace synkro
{


namespace ui
{


/**
 * user interface theme.
 */
iface ITheme :
	public core::IObject
{
public:
	/**
	 * Sets widget color for the given state.
	 * @param state Widget state.
	 * @param color Widget color.
	 */
	virtual void											SetWidgetColor( const WidgetState& state, const img::Color& color ) = 0;

	/**
	 * Sets widget text color for the given state.
	 * @param state Widget state.
	 * @param color Widget text color.
	 */
	virtual void											SetTextColor( const WidgetState& state, const img::Color& color ) = 0;

	/**
	 * Retrieves coordinates of cursor rectangle in the theme resources.
	 * @param [out] rect Cursor rectangle.
	 */
	virtual void											GetCursorRect( lang::Rect& rect ) const = 0;

	/**
	 * Retrieves coordinates of angle rectangle in the theme resources.
	 * @param [out] rect Angle rectangle.
	 */
	virtual void											GetAngleRect( lang::Rect& rect ) const = 0;

	/**
	 * Retrieves coordinates of angle thumb rectangle in the theme resources.
	 * @param [out] rect Angle thumb rectangle.
	 */
	virtual void											GetAngleThumb( lang::Rect& rect ) const = 0;

	/**
	 * Retrieves coordinates of button rectangle in the theme resources.
	 * @param [out] rect Button rectangle.
	 */
	virtual void											GetButtonRect( lang::Rect& rect ) const = 0;

	/**
	 * Retrieves coordinates of button center area in the theme resources.
	 * @param [out] rect Button center area.
	 */
	virtual void											GetButtonCenter( lang::Rect& rect ) const = 0;

	/**
	 * Retrieves coordinates of edit rectangle in the theme resources.
	 * @param [out] rect Edit rectangle.
	 */
	virtual void											GetEditRect( lang::Rect& rect ) const = 0;

	/**
	 * Retrieves coordinates of edit center area in the theme resources.
	 * @param [out] rect Edit center area.
	 */
	virtual void											GetEditCenter( lang::Rect& rect ) const = 0;

	/**
	 * Retrieves coordinates of list rectangle in the theme resources.
	 * @param [out] rect List rectangle.
	 */
	virtual void											GetListRect( lang::Rect& rect ) const = 0;

	/**
	 * Retrieves coordinates of list center area in the theme resources.
	 * @param [out] rect List center area.
	 */
	virtual void											GetListCenter( lang::Rect& rect ) const = 0;

	/**
	 * Retrieves coordinates of the option rectangle in the theme resources.
	 * @param selected Option selected state.
	 * @param [out] rect Option rectangle.
	 */
	virtual void											GetOptionRect( Bool selected, lang::Rect& rect ) const = 0;

	/**
	 * Retrieves coordinates of the option center area in the theme resources.
	 * @param selected Option selected state.
	 * @param [out] rect Option center area.
	 */
	virtual void											GetOptionCenter( Bool selected, lang::Rect& rect ) const = 0;

	/**
	 * Retrieves coordinates of the empty progress rectangle in the theme resources.
	 * @param [out] rect Empty progress rectangle.
	 */
	virtual void											GetProgressEmptyRect( lang::Rect& rect ) const = 0;

	/**
	 * Retrieves coordinates of the empty progress center area in the theme resources.
	 * @param [out] rect Empty progress center area.
	 */
	virtual void											GetProgressEmptyCenter( lang::Rect& rect ) const = 0;

	/**
	 * Retrieves coordinates of the filled progress rectangle in the theme resources.
	 * @param [out] rect Filled progress rectangle.
	 */
	virtual void											GetProgressFilledRect( lang::Rect& rect ) const = 0;

	/**
	 * Retrieves coordinates of the filled progress center area in the theme resources.
	 * @param [out] rect Filled progress center area.
	 */
	virtual void											GetProgressFilledCenter( lang::Rect& rect ) const = 0;

	/**
	 * Retrieves coordinates of slider rectangle in the theme resources.
	 * @param orientation Slider orientation.
	 * @param [out] rect Slider rectangle.
	 */
	virtual void											GetSliderRect( const Orientation& orientation, lang::Rect& rect ) const = 0;

	/**
	 * Retrieves coordinates of slider center area in the theme resources.
	 * @param orientation Slider orientation.
	 * @param [out] rect Slider center area.
	 */
	virtual void											GetSliderCenter( const Orientation& orientation, lang::Rect& rect ) const = 0;

	/**
	 * Retrieves coordinates of slider thumb rectangle in the theme resources.
	 * @param orientation Slider orientation.
	 * @param [out] rect Slider thumb rectangle.
	 */
	virtual void											GetSliderThumb( const Orientation& orientation, lang::Rect& rect ) const = 0;

	/**
	 * Retrieves coordinates of the switch rectangle in the theme resources.
	 * @param on Switch 'on' state.
	 * @param [out] rect Switch rectangle.
	 */
	virtual void											GetSwitchRect( Bool on, lang::Rect& rect ) const = 0;

	/**
	 * Retrieves coordinates of the switch center area in the theme resources.
	 * @param on Switch 'on' state.
	 * @param [out] rect Switch center area.
	 */
	virtual void											GetSwitchCenter( Bool on, lang::Rect& rect ) const = 0;

	/**
	 * Retrieves widget color for the given state.
	 * @param state Widget state.
	 * @param [out] color Widget color.
	 */
	virtual void											GetWidgetColor( const WidgetState& state, img::Color& color ) const = 0;

	/**
	 * Retrieves widget text color for the given state.
	 * @param state Widget state.
	 * @param [out] color Widget text color.
	 */
	virtual void											GetTextColor( const WidgetState& state, img::Color& color ) const = 0;

	/**
	 * Retrieves program used to draw user interface.
	 */
	virtual gfx::IProgram*									GetProgram() const = 0;

	/**
	 * Retrieves theme resources.
	 */
	virtual gfx::IResourceSet*								GetResources() const = 0;

	/**
	 * Converts rectangle coordinates to [0.0-1.0] range.
	 */
	virtual void											ToRectF( const lang::Rect& rect, lang::RectF& rectF ) const = 0;
};


} // ui


} // synkro


#endif // _SYNKRO_UI_ITHEME_
