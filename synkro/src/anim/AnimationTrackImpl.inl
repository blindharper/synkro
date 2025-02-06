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
// Purpose: Generic value animation track implementation.
//==============================================================================
template <class T, UInt D>
SYNKRO_INLINE AnimationTrackImpl<T, D>::AnimationTrackImpl( const lang::String& name ) :
	_name( name ),
	_type( (AnimationDataType)D ),
	_length( 0.0 )
{
}

template <class T, UInt D>
SYNKRO_INLINE AnimationTrackImpl<T, D>::~AnimationTrackImpl()
{
}

template <class T, UInt D>
SYNKRO_INLINE lang::String AnimationTrackImpl<T, D>::GetName() const
{
	return _name;
}

template <class T, UInt D>
SYNKRO_INLINE AnimationDataType AnimationTrackImpl<T, D>::GetType() const
{
	return _type;
}

template <class T, UInt D>
SYNKRO_INLINE Double AnimationTrackImpl<T, D>::GetLength() const
{
	return _length;
}

template <class T, UInt D>
SYNKRO_INLINE IAnimationBoolTrack* AnimationTrackImpl<T, D>::AsBool() const
{
	return (_type == AnimationDataType::Bool) ? (IAnimationBoolTrack*)this : nullptr;
}

template <class T, UInt D>
SYNKRO_INLINE IAnimationColorTrack* AnimationTrackImpl<T, D>::AsColor() const
{
	return (_type == AnimationDataType::Color) ? (IAnimationColorTrack*)this : nullptr;
}

template <class T, UInt D>
SYNKRO_INLINE IAnimationColorGradientTrack* AnimationTrackImpl<T, D>::AsColorGradient() const
{
	return (_type == AnimationDataType::ColorGradient) ? (IAnimationColorGradientTrack*)this : nullptr;
}

template <class T, UInt D>
SYNKRO_INLINE IAnimationFloatTrack* AnimationTrackImpl<T, D>::AsFloat() const
{
	return (_type == AnimationDataType::Float) ? (IAnimationFloatTrack*)this : nullptr;
}

template <class T, UInt D>
SYNKRO_INLINE IAnimationFloatRectTrack* AnimationTrackImpl<T, D>::AsFloatRect() const
{
	return (_type == AnimationDataType::FloatRect) ? (IAnimationFloatRectTrack*)this : nullptr;
}

template <class T, UInt D>
SYNKRO_INLINE IAnimationIntTrack* AnimationTrackImpl<T, D>::AsInt() const
{
	return (_type == AnimationDataType::Int) ? (IAnimationIntTrack*)this : nullptr;
}

template <class T, UInt D>
SYNKRO_INLINE IAnimationMatrix4x4Track* AnimationTrackImpl<T, D>::AsMatrix4x4() const
{
	return (_type == AnimationDataType::Matrix4x4) ? (IAnimationMatrix4x4Track*)this : nullptr;
}

template <class T, UInt D>
SYNKRO_INLINE IAnimationPointTrack* AnimationTrackImpl<T, D>::AsPoint() const
{
	return (_type == AnimationDataType::Point) ? (IAnimationPointTrack*)this : nullptr;
}

template <class T, UInt D>
SYNKRO_INLINE IAnimationQuaternionTrack* AnimationTrackImpl<T, D>::AsQuaternion() const
{
	return (_type == AnimationDataType::Quaternion) ? (IAnimationQuaternionTrack*)this : nullptr;
}

template <class T, UInt D>
SYNKRO_INLINE IAnimationRangeTrack* AnimationTrackImpl<T, D>::AsRange() const
{
	return (_type == AnimationDataType::Range) ? (IAnimationRangeTrack*)this : nullptr;
}

template <class T, UInt D>
SYNKRO_INLINE IAnimationRectTrack* AnimationTrackImpl<T, D>::AsRect() const
{
	return (_type == AnimationDataType::Rect) ? (IAnimationRectTrack*)this : nullptr;
}

template <class T, UInt D>
SYNKRO_INLINE IAnimationSizeTrack* AnimationTrackImpl<T, D>::AsSize() const
{
	return (_type == AnimationDataType::Size) ? (IAnimationSizeTrack*)this : nullptr;
}

template <class T, UInt D>
SYNKRO_INLINE IAnimationVector3Track* AnimationTrackImpl<T, D>::AsVector3() const
{
	return (_type == AnimationDataType::Vector3) ? (IAnimationVector3Track*)this : nullptr;
}
