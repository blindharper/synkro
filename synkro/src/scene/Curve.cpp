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
// Purpose: Curve node implementation.
//==============================================================================
#include "config.h"
#include "Curve.h"
#include "NodeAnimationController.h"
#include <scene/DebugMode.h>
#include <internal/Lerp.h>


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


Curve::Curve( ISceneEx* scene, IContext* context, const String& name ) :
	NodeImpl<ICurve>( scene, context, AsBaseScene(scene)->GetCurveName(name), false ),
	_points( A(ControlPoint) ),
	_vertices( A(Vector3) ),
	_color( Color::DarkRed ),
	_indexSelected( none )
{
	// Create debug geometry.
	if ( _scene->GetDebugMode().IsSet(DebugMode::Curves) )
	{
		_curve.CreateStrip( _context->GetGraphicsSystem(), _scene, 1, _color );
		_curve.SetVisibleVertexCount( 0 );
		_gizmo.Create( _context->GetGraphicsSystem(), _scene );
	}
}

Curve::Curve( const Curve& other ) :
	NodeImpl<ICurve>( other._scene, other._context, AsBaseScene(other._scene)->GetCurveName(other._name) ),
	_points( A(ControlPoint) ),
	_vertices( A(Vector3) ),
	_color( other._color ),
	_indexSelected( none )
{
}

INodeAnimationController* Curve::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new NodeAnimationController( this, _context->GetAnimationSystem(), animation, listener ) : _ctrlAnimation;
}

void Curve::AddPoint( const Vector3& point )
{
	_points.Add( ControlPoint(point) );
	if ( _points.Size() == 1 )
	{
		ControlPoint& pt = _points.LastValue();
		_spline.CalculateTangents( pt.Position, pt.Position, pt.Position, pt.Tension, pt.Continuity, pt.Bias, pt.InputTangent, pt.OutputTangent );
		_vertices.Add( point );
		return;
	}
	else if ( _points.Size() == 2 )
	{
		ControlPoint& pt0 = _points[_points.Size()-2];
		ControlPoint& pt = _points[_points.Size()-1];
		_spline.CalculateTangents( pt0.Position, pt0.Position, pt.Position, pt0.Tension, pt0.Continuity, pt0.Bias, pt0.InputTangent, pt0.OutputTangent );
		_spline.CalculateTangents( pt.Position, pt0.Position, pt.Position, pt.Tension, pt.Continuity, pt.Bias, pt.InputTangent, pt.OutputTangent );
	}
	else if ( _points.Size() > 2 )
	{
		ControlPoint& pt1 = _points[_points.Size()-3];
		ControlPoint& pt = _points[_points.Size()-2];
		ControlPoint& pt2 = _points[_points.Size()-1];
		_spline.CalculateTangents( pt.Position, pt1.Position, pt2.Position, pt.Tension, pt.Continuity, pt.Bias, pt.InputTangent, pt.OutputTangent );
		_spline.CalculateTangents( pt2.Position, pt.Position, pt2.Position, pt2.Tension, pt2.Continuity, pt2.Bias, pt2.InputTangent, pt2.OutputTangent );
	}

	const Float step = 1.0f/CastFloat(_points.Size()-1);
	for ( UInt i = 0; i < _points.Size(); ++i )
	{
		_points[i].Phase = CastFloat(i)*step;
	}

	if ( _curve.IsCreated() )
	{
		for ( UInt i = 0; i < INNER_POINT_COUNT; ++i )
		{
			Vector3 vertex;
			const ControlPoint& pt1 = _points[_points.Size()-2];
			const ControlPoint& pt2 = _points[_points.Size()-1];
			const Float phase1 = pt1.Phase;
			const Float phase2 = pt2.Phase;
			const Float delta = (phase2-phase1)/CastFloat(INNER_POINT_COUNT-1);
			_spline.GetPoint( phase1+i*delta, phase1, phase2, pt1.Position, pt2.Position, pt1.OutputTangent, pt2.InputTangent, vertex );
			_vertices.Add( vertex );
		}
		_vertices.Add( point );

		const UInt vertexCount = _curve.GetVertexCount();
		if ( vertexCount < _vertices.Size() )
		{
			_curve.Resize( 2*_vertices.Size(), 0 );
		}
		_curve.SetVertices( _vertices.Begin(), _vertices.Size() );
		_curve.SetVisibleVertexCount( _vertices.Size() );
	}
}

void Curve::SelectPoint( UInt index )
{
	_indexSelected = index;
	_gizmo.Show( _indexSelected < _points.Size() );
}

void Curve::SetTension( UInt index, Float value )
{
	ValidateIndex( index );

	_points[index].Tension = Clamp( value, -1.0f, 1.0f );

	UpdateTangents( index );
}

void Curve::SetContinuity( UInt index, Float value )
{
	ValidateIndex( index );

	_points[index].Continuity = Clamp( value, -1.0f, 1.0f );

	UpdateTangents( index );
}

void Curve::SetBias( UInt index, Float value )
{
	ValidateIndex( index );

	_points[index].Bias = Clamp( value, -1.0f, 1.0f );

	UpdateTangents( index );
}

void Curve::GetPosition( Float phase, Vector3& position ) const
{
	if ( _points.Size() == 0 )
	{
		position = Vector3::Origin;
		return;
	}
	else if ( _points.Size() == 1 )
	{
		position = _points[0].Position;
		return;
	}
	else if ( _points.Size() == 2 )
	{
		position = Lerp( _points[0].Position, _points[1].Position, CastDouble(phase) );
		return;
	}

	for ( UInt i = 0; i < _points.Size()-1; ++i )
	{
		const Float phase1 = _points[i].Phase;
		const Float phase2 = _points[i+1].Phase;
		if ( (phase1 <= phase) && (phase <= phase2) )
		{
			const ControlPoint& pt1 = _points[i];
			const ControlPoint& pt2 = _points[i+1];
			_spline.GetPoint( phase, phase1, phase2, pt1.Position, pt2.Position, pt1.OutputTangent, pt2.InputTangent, position );

			Matrix4x4 worldTransform;
			GetWorldTransform( worldTransform );
			position = worldTransform * position;
			break;
		}
	}
}

void Curve::Update()
{
	NodeImpl<ICurve>::ApplyConstraints( _ctrlAnimation );

	if ( _curve.IsCreated() )
	{
		Matrix4x4 worldTransform;
		GetWorldTransform( worldTransform );
		_curve.SetTransform( worldTransform );

		// Display selected point gizmo.
		if ( _indexSelected < _points.Size() )
		{
			worldTransform.SetTranslation( _points[_indexSelected].Position );
			_gizmo.SetTransform( worldTransform );
		}
	}
}

void Curve::ValidateIndex( UInt index ) const
{
	assert( index < _points.Size() );

	if ( index >= _points.Size() )
		throw OutOfRangeException( index, _points.Size() );
}

void Curve::UpdateTangents( UInt index )
{
	if ( _points.Size() < 3 )
		return;		

	UInt index1 = index;	
	if ( index == 0 )
	{
		ControlPoint& pt = _points[0];
		_spline.CalculateTangents( pt.Position, pt.Position, pt.Position, pt.Tension, pt.Continuity, pt.Bias, pt.InputTangent, pt.OutputTangent );
	}
	else if ( index < _points.Size()-1 )
	{
		const ControlPoint& pt1 = _points[index-1];
		ControlPoint& pt = _points[index];
		const ControlPoint& pt2 = _points[index+1];
		_spline.CalculateTangents( pt.Position, pt1.Position, pt2.Position, pt.Tension, pt.Continuity, pt.Bias, pt.InputTangent, pt.OutputTangent );
	}
	else // index == _points.Size()-1
	{
		const ControlPoint& pt1 = _points[_points.Size()-3];
		ControlPoint& pt = _points[_points.Size()-2];
		ControlPoint& pt2 = _points[_points.Size()-1];
		_spline.CalculateTangents( pt.Position, pt1.Position, pt2.Position, pt.Tension, pt.Continuity, pt.Bias, pt.InputTangent, pt.OutputTangent );
		_spline.CalculateTangents( pt2.Position, pt.Position, pt2.Position, pt2.Tension, pt2.Continuity, pt2.Bias, pt2.InputTangent, pt2.OutputTangent );
		index1 = _points.Size()-2;
	}

	const UInt start = 1 + INNER_POINT_COUNT*index1;
	for ( UInt i = 0; i < INNER_POINT_COUNT; ++i )
	{
		Vector3 vertex;
		const ControlPoint& pt1 = _points[index1];
		const ControlPoint& pt2 = _points[index1+1];
		const Float phase1 = pt1.Phase;
		const Float phase2 = pt2.Phase;
		const Float delta = (phase2-phase1)/CastFloat(INNER_POINT_COUNT-1);
		_spline.GetPoint( phase1+i*delta, phase1, phase2, pt1.Position, pt2.Position, pt1.OutputTangent, pt2.InputTangent, vertex );
		_vertices[start+i] = vertex;
	}
	_curve.SetVertices( _vertices.Begin(), _vertices.Size() );
}


} // scene


} // synkro
