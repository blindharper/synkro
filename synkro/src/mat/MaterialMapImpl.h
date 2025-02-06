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
// Purpose: Generic map implementation.
//==============================================================================
#ifndef _SYNKRO_MAT_MATERIALMAPIMPL_
#define _SYNKRO_MAT_MATERIALMAPIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <img/IImage.h>


namespace synkro
{


namespace mat
{


// Generic map implementation.
template <class T>
class MaterialMapImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	MaterialMapImpl();
	virtual ~MaterialMapImpl();

	// IMap methods.
	virtual void											SetImage( img::IImage* image );
	virtual void											SetAmount( Float amount );
	virtual void											SetName( const lang::String& name );
	virtual img::IImage*									GetImage() const;
	virtual Float											GetAmount() const;
	virtual lang::String									GetName() const;

protected:
	P(img::IImage)											_image;
	Float													_amount;
	lang::String											_name;
};


#include "MaterialMapImpl.inl"


} // mat


} // synkro


#endif // _SYNKRO_MAT_MATERIALMAPIMPL_
