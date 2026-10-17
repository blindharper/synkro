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
// Purpose: Obj mesh writer.
//==============================================================================
#ifndef _SYNKRO_SCENE_OBJWRITER_
#define _SYNKRO_SCENE_OBJWRITER_


#include "config.h"
#include "ObjStreamWriter.h"
#include "ObjMesh.h"
#include <math/Vector2.h>
#include <math/Vector3.h>


namespace synkro
{


namespace scene
{


// Obj mesh writer.
class ObjWriter :
	public ObjStreamWriter
{
public:
	// Constructor.
	ObjWriter( io::IStream* stream );

	// Methods.
	void													WriteMaterialLibrary( const lang::String& name );
	void													WriteMaterial( const lang::String& name );
	void													WriteSubset( const lang::String& name );
	void													WriteTexCoords( const lang::Vector<math::Vector2>& array );
	void													WritePositions( const lang::Vector<math::Vector3>& array );
	void													WriteNormals( const lang::Vector<math::Vector3>& array );
	void													WriteFaces( const lang::Vector<Face>& array );
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_OBJWRITER_
