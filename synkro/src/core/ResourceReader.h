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
// Purpose: Defines untyped resource reader.
//==============================================================================
#ifndef _SYNKRO_CORE_RESOURCEREADER_
#define _SYNKRO_CORE_RESOURCEREADER_


#include "config.h"
#include <lang/Map.h>
#include <lang/String.h>


namespace synkro
{


namespace core
{


// Untyped resource reader.
class ResourceReader
{
public:
	// Creates resource reader from the specified stream directory.
	ResourceReader( io::IStreamDirectory* directory );

	// Gets resource stream by resource name.
	io::IStream*											GetResource( const lang::String& name ) const;

private:
	typedef lang::MapPair<lang::String, lang::String>		StringEntry;

	lang::MapCI<lang::String, lang::String>					_entries;
	io::IStreamDirectory*									_directory;

	void													Init();
};


} // core


} // synkro


#endif // _SYNKRO_CORE_RESOURCEREADER_
