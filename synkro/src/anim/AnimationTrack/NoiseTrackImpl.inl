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
template <class T, UInt D>
SYNKRO_INLINE NoiseTrackImpl<T, D>::NoiseTrackImpl( const lang::String& name ) :
	ProceduralTrackImpl<T, D>( name, ProcedureType::Noise ),
	_seed( 0 )
{
}

template <class T, UInt D>
SYNKRO_INLINE NoiseTrackImpl<T, D>::~NoiseTrackImpl()
{
}

template <class T, UInt D>
SYNKRO_INLINE T* NoiseTrackImpl<T, D>::AsNoise() const
{
	return (T*)this;
}

template <class T, UInt D>
SYNKRO_INLINE void NoiseTrackImpl<T, D>::SetSeed( UInt seed )
{
	_seed = seed;
}

template <class T, UInt D>
SYNKRO_INLINE UInt NoiseTrackImpl<T, D>::GetSeed() const
{
	return _seed;
}

template <class T, UInt D>
SYNKRO_INLINE Float NoiseTrackImpl<T, D>::GetNoise( UInt s ) const
{
	s += _seed;
	s = (s << 13) ^ s;
	return (1.0f - ((s * (s*s*15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0f);
}
