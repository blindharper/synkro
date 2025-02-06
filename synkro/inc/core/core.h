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
// Purpose: 'core' namespace includes.
//==============================================================================
#ifndef _SYNKRO_CORE_
#define _SYNKRO_CORE_


#include <core/IConfiguration.h>
#include <core/IController.h>
#include <core/IConstraint.h>
#include <core/IStringList.h>
#include <core/INodeList.h>
#include <core/ITriangleMeshList.h>
#include <core/ISynkro.h>
#include <core/IFactory.h>
#include <core/IObject.h>
#include <core/IResource.h>
#include <core/Task.h>
#include <core/Param.h>
#include <core/Platform.h>
#include <core/DataMode.h>
#include <core/ConfigurationException.h>
#include <core/VersionException.h>
#include <core/SynkroListener.h>
#include <core/TimerListener.h>
#include <core/ProgressListener.h>


#define PtrSynkro P(synkro::core::ISynkro)
#define PtrStringList P(synkro::core::IStringList)
#define PtrNodeList P(synkro::core::INodeList)
#define PtrTriangleMeshList P(synkro::core::ITriangleMeshList)
#define PtrConfiguration P(synkro::core::IConfiguration)


namespace synkro
{


/**
 * The 'core' namespace defines main framework object
 * as well as several base interfaces.
 */
namespace core
{
} // core


} // synkro


#endif // _SYNKRO_CORE_
