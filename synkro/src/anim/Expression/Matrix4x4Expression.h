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
// Purpose: 4x4 matrix expression.
//==============================================================================
#ifndef _SYNKRO_ANIM_MATRIX4X4EXPRESSION_
#define _SYNKRO_ANIM_MATRIX4X4EXPRESSION_


#include "config.h"
#include "SimpleExpression.h"
#include <math/Matrix4x4.h>


namespace synkro
{


namespace anim
{


// 4x4 matrix expression.
class Matrix4x4Expression : 
	public SimpleExpression
{
public:
	// Constructor.
	Matrix4x4Expression( const Matrix4x4Expression& other );
	Matrix4x4Expression();

	void													GetValue( Float* value );
	Expression*												Clone( BaseExpressionScript* script ) const;

	math::Matrix4x4											Value;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_MATRIX4X4EXPRESSION_
