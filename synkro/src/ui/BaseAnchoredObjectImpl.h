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
// Purpose: Base anchored object implementation.
//=============================================================================
#ifndef _SYNKRO_UI_BASEANCHOREDOBJECTIMPL_
#define _SYNKRO_UI_BASEANCHOREDOBJECTIMPL_


#include "config.h"
#include <ui/IFrame.h>
#include <ui/IWidget.h>
#include "BaseAnchoredObject.h"


namespace synkro
{


namespace ui
{


// Base anchored object implementation.
template <class T, class O>
class BaseAnchoredObjectImpl :
	public T
{
public:
	// Constructor and destructor.
	BaseAnchoredObjectImpl( O* widget );
	virtual ~BaseAnchoredObjectImpl();

	// BaseAnchoredObject methods.
	virtual void											SaveAnchors();
	virtual void											RestoreAnchors();

protected:
	O*														_anchoredObject;
	lang::Point												_edges;
};


#include "BaseAnchoredObjectImpl.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_BASEANCHOREDOBJECTIMPL_
