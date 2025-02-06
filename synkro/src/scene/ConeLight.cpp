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
// Purpose: Cone light node implementation.
//==============================================================================
#include "config.h"
#include "ConeLight.h"
#include "ConeLightAnimationController.h"
#include "ParentConstraint.h"
#include "LookAtConstraint.h"


namespace synkro
{


namespace scene
{


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::img;
using namespace synkro::input;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


ConeLight::ConeLight( ISceneEx* scene, IContext* context, const String& name ) :
	LightImpl<IConeLight>( scene, context, AsBaseScene(scene)->GetLightName(name), true ),
	_innerAngle( Math::Pi ),
	_outerAngle( Math::Pi ),
	_falloff( 1.0f ),
	_range( 1e9f )
{
	// Create debug geometry.
	if ( _scene->GetDebugMode().IsSet(DebugMode::Helpers) )
	{
		constexpr UInt VERTEX_COUNT = 2*SEGMENT_COUNT+1;
		constexpr UInt INDEX_COUNT = 8*SEGMENT_COUNT;
		_cone.Create( _context->GetGraphicsSystem(), _scene, VERTEX_COUNT, INDEX_COUNT, _diffuseColor*_intensity );
		UShort indices[INDEX_COUNT];
		BuildIndices( indices, 0, 0 );
		BuildIndices( indices, 4*SEGMENT_COUNT, SEGMENT_COUNT );
		_cone.SetIndices( indices, INDEX_COUNT );
		UpdateAngles();
	}
}

INodeAnimationController* ConeLight::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new ConeLightAnimationController( this, _context->GetAnimationSystem(), animation, listener ) : _ctrlAnimation;
}

IParentConstraint* ConeLight::CreateParentConstraint( INode* parent, const Matrix4x4& transform )
{
	return (_parentConstraint == nullptr) ? _parentConstraint = new ParentConstraint( this, parent, transform ) : _parentConstraint;
}

ILookAtConstraint* ConeLight::CreateLookAtConstraint( INode* target )
{
	return (_lookAtConstraint == nullptr) ? _lookAtConstraint = new LookAtConstraint( _context->GetGraphicsSystem(), this, target ) : _lookAtConstraint;
}

void ConeLight::Update()
{
	NodeImpl<IConeLight>::ApplyConstraints( _ctrlAnimation );

	if ( _cone.IsCreated() )
	{
		Matrix4x4 worldTransform;
		GetWorldTransform( worldTransform );
		_cone.SetTransform( worldTransform );
	}

	if ( _gizmo.IsCreated() )
	{
		Matrix4x4 worldTransform;
		GetWorldTransform( worldTransform );
		_gizmo.SetTransform( worldTransform );
	}
}

void ConeLight::GetState( LightState& state ) const
{
	Matrix4x4 trans;
	GetWorldTransform( trans );
	const Vector4 pos( trans.Translation4() );
	Vector4 rot( trans.Forward() );
	state.Type					= LIGHT_TYPE_CONE;
	state.Diffuse				= ToVector( _diffuseColor*_intensity );
	state.Ambient				= ToVector( _ambientColor*_intensity );
	state.Specular				= ToVector( _specularColor*_intensity );
	state.Position				= pos;
	state.Direction				= rot.Normalize();
	state.ConstAttenuation		= _attenuation.Constant;
	state.LinearAttenuation		= _attenuation.Linear;
	state.QuadraticAttenuation	= _attenuation.Quadratic;
	state.Range					= _range;
	state.Falloff				= _falloff;
	state.Theta					= _innerAngle;
	state.Phi					= _outerAngle;
}

Float ConeLight::BuildCone( Vector3* vertices, UInt offset, Float angle, Float height )
{
	constexpr Float RADIUS = 5.0f;
	const Float z = (height == 0.0f) ? RADIUS*Math::Cos( 0.5f*angle ) : height;
	const Float s = RADIUS*Math::Sin( 0.5f*angle );
	const Float dt = Math::TwoPi/CastFloat(SEGMENT_COUNT);
	for ( UInt i = 0; i < SEGMENT_COUNT; ++i )
	{
		const Float a = i*dt;
		const Float x = s*Math::Cos( a );
		const Float y = s*Math::Sin( a );
		vertices[offset+i] = Vector3( x, y, -z );
	}
	return z;
}

void ConeLight::BuildIndices( UShort* indices, UInt offset, UInt start )
{
	UInt idx = offset;
	for ( UInt i = 1; i <= SEGMENT_COUNT; ++i )
	{
		indices[idx++] = CastUShort(0);
		indices[idx++] = CastUShort(i+start);
	}
	for ( UInt i = 1; i < SEGMENT_COUNT; ++i )
	{
		indices[idx++] = CastUShort(i+start);
		indices[idx++] = CastUShort(i+start+1);
	}
	indices[idx++] = CastUShort(start+SEGMENT_COUNT);
	indices[idx++] = CastUShort(start+1);
}

void ConeLight::UpdateAngles()
{
	if ( _cone.IsCreated() )
	{
		constexpr UInt VERTEX_COUNT = 2*SEGMENT_COUNT+1;
		Vector3 vertices[VERTEX_COUNT];
		vertices[0] = Vector3::Origin;
		Float height = BuildCone( vertices, 1, _innerAngle, 0.0f );
		BuildCone( vertices, SEGMENT_COUNT+1, _outerAngle, height );
		_cone.SetVertices( vertices, VERTEX_COUNT );
	}
}


} // scene


} // synkro
