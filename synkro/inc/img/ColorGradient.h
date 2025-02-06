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
// Purpose: Defines color gradient.
//==============================================================================
#ifndef _SYNKRO_IMG_COLORGRADIENT_
#define _SYNKRO_IMG_COLORGRADIENT_


#include "config.h"
#include <img/Color.h>
#include <lang/GradientType.h>


namespace synkro
{


namespace img
{


/**
 * Color gradient.
 */
class SYNKRO_API ColorGradient
{
public:
	// Gradient extremum values.
	Color Start, End;

	// Gradient type.
	lang::GradientType Type;

	/**
	 * Constructs a gradient with the given properties.
	 * @param type Gradient type.
	 * @param start Start value.
	 * @param end End value.
	 */
	ColorGradient( const lang::GradientType& type, const Color& start, const Color& end );

	/**
	 * Copy constructor.
	 */
	ColorGradient( const ColorGradient& other );

	/**
	 * Constructs a default gradient.
	 */
	ColorGradient();

	/**
	 * Copy by reference.
	 */
	ColorGradient&											operator=( const ColorGradient& other );

	/**
	 * Tests two gradients for equality.
	 * @param other Gradient to compare to.
	 * @return True for equal gradients, false otherwise.
	 */
	Bool													operator==( const ColorGradient& other ) const;

	/**
	 * Tests two gradients for inequality.
	 * @param other Gradient to compare to.
	 * @return True for unequal gradients, false otherwise.
	 */
	Bool													operator!=( const ColorGradient& other ) const;
};


} // img


} // synkro


#endif // _SYNKRO_IMG_COLORGRADIENT_
