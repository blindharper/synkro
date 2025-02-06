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
// Purpose: Multi-material.
//==============================================================================
#ifndef _SYNKRO_MAT_IMULTIMATERIAL_
#define _SYNKRO_MAT_IMULTIMATERIAL_


#include "config.h"
#include <mat/IVisualMaterial.h>


namespace synkro
{


namespace mat
{


/**
 * Multi-material Used to draw multi-subset geometry.
 */
iface IMultiMaterial :
	public IVisualMaterial
{
public:
	/**
	 * Sets sub-material at the given index.
	 * @param index Sub-material index.
	 * @param material Sub-material to set.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual void											SetSubset( UInt index, ISimpleMaterial* material ) = 0;

	/**
	 * Retrieves sub-material by index.
	 * @param index Index of the material to retrieve.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual ISimpleMaterial*								GetSubset( UInt index ) const = 0;

	/**
	 * Creates an exact copy of the material.
	 */
	virtual IMultiMaterial*									Clone() const = 0;
};


} // mat


} // synkro


#endif // _SYNKRO_MAT_IMULTIMATERIAL_
