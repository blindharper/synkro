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
// Purpose: Implements solid mesh skeleton.
//==============================================================================
#include "config.h"
#include "Skeleton.h"
#include "SkeletonAnimationController.h"
#include "Bone.h"
#include <io/IStream.h>
#include <io/Path.h>
#include <internal/Min.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::diag;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


Skeleton::Skeleton( BaseSceneManager* sceneManager, IAnimationSystem* animationSystem, ILog* log ) :
	_bones( A(BoneDesc) ),
	_boneIndices( A(IndexEntry) ),
	_animationSets( A(P(IAnimationSet)) ),
	_animationSetIndices( A(IndexEntry) ),
	_sceneManager( sceneManager ),
	_animationSystem( animationSystem ),
	Logger( log, LogFacility::SceneManager )
{
}

Skeleton::Skeleton( const Skeleton& other ) :
	_bones( other._bones ),
	_boneIndices( other._boneIndices ),
	_animationSets( other._animationSets ),
	_animationSetIndices( other._animationSetIndices ),
	_sceneManager( other._sceneManager ),
	_animationSystem( other._animationSystem ),
	Logger( other._log, LogFacility::SceneManager )
{
	for ( UInt i = 0; i < _bones.Size(); ++i )
	{
		_bones[i].Bone = new Bone( this, (Bone*)other._bones[i].Bone.AsPtr() );
	}
}

ISkeletonAnimationController* Skeleton::CreateAnimationController( IAnimationSet* animations, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new SkeletonAnimationController( this, _animationSystem, animations, listener ) : _ctrlAnimation;
}

IBone* Skeleton::CreateBone( IBone* parent, const String& name, const Matrix4x4& transform, const Matrix4x4& offset )
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Creating bone '{0}'...", name) );

	UInt parentIndex = (parent != nullptr) ? _boneIndices[parent->GetName()] : none;
	UInt index = _boneIndices[name] = _boneIndices.Size();
	IBone* bone = new Bone( this, index );
	BoneDesc desc( bone, parentIndex, transform, offset, name );
	_bones.Add( desc );
	return bone;
}

void Skeleton::Save( IStream* stream, const DataMode& mode, const MeshCodec& type )
{
	_sceneManager->SaveSkeleton( this, stream, mode, type );
}

void Skeleton::Save( IStream* stream, const DataMode& mode )
{
	String type = Path(stream->GetName()).GetExtensionWoDot();
	if ( !type.IsEmpty() )
	{
		Save( stream, mode, MeshCodec(type) );
	}
}

void Skeleton::GetBoneTransforms( const Matrix4x4& worldTransform, Matrix4x4** transforms, UInt count ) const
{
	// Invalidate bones transforms.
	for ( UInt i = 0; i < _bones.Size(); ++i )
	{
		_bones[i].WorldDirty = true;
	}

	// Build bone hierarchy.
	UInt cnt = Min( _bones.Size(), count );
	for ( UInt i = 0; i < cnt; ++i )
	{
		const BoneDesc& bone = _bones[i];
		bone.Update( _bones, worldTransform );
		(*transforms)[i] = bone.WorldTransform * bone.Offset;
	}
}
	

} // scene


} // synkro
