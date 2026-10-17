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
// Purpose: Obj mesh material reader.
//==============================================================================
#ifndef _SYNKRO_SCENE_MTLREADER_
#define _SYNKRO_SCENE_MTLREADER_


#include "config.h"
#include "ObjMaterial.h"
#include "ObjStreamReader.h"


namespace synkro
{


namespace scene
{


// Obj mesh material reader.
class MtlReader :
	public ObjStreamReader
{
public:
	// Constructor.
	MtlReader( io::IStream* stream );

	// Methods.
	UInt													GetMaterialCount() const;
	void													GetMaterial( UInt index, ObjMaterial& desc ) const;

private:
	lang::Vector<ObjMaterial>								_materials;

	void													ReadColor( img::Color& color );
	void													Init();
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_MTLREADER_
