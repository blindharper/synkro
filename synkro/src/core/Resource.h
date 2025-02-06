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
// Purpose: Resource implementation.
//==============================================================================
#ifndef _SYNKRO_CORE_RESOURCE_
#define _SYNKRO_CORE_RESOURCE_


#include "config.h"
#include <core/IResource.h>
#ifdef SYNKRO_STATIC
#include "BaseResource.h"
#endif // SYNKRO_STATIC


namespace synkro
{


namespace core
{


// Resource implementation.
class SYNKRO_API Resource :
	public IResource
#ifdef SYNKRO_STATIC
	, public BaseResource
#endif // SYNKRO_STATIC
{
public:
	// Constructors.
	Resource( const ResourceType& type, const Byte* data, UInt size );
	Resource( UInt id, const Byte* data, UInt size );

	// IResource methods.
	io::IStreamDirectory*									Load();
	ResourceType											GetType() const;
	UInt													ID() const;

private:
	ResourceType											_type;
	const Byte*												_data;
	UInt													_size;
	UInt													_id;

#ifdef SYNKRO_STATIC
	void													Init();
#endif // SYNKRO_STATIC
};


} // core


} // synkro


#endif // _SYNKRO_CORE_RESOURCE_
