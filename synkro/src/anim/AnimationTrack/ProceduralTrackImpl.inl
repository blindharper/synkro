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
template <class T, UInt D>
SYNKRO_INLINE ProceduralTrackImpl<T, D>::ProceduralTrackImpl( const lang::String& name, const ProcedureType& procedureType ) :
	AnimationTrackImpl<T, D>( name ),
	_procedureType( procedureType )
{
}

template <class T, UInt D>
SYNKRO_INLINE ProceduralTrackImpl<T, D>::~ProceduralTrackImpl()
{
}

template <class T, UInt D>
SYNKRO_INLINE void ProceduralTrackImpl<T, D>::SetLength( Double length )
{
	_length = length;
}

template <class T, UInt D>
SYNKRO_INLINE ProcedureType ProceduralTrackImpl<T, D>::GetProcedureType() const
{
	return _procedureType;
}
