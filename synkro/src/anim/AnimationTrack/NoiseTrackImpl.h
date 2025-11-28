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
// Purpose: Implements generic noise animation track.
//==============================================================================
#ifndef _SYNKRO_ANIM_NOISETRACKIMPL_
#define _SYNKRO_ANIM_NOISETRACKIMPL_

#include "config.h"
#include "ProceduralTrackImpl.h"


namespace synkro
{


namespace anim
{


// Generic noise animation track implementation.
template <class T, UInt D>
class NoiseTrackImpl :
	public ProceduralTrackImpl<T, D>
{
public:
	// Constructor & destructor.
	NoiseTrackImpl( const lang::String& name );
	virtual ~NoiseTrackImpl();

	// IProceduralFloatTrack methods.
	virtual T*												AsNoise() const;

	// INoise<K>Track methods.
	virtual void											SetSeed( UInt seed );
	virtual UInt											GetSeed() const;

protected:
	UInt													_seed;

	Float													GetNoise( UInt s ) const;
};


#include "NoiseTrackImpl.inl"


} // anim


} // synkro


#endif // _SYNKRO_ANIM_NOISETRACKIMPL_
