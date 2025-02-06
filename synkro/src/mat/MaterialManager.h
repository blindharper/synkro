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
// Purpose: Material manager implementation.
//==============================================================================
#ifndef _SYNKRO_MAT_MATERIALMANAGER_
#define _SYNKRO_MAT_MATERIALMANAGER_


#include "config.h"
#include <core/ObjectImpl.h>
#include <mat/IMaterialManager.h>
#include <mat/IVisualMaterial.h>
#include <lang/Map.h>
#include <core/IContext.h>


namespace synkro
{


namespace mat
{


// Material manager implementation.
class MaterialManager :
	public core::ObjectImpl<IMaterialManager>,
	public Logger
{
public:
	// Constructor & destructor.
	MaterialManager( core::IContext* context, diag::ILog* log );
	~MaterialManager();

	// ISystem methods.
	Bool													Update( Double delta );

	// IMaterialManager methods.
	IOpaqueMaterial*										CreateOpaqueMaterial( const LightingModel& model );
	ITransparentMaterial*									CreateTransparentMaterial( const LightingModel& model );
	IMultiMaterial*											CreateMultiMaterial( UInt size );

private:
	core::IContext*											_context;
};


} // mat


} // synkro


#endif // _SYNKRO_MAT_MATERIALMANAGER_
