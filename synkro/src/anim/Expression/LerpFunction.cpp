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
// Purpose: 'lerp' function.
//==============================================================================
#include "config.h"
#include "LerpFunction.h"
#include <anim/AnimationDataTypeConst.h>
#include <internal/Lerp.h>


//------------------------------------------------------------------------------

using namespace synkro::img;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


LerpFunction::LerpFunction() :
	Function( L"lerp" ),
	_valueFloat( 0.0f, Token() ),
	_valueColor( Color::Black, Token() )
{
	_arguments.Add( AnimationDataType::Unknown );
	_arguments.Add( AnimationDataType::Unknown );
	_arguments.Add( AnimationDataType::Float );
}

AnimationDataType LerpFunction::DeduceType( ExpressionList* arguments )
{
	if ( (arguments->GetSize() == 3) && (arguments->Get(2)->ValueType == AnimationDataType::Float) )
	{
		if ( arguments->Get(0)->ValueType == arguments->Get(1)->ValueType )
		{
			return arguments->Get(0)->ValueType;
		}
	}
	return AnimationDataType::Unknown;
}

Expression* LerpFunction::Call( ExpressionList* arguments )
{
	Float f1 = 0.0f; Float f2 = 0.0f;
	Color c1; Color c2;

	Float s = 0.0f;
	arguments->Get( 2 )->GetValue( &s );

	const AnimationDataType retType = arguments->Get(0)->ValueType;
	switch ( retType.Value() )
	{
		case TYPE_FLOAT:
			arguments->Get( 0 )->GetValue( &f1 );
			arguments->Get( 1 )->GetValue( &f2 );
			_valueFloat.Value = Lerp( f1, f2, CastDouble(s) );
			return &_valueFloat;

		case TYPE_COLOR:
			arguments->Get( 0 )->GetValue( &c1.R );
			arguments->Get( 1 )->GetValue( &c2.R );
			_valueColor.Value = Lerp( c1, c2, CastDouble(s) );
			return &_valueColor;

		default:
			break;
	}

	return nullptr;
}


} // anim


} // synkro
