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
// Purpose: Binary DirectX mesh reader.
//==============================================================================
#ifndef _SYNKRO_SCENE_XMESHBINARYREADER_
#define _SYNKRO_SCENE_XMESHBINARYREADER_


#include "config.h"
#include "XMeshReaderImpl.h"


namespace synkro
{


namespace scene
{


// Binary DirectX mesh reader.
class XMeshBinaryReader :
	public XMeshReaderImpl<XMeshReader>
{
public:
	// Constructor.
	XMeshBinaryReader();

	// XMeshReader methods.
	void													Initialize( io::IStream* stream );
	UShort													PeekToken();
	UShort													GetToken();
	void													ReadTemplateDefinition();
	Byte													ReadTemplateName();
	lang::String											ReadName();
	void													ReadMesh( const lang::String& name );
	void													ReadMeshNormals();
	void													ReadMeshTextureCoords();
	void													ReadMeshMaterialList();
	void													ReadMaterial(const lang::String& name, Bool load );
	void													ReadTextureFilename( Bool load );
	void													ReadUnknown();

private:
	UShort													_token;

	void													Skip( UInt count );
	UInt													ReadDword();
	void													ReadIntegerList();
	void													ReadFloatList();
	Float													ReadFloat();
	void													ReadArray( lang::Vector<UInt>& array, UInt count );
	void													ReadArray( lang::Vector<Float>& array, UInt count );
	void													ReadArray( lang::Vector<math::Vector2>& array, UInt count );
	void													ReadArray( lang::Vector<math::Vector3>& array, UInt count );
	lang::String											ReadReference();
	lang::String											ReadString();
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_XMESHBINARYREADER_
