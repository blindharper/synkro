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
// Purpose: Implements DirectX mesh codec.
//==============================================================================
#ifndef _SYNKRO_SCENE_XMESHCODEC_
#define _SYNKRO_SCENE_XMESHCODEC_


#include "config.h"
#include "XMeshTextReader.h"
#include "XMeshBinaryReader.h"
#include "XMeshTextWriter.h"
#include "XMeshBinaryWriter.h"


namespace synkro
{


namespace scene
{


// DirectX mesh codec implementation.
class XMeshCodec :
	public MeshCodecImpl<IMeshCodec>
{
public:
	// Constructor & destructor.
	XMeshCodec( ISceneManager* sceneManager, mat::IMaterialManager* materialManager, img::IImageManager* imageManager, anim::IAnimationSystem* animationSystem );
	~XMeshCodec();

	// IMeshCodec methods.
	ITriangleMesh*											Load( IScene* scene, io::IStream* stream, const img::PixelFormat& format, mat::IVisualMaterial* material, ISkeleton* skeleton, UInt instanceCapacity );
	void													Save( const ITriangleMesh* mesh, io::IStream* stream, const core::DataMode& mode );

private:
	lang::MapCI<lang::String, MaterialDesc>*				_materials;
	lang::Vector<SubMaterialDesc>*							_subMaterials;
	lang::Vector<ModelDesc>*								_models;
	lang::Vector<AnimationSetDesc>*							_animationSets;
	lang::Vector<FrameDesc>*								_frames;
	lang::Map<lang::String, Byte>*							_frameIndices;
	lang::MapCI<lang::String, Byte>							_templates;
	lang::Map<UInt, P(mat::IVisualMaterial)>				_materialCache;
	lang::Map<UInt, AnimationSetCollection>					_animationCache;
	lang::Vector<char>										_lexem;
	XMeshReader*											_reader;
	XMeshTextReader*										_textReader;
	XMeshBinaryReader*										_binaryReader;
	XMeshWriter*											_writer;
	XMeshTextWriter*										_textWriter;
	XMeshBinaryWriter*										_binaryWriter;

	void													CreateReader( UInt format );
	void													CreateWriter( const core::DataMode& mode );
	void													RegisterTemplates();
	void													RegisterTemplate( Byte type, const lang::String& name );
	UInt													ReadHeader( io::IStream* stream );
	void													ReadBinary( Bool loadMaterial, Bool loadSkin, Bool loadAnimations );
	void													ReadText( Bool loadMaterial, Bool loadSkin, Bool loadAnimations );
	UShort													GetToken( io::IStream* stream );
	void													ReadTemplate( Byte type, const lang::String& name, Bool loadMaterial, Bool loadSkin, Bool loadAnimations );
	void													WriteHeader( io::IStream* stream, const core::DataMode& mode );
	mat::IVisualMaterial*									ChooseMaterial( io::IStream* stream, mat::IVisualMaterial* material, const img::PixelFormat& format, Bool loadMaps );
	void													PrepareMaterials( io::IStream* stream, const img::PixelFormat& format, Bool loadMaps );
	void													PrepareMesh( ITriangleMesh* mesh );
	void													PrepareSkeleton( ISkeleton* skeleton );
	void													PrepareSkin( ITriangleMesh* mesh );
	void													PrepareAnimation( io::IStream* stream, ISkeleton* skeleton );
	UInt*													ReadTransformTrack( anim::IAnimation* animation, UInt* ptr );
	UInt*													ReadPositionTrack( anim::IAnimation* animation, UInt* ptr );
	UInt*													ReadOrientationTrack( anim::IAnimation* animation, UInt* ptr );
	UInt*													ReadScaleTrack( anim::IAnimation* animation, UInt* ptr );
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_XMESHCODEC_
