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
// Purpose: Generic IObject interface implementation.
//==============================================================================
#ifndef _SYNKRO_CORE_OBJECTIMPL_
#define _SYNKRO_CORE_OBJECTIMPL_


#include "config.h"
#include <core/IObject.h>
#include <core/Str.h>
#include <core/Platform.h>
#include <lang/Ptr.h>
#include <lang/BadArgumentException.h>
#include <lang/OutOfRangeException.h>
#include <lang/InvalidOperationException.h>
#include <lang/NotSupportedException.h>
#include <lang/Formatter.h>
#include <internal/Average.h>
#include <internal/Clamp.h>
#include <internal/Compare.h>
#include <internal/Copy.h>
#include <internal/Lerp.h>
#include <internal/Logger.h>
#include <internal/SizeOf.h>
#include <internal/ToColor.h>
#include <internal/ToVector.h>
#include <internal/Zero.h>
#include <mem/OperatorNew.h>
#include <prf/Profiler.h>


namespace synkro
{


namespace core
{


// Standard implementation of IObject interface.
template <class T>
class ObjectImpl :
	public T
{
public:
	// Constructors & destructor.
	ObjectImpl();
	virtual ~ObjectImpl();

	// IObject methods.
	Int														AddRef();
	Int														Release();
	UInt													ID() const;

private:
	UInt													_id;
	Int														_refCount;
};


#include "ObjectImpl.inl"


} // core


} // synkro


#define new SYNKRO_NEW


#endif // _SYNKRO_CORE_OBJECTIMPL_
