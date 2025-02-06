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
// Purpose: Bone implementation.
//==============================================================================
SYNKRO_INLINE void Bone::SetTransform( const math::Matrix4x4& transform )
{
	_skeleton->SetBoneTransform( _index, transform );
}

SYNKRO_INLINE void Bone::GetTransform( math::Matrix4x4& transform ) const
{
	_skeleton->GetBoneTransform( _index, transform );
}

SYNKRO_INLINE void Bone::GetOffset( math::Matrix4x4& offset ) const
{
	_skeleton->GetBoneOffset( _index, offset );
}

SYNKRO_INLINE IBone* Bone::GetParent() const
{
	return _skeleton->GetBoneParent( _index );
}

SYNKRO_INLINE lang::String Bone::GetName() const
{
	return _skeleton->GetBoneName( _index );
}
