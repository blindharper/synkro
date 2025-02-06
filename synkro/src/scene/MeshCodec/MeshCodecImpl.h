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
// Purpose: Generic mesh codec implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_MESHCODECIMPL_
#define _SYNKRO_SCENE_MESHCODECIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <anim/IAnimationSystem.h>
#include <anim/IAnimationSet.h>
#include <anim/IAnimation.h>
#include <anim/IKeyframedVector3Track.h>
#include <anim/IKeyframedMatrix4x4Track.h>
#include <anim/IKeyframedQuaternionTrack.h>
#include <img/IImageManager.h>
#include <mat/IMaterialManager.h>
#include <scene/ISceneManager.h>
#include <scene/ISceneEx.h>
#include <scene/ITriangleMesh.h>
#include <scene/ISkeleton.h>
#include <core/DataMode.h>
#include <gfx/IndexType.h>


namespace synkro
{


namespace scene
{


// Generic mesh codec implementation.
template <class T>
class MeshCodecImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	MeshCodecImpl( ISceneManager* sceneManager, mat::IMaterialManager* materialManager, img::IImageManager* imageManager, anim::IAnimationSystem* animationSystem );
	virtual ~MeshCodecImpl();

	// IMeshCodec methods.
	virtual ITriangleMesh*									Load( IScene* scene, io::IStream* stream, const img::PixelFormat& format, mat::IVisualMaterial* material, ISkeleton* skeleton, UInt instanceCapacity );
	virtual ISkeleton*										Load( io::IStream* stream );
	virtual void											Save( const ITriangleMesh* mesh, io::IStream* stream, const core::DataMode& mode );
	virtual void											Save( const ISkeleton* skeleton, io::IStream* stream, const core::DataMode& mode );

protected:
	ISceneManager*											_sceneManager;
	mat::IMaterialManager*									_materialManager;
	img::IImageManager*										_imageManager;
	anim::IAnimationSystem*									_animationSystem;
};


#include "MeshCodecImpl.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_MESHCODECIMPL_
