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
// Purpose: Text DirectX mesh reader.
//==============================================================================
#ifndef _SYNKRO_SCENE_XMESHTEXTREADER_
#define _SYNKRO_SCENE_XMESHTEXTREADER_


#include "config.h"
#include "XMeshReaderImpl.h"


namespace synkro
{


namespace scene
{


// Text DirectX mesh reader.
class XMeshTextReader :
	public XMeshReaderImpl<XMeshReader>
{
public:
	// Constructor.
	XMeshTextReader();

	// XMeshReader methods.
	void													Initialize( io::IStream* stream );
	UShort													PeekToken();
	UShort													GetToken();
	char													ReadChar();
	void													ReadTemplateDefinition();
	Byte													ReadTemplateName();
	lang::String											ReadName();
	void													ReadAnimationKey( Bool load );
	void													ReadFrame( const lang::String& name );
	void													PopFrame();
	void													ReadFrameTransformMatrix();
	void													ReadMesh( const lang::String& name );
	void													ReadMeshNormals();
	void													ReadMeshTextureCoords();
	void													ReadMeshMaterialList();
	void													ReadMaterial(const lang::String& name, Bool load );
	void													ReadTextureFilename( Bool load );
	void													ReadMeshSkinHeader( Bool load );
	void													ReadSkinWeights( Bool load );
	void													ReadUnknown();

private:
	lang::Vector<char>										_lexem;
	char													_char;

	void													Put( lang::Vector<Byte>& data, UInt value );
	void													Put( lang::Vector<Byte>& data, Float value );
	char													PeekChar();
	Float													ReadFloat();
	UInt													ReadDword();
	lang::String											ReadReference();
	lang::String											ReadString();
	void													ReadFaces( lang::Vector<UInt>& array, UInt count );
	void													ReadArray( lang::Vector<UInt>& array, UInt count );
	void													ReadArray( lang::Vector<Float>& array, UInt count );
	void													ReadArray( lang::Vector<math::Vector2>& array, UInt count );
	void													ReadArray( lang::Vector<math::Vector3>& array, UInt count );
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_XMESHTEXTREADER_
