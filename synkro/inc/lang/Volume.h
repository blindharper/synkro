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
// Purpose: Defines floating-point value volume.
//==============================================================================
#ifndef _SYNKRO_LANG_VOLUME_
#define _SYNKRO_LANG_VOLUME_


#include "config.h"


namespace synkro
{


namespace lang
{


/**
 * Floating-point value volume.
 */
class SYNKRO_API Volume
{
public:
	// Volume borders.
	Float Left, Top, Near, Right, Bottom, Far;

	/**
	 * Constructs volume from a set of scalars.
	 * @param left Left coordinate.
	 * @param top Top coordinate.
	 * @param _near Near coordinate.
	 * @param right Right coordinate.
	 * @param bottom Bottom coordinate.
	 * @param _far Far coordinate.
	 */
	Volume( Float left, Float top, Float _near, Float right, Float bottom, Float _far );

	/**
	 * Copy constructor.
	 * @param other Volume to copy from.
	 */
	Volume( const Volume& other );

	/**
	 * Constructs an empty volume.
	 */
	Volume();

	/**
	 * Sets volume coordinates.
	 * @param left Left coordinate.
	 * @param top Top coordinate.
	 * @param _near Near coordinate.
	 * @param right Right coordinate.
	 * @param bottom Bottom coordinate.
	 * @param _far Far coordinate.
	 */
	Volume&													Set( Float left, Float top, Float _near, Float right, Float bottom, Float _far );

	/**
	 * Increases volume dimensions.
	 * @param x Horizontal offset.
	 * @param y Vertical offset.
	 * @param z Depth offset.
	 */
	Volume&													Inflate( Float x, Float y, Float z );

	/**
	 * Decreases volume dimensions.
	 * @param x Horizontal offset.
	 * @param y Vertical offset.
	 * @param z Depth offset.
	 */
	Volume&													Deflate( Float x, Float y, Float z );

	/**
	 * Empties the volume by setting its coordinates to zero.
	 */
	Volume&													Empty();

	/**
	 * Copy by reference.
	 * @param other Volume to copy from.
	 */
	Volume&													operator=( const Volume& other );

	/**
	 * Tests two volumes for equality.
	 * @param other Volume to compate to.
	 * @return True for equal volumes, false otherwise.
	 */
	Bool													operator==( const Volume& other ) const;

	/**
	 * Tests two volumes for inequality.
	 * @param other Volume to compate to.
	 * @return True for unequal volumes, false otherwise.
	 */
	Bool													operator!=( const Volume& other ) const;

	/**
	 * Returns true if all volume dimensions are set to zero.
	 */
	Bool													IsNull() const;

	/**
	 * Returns true if either width or height of the volume equals to zero.
	 */
	Bool													IsEmpty() const;

	/**
	 * Retrieves volume width.
	 */
	Float													Width() const;

	/**
	 * Retrieves volume height.
	 */
	Float													Height() const;

	/**
	 * Retrieves volume depth.
	 */
	Float													Depth() const;
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_VOLUME_
