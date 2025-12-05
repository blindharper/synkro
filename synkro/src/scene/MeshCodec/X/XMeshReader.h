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
// Purpose: Abstract DirectX mesh reader.
//==============================================================================
#ifndef _SYNKRO_SCENE_XMESHREADER_
#define _SYNKRO_SCENE_XMESHREADER_


#include "config.h"
#include "XMesh.h"


namespace synkro
{


namespace scene
{


// Abstract DirectX mesh reader.
class XMeshReader
{
public:
	virtual void											Initialize( io::IStream* stream ) = 0;
	virtual UShort											PeekToken() = 0;
	virtual UShort											GetToken() = 0;
	virtual char											ReadChar() = 0;
	virtual void											ReadTemplateDefinition() = 0;
	virtual Byte											ReadTemplateName() = 0;
	virtual lang::String									ReadName() = 0;
	virtual void											ReadAnimationSet( const lang::String& name, Bool load ) = 0;
	virtual void											ReadAnimation( Bool load ) = 0;
	virtual void											ReadAnimationKey( Bool load ) = 0;
	virtual void											ReadFrame( const lang::String& name ) = 0;
	virtual void											PopFrame() = 0;
	virtual void											ReadFrameTransformMatrix() = 0;
	virtual void											ReadMesh( const lang::String& name ) = 0;
	virtual void											ReadMeshNormals() = 0;
	virtual void											ReadMeshTextureCoords() = 0;
	virtual void											ReadMeshMaterialList() = 0;
	virtual void											ReadMaterial( const lang::String& name, Bool load ) = 0;
	virtual void											ReadTextureFilename( Bool load ) = 0;
	virtual void											ReadMeshSkinHeader( Bool load ) = 0;
	virtual void											ReadSkinWeights( Bool load ) = 0;
	virtual void											ReadUnknown() = 0;
	virtual void											GetModels( lang::Vector<ModelDesc>** models ) = 0;
	virtual void											GetMaterials( lang::MapCI<lang::String, MaterialDesc>** materials ) = 0;
	virtual void											GetSubMaterials( lang::Vector<SubMaterialDesc>** subMaterials ) = 0;
	virtual void											GetAnimations( lang::Vector<AnimationSetDesc>** animationSets ) = 0;
	virtual void											GetFrames( lang::Vector<FrameDesc>** frames ) = 0;
	virtual void											GetFrameIndices( lang::Map<lang::String, Byte>** frameIndices ) = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_XMESHREADER_
