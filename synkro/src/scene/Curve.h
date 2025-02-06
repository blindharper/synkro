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
#ifndef _SYNKRO_SCENE_CURVE_
#define _SYNKRO_SCENE_CURVE_


#include "config.h"
#include "NodeImpl.h"
#include <scene/ICurve.h>
#include <scene/INodeAnimationController.h>
#include <lang/Vector.h>
#include <math/TcbSpline.h>
#include "BaseNode.h"
#include "DebugHelper.h"


namespace synkro
{


namespace scene
{


// Curve node implementation.
class Curve :
	public NodeImpl<ICurve>,
	public BaseNode
{
public:
	// Constructors.
	Curve( ISceneEx* scene, core::IContext* context, const lang::String& name );
	Curve( const Curve& other );

	// INode methods.
	INodeAnimationController*								CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );

	// ICurve methods.
	void													AddPoint( const math::Vector3& point );
	void													SelectPoint( UInt index );
	void													SetTension( UInt index, Float value );
	void													SetContinuity( UInt index, Float value );
	void													SetBias( UInt index, Float value );
	void													SetColor( const img::Color& color );
	UInt													GetPointCount() const;
	void													GetPoint( UInt index, math::Vector3& point ) const;
	Float													GetTension( UInt index ) const;
	Float													GetContinuity( UInt index ) const;
	Float													GetBias( UInt index ) const;
	void													GetColor( img::Color& color ) const;
	void													GetPosition( Float phase, math::Vector3& position ) const;

	// BaseNode methods.
	void													Update();

private:
	enum
	{
		INNER_POINT_COUNT = 20,
	};

	struct ControlPoint
	{
		ControlPoint( const math::Vector3& position ) :
			Position( position ),
			Tension( 0.0f ),
			Continuity( 0.0f ),
			Bias( 0.0f ),
			Phase( 0.0f )
		{
		}

		ControlPoint() :
			Tension( 0.0f ),
			Continuity( 0.0f ),
			Bias( 0.0f ),
			Phase( 0.0f )
		{
		}

		math::Vector3	Position;
		math::Vector3	InputTangent;
		math::Vector3	OutputTangent;
		Float			Tension;
		Float			Continuity;
		Float			Bias;
		Float			Phase;
	};

	lang::Vector<ControlPoint>								_points;
	lang::Vector<math::Vector3>								_vertices;
	P(INodeAnimationController)								_ctrlAnimation;
	math::TcbSpline											_spline;
	DebugHelper												_curve;
	img::Color												_color;
	UInt													_indexSelected;

	void													ValidateIndex( UInt index ) const;
	void													UpdateTangents( UInt index );
};


#include "Curve.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_CURVE_
