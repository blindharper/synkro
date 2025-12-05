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
// Purpose: Generic DirectX mesh reader implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_XMESHREADERIMPL_
#define _SYNKRO_SCENE_XMESHREADERIMPL_


#include "config.h"
#include "XMeshReader.h"


namespace synkro
{


namespace scene
{


// Generic DirectX mesh reader.
template <class T>
class XMeshReaderImpl :
	public T
{
public:
	// Constructors & destructor.
	XMeshReaderImpl();
	virtual ~XMeshReaderImpl();

	// XMeshReader methods.
	virtual char											ReadChar();
	virtual void											ReadAnimationSet( const lang::String& name, Bool load );
	virtual void											ReadAnimation( Bool load );
	virtual void											ReadAnimationKey( Bool load );
	virtual void											ReadFrame( const lang::String& name );
	virtual void											PopFrame();
	virtual void											ReadFrameTransformMatrix();
	virtual void											ReadMeshSkinHeader( Bool load );
	virtual void											ReadSkinWeights( Bool load );
	virtual void											GetModels( lang::Vector<ModelDesc>** models );
	virtual void											GetMaterials( lang::MapCI<lang::String, MaterialDesc>** materials );
	virtual void											GetSubMaterials( lang::Vector<SubMaterialDesc>** subMaterials );
	virtual void											GetAnimations( lang::Vector<AnimationSetDesc>** animationSets );
	virtual void											GetFrames( lang::Vector<FrameDesc>** frames );
	virtual void											GetFrameIndices( lang::Map<lang::String, Byte>** frameIndices );

protected:
	io::IStream*											_stream;
	lang::MapCI<lang::String, Byte>							_templates;
	lang::MapCI<lang::String, MaterialDesc>					_materials;
	lang::Vector<SubMaterialDesc>							_subMaterials;
	lang::Vector<ModelDesc>									_models;
	lang::Vector<AnimationSetDesc>							_animationSets;
	lang::Vector<FrameDesc>									_frames;
	lang::Stack<UInt>										_frameStack;
	lang::Map<lang::String, Byte>							_frameIndices;
	lang::String											_lastMaterialName;

	void													RegisterTemplates();
	void													RegisterTemplate( Byte type, const lang::String& name );
};


#include "XMeshReaderImpl.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_XMESHREADERIMPL_
