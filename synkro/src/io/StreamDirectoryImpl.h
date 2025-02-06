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
// Purpose: Generic stream directory implementation.
//==============================================================================
#ifndef _SYNKRO_IO_STREAMDIRECTORYIMPL_
#define _SYNKRO_IO_STREAMDIRECTORYIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <lang/Vector.h>
#include <lang/Mask.h>
#include <io/IStream.h>
#include <io/StreamSet.h>
#include "Path.h"


namespace synkro
{


namespace io
{


// Generic stream directory implementation.
template <class T>
class StreamDirectoryImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructors & destructor.
	StreamDirectoryImpl( IStreamDirectory* parent, const lang::String& path );
	StreamDirectoryImpl( IStreamDirectory* parent, IStream* stream );
	StreamDirectoryImpl();
	virtual ~StreamDirectoryImpl();

	// IStreamDirectory methods.
	virtual UInt											GetStreamCount() const;
	virtual IStream*										GetStream( UInt index ) const;
	virtual IStream*										GetStream( const lang::String& name ) const;
	virtual IStreamSet*										GetStreams( const lang::String& pattern ) const;
	virtual IStreamSet*										GetStreams() const;
	virtual UInt											GetDirectoryCount() const;
	virtual IStreamDirectory*								GetDirectory( UInt index ) const;
	virtual IStreamDirectory*								GetDirectory( const lang::String& name ) const;
	virtual IStreamDirectory*								GetParent() const;
	virtual lang::String									GetName() const;

protected:
	IStreamDirectory*										_parent;
	P(IStream)												_stream;
	lang::String											_path;
	lang::String											_name;
	lang::Vector<P(IStream)>								_streams;
	lang::Vector<P(IStreamDirectory)>						_dirs;
};


#include "StreamDirectoryImpl.inl"


} // io


} // synkro


#endif // _SYNKRO_IO_STREAMDIRECTORYIMPL_
