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
// Purpose: Obj mesh reader.
//==============================================================================
#ifndef _SYNKRO_SCENE_OBJREADER_
#define _SYNKRO_SCENE_OBJREADER_


#include "config.h"
#include "ObjMesh.h"
#include "ObjStreamReader.h"


namespace synkro
{


namespace scene
{


// Obj mesh reader.
class ObjReader :
	public ObjStreamReader
{
public:
	// Constructor.
	ObjReader( io::IStream* stream );

	// Methods.
	lang::String											GetMaterialLibrary() const;
	UInt													GetModelCount() const;
	void													GetModel( UInt index, ObjModelDesc& desc ) const;

private:
	lang::Vector<ObjModelDesc>								_models;
	lang::String											_materialLibrary;

	void													Init();
	Bool													GetFace( Face& face );
};

} // scene


} // synkro


#endif // _SYNKRO_SCENE_OBJREADER_
