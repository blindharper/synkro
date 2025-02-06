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
// Purpose: Color type constructor.
//==============================================================================
#include "config.h"
#include "ColorFunction.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::img;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


ColorFunction::ColorFunction() :
	Function( L"color" ),
	_value( Color::Black, Token() )
{
	for ( UInt i = 0; i < 3; ++i )
	{
		_arguments.Add( AnimationDataType::Float );
	}
}

AnimationDataType ColorFunction::DeduceType( ExpressionList* arguments )
{
	if ( arguments->GetSize() == 3 )
	{
		for ( UInt i = 0; i < 3; ++i )
		{
			if ( arguments->Get(i)->ValueType != AnimationDataType::Float )
				return AnimationDataType::Unknown;
		}
		return AnimationDataType::Color;
	}
	return AnimationDataType::Unknown;
}

Expression* ColorFunction::Call( ExpressionList* arguments )
{
	Float r = 0.0f; Float g = 0.0f; Float b = 0.0f;
	arguments->Get( 0 )->GetValue( &r );
	arguments->Get( 1 )->GetValue( &g );
	arguments->Get( 2 )->GetValue( &b );
	_value.Value = Color( r, g, b );
	return &_value;
}


} // anim


} // synkro
