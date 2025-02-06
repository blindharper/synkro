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
// Purpose: Defines extended framework context.
//==============================================================================
#ifndef _SYNKRO_CORE_ICONTEXTEX_
#define _SYNKRO_CORE_ICONTEXTEX_


#include "config.h"
#include <core/IContext.h>
#include <lang/String.h>


namespace synkro
{


namespace core
{


/**
 * Extended framework context.
 */
iface IContextEx :
	public IContext
{
public:
	/**
	 * Creates an empty node list.
	 * @return Node list.
	 */
	virtual INodeList*										CreateNodeList() = 0;

	/**
	 * Creates an empty triangle mesh list.
	 * @return Triangle mesh list.
	 */
	virtual ITriangleMeshList*								CreateTriangleMeshList() = 0;

	/**
	 * Reads string from a stream.
	 * @param stream Stream to read from.
	 * @return Stream contents as a string.
	 */
	virtual lang::String									ReadString( io::IStream* stream ) = 0;

	/**
	 * Writes string to a stream.
	 * @param stream Stream to write to.
	 * @param text String to write to stream.
	 */
	virtual void											WriteString( io::IStream* stream, const lang::String& text ) = 0;

	/**
	 * Splits string using given delimiter.
	 * @param str String to split.
	 * @param delim Delimiter to use.
	 * @return String list containing the result of the split.
	 */
	virtual IStringList*									SplitString( const lang::String& str, Char delim ) = 0;
};


} // core


} // synkro


#endif // _SYNKRO_CORE_ICONTEXTEX_
