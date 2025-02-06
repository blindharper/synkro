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
// Purpose: Implements Xml animation codec.
//==============================================================================
#ifndef _SYNKRO_ANIM_XMLANIMATIONCODEC_
#define _SYNKRO_ANIM_XMLANIMATIONCODEC_


#include "config.h"
#include "AnimationCodecImpl.h"
#include <anim/IAnimationCodec.h>
#include <io/XmlReader.h>
#include <io/XmlWriter.h>
#include <lang/Convert.h>


namespace synkro
{


namespace anim
{


// Xml animation codec implementation.
class XmlAnimationCodec :
	public AnimationCodecImpl<IAnimationCodec>
{
public:
	// Constructor.
	XmlAnimationCodec( core::IContext* context );

	// IAnimationCodec methods.
	IAnimationSet*											Load( io::IStream* stream );
	void													Save( const IAnimationSet* animation, io::IStream* stream );

private:
	void													ReadTrack( io::XmlReader& rd, IKeyframedBoolTrack* track );
	void													ReadTrack( io::XmlReader& rd, IKeyframedColorGradientTrack* track );
	void													ReadTrack( io::XmlReader& rd, IKeyframedColorTrack* track );
	void													ReadTrack( io::XmlReader& rd, IKeyframedFloatRectTrack* track );
	void													ReadTrack( io::XmlReader& rd, IKeyframedFloatTrack* track );
	void													ReadTrack( io::XmlReader& rd, IKeyframedIntTrack* track );
	void													ReadTrack( io::XmlReader& rd, IKeyframedMatrix4x4Track* track );
	void													ReadTrack( io::XmlReader& rd, IKeyframedPointTrack* track );
	void													ReadTrack( io::XmlReader& rd, IKeyframedQuaternionTrack* track );
	void													ReadTrack( io::XmlReader& rd, IKeyframedRectTrack* track );
	void													ReadTrack( io::XmlReader& rd, IKeyframedSizeTrack* track );
	void													ReadTrack( io::XmlReader& rd, IKeyframedRangeTrack* track );
	void													ReadTrack( io::XmlReader& rd, IKeyframedVector3Track* track );

	void													WriteTrack( io::XmlWriter& wr, IKeyframedBoolTrack* track );
	void													WriteTrack( io::XmlWriter& wr, IKeyframedColorGradientTrack* track );
	void													WriteTrack( io::XmlWriter& wr, IKeyframedColorTrack* track );
	void													WriteTrack( io::XmlWriter& wr, IKeyframedFloatRectTrack* track );
	void													WriteTrack( io::XmlWriter& wr, IKeyframedFloatTrack* track );
	void													WriteTrack( io::XmlWriter& wr, IKeyframedIntTrack* track );
	void													WriteTrack( io::XmlWriter& wr, IKeyframedMatrix4x4Track* track );
	void													WriteTrack( io::XmlWriter& wr, IKeyframedPointTrack* track );
	void													WriteTrack( io::XmlWriter& wr, IKeyframedQuaternionTrack* track );
	void													WriteTrack( io::XmlWriter& wr, IKeyframedRectTrack* track );
	void													WriteTrack( io::XmlWriter& wr, IKeyframedSizeTrack* track );
	void													WriteTrack( io::XmlWriter& wr, IKeyframedRangeTrack* track );
	void													WriteTrack( io::XmlWriter& wr, IKeyframedVector3Track* track );
	void													WriteKey( io::XmlWriter& wr, Double time, const lang::String& value );
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_XMLANIMATIONCODEC_
