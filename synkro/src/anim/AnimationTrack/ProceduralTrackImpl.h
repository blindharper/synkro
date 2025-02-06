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
// Purpose: Implements generic procedural animation track.
//==============================================================================
#ifndef _SYNKRO_ANIM_PROCEDURALTRACKIMPL_
#define _SYNKRO_ANIM_PROCEDURALTRACKIMPL_


#include "config.h"
#include <anim/AnimationTrackImpl.h>
#include <anim/IProceduralBoolTrack.h>
#include <anim/IProceduralColorGradientTrack.h>
#include <anim/IProceduralColorTrack.h>
#include <anim/IProceduralFloatRectTrack.h>
#include <anim/IProceduralFloatTrack.h>
#include <anim/IProceduralIntTrack.h>
#include <anim/IProceduralMatrix4x4Track.h>
#include <anim/IProceduralPointTrack.h>
#include <anim/IProceduralQuaternionTrack.h>
#include <anim/IProceduralRangeTrack.h>
#include <anim/IProceduralRectTrack.h>
#include <anim/IProceduralSizeTrack.h>
#include <anim/IProceduralVector3Track.h>


namespace synkro
{


namespace anim
{


// Generic procedural animation track implementation.
template <class T, UInt D>
class ProceduralTrackImpl :
	public AnimationTrackImpl<T, D>
{
public:
	// Constructor & destructor.
	ProceduralTrackImpl( const lang::String& name, const ProcedureType& procedureType );
	virtual ~ProceduralTrackImpl();

	// IProcedural<K>Track methods.
	virtual void											SetLength( Double length );
	virtual ProcedureType									GetProcedureType() const;

protected:
	ProcedureType											_procedureType;
};


#include "ProceduralTrackImpl.inl"


} // anim


} // synkro


#endif // _SYNKRO_ANIM_PROCEDURALTRACKIMPL_
