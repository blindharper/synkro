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
// Purpose: Implements expression script.
//==============================================================================
SYNKRO_INLINE void ExpressionScript::GetValue( Bool& value ) const
{
	Evaluate();
	value = (_value[0] != 0.0f);
}

SYNKRO_INLINE void ExpressionScript::GetValue( img::Color& value ) const
{
	Evaluate();
	Copy( &value.R, _value, 3 );
}

SYNKRO_INLINE void ExpressionScript::GetValue( img::ColorGradient& value ) const
{
	Evaluate();
	value.Start.R =	_value[0];
	value.Start.G =	_value[1];
	value.Start.B =	_value[2];
	value.End.R =	_value[3];
	value.End.G =	_value[4];
	value.End.B =	_value[5];
}

SYNKRO_INLINE void ExpressionScript::GetValue( Float& value ) const
{
	Evaluate();
	value = _value[0];
}

SYNKRO_INLINE void ExpressionScript::GetValue( Int& value ) const
{
	Evaluate();
	value = CastInt(_value[0]);
}

SYNKRO_INLINE void ExpressionScript::GetValue( math::Matrix4x4& value ) const
{
	Evaluate();
	Copy( value.d, _value, 16 );
}

SYNKRO_INLINE void ExpressionScript::GetValue( lang::Point& value ) const
{
	Evaluate();
	value.X = CastInt(_value[0]);
	value.Y = CastInt(_value[1]);
}

SYNKRO_INLINE void ExpressionScript::GetValue( lang::Range& value ) const
{
	Evaluate();
	value.Start =	CastUInt(_value[0]);
	value.Length =	CastUInt(_value[1]);
}

SYNKRO_INLINE void ExpressionScript::GetValue( math::Quaternion& value ) const
{
	Evaluate();
	Copy( value.q, _value, 4 );
}

SYNKRO_INLINE void ExpressionScript::GetValue( lang::Rect& value ) const
{
	Evaluate();
	value.Left =	CastInt(_value[0]);
	value.Top =		CastInt(_value[1]);
	value.Right =	CastInt(_value[2]);
	value.Bottom =	CastInt(_value[3]);
}

SYNKRO_INLINE void ExpressionScript::GetValue( lang::RectF& value ) const
{
	Evaluate();
	Copy( &value.Left, &_value[0], 4 );
}

SYNKRO_INLINE void ExpressionScript::GetValue( lang::Size& value ) const
{
	Evaluate();
	value.Width =	CastUInt(_value[0]);
	value.Height =	CastUInt(_value[1]);
}

SYNKRO_INLINE void ExpressionScript::GetValue( math::Vector3& value ) const
{
	Evaluate();
	Copy( value.v, _value, 3 );
}

SYNKRO_INLINE AnimationDataType ExpressionScript::GetType() const
{
	return _type;
}

SYNKRO_INLINE lang::String ExpressionScript::GetText() const
{
	return _text;
}

SYNKRO_INLINE IExpressionScript* ExpressionScript::Clone() const
{
	if ( _type == AnimationDataType::Unknown )
		throw lang::InvalidOperationException( L"Script is not prepared." );

	return new ExpressionScript( *this );
}
