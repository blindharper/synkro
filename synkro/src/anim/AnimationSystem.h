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
// Purpose: Implements animation system.
//==============================================================================
#ifndef _SYNKRO_ANIM_ANIMATIONSYSTEM_
#define _SYNKRO_ANIM_ANIMATIONSYSTEM_


#include "config.h"
#include <lang/Map.h>
#include <lang/List.h>
#include <lang/Vector.h>
#include <core/ObjectImpl.h>
#include <core/ThreadPool.h>
#include <anim/IAnimationSet.h>
#include <anim/IAnimationSystem.h>
#include <anim/IPlaybackAnimationController.h>
#include <anim/IRecordAnimationController.h>
#include <anim/IAnimationCodec.h>
#include <anim/IAnimationCodecFactory.h>
#include <anim/IAnimationTrackFactory.h>
#include <anim/AnimationListener.h>
#include "Expression/ExpressionCompiler.h"
#include "BaseAnimationController.h"
#include "BaseAnimationSystem.h"


namespace synkro
{


namespace anim
{


// Animation system implementation.
class AnimationSystem :
	public core::ObjectImpl<IAnimationSystem>,
	public BaseAnimationSystem,
	public Logger
{
public:
	// Constructor & destructor.
	AnimationSystem( core::IContext* context, diag::ILog* log );
	~AnimationSystem();

	// ISystem methods.
	Bool													Update( Double delta );

	// IAnimationSystem methods.
	IAnimationSet*											CreateAnimationSet( const lang::String& name );
	IAnimation*												CreateAnimation( const lang::String& name );
	IAnimation*												CreateAnimation();
	IExpressionScript*										CreateScript( const lang::String& expression );
	IAnimationSet*											LoadAnimation( io::IStream* stream, const AnimationCodec& type );
	IAnimationSet*											LoadAnimation( io::IStream* stream );

	// BaseAnimationSystem methods.
	void													AddController( IPlaybackAnimationController* controller );
	void													AddController( IRecordAnimationController* controller );
	void													RemoveController( IPlaybackAnimationController* controller );
	void													RemoveController( IRecordAnimationController* controller );
	void													AddStopEvent( IAnimationController* sender, AnimationListener* listener );
	void													AddLoopEvent( IAnimationController* sender, AnimationListener* listener );
	IExpressionScript*										CreateScriptInternal( const lang::String& expression );
	IAnimationTrack*										CreateTrack( const lang::String& name, const AnimationTrack& type, const AnimationDataType& dataType );
	void													SaveAnimation( const IAnimationSet* animation, io::IStream* stream, const AnimationCodec& type );
	void													SaveAnimation( const IAnimationSet* animation, io::IStream* stream );
	void													SaveAnimationAsync( const IAnimationSet* animation, io::IStream* stream, const AnimationCodec& type );
	void													SaveAnimationAsync( const IAnimationSet* animation, io::IStream* stream );

	// Other methods.
	void													SetThreadPool( core::ThreadPool* threadPool );
	void													RegisterCodec( IAnimationCodecFactory* factory );
	void													RegisterTrackFactory( IAnimationTrackFactory* factory );

private:
	enum AnimationEventType
	{
		ANIMATION_EVENT_STOP,
		ANIMATION_EVENT_LOOP
	};

	struct AnimationEvent
	{
		AnimationEvent( AnimationEventType type, IAnimationController* sender, AnimationListener* listener ) :
			Type( type ),
			Sender( sender ),
			Listener( listener )
		{
		}

		AnimationEvent() :
			Type( ANIMATION_EVENT_STOP ),
			Sender( nullptr ),
			Listener( nullptr )
		{
		}

		AnimationEventType		Type;
		IAnimationController*	Sender;
		AnimationListener*		Listener;
	};

	struct RecordControllerDesc
	{
		RecordControllerDesc( IRecordAnimationController* controller ) :
			Controller( controller ),
			LastUpdated( 0.0 ),
			First( true )
		{
		}

		RecordControllerDesc() :
			Controller( nullptr ),
			LastUpdated( 0.0 ),
			First( true )
		{
		}

		IRecordAnimationController*	Controller;
		Double						LastUpdated;
		Bool						First;
	};

	typedef lang::MapPair<UInt, P(IAnimationCodec)>			CodecEntry;
	typedef lang::MapPair<UInt, P(IAnimationSet)>			SetEntry;
	typedef lang::MapPair<UInt, IAnimationTrackFactory*>	FactoryEntry;
	typedef lang::ListItem<IPlaybackAnimationController*>	ControllerEntry;

	lang::Map<UInt, P(IAnimationCodec)>						_codecs;
	lang::Map<UInt, P(IAnimationSet)>						_animationCache;
	lang::Map<UInt, IAnimationTrackFactory*>				_trackFactories;
	lang::Vector<AnimationEvent>							_events;
	lang::List<IPlaybackAnimationController*>				_playbackControllers;
	lang::Vector<RecordControllerDesc>						_recordControllers;
	core::ThreadPool*										_threadPool;
	core::IContext*											_context;
	ExpressionCompiler*										_compiler;
	Double													_time;
	Bool													_enabled;
};


#include "AnimationSystem.inl"


} // anim


} // synkro


#endif // _SYNKRO_ANIM_ANIMATIONSYSTEM_
