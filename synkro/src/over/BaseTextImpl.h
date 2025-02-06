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
// Purpose: Generic base text implementation.
//=============================================================================
#ifndef _SYNKRO_OVER_BASETEXTIMPL_
#define _SYNKRO_OVER_BASETEXTIMPL_


#include "config.h"
#include "BaseTextPool.h"


namespace synkro
{


namespace over
{


// Generic base text implementation.
template <class T>
class BaseTextImpl :
	public T
{
public:
	// Constructor and destructor.
	BaseTextImpl( BaseTextPool* pool );
	virtual ~BaseTextImpl();
	
	// BaseText methods.
	virtual void											Update();

protected:
	BaseTextPool*											_pool;
};


#include "BaseTextImpl.inl"


} // over


} // synkro


#endif // _SYNKRO_OVER_BASETEXTIMPL_
