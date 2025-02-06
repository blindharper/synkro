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
// Purpose: Implements generic animation.
//==============================================================================
#include "config.h"
#include "Animation.h"
#include "KeyframedTrackImpl.h"
#include "Expression/ExpressionTrackImpl.h"
#include "AnimationTrack/ProceduralTrackImpl.h"
#include <anim/AnimationDataTypeConst.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


Animation::Animation( BaseAnimationSystem* animationSystem, const String& name ) :
	_animationSystem( animationSystem ),
	_tracks( A(P(IAnimationTrack)) ),
	_indexes( A(IndexEntry) ),
	_name( name )
{
}

Animation::Animation( BaseAnimationSystem* animationSystem ) :
	_animationSystem( animationSystem ),
	_tracks( A(P(IAnimationTrack)) ),
	_indexes( A(IndexEntry) )
{
}

IKeyframedBoolTrack* Animation::CreateBoolTrack( const String& name )
{
	VerifyName( name );
	IKeyframedBoolTrack* track = new KeyframedBoolTrack( name );
	AddTrack( track );
	return track;
}

IExpressionBoolTrack* Animation::CreateBoolTrack( const String& name, IExpressionScript* script )
{
	VerifyName( name );
	PrepareValidate( script, AnimationDataType::Bool );
	IExpressionBoolTrack* track = new ExpressionBoolTrack( name, script );
	AddTrack( track );
	return track;
}

IExpressionBoolTrack* Animation::CreateBoolTrack( const String& name, const String& expression )
{
	return CreateBoolTrack( name, _animationSystem->CreateScriptInternal(expression) );
}

IKeyframedColorTrack* Animation::CreateColorTrack( const String& name )
{
	VerifyName( name );
	IKeyframedColorTrack* track = new KeyframedColorTrack( name );
	AddTrack( track );
	return track;
}

IExpressionColorTrack* Animation::CreateColorTrack( const String& name, IExpressionScript* script )
{
	VerifyName( name );
	PrepareValidate( script, AnimationDataType::Color );
	IExpressionColorTrack* track = new ExpressionColorTrack( name, script );
	AddTrack( track );
	return track;
}

IExpressionColorTrack* Animation::CreateColorTrack( const String& name, const String& expression )
{
	return CreateColorTrack( name, _animationSystem->CreateScriptInternal(expression) );
}

IProceduralColorTrack* Animation::CreateColorTrack( const String& name, const AnimationTrack& type )
{
	VerifyName( name );
	IProceduralColorTrack* track = _animationSystem->CreateTrack( name, type, AnimationDataType::Color )->AsColor()->AsProcedural();
	AddTrack( track );
	return track;
}

IKeyframedColorGradientTrack* Animation::CreateColorGradientTrack( const String& name )
{
	VerifyName( name );
	IKeyframedColorGradientTrack* track = new KeyframedColorGradientTrack( name );
	AddTrack( track );
	return track;
}

IExpressionColorGradientTrack* Animation::CreateColorGradientTrack( const String& name, IExpressionScript* script )
{
	VerifyName( name );
	PrepareValidate( script, AnimationDataType::ColorGradient );
	IExpressionColorGradientTrack* track = new ExpressionColorGradientTrack( name, script );
	AddTrack( track );
	return track;
}

IExpressionColorGradientTrack* Animation::CreateColorGradientTrack( const String& name, const String& expression )
{
	return CreateColorGradientTrack( name, _animationSystem->CreateScriptInternal(expression) );
}

IKeyframedFloatTrack* Animation::CreateFloatTrack( const String& name )
{
	VerifyName( name );
	IKeyframedFloatTrack* track = new KeyframedFloatTrack( name );
	AddTrack( track );
	return track;
}

IExpressionFloatTrack* Animation::CreateFloatTrack( const String& name, IExpressionScript* script )
{
	VerifyName( name );
	PrepareValidate( script, AnimationDataType::Float );
	IExpressionFloatTrack* track = new ExpressionFloatTrack( name, script );
	AddTrack( track );
	return track;
}

IExpressionFloatTrack* Animation::CreateFloatTrack( const String& name, const String& expression )
{
	return CreateFloatTrack( name, _animationSystem->CreateScriptInternal(expression) );
}

IProceduralFloatTrack* Animation::CreateFloatTrack( const String& name, const AnimationTrack& type )
{
	VerifyName( name );
	IProceduralFloatTrack* track = _animationSystem->CreateTrack( name, type, AnimationDataType::Float )->AsFloat()->AsProcedural();
	AddTrack( track );
	return track;
}

IKeyframedFloatRectTrack* Animation::CreateFloatRectTrack( const String& name )
{
	VerifyName( name );
	IKeyframedFloatRectTrack* track = new KeyframedFloatRectTrack( name );
	AddTrack( track );
	return track;
}

IExpressionFloatRectTrack* Animation::CreateFloatRectTrack( const String& name, IExpressionScript* script )
{
	VerifyName( name );
	PrepareValidate( script, AnimationDataType::FloatRect );
	IExpressionFloatRectTrack* track = new ExpressionFloatRectTrack( name, script );
	AddTrack( track );
	return track;
}

IExpressionFloatRectTrack* Animation::CreateFloatRectTrack( const String& name, const String& expression )
{
	return CreateFloatRectTrack( name, _animationSystem->CreateScriptInternal(expression) );
}

IKeyframedIntTrack* Animation::CreateIntTrack( const String& name )
{
	VerifyName( name );
	IKeyframedIntTrack* track = new KeyframedIntTrack( name );
	AddTrack( track );
	return track;
}

IExpressionIntTrack* Animation::CreateIntTrack( const String& name, IExpressionScript* script )
{
	VerifyName( name );
	PrepareValidate( script, AnimationDataType::Int );
	IExpressionIntTrack* track = new ExpressionIntTrack( name, script );
	AddTrack( track );
	return track;
}

IExpressionIntTrack* Animation::CreateIntTrack( const String& name, const String& expression )
{
	return CreateIntTrack( name, _animationSystem->CreateScriptInternal(expression) );
}

IKeyframedMatrix4x4Track* Animation::CreateMatrix4x4Track( const String& name )
{
	VerifyName( name );
	IKeyframedMatrix4x4Track* track = new KeyframedMatrix4x4Track( name );
	AddTrack( track );
	return track;
}

IExpressionMatrix4x4Track* Animation::CreateMatrix4x4Track( const String& name, IExpressionScript* script )
{
	VerifyName( name );
	PrepareValidate( script, AnimationDataType::Matrix4x4 );
	IExpressionMatrix4x4Track* track = new ExpressionMatrix4x4Track( name, script );
	AddTrack( track );
	return track;
}

IExpressionMatrix4x4Track* Animation::CreateMatrix4x4Track( const String& name, const String& expression )
{
	return CreateMatrix4x4Track( name, _animationSystem->CreateScriptInternal(expression) );
}

IKeyframedPointTrack* Animation::CreatePointTrack( const String& name )
{
	VerifyName( name );
	IKeyframedPointTrack* track = new KeyframedPointTrack( name );
	AddTrack( track );
	return track;
}

IExpressionPointTrack* Animation::CreatePointTrack( const String& name, IExpressionScript* script )
{
	VerifyName( name );
	PrepareValidate( script, AnimationDataType::Point );
	IExpressionPointTrack* track = new ExpressionPointTrack( name, script );
	AddTrack( track );
	return track;
}

IExpressionPointTrack* Animation::CreatePointTrack( const String& name, const String& expression )
{
	return CreatePointTrack( name, _animationSystem->CreateScriptInternal(expression) );
}

IKeyframedQuaternionTrack* Animation::CreateQuaternionTrack( const String& name )
{
	VerifyName( name );
	IKeyframedQuaternionTrack* track = new KeyframedQuaternionTrack( name );
	AddTrack( track );
	return track;
}

IExpressionQuaternionTrack* Animation::CreateQuaternionTrack( const String& name, IExpressionScript* script )
{
	VerifyName( name );
	PrepareValidate( script, AnimationDataType::Quaternion );
	IExpressionQuaternionTrack* track = new ExpressionQuaternionTrack( name, script );
	AddTrack( track );
	return track;
}

IExpressionQuaternionTrack* Animation::CreateQuaternionTrack( const String& name, const String& expression )
{
	return CreateQuaternionTrack( name, _animationSystem->CreateScriptInternal(expression) );
}

IKeyframedRangeTrack* Animation::CreateRangeTrack( const String& name )
{
	VerifyName( name );
	IKeyframedRangeTrack* track = new KeyframedRangeTrack( name );
	AddTrack( track );
	return track;
}

IExpressionRangeTrack* Animation::CreateRangeTrack( const String& name, IExpressionScript* script )
{
	VerifyName( name );
	PrepareValidate( script, AnimationDataType::Range );
	IExpressionRangeTrack* track = new ExpressionRangeTrack( name, script );
	AddTrack( track );
	return track;
}

IExpressionRangeTrack* Animation::CreateRangeTrack( const String& name, const String& expression )
{
	return CreateRangeTrack( name, _animationSystem->CreateScriptInternal(expression) );
}

IKeyframedRectTrack* Animation::CreateRectTrack( const String& name )
{
	VerifyName( name );
	IKeyframedRectTrack* track = new KeyframedRectTrack( name );
	AddTrack( track );
	return track;
}

IExpressionRectTrack* Animation::CreateRectTrack( const String& name, IExpressionScript* script )
{
	VerifyName( name );
	PrepareValidate( script, AnimationDataType::Rect );
	IExpressionRectTrack* track = new ExpressionRectTrack( name, script );
	AddTrack( track );
	return track;
}

IExpressionRectTrack* Animation::CreateRectTrack( const String& name, const String& expression )
{
	return CreateRectTrack( name, _animationSystem->CreateScriptInternal(expression) );
}

IKeyframedSizeTrack* Animation::CreateSizeTrack( const String& name )
{
	VerifyName( name );
	IKeyframedSizeTrack* track = new KeyframedSizeTrack( name );
	AddTrack( track );
	return track;
}

IExpressionSizeTrack* Animation::CreateSizeTrack( const String& name, IExpressionScript* script )
{
	VerifyName( name );
	PrepareValidate( script, AnimationDataType::Size );
	IExpressionSizeTrack* track = new ExpressionSizeTrack( name, script );
	AddTrack( track );
	return track;
}

IExpressionSizeTrack* Animation::CreateSizeTrack( const String& name, const String& expression )
{
	return CreateSizeTrack( name, _animationSystem->CreateScriptInternal(expression) );
}

IKeyframedVector3Track* Animation::CreateVector3Track( const String& name )
{
	VerifyName( name );
	IKeyframedVector3Track* track = new KeyframedVector3Track( name );
	AddTrack( track );
	return track;
}

IExpressionVector3Track* Animation::CreateVector3Track( const String& name, IExpressionScript* script )
{
	VerifyName( name );
	PrepareValidate( script, AnimationDataType::Vector3 );
	IExpressionVector3Track* track = new ExpressionVector3Track( name, script );
	AddTrack( track );
	return track;
}

IExpressionVector3Track* Animation::CreateVector3Track( const String& name, const String& expression )
{
	return CreateVector3Track( name, _animationSystem->CreateScriptInternal(expression) );
}

IProceduralVector3Track* Animation::CreateVector3Track( const String& name, const AnimationTrack& type )
{
	VerifyName( name );
	IProceduralVector3Track* track = _animationSystem->CreateTrack( name, type, AnimationDataType::Vector3 )->AsVector3()->AsProcedural();
	AddTrack( track );
	return track;
}

Double Animation::GetLength() const
{
	Double length = 0.0;

	for ( UInt i = 0; i < _tracks.Size(); ++i )
	{
		const Double trackLength = _tracks[i]->GetLength();
		if ( trackLength > length )
			length = trackLength;
	}

	return length;
}

void Animation::PrepareValidate( IExpressionScript* script, const AnimationDataType& type )
{
	script->Prepare();
	if ( script->GetType() != type )
		throw BadArgumentException( L"Wrong expression type.", L"script", script->GetType().ToString() );
}

void Animation::VerifyName( const String& name ) const
{
	if ( _indexes.ContainsKey(name) )
		throw BadArgumentException( String::Format(L"Track with name {0,q} already exists.", name), L"name", name );
}

void Animation::AddTrack( IAnimationTrack* track )
{
	String name = track->GetName();
	_indexes[name] = _tracks.Size();
	_tracks.Add( track );
}


} // anim


} // synkro
