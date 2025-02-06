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
// Purpose: Generic constraint implementation.
//==============================================================================
#ifndef _SYNKRO_CORE_CONSTRAINTIMPL_
#define _SYNKRO_CORE_CONSTRAINTIMPL_


#include "config.h"
#include "ObjectImpl.h"


namespace synkro
{


namespace core
{


// Generic constraint implementation.
template <class T>
class ConstraintImpl :
	public ObjectImpl<T>
{
public:
	// Constructors & destructor.
	ConstraintImpl();
	virtual ~ConstraintImpl();

	// IConstraint methods.
	virtual void											Enable( Bool enable );
	virtual Bool											IsEnabled() const;

protected:
	Bool													_enabled;
};


#include "ConstraintImpl.inl"


} // core


} // synkro


#endif // _SYNKRO_CORE_CONSTRAINTIMPL_
