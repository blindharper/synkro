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
// Purpose: Obj mesh material writer.
//==============================================================================
#ifndef _SYNKRO_SCENE_MTLWRITER_
#define _SYNKRO_SCENE_MTLWRITER_


#include "config.h"
#include "ObjMaterial.h"
#include "ObjStreamWriter.h"


namespace synkro
{


namespace scene
{


// Obj mesh material writer.
class MtlWriter :
	public ObjStreamWriter
{
public:
	// Constructor.
	MtlWriter( io::IStream* stream );

	// Methods.
	void													Write( const ObjMaterial& desc );

private:
	void													Write( const lang::String& name, const img::Color& color );
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_MTLWRITER_
