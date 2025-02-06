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
// Purpose: Defines 3D curve.
//==============================================================================
#ifndef _SYNKRO_SCENE_ICURVE_
#define _SYNKRO_SCENE_ICURVE_


#include "config.h"
#include <scene/INode.h>


namespace synkro
{


namespace scene
{


/**
 * 3D curve.
 */
iface ICurve :
	public INode
{
public:
	/**
	 * Adds a control point.
	 * @param point Point to add.
	 */
	virtual void											AddPoint( const math::Vector3& point ) = 0;

	/**
	 * Selects the given control point.
	 * @param index Index of the control point to select.
	 */
	virtual void											SelectPoint( UInt index ) = 0;

	/**
	 * Sets curve tension at the given control point.
	 * @param index Index of the control point for which to set tension.
	 * @param value Tension value. Valid range [-1.0 - 1.0]
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual void											SetTension( UInt index, Float value ) = 0;

	/**
	 * Sets curve continuity at the given control point.
	 * @param index Index of the control point for which to set continuity.
	 * @param value Continuity value. Valid range [-1.0 - 1.0]
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual void											SetContinuity( UInt index, Float value ) = 0;

	/**
	 * Sets curve bias at the given control point.
	 * @param index Index of the control point for which to set bias.
	 * @param value Bias value. Valid range [-1.0 - 1.0]
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual void											SetBias( UInt index, Float value ) = 0;

	/**
	 * Sets curve color.
	 * @param color Color to assign to curve.
	 */
	virtual void											SetColor( const img::Color& color ) = 0;

	/**
	 * Retrieves the total number of control points in the curve.
	 * @return Number of control points.
	 */
	virtual UInt											GetPointCount() const = 0;

	/**
	 * Retrieves curve's control point by index.
	 * @param index Index of the point to retrieve.
	 * @param [out] point Requested point.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual void											GetPoint( UInt index, math::Vector3& point ) const = 0;

	/**
	 * Retrieves curve tension at the given control point.
	 * @param index Index of the control point for which to retrieves tension.
	 * @exception OutOfRangeException Index is out of range.
	 * @return Tension value.
	 */
	virtual Float											GetTension( UInt index ) const = 0;

	/**
	 * Retrieves curve continuity at the given control point.
	 * @param index Index of the control point for which to retrieves continuity.
	 * @exception OutOfRangeException Index is out of range.
	 * @return Continuity value.
	 */
	virtual Float											GetContinuity( UInt index ) const = 0;

	/**
	 * Retrieves curve bias at the given control point.
	 * @param index Index of the control point for which to retrieves bias.
	 * @exception OutOfRangeException Index is out of range.
	 * @return Bias value.
	 */
	virtual Float											GetBias( UInt index ) const = 0;

	/**
	 * Retrieves curve color.
	 * @param [out] color Color value.
	 */
	virtual void											GetColor( img::Color& color ) const = 0;

	/**
	 * Retrieves position on the curve at the given phase.
	 * @param phase Phase of the curve [0.0-1.0].
	 * @param [out] position Requested point.
	 */
	virtual void											GetPosition( Float phase, math::Vector3& position ) const = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_ICURVE_
