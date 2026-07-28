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
#include "config.h"
#include "PrimitiveMorphController.h"
#include <internal/Average.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


PrimitiveMorphController::PrimitiveMorphController( IPrimitive* primitive, IAnimationSystem* animationSystem, IAnimationSet* animations, AnimationListener* listener ) :
	PlaybackControllerImpl<IPrimitiveMorphController>( animationSystem, animations, listener ),
	_primitive( primitive ),
	_channels( A(ChannelDesc) ),
	_channelIndices( A(IndexEntry) ),
	_positions( A(Vector3) ),
	_sources( A(Vector3) ),
	_weights( A(Float) )
{
	// Allocate space for target positions.
	_positions.SetSize( _primitive->GetVertexCount() );
}

void PrimitiveMorphController::Start( Bool start )
{
	// Call base implementation.
	PlaybackControllerImpl<IPrimitiveMorphController>::Start( start );

	for ( UInt i = 0; i < _channels.Size(); ++i )
	{
		if ( _channels[i].TrackWeight == nullptr )
			throw InvalidOperationException( L"Not all channel weight tracks created." );
	}

	_sources.SetSize( _channels.Size() );
	_weights.SetSize( _channels.Size() );
}

void PrimitiveMorphController::Update( Double delta )
{
	// Call base implementation.
	PlaybackControllerImpl<IPrimitiveMorphController>::Update( delta );

	// Retrieve current channel weights.
	for ( UInt i = 0; i < _channels.Size(); ++i )
	{
		_channels[i].TrackWeight->GetValue( CurrentTime(), _weights[i] );
	}

	// Do morphing for every primitive vertex.
	for ( UInt p = 0; p < _positions.Size(); ++p )
	{
		for ( UInt i = 0; i < _channels.Size(); ++i )
		{
			_sources[i] = _channels[i].Positions[p];
		}
		_positions[p] = Average<Vector3>( _weights.Size(), _sources.Begin(), _weights.Begin() );
	}

	// Update target.
	_primitive->SetPositions( _positions.Begin(), 0, _positions.Size() );
}

void PrimitiveMorphController::AddChannel( const String& name, IPrimitive* channel )
{
	assert( channel != nullptr );
	assert( !_channelIndices.ContainsKey(name) );
	assert( channel->GetVertexCount() == _positions.Size() );

	if ( channel == nullptr )
		throw BadArgumentException( L"Invalid morph channel", L"channel", L"nullptr" );

	if ( _channelIndices.ContainsKey(name) )
		throw BadArgumentException( L"Morph channel with this name already exists", L"name", name );

	 if ( channel->GetVertexCount() != _positions.Size() )
		 throw BadArgumentException( L"Channel's vertex count doesn't match that of target primitive", L"channel" );

	_channelIndices[name] = _channelIndices.Size();
	ChannelDesc desc(channel);
	desc.Positions.SetSize( _positions.Size() );
	desc.Primitive->GetPositions( desc.Positions.Begin(), 0, _positions.Size() );
	_channels.Add( desc );
}

IKeyframedFloatTrack* PrimitiveMorphController::CreateChannelWeightTrack( const String& channel )
{
	VerifyChannel( channel );

	UInt index = _channelIndices[channel];
	_channels[index].TrackWeight = _animations->GetActiveAnimation()->CreateFloatTrack( channel );
	return _channels[index].TrackWeight->AsKeyframed();
}

IExpressionFloatTrack* PrimitiveMorphController::CreateChannelWeightTrack( const String& channel, IExpressionScript* script )
{
	VerifyChannel( channel );

	UInt index = _channelIndices[channel];
	_channels[index].TrackWeight = _animations->GetActiveAnimation()->CreateFloatTrack( channel, script );
	return _channels[index].TrackWeight->AsExpression();
}

IExpressionFloatTrack* PrimitiveMorphController::CreateChannelWeightTrack( const String& channel, const String& expression )
{
	VerifyChannel( channel );

	UInt index = _channelIndices[channel];
	_channels[index].TrackWeight = _animations->GetActiveAnimation()->CreateFloatTrack( channel, expression );
	return _channels[index].TrackWeight->AsExpression();
}

void PrimitiveMorphController::VerifyChannel( const String& name )
{
	assert( _channelIndices.ContainsKey(name) );

	if ( !_channelIndices.ContainsKey(name) )
		throw BadArgumentException( L"Unknown channel name", L"channel", name );
}


} // scene


} // synkro
