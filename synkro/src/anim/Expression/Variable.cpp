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
// Purpose: Expression variable.
//==============================================================================
#include "config.h"
#include "Variable.h"
#include "ColorExpression.h"
#include "FloatExpression.h"
#include "Vector3Expression.h"
#include "Matrix4x4Expression.h"
#include <anim/AnimationDataTypeConst.h>
#include <internal/SafeDelete.h>


//------------------------------------------------------------------------------

using namespace synkro::img;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


Variable::Variable( const String& name, const AnimationDataType& type, Expression* value ) :
	Name( name ),
	Type( type ),
	Value( value )
{
}

Variable::Variable( const String& name, const AnimationDataType& type ) :
	Name( name ),
	Type( type ),
	Value( nullptr )
{
	switch ( type.Value() )
	{
		case TYPE_COLOR:
			Value = new ColorExpression();
			break;

		case TYPE_FLOAT:
			Value = new FloatExpression();
			break;

		case TYPE_VECTOR3:
			Value = new Vector3Expression();
			break;

		case TYPE_MATRIX4X4:
			Value = new Matrix4x4Expression();
			break;

		default:
			break;
	}
}

Variable::~Variable()
{
	SafeDelete( Value );
}


} // anim


} // synkro
