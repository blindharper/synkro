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
// Purpose: Defines typed buffer resource.
//==============================================================================
#ifndef _SYNKRO_GFX_ITYPEDBUFFER_
#define _SYNKRO_GFX_ITYPEDBUFFER_


#include "config.h"
#include <gfx/IBuffer.h>
#include <gfx/ProgramDataType.h>
#include <math/Vector2.h>
#include <math/Vector3.h>
#include <math/Vector4.h>
#include <math/Matrix4x4.h>


namespace synkro
{


namespace gfx
{


/**
 * Typed buffer resource.
 */
iface ITypedBuffer :
	public IBuffer
{
public:
	/**
	 * Sets an array of floating-point numbers.
	 * @param value Pointer to the first element's data.
	 * @param count Number of array elements.
	 */
	virtual void											Set( const Float* value, UInt count ) = 0;

	/**
	 * Sets an array of 2-component vector.
	 * @param value Pointer to the first element's data.
	 * @param count Number of array elements.
	 */
	virtual void											Set( const math::Vector2* value, UInt count ) = 0;

	/**
	 * Sets an array of 3-component vector.
	 * @param value Pointer to the first element's data.
	 * @param count Number of array elements.
	 */
	virtual void											Set( const math::Vector3* value, UInt count ) = 0;

	/**
	 * Sets an array of 4-component vector.
	 * @param value Pointer to the first element's data.
	 * @param count Number of array elements.
	 */
	virtual void											Set( const math::Vector4* value, UInt count ) = 0;

	/**
	 * Sets an array of matrices.
	 * @param value Pointer to the first element's data.
	 * @param count Number of array elements.
	 */
	virtual void											Set( const math::Matrix4x4* value, UInt count ) = 0;

	/**
	 * Retrieves buffer data type.
	 */
	virtual ProgramDataType									GetDataType() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_ITYPEDBUFFER_
