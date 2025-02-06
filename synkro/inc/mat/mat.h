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
// Purpose: 'mat' namespace includes.
//==============================================================================
#ifndef _SYNKRO_MAT_
#define _SYNKRO_MAT_


#include <mat/IMaterialMap.h>
#include <mat/IMaterialManager.h>
#include <mat/IMultiMaterial.h>
#include <mat/IOpaqueMaterial.h>
#include <mat/ITransparentMaterial.h>
#include <mat/ITransparentMaterialAnimationController.h>
#include <mat/ISimpleMaterialAnimationController.h>


#define PtrMultiMaterial P(synkro::mat::IMultiMaterial)
#define PtrOpaqueMaterial P(synkro::mat::IOpaqueMaterial)
#define PtrSimpleMaterial P(synkro::mat::ISimpleMaterial)
#define PtrSimpleMaterialAnimationController P(synkro::mat::ISimpleMaterialAnimationController)
#define PtrTransparentMaterial P(synkro::mat::ITransparentMaterial)
#define PtrTransparentMaterialAnimationController P(synkro::mat::ITransparentMaterialAnimationController)


namespace synkro
{


/**
 * The 'mat' namespace contains interfaces
 * defining visual properties of 3D objects.
 */
namespace mat
{
} // mat


} // synkro


#endif // _SYNKRO_MAT_
