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
#include "config.h"
#include "AnimationSystem.h"
#include "AnimationSet.h"
#include "Animation.h"
#include "Expression/ExpressionScript.h"
#include "Task/SaveAnimationTask.h"
#include <anim/AnimationCodec.h>
#include <io/IStream.h>
#include <io/Path.h>
#include <internal/SafeDelete.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::diag;
using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


AnimationSystem::AnimationSystem( IContext* context, ILog* log ) :
	_codecs( A(CodecEntry) ),
	_animationCache( A(SetEntry) ),
	_trackFactories( A(FactoryEntry) ),
	_events( A(AnimationEvent) ),
	_playbackControllers( A(ControllerEntry) ),
	_recordControllers( A(RecordControllerDesc) ),
	_context( context ),
	_compiler( new ExpressionCompiler(log) ),
	_time( 0.0 ),
	Logger( log, LogFacility::AnimationSystem )
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Creating animation system...") );
}

AnimationSystem::~AnimationSystem()
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Destroying animation system...") );

	SafeDelete( _compiler );
}

Bool AnimationSystem::Update( Double delta )
{
	SynkroProfile( "AnimationSystem.Update" );

	// Update playback controllers.
	ListIterator<IPlaybackAnimationController*> it = _playbackControllers.Begin();
	for ( ; it != _playbackControllers.End(); ++it )
	{
		if ( it.IsValid() && (it->GetState() == ControllerState::Active) )
		{
			it->Update( delta );
			AsBaseAnimationController( it.Item()->value )->PostUpdate();
		}
	}

	// Notify listeners.
	for ( UInt i = 0; i < _events.Size(); ++i )
	{
		AnimationEvent& event = _events[i];
		switch ( event.Type )
		{
			case ANIMATION_EVENT_STOP: event.Listener->OnAnimationStop( event.Sender ); break;
			case ANIMATION_EVENT_LOOP: event.Listener->OnAnimationLoop( event.Sender ); break;
		}
	}
	_events.Clear();

	// Update recording controllers.
	_time += delta;
	for ( UInt i = 0; i < _recordControllers.Size(); ++i )
	{
		RecordControllerDesc& desc = _recordControllers[i];
		if ( desc.Controller->GetState() == ControllerState::Active )
		{
			const Double step = desc.Controller->GetStep();
			const Double dt = _time - desc.LastUpdated;
			if ( dt >= step )
			{
				if ( desc.First )
				{
					desc.First = false;
					desc.Controller->Reset();
					desc.Controller->Update( 0.0 );
				}
				else
				{
					desc.Controller->Update( dt );
				}
				desc.LastUpdated = _time;
			}
		}
	}

	return true;
}

IAnimationSet* AnimationSystem::CreateAnimationSet( const String& name )
{
	return new AnimationSet( this, name );
}

IAnimation* AnimationSystem::CreateAnimation( const String& name )
{
	return new Animation( this, name );
}

IAnimation* AnimationSystem::CreateAnimation()
{
	return CreateAnimation( String::Empty );
}

IExpressionScript* AnimationSystem::CreateScript( const String& expression )
{
	ExpressionScript* scr = new ExpressionScript( _compiler, expression );
	scr->DeclareParam( L"time", AnimationDataType::Float );
	return scr;
}

IAnimationSet* AnimationSystem::LoadAnimation( IStream* stream, const AnimationCodec& type )
{
	SynkroProfile( "AnimationSystem.LoadAnimation" );

	assert( stream != nullptr );

	const UInt key = stream->ID();
	LogInfoStart( MessagePriority::Lowest, Formatter::Format(L"Loading animation. Name = {0,q}. Key = 0x{1,x}.", stream->GetName(), key) );
	if ( _animationCache.ContainsKey(key) )
	{
		LogInfoEnd( Formatter::Format(L"Loaded from cache.") );
		return _animationCache[key];
	}

	IAnimationCodec* codec = _codecs[type];
	if ( codec != nullptr )
	{
		SynkroProfile( "AnimationSystem.LoadAnimation.FromStream" );

		stream->Open( OpenMode::Read );
		_animationCache[key] = codec->Load( stream );
		stream->Close();
		LogInfoEnd( Formatter::Format(L"Loaded from stream.") );
		return _animationCache[key];
	}

	return nullptr;
}

IAnimationSet* AnimationSystem::LoadAnimation( IStream* stream )
{
	String type = Path(stream->GetName()).GetExtensionWoDot();
	if ( !type.IsEmpty() )
	{
		return LoadAnimation( stream, AnimationCodec(type) );
	}
	return nullptr;
}

IExpressionScript* AnimationSystem::CreateScriptInternal( const String& expression )
{
	return CreateScript( expression );
}

IAnimationTrack* AnimationSystem::CreateTrack( const String& name, const AnimationTrack& type, const AnimationDataType& dataType )
{
	if ( !_trackFactories.ContainsKey(type) )
		throw BadArgumentException( String::Format(L"Unknown track type {0,q}.", type.ToString()), L"type", type.ToString() );

	IAnimationTrackFactory* factory = _trackFactories[type];
	if ( dataType != factory->GetType() )
		throw BadArgumentException( String::Format(L"Wrong track data type: {0,q}.", dataType.ToString()), "dataType" );

	return factory->Create( name );
}

void AnimationSystem::SaveAnimation( const IAnimationSet* animation, IStream* stream, const AnimationCodec& type )
{
	assert( animation != nullptr );
	assert( stream != nullptr );

	if ( animation == nullptr )
		throw BadArgumentException( L"Failed to save animation. Bad animation set.", L"animation" );

	if ( stream == nullptr )
		throw BadArgumentException( L"Failed to save animation. Bad stream.", L"stream" );

	IAnimationCodec* codec = _codecs[type];
	if ( codec == nullptr )
		throw BadArgumentException( String::Format(L"Failed to save animation. Unknown animation type '{0}'.", type.ToString()), L"type", type.ToString() );

	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Saving animation {0,q} to stream [{1}]. Name = {2,q}.", animation->GetName(), stream->ID(), stream->GetName()) );

	stream->Open( OpenMode::Write );
	codec->Save( animation, stream );
	stream->Close();

	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Animation {0,q} saved to stream.", animation->GetName()) );
}

void AnimationSystem::SaveAnimation( const IAnimationSet* animation, IStream* stream )
{
	String type = Path(stream->GetName()).GetExtensionWoDot();
	if ( !type.IsEmpty() )
	{
		SaveAnimation( animation, stream, AnimationCodec(type) );
	}
}

void AnimationSystem::SaveAnimationAsync( const IAnimationSet* animation, IStream* stream, const AnimationCodec& type )
{
	assert( stream != nullptr );

	if ( stream == nullptr )
		throw BadArgumentException( L"Failed to save animation. Bad stream.", L"stream" );

	IAnimationCodec* codec = _codecs[type];
	if ( codec == nullptr )
		throw BadArgumentException( String::Format(L"Failed to save animation. Unknown animation type '{0}'.", type.ToString()), L"type", type.ToString() );

	_threadPool->AddTask( new SaveAnimationTask(animation, codec, stream, _log) );
}

void AnimationSystem::SaveAnimationAsync( const IAnimationSet* animation, IStream* stream )
{
	String type = Path(stream->GetName()).GetExtensionWoDot();
	if ( !type.IsEmpty() )
	{
		SaveAnimationAsync( animation, stream, AnimationCodec(type) );
	}
}

void AnimationSystem::RemoveController( IRecordAnimationController* controller )
{
	assert( controller != nullptr );

	for ( UInt i = 0; i < _recordControllers.Size(); ++i )
	{
		if ( _recordControllers[i].Controller == controller )
		{
			_recordControllers.Remove( i );
			break;
		}
	}
}

void AnimationSystem::RegisterCodec( IAnimationCodecFactory* factory )
{
	assert( factory != nullptr );

	AnimationCodec type( factory->GetClassID() );
	LogInfoStart( MessagePriority::Lowest, Formatter::Format(L"Registering animation codec {0,q}...", type.ToString()) );
	if ( !_codecs.ContainsKey(type) )
	{
		try
		{
			_codecs[type] = factory->Create( _context );
			LogInfoEnd( Formatter::Format(Str::Done) );
		}
		catch ( const Exception& ex )
		{
			LogInfoEnd( String::Empty );
			LogWarning( MessagePriority::Normal, ex.ToString() );
		}
	}
	else
	{
		LogInfoEnd( Formatter::Format(L"Codec already registered.") );
	}
}

void AnimationSystem::RegisterTrackFactory( IAnimationTrackFactory* factory )
{
	assert( factory != nullptr );

	AnimationTrack classID( factory->GetClassID() );
	LogInfoStart( MessagePriority::Lowest, Formatter::Format(L"Registering animation track factory {0,q}...", classID.ToString()) );
	if ( !_trackFactories.ContainsKey(classID) )
	{
		try
		{
			_trackFactories[classID] = factory;
			LogInfoEnd( Formatter::Format(Str::Done) );
		}
		catch ( const Exception& ex )
		{
			LogInfoEnd( String::Empty );
			LogWarning( MessagePriority::Normal, ex.ToString() );
		}
	}
	else
	{
		LogInfoEnd( Formatter::Format(L"Factory already registered.") );
	}
}


} // anim


} // synkro
