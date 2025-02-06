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
// Purpose: Base overlay font.
//==============================================================================
#ifndef _SYNKRO_OVER_BASEFONT_
#define _SYNKRO_OVER_BASEFONT_


#include "config.h"
#include <over/TextDesc.h>
#include <over/TextBuffer.h>


namespace synkro
{


namespace over
{


// Base overlay font.
class BaseFont
{
public:
	virtual void											SetFrame( UInt frame ) = 0;
	virtual UInt											GetTextCapacity( const lang::String& text ) = 0;
	virtual gfx::IOverlayRenderObject*						CreateText( gfx::IOverlayRenderQueue* queue, UInt capacity, UInt order ) = 0;
	virtual UInt											DrawText( const TextBuffer& buffer, const TextDesc& desc, UInt start ) = 0;
	virtual void											UpdateColor( gfx::IOverlayRenderObject* obj, const img::Color& color, Float opacity ) = 0;
};


// Casts object to BaseFont.
#define AsBaseFont( OBJ ) dynamic_cast<BaseFont*>( OBJ )


} // over


} // synkro


#endif // _SYNKRO_OVER_BASEFONT_
