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
#include "config.h"
#include "MaterialManager.h"
#include "OpaqueMaterial.h"
#include "TransparentMaterial.h"
#include "MultiMaterial.h"
#include <gfx/IGraphicsSystemEx.h>
#include <gfx/IFrameRenderWindowEx.h>
#include <gfx/IViewRenderWindowEx.h>
#include <io/IStreamDirectory.h>
#include <img/IImageManager.h>
#include <mat/ISimpleMaterial.h>
#include <mat/IMaterialMap.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::diag;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::math;
using namespace synkro::scene;

//------------------------------------------------------------------------------


namespace synkro
{


namespace mat
{


MaterialManager::MaterialManager( IContext* context, ILog* log ) :
	_context( context ),
	Logger( log, LogFacility::MaterialManager )
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Creating material manager...") );
}

MaterialManager::~MaterialManager()
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Destroying material manager...") );
}

Bool MaterialManager::Update( Double delta )
{
	// Do nothing.
	return true;
}

IOpaqueMaterial* MaterialManager::CreateOpaqueMaterial( const LightingModel& model )
{
	return new OpaqueMaterial( _context, model );
}

ITransparentMaterial* MaterialManager::CreateTransparentMaterial( const LightingModel& model )
{
	return new TransparentMaterial( _context, model );
}

IMultiMaterial* MaterialManager::CreateMultiMaterial( UInt size )
{
	return new MultiMaterial( size );
}


} // mat


} // synkro
