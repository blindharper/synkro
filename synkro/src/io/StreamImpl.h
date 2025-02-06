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
// Purpose: Generic stream implementation.
//==============================================================================
#ifndef _SYNKRO_IO_STREAMIMPL_
#define _SYNKRO_IO_STREAMIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <io/AccessMode.h>
#include <io/OpenMode.h>
#include <io/IoException.h>


namespace synkro
{


namespace io
{


// Generic stream implementation.
template <class T>
class StreamImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructors & destructors.
	StreamImpl( IStreamDirectory* directory, const lang::String& name );
	virtual ~StreamImpl();

	// IStream methods.
	virtual void											Open( const OpenMode& mode );
	virtual void											Close();
	virtual void											Delete();
	virtual void											SetAccessMode( const AccessMode& mode );
	virtual Bool											Exists() const;
	virtual AccessMode										GetAccessMode() const;
	virtual OpenMode										GetMode() const;
	virtual lang::String									GetName() const;
	virtual IStreamDirectory*								GetDirectory() const;

protected:
	IStreamDirectory*										_directory;
	lang::String											_name;
	AccessMode												_accessMode;
	OpenMode												_mode;
};


#include "StreamImpl.inl"


} // io


} // synkro


#endif // _SYNKRO_IO_STREAMIMPL_
