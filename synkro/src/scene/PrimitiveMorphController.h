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
// Purpose: Morph controller for primitive.
//==============================================================================
#ifndef _SYNKRO_SCENE_PRIMITIVEMORPHCONTROLLER_
#define _SYNKRO_SCENE_PRIMITIVEMORPHCONTROLLER_


#include "config.h"
#include <anim/PlaybackControllerImpl.h>
#include <scene/IPrimitiveMorphController.h>
#include <scene/IPrimitive.h>
#include <lang/Vector.h>
#include <lang/Map.h>


namespace synkro
{


namespace scene
{


// Morph controller for primitive.
class PrimitiveMorphController :
	public anim::PlaybackControllerImpl<IPrimitiveMorphController>
{
public:
	// Constructor.
	PrimitiveMorphController( IPrimitive* primitive, anim::IAnimationSystem* animationSystem, anim::IAnimationSet* animations, anim::AnimationListener* listener );

	// IController methods.
	void													Start( Bool start );
	void													Update( Double delta );

	// IPrimitiveMorphController methods.
	void													AddChannel( const lang::String& name, IPrimitive* channel );
	anim::IKeyframedFloatTrack*								CreateChannelWeightTrack( const lang::String& channel );
	anim::IExpressionFloatTrack*							CreateChannelWeightTrack( const lang::String& channel, anim::IExpressionScript* script );
	anim::IExpressionFloatTrack*							CreateChannelWeightTrack( const lang::String& channel, const lang::String& expression );

private:
	struct ChannelDesc
	{
		ChannelDesc( IPrimitive* primitive ) :
			Primitive( primitive ),
			Positions( A(math::Vector3) )
		{
		}

		ChannelDesc() :
			Positions( A(math::Vector3) )
		{
		}

		P(IPrimitive)					Primitive;
		P(anim::IAnimationFloatTrack)	TrackWeight;
		lang::Vector<math::Vector3>		Positions;
	};

	typedef lang::MapPair<lang::String, UInt>				IndexEntry;

	IPrimitive*												_primitive;
	lang::Vector<ChannelDesc>								_channels;
	lang::MapCI<lang::String, UInt>							_channelIndices;
	lang::Vector<math::Vector3>								_positions;
	lang::Vector<math::Vector3>								_sources;
	lang::Vector<Float>										_weights;

	void													VerifyChannel( const lang::String& name );
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_PRIMITIVEMORPHCONTROLLER_
