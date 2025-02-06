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
// Purpose: Defines material manager.
//==============================================================================
#ifndef _SYNKRO_MAT_IMATERIALMANAGER_
#define _SYNKRO_MAT_IMATERIALMANAGER_


#include "config.h"
#include <core/ISystem.h>
#include <lang/Size.h>
#include <lang/String.h>
#include <math/Matrix4x4.h>
#include <mat/LightingModel.h>


namespace synkro
{


namespace mat
{


/**
 * Material manager.
 */
iface IMaterialManager :
	public core::ISystem
{
public:
	/**
	 * Creates opaque material.
	 * @param model Lighting model.
	 * @return Created material.
	 */
	virtual IOpaqueMaterial*								CreateOpaqueMaterial( const LightingModel& model ) = 0;

	/**
	 * Creates transparent material.
	 * @param model Lighting model.
	 * @return Created material.
	 */
	virtual ITransparentMaterial*							CreateTransparentMaterial( const LightingModel& model ) = 0;

	/**
	 * Creates multi-material.
	 * @param size Number of sub-materials.
	 * @return Created material.
	 */
	virtual IMultiMaterial*									CreateMultiMaterial( UInt size ) = 0;
};


} // mat


} // synkro


#endif // _SYNKRO_MAT_IMATERIALMANAGER_
