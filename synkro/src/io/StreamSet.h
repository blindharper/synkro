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
// Purpose: Stream set implementation.
//==============================================================================
#ifndef _SYNKRO_IO_STREAMSET_
#define _SYNKRO_IO_STREAMSET_


#include "config.h"
#include <core/ObjectImpl.h>
#include <io/IStreamSet.h>
#include <io/IStream.h>
#include <lang/Vector.h>


namespace synkro
{


namespace io
{


// Stream set implementation.
class SYNKRO_API StreamSet :
	public core::ObjectImpl<IStreamSet>
{
public:
	// Constructor.
	StreamSet();

	// IStreamSet methods.
	void													Clear();
	void													Add( IStream* stream );
	UInt													GetSize() const;
	IStream*												Get( UInt index ) const;
	UInt													IndexOf( IStream* stream ) const;

private:
	lang::Vector<P(IStream)>								_streams;
};


#include "StreamSet.inl"


} // io


} // synkro


#endif // _SYNKRO_IO_STREAMSET_
