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
// Purpose: Defines base factory.
//==============================================================================
#ifndef _SYNKRO_CORE_BASEFACTORY_
#define _SYNKRO_CORE_BASEFACTORY_


#include "config.h"


namespace synkro
{


namespace core
{


// Base factory.
struct BaseFactory;
struct BaseFactory
{
	BaseFactory*											Next;
	IFactory*												Fact;
	virtual void											Init() = 0;
};
extern BaseFactory*											_Factories;


} // core


} // synkro


#endif // _SYNKRO_CORE_BASEFACTORY_
