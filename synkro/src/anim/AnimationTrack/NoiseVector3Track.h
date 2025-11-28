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
// Purpose: Implements 3-component vector noise animation track.
//==============================================================================
#ifndef _SYNKRO_ANIM_NOISEVECTOR3TRACK_
#define _SYNKRO_ANIM_NOISEVECTOR3TRACK_


#include "config.h"
#include "NoiseTrackImpl.h"
#include <anim/INoiseVector3Track.h>


namespace synkro
{


namespace anim
{


// 3-component vector noise animation track.
class NoiseVector3Track :
	public NoiseTrackImpl<INoiseVector3Track, TYPE_VECTOR3>
{
public:
	// Constructor.
	NoiseVector3Track( const lang::String& name );

	// IAnimationVector3Track methods.
	void													GetValue( Double time, math::Vector3& value ) const;
	IKeyframedVector3Track*									AsKeyframed() const;
	IProceduralVector3Track*								AsProcedural() const;
	IExpressionVector3Track*								AsExpression() const;

	// INoiseVector3Track methods.
	void													SetMagnitude( Float magnitude );
	void													SetShift( const math::Vector3 shift );
	Float													GetMagnitude() const;
	void													GetShift( math::Vector3& shift ) const;

private:
	Float													_magnitude;
	math::Vector3											_shift;
};


#include "NoiseVector3Track.inl"


} // anim


} // synkro


#endif // _SYNKRO_ANIM_NOISEVECTOR3TRACK_
