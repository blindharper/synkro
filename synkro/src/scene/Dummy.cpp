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
// Purpose: Dummy node implementation.
//==============================================================================
#include "config.h"
#include "Dummy.h"
#include "NodeAnimationController.h"
#include <scene/DebugMode.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::img;
using namespace synkro::input;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


Dummy::Dummy( ISceneEx* scene, IContext* context, const String& name, Bool visualize ) :
	NodeImpl<INode>( scene, context, AsBaseScene(scene)->GetDummyName(name), visualize )
{
	// Create debug geometry.
	if ( visualize && _scene->GetDebugMode().IsSet(DebugMode::Helpers) )
	{
		// Create helper object.
		_dummy.Create( _context->GetGraphicsSystem(), _scene, 8, 24, Color::DarkOrange );

		// Set positions.
		constexpr Float SIZE = 0.5f;
		Vector3 positions[] =
		{
			// Top.
			Vector3(-SIZE,	 SIZE,	 SIZE ),
			Vector3( SIZE,	 SIZE,	 SIZE ),
			Vector3(-SIZE,	 SIZE,	-SIZE ),
			Vector3( SIZE,	 SIZE,	-SIZE ),
			// Bottom.
			Vector3(-SIZE,	-SIZE,	 SIZE ),
			Vector3( SIZE,	-SIZE,	 SIZE ),
			Vector3(-SIZE,	-SIZE,	-SIZE ),
			Vector3( SIZE,	-SIZE,	-SIZE ),
		};
		_dummy.SetVertices( positions, SizeOf(positions) );

		// Set indices.
		UShort indices[] =
		{
			0, 1, 1, 3, 3, 2, 2, 0,
			4, 5, 5, 7, 7, 6, 6, 4,
			0, 4, 1, 5, 2, 6, 3, 7
		};
		_dummy.SetIndices( indices, SizeOf(indices) );
	}
}

Dummy::Dummy( const Dummy& other ) :
	NodeImpl<INode>( other._scene, other._context, AsBaseScene(other._scene)->GetDummyName(other._name) )
{
}

INodeAnimationController* Dummy::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new NodeAnimationController( this, _context->GetAnimationSystem(), animation, listener ) : _ctrlAnimation;
}

void Dummy::Update()
{
	NodeImpl<INode>::ApplyConstraints( _ctrlAnimation );

	if ( _dummy.IsCreated() )
	{
		Matrix4x4 worldTransform;
		GetWorldTransform( worldTransform );
		_dummy.SetTransform( worldTransform );
	}

	if ( _gizmo.IsCreated() )
	{
		Matrix4x4 worldTransform;
		GetWorldTransform( worldTransform );
		_gizmo.SetTransform( worldTransform );
	}
}


} // scene


} // synkro
