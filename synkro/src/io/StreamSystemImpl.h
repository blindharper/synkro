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
// Purpose: Generic stream system implementation.
//==============================================================================
#ifndef _SYNKRO_IO_STREAMSYSTEMIMPL_
#define _SYNKRO_IO_STREAMSYSTEMIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <io/IStreamDirectory.h>
#include <io/IStream.h>
#include "Path.h"


namespace synkro
{


namespace io
{


// Generic stream system implementation.
template <class T>
class StreamSystemImpl :
	public core::ObjectImpl<T>,
	public Logger
{
public:
	// Constructor & destructor.
	StreamSystemImpl( diag::ILog* log );
	virtual ~StreamSystemImpl();

	// IStreamSystem methods.
	virtual IStream*										GetStream( const lang::String& name ) const;
	virtual IStreamDirectory*								GetDirectory( const lang::String& name ) const;

protected:
	lang::Vector<P(IStream)>								_streams;
	lang::Vector<P(IStreamDirectory)>						_dirs;
};


#include "StreamSystemImpl.inl"


} // io


} // synkro


#endif // _SYNKRO_IO_STREAMSYSTEMIMPL_
