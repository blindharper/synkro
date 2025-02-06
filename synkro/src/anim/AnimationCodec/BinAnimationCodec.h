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
// Purpose: Implements binary animation codec.
//==============================================================================
#ifndef _SYNKRO_ANIM_BINANIMATIONCODEC_
#define _SYNKRO_ANIM_BINANIMATIONCODEC_


#include "config.h"
#include "AnimationCodecImpl.h"
#include <anim/IAnimationCodec.h>
#include <io/BinaryReader.h>
#include <io/BinaryWriter.h>
#include <lang/Convert.h>


namespace synkro
{


namespace anim
{


// Binary animation codec implementation.
class BinAnimationCodec :
	public AnimationCodecImpl<IAnimationCodec>
{
public:
	// Constructor.
	BinAnimationCodec( core::IContext* context );

	// IAnimationCodec methods.
	IAnimationSet*											Load( io::IStream* stream );
	void													Save( const IAnimationSet* animation, io::IStream* stream );

private:
	IAnimationSet*											LoadBinary( io::IStream* stream );
	void													SaveBinary( const IAnimationSet* animation, io::IStream* stream );

	void													ReadTrack( io::BinaryReader& rd, IKeyframedBoolTrack* track );
	void													ReadTrack( io::BinaryReader& rd, IKeyframedColorGradientTrack* track );
	void													ReadTrack( io::BinaryReader& rd, IKeyframedColorTrack* track );
	void													ReadTrack( io::BinaryReader& rd, IKeyframedFloatRectTrack* track );
	void													ReadTrack( io::BinaryReader& rd, IKeyframedFloatTrack* track );
	void													ReadTrack( io::BinaryReader& rd, IKeyframedIntTrack* track );
	void													ReadTrack( io::BinaryReader& rd, IKeyframedMatrix4x4Track* track );
	void													ReadTrack( io::BinaryReader& rd, IKeyframedPointTrack* track );
	void													ReadTrack( io::BinaryReader& rd, IKeyframedQuaternionTrack* track );
	void													ReadTrack( io::BinaryReader& rd, IKeyframedRectTrack* track );
	void													ReadTrack( io::BinaryReader& rd, IKeyframedSizeTrack* track );
	void													ReadTrack( io::BinaryReader& rd, IKeyframedRangeTrack* track );
	void													ReadTrack( io::BinaryReader& rd, IKeyframedVector3Track* track );

	void													WriteTrack( io::BinaryWriter& wr, IKeyframedBoolTrack* track );
	void													WriteTrack( io::BinaryWriter& wr, IKeyframedColorGradientTrack* track );
	void													WriteTrack( io::BinaryWriter& wr, IKeyframedColorTrack* track );
	void													WriteTrack( io::BinaryWriter& wr, IKeyframedFloatRectTrack* track );
	void													WriteTrack( io::BinaryWriter& wr, IKeyframedFloatTrack* track );
	void													WriteTrack( io::BinaryWriter& wr, IKeyframedIntTrack* track );
	void													WriteTrack( io::BinaryWriter& wr, IKeyframedMatrix4x4Track* track );
	void													WriteTrack( io::BinaryWriter& wr, IKeyframedPointTrack* track );
	void													WriteTrack( io::BinaryWriter& wr, IKeyframedQuaternionTrack* track );
	void													WriteTrack( io::BinaryWriter& wr, IKeyframedRectTrack* track );
	void													WriteTrack( io::BinaryWriter& wr, IKeyframedSizeTrack* track );
	void													WriteTrack( io::BinaryWriter& wr, IKeyframedRangeTrack* track );
	void													WriteTrack( io::BinaryWriter& wr, IKeyframedVector3Track* track );
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_BINANIMATIONCODEC_
