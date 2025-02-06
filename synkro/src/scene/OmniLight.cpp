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
// Purpose: Omni light node implementation.
//==============================================================================
#include "config.h"
#include "OmniLight.h"
#include "OmniLightAnimationController.h"
#include "internal/ToVector.h"


namespace synkro
{


namespace scene
{


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::input;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


OmniLight::OmniLight( ISceneEx* scene, IContext* context, const String& name ) :
	LightImpl<IOmniLight>( scene, context, AsBaseScene(scene)->GetLightName(name), true ),
	_range( 1e9f )
{
	// Create debug geometry.
	if ( _scene->GetDebugMode().IsSet(DebugMode::Helpers) )
	{
		constexpr Float RADUIS = 1.0f;
		constexpr UInt STACK_COUNT = 20;
		constexpr UInt SLICE_COUNT = 20;
		const UInt VERTEX_COUNT = (STACK_COUNT+1)*(SLICE_COUNT+1);
		const UInt INDEX_COUNT = 4*SLICE_COUNT*SLICE_COUNT;
		_omni.Create( _context->GetGraphicsSystem(), _scene, VERTEX_COUNT, INDEX_COUNT, _diffuseColor*_intensity );
		Vector3 vertices[VERTEX_COUNT];
		UShort indices[INDEX_COUNT];

		UInt pos = 0; UInt idx = 0;
		const Float drho = Math::Pi/CastFloat(STACK_COUNT);
		const Float dtheta = Math::TwoPi/CastFloat(SLICE_COUNT);
		for ( UInt i = 0; i <= STACK_COUNT; ++i )
		{
			const Float rho = CastFloat(i)*drho;
			const Float sinRho = Math::Sin( rho );
			const Float cosRho = Math::Cos( rho );

			for ( UInt j = 0; j <= SLICE_COUNT; ++j )
			{
				const Float theta = (j == SLICE_COUNT) ? 0.0f : j*dtheta;
				const Float sinTheta = -Math::Sin( theta );
				const Float cosTheta = Math::Cos( theta );
				vertices[pos++] = Vector3( RADUIS*sinTheta*sinRho, RADUIS*cosRho, RADUIS*cosTheta*sinRho );

				if ( (i < STACK_COUNT) && (j < SLICE_COUNT) )
				{
					const UInt idx1 = i*(SLICE_COUNT+1)+j;
					indices[idx++] = idx1;
					indices[idx++] = idx1+1;

					const UInt idx2 = (i+1)*(SLICE_COUNT+1)+j;
					indices[idx++] = idx1;
					indices[idx++] = idx2;
				}
			}
		}
		_omni.SetVertices( vertices, VERTEX_COUNT );
		_omni.SetIndices( indices, INDEX_COUNT );
	}
}

INodeAnimationController* OmniLight::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new OmniLightAnimationController( this, _context->GetAnimationSystem(), animation, listener ) : _ctrlAnimation;
}

void OmniLight::Update()
{
	NodeImpl<IOmniLight>::ApplyConstraints( _ctrlAnimation );

	if ( _omni.IsCreated() )
	{
		Matrix4x4 worldTransform;
		GetWorldTransform( worldTransform );
		_omni.SetTransform( worldTransform );
	}

	if ( _gizmo.IsCreated() )
	{
		Matrix4x4 worldTransform;
		GetWorldTransform( worldTransform );
		_gizmo.SetTransform( worldTransform );
	}
}

void OmniLight::GetState( LightState& state ) const
{
	Matrix4x4 trans;
	GetWorldTransform( trans );
	const Vector4 pos( trans.Translation4() );
	state.Type					= LIGHT_TYPE_OMNI;
	state.Diffuse				= ToVector( _diffuseColor*_intensity );
	state.Ambient				= ToVector( _ambientColor*_intensity );
	state.Specular				= ToVector( _specularColor*_intensity );
	state.Position				= pos;
	state.Range					= _range;
	state.ConstAttenuation		= _attenuation.Constant;
	state.LinearAttenuation		= _attenuation.Linear;
	state.QuadraticAttenuation	= _attenuation.Quadratic;

}


} // scene


} // synkro
