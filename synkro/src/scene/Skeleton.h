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
#ifndef _SYNKRO_SCENE_SKELETON_
#define _SYNKRO_SCENE_SKELETON_


#include "config.h"
#include <core/ObjectImpl.h>
#include <scene/ISkeleton.h>
#include <scene/ISkeletonAnimationController.h>
#include <scene/IBone.h>
#include <anim/IAnimationSet.h>
#include <lang/Map.h>
#include <lang/Vector.h>
#include "BaseSkeleton.h"
#include "BaseSceneManager.h"


namespace synkro
{


namespace scene
{


// Solid mesh skeleton implementation.
class Skeleton :
	public core::ObjectImpl<ISkeleton>,
	public BaseSkeleton,
	public Logger
{
public:
	// Constructors.
	Skeleton( BaseSceneManager* sceneManager, anim::IAnimationSystem* animationSystem, diag::ILog* log );
	Skeleton( const Skeleton& other );

	// ISkeleton methods.
	ISkeletonAnimationController*							CreateAnimationController( anim::IAnimationSet* animations, anim::AnimationListener* listener );
	IBone*													CreateBone( IBone* parent, const lang::String& name, const math::Matrix4x4& transform, const math::Matrix4x4& offset );
	void													AddAnimationSet( anim::IAnimationSet* set );
	void													Save( io::IStream* stream, const core::DataMode& mode, const MeshCodec& type );
	void													Save( io::IStream* stream, const core::DataMode& mode );
	UInt													GetBoneCount() const;
	IBone*													GetBone( UInt index ) const;
	IBone*													GetBone( const lang::String& name ) const;
	void													GetBoneTransforms( const math::Matrix4x4& worldTransform, math::Matrix4x4** transforms, UInt count ) const;
	UInt													GetAnimationSetCount() const;
	anim::IAnimationSet*									GetAnimationSet( UInt index ) const;
	anim::IAnimationSet*									GetAnimationSet( const lang::String& name ) const;
	ISkeleton*												Clone() const;

	// BaseSkeleton methods.
	void													SetBoneTransform( UInt index, const math::Matrix4x4& transform );
	void													GetBoneTransform( UInt index, math::Matrix4x4& transform ) const;
	void													GetBoneOffset( UInt index, math::Matrix4x4& offset ) const;
	IBone*													GetBoneParent( UInt index ) const;
	lang::String											GetBoneName( UInt index ) const;

private:
	struct BoneDesc
	{
		BoneDesc( IBone* bone, UInt parentIndex, const math::Matrix4x4& transform, const math::Matrix4x4& offset, const lang::String& name ) :
			Bone( bone ),
			ParentIndex( parentIndex ),
			Transform( transform ),
			Offset( offset ),
			Name( name ),
			WorldDirty( true )
		{
		}

		BoneDesc() :
			ParentIndex( none ),
			WorldDirty( false )
		{
		}

		void Update( const lang::Vector<BoneDesc>& bones, const math::Matrix4x4& worldTransform ) const
		{
			if ( WorldDirty )
			{
				if ( ParentIndex != none )
				{
					const BoneDesc& parent = bones[ParentIndex];
					parent.Update( bones, worldTransform );
					WorldTransform = parent.WorldTransform * Transform;
				}
				else
				{
					WorldTransform = worldTransform * Transform;
				}
				WorldDirty = false;
			}
		}

		P(IBone)				Bone;
		UInt					ParentIndex;
		mutable math::Matrix4x4	WorldTransform;
		math::Matrix4x4			Transform;
		math::Matrix4x4			Offset;
		lang::String			Name;
		mutable Bool			WorldDirty;
	};

	typedef lang::MapPair<lang::String, UInt>				IndexEntry;

	lang::Vector<BoneDesc>									_bones;
	lang::MapCI<lang::String, UInt>							_boneIndices;
	lang::Vector<P(anim::IAnimationSet)>					_animationSets;
	lang::MapCI<lang::String, UInt>							_animationSetIndices;
	BaseSceneManager*										_sceneManager;
	anim::IAnimationSystem*									_animationSystem;
	P(ISkeletonAnimationController)							_ctrlAnimation;
};


#include "Skeleton.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_SKELETON_
