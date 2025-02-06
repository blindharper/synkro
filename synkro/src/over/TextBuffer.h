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
// Purpose: Text buffer.
//==============================================================================
#ifndef _SYNKRO_OVER_TEXTBUFFER_
#define _SYNKRO_OVER_TEXTBUFFER_


#include "config.h"


namespace synkro
{


namespace over
{


// Text buffer.
class TextBuffer
{
public:
	// Constructor & destructor.
	TextBuffer( gfx::IOverlayRenderObject* object );
	~TextBuffer();

	// Methods.
	Bool													IsValid() const;

	gfx::IVector4Stream*									StreamPosition;
	gfx::IVector2Stream*									StreamTexCoord;
	gfx::IVector4Stream*									StreamColor;
};


} // over


} // synkro


#endif // _SYNKRO_OVER_TEXTBUFFER_
