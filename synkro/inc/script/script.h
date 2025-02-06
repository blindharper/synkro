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
// Purpose: 'script' namespace includes.
//==============================================================================
#ifndef _SYNKRO_SCRIPT_
#define _SYNKRO_SCRIPT_


#include <script/IScriptObject.h>
#include <script/IScriptMachine.h>
#include <script/IScriptSystem.h>
#include <script/ScriptSystem.h>
#include <script/IScriptSystemEx.h>
#include <script/IScriptSystemFactory.h>


#define PtrScriptObject P(synkro::script::IScriptObject)
#define PtrScriptMachine P(synkro::script::IScriptMachine)


namespace synkro
{


/**
 * The 'script' namespace contains interfaces
 * used to add scripting functionality to objects created by user.
 */
namespace script
{
} // script


} // synkro


#endif // _SYNKRO_SCRIPT_
