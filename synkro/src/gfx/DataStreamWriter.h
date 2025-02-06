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
// Purpose: Defines data stream writer.
//==============================================================================
#ifndef _SYNKRO_GFX_DATASTREAMWRITER_
#define _SYNKRO_GFX_DATASTREAMWRITER_


#include "config.h"
#include <gfx/IDataStream.h>


namespace synkro
{


namespace gfx
{


// Data stream writer.
class DataStreamWriter
{
public:
	// Constructor & destructor.
	DataStreamWriter( IDataStream* stream );
	~DataStreamWriter();

	// Methods.
	Bool													Open();

private:
	IDataStream*											_stream;
};


#include "DataStreamWriter.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DATASTREAMWRITER_
