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
// Purpose: Obj mesh stream reader.
//==============================================================================
#ifndef _SYNKRO_SCENE_OBJSTREAMREADER_
#define _SYNKRO_SCENE_OBJSTREAMREADER_


#include "config.h"
#include <io/IStream.h>
#include <lang/Vector.h>
#include <lang/Ptr.h>


namespace synkro
{


namespace scene
{


// Obj mesh stream reader.
class ObjStreamReader
{
public:
	// Constructor & destructor.
	ObjStreamReader( io::IStream* stream );
	virtual ~ObjStreamReader();

	// Methods.
	lang::String											GetString();
	Float													GetFloat();
	Bool													GetLexem();
	Bool													PeekLexem();
	void													SkipComment();
	char													ReadChar();

protected:
	P(io::IStream)											_stream;
	lang::Vector<char>										_lexem;
	lang::Vector<char>										_lexemCache;
	char													_char;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_OBJSTREAMREADER_
