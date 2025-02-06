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
// Purpose: Defines a particular stream.
//==============================================================================
#include "config.h"
#include "StreamEx.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace io
{


StreamEx::StreamEx( IStreamDirectory* dir, IStream* stream ) :
	StreamImpl<IStream>( dir, stream->GetName() ),
	_stream( stream )
{
}


} // io


} // synkro
