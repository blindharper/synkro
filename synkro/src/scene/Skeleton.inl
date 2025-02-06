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
SYNKRO_INLINE void Skeleton::AddAnimationSet( anim::IAnimationSet* set )
{
	assert( set != nullptr );

	UInt index = _animationSetIndices.Size();
	_animationSetIndices[set->GetName()] = index;
	_animationSets.Add( set );
}

SYNKRO_INLINE UInt Skeleton::GetBoneCount() const
{
	return _bones.Size();
}

SYNKRO_INLINE IBone* Skeleton::GetBone( UInt index ) const
{
	assert( index < _bones.Size() );

	if ( index >= _bones.Size() )
		throw lang::OutOfRangeException( index, _bones.Size() );

	return _bones[index].Bone;
}

SYNKRO_INLINE IBone* Skeleton::GetBone( const lang::String& name ) const
{
	return _boneIndices.ContainsKey(name) ? GetBone( _boneIndices[name] ) : nullptr;
}

SYNKRO_INLINE UInt Skeleton::GetAnimationSetCount() const
{
	return _animationSets.Size();
}

SYNKRO_INLINE anim::IAnimationSet* Skeleton::GetAnimationSet( UInt index ) const
{
	assert( index < _animationSets.Size() );

	if ( index >= _animationSets.Size() )
		throw lang::OutOfRangeException( index, _animationSets.Size() );

	return _animationSets[index];
}

SYNKRO_INLINE anim::IAnimationSet* Skeleton::GetAnimationSet( const lang::String& name ) const
{
	return _animationSetIndices.ContainsKey(name) ? GetAnimationSet( _animationSetIndices[name] ) : nullptr;
}

SYNKRO_INLINE ISkeleton* Skeleton::Clone() const
{
	return new Skeleton( *this );
}

SYNKRO_INLINE void Skeleton::SetBoneTransform( UInt index, const math::Matrix4x4& transform )
{
	_bones[index].Transform = transform;
	_bones[index].WorldDirty = true;
}

SYNKRO_INLINE void Skeleton::GetBoneTransform( UInt index, math::Matrix4x4& transform ) const
{
	transform = _bones[index].Transform;
}

SYNKRO_INLINE void Skeleton::GetBoneOffset( UInt index, math::Matrix4x4& offset ) const
{
	offset = _bones[index].Offset;
}

SYNKRO_INLINE IBone* Skeleton::GetBoneParent( UInt index ) const
{
	UInt parentIndex = _bones[index].ParentIndex;
	return _bones[parentIndex].Bone;
}

SYNKRO_INLINE lang::String Skeleton::GetBoneName( UInt index ) const
{
	return _bones[index].Name;
}
