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
// Purpose: Obj mesh stream writer.
//==============================================================================
#ifndef _SYNKRO_SCENE_OBJSTREAMWRITER_
#define _SYNKRO_SCENE_OBJSTREAMWRITER_


#include "config.h"
#include <io/IStream.h>
#include <lang/Vector.h>
#include <lang/Ptr.h>


namespace synkro
{


namespace scene
{


// Obj mesh stream writer.
class ObjStreamWriter
{
public:
	// Constructor & destructor.
	ObjStreamWriter( io::IStream* stream );
	virtual ~ObjStreamWriter();

	// Methods.
	void													WriteComment( const lang::String& comment );
	void													WriteString( const lang::String& value );
	void													WriteFloat( Float value );
	void													WriteUInt( UInt value );
	void													WriteChar( char value );
	void													WriteCRLF();

protected:
	P(io::IStream)											_stream;
	lang::Vector<Byte>										_buffer;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_OBJSTREAMWRITER_
