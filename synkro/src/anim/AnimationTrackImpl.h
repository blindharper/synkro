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
#ifndef _SYNKRO_ANIM_ANIMATIONTRACKIMPL_
#define _SYNKRO_ANIM_ANIMATIONTRACKIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <anim/AnimationDataTypeConst.h>
#include <anim/AnimationDataType.h>


namespace synkro
{


namespace anim
{


// Generic value animation track implementation.
template <class T, UInt D>
class AnimationTrackImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	AnimationTrackImpl( const lang::String& name );
	virtual ~AnimationTrackImpl();

	// IAnimationTrack methods.
	virtual lang::String									GetName() const;
	virtual AnimationDataType								GetType() const;
	virtual Double											GetLength() const;
	virtual IAnimationBoolTrack*							AsBool() const;
	virtual IAnimationColorTrack*							AsColor() const;
	virtual IAnimationColorGradientTrack*					AsColorGradient() const;	
	virtual IAnimationFloatTrack*							AsFloat() const;
	virtual IAnimationFloatRectTrack*						AsFloatRect() const;
	virtual IAnimationIntTrack*								AsInt() const;
	virtual IAnimationMatrix4x4Track*						AsMatrix4x4() const;
	virtual IAnimationPointTrack*							AsPoint() const;
	virtual IAnimationQuaternionTrack*						AsQuaternion() const;	
	virtual IAnimationRangeTrack*							AsRange() const;
	virtual IAnimationRectTrack*							AsRect() const;
	virtual IAnimationSizeTrack*							AsSize() const;
	virtual IAnimationVector3Track*							AsVector3() const;

protected:
	lang::String											_name;
	AnimationDataType										_type;
	Double													_length;
};


#include "AnimationTrackImpl.inl"


} // anim


} // synkro


#endif // _SYNKRO_ANIM_ANIMATIONTRACKIMPL_
