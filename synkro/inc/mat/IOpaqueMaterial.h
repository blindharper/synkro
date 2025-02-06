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
// Purpose: Opaque material.
//==============================================================================
#ifndef _SYNKRO_MAT_IOPAQUEMATERIAL_
#define _SYNKRO_MAT_IOPAQUEMATERIAL_


#include "config.h"
#include <mat/ISimpleMaterial.h>


namespace synkro
{


namespace mat
{


/**
 * Opaque material.
 */
iface IOpaqueMaterial :
	public ISimpleMaterial
{
public:
	/**
	 * Controls whether the mesh drawn with this material looks two-sided.
	 * @param twoSided Set to true to make the mesh two-sided. Default is false.
	 */
	virtual void											SetTwoSided( Bool twoSided ) = 0;

	/**
	 * Controls whether the mesh rendered with this material looks as being made from wire.
	 * @param wireframe Set to true to make the mesh wireframed. Default is false.
	 */
	virtual void											SetWireframe( Bool wireframe ) = 0;

	/** 
	 * Checks whether the material is two-sided.
	 */
	virtual Bool											IsTwoSided() const = 0;

	/** 
	 * Checks whether the mesh rendered with this material looks as being made from wire.
	 */
	virtual Bool											IsWireframe() const = 0;

	/**
	 * Creates an exact copy of the material.
	 */
	virtual IOpaqueMaterial*								Clone() const = 0;
};


} // mat


} // synkro


#endif // _SYNKRO_MAT_IOPAQUEMATERIAL_
