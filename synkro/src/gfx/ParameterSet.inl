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
// Purpose: Logical parameter set.
//==============================================================================
SYNKRO_INLINE void ParameterSet::Bind()
{
	SynkroProfile( "ParameterSet.Bind" );

	_set->Bind();
}

SYNKRO_INLINE void ParameterSet::Set( ProgramParam* param, Bool value )
{
	PreventModify();
	ValidateParam( param, ProgramDataType::Bool, 1 );
	_set->Set( param, value );
}

SYNKRO_INLINE void ParameterSet::Set( ProgramParam* param, const Bool* value, UInt count )
{
	PreventModify();
	ValidateParam( param, ProgramDataType::Bool, count );
	_set->Set( param, value, count );
}

SYNKRO_INLINE void ParameterSet::Set( ProgramParam* param, Int value )
{
	PreventModify();
	ValidateParam( param, ProgramDataType::Int, 1 );
	_set->Set( param, value );
}

SYNKRO_INLINE void ParameterSet::Set( ProgramParam* param, const Int* value, UInt count )
{
	PreventModify();
	ValidateParam( param, ProgramDataType::Int, count );
	_set->Set( param, value, count );
}

SYNKRO_INLINE void ParameterSet::Set( ProgramParam* param, Float value )
{
	PreventModify();
	ValidateParam( param, ProgramDataType::Float, 1 );
	_set->Set( param, value );
}

SYNKRO_INLINE void ParameterSet::Set( ProgramParam* param, const Float* value, UInt count )
{
	PreventModify();
	ValidateParam( param, ProgramDataType::Float, count );
	_set->Set( param, value, count );
}

SYNKRO_INLINE void ParameterSet::Set( ProgramParam* param, const math::Vector2& value )
{
	PreventModify();
	ValidateParam( param, ProgramDataType::Vector2, 1 );
	_set->Set( param, value );
}

SYNKRO_INLINE void ParameterSet::Set( ProgramParam* param, const math::Vector2* value, UInt count )
{
	PreventModify();
	ValidateParam( param, ProgramDataType::Vector2, count );
	_set->Set( param, value, count );
}

SYNKRO_INLINE void ParameterSet::Set( ProgramParam* param, const math::Vector3& value )
{
	PreventModify();
	ValidateParam( param, ProgramDataType::Vector3, 1 );
	_set->Set( param, value );
}

SYNKRO_INLINE void ParameterSet::Set( ProgramParam* param, const math::Vector3* value, UInt count )
{
	PreventModify();
	ValidateParam( param, ProgramDataType::Vector3, count );
	_set->Set( param, value, count );
}

SYNKRO_INLINE void ParameterSet::Set( ProgramParam* param, const math::Vector4& value )
{
	PreventModify();
	ValidateParam( param, ProgramDataType::Vector4, 1 );
	_set->Set( param, value );
}

SYNKRO_INLINE void ParameterSet::Set( ProgramParam* param, const math::Vector4* value, UInt count )
{
	PreventModify();
	ValidateParam( param, ProgramDataType::Vector4, count );
	_set->Set( param, value, count );
}

SYNKRO_INLINE void ParameterSet::Set( ProgramParam* param, const math::Matrix4x4& value )
{
	PreventModify();
	ValidateMatrixParam( param, 1 );
	_set->Set( param, value );
}

SYNKRO_INLINE void ParameterSet::Set( ProgramParam* param, const math::Matrix4x4* value, UInt count )
{
	PreventModify();
	ValidateMatrixParam( param, count );
	_set->Set( param, value, count );
}

SYNKRO_INLINE void ParameterSet::Set( ProgramParam* param, const Byte* value, UInt size )
{
	PreventModify();
	ValidateParam( param, ProgramDataType::Structure, 1 );
	_set->Set( param, value, size );
}

SYNKRO_INLINE void ParameterSet::Set( ProgramParam* param, const Byte* value, UInt size, UInt count )
{
	PreventModify();
	ValidateParam( param, ProgramDataType::Structure, count );
	_set->Set( param, value, size, count );
}

SYNKRO_INLINE void ParameterSet::Get( ProgramParam* param, Bool* value ) const
{
	ValidateParam( param, ProgramDataType::Bool, 1 );
	_set->Get( param, value );
}

SYNKRO_INLINE void ParameterSet::Get( ProgramParam* param, Bool* value, UInt count ) const
{
	ValidateParam( param, ProgramDataType::Bool, count );
	_set->Get( param, value, count );
}

SYNKRO_INLINE void ParameterSet::Get( ProgramParam* param, Int* value ) const
{
	ValidateParam( param, ProgramDataType::Int, 1 );
	_set->Get( param, value );
}

SYNKRO_INLINE void ParameterSet::Get( ProgramParam* param, Int* value, UInt count ) const
{
	ValidateParam( param, ProgramDataType::Int, count );
	_set->Get( param, value, count );
}

SYNKRO_INLINE void ParameterSet::Get( ProgramParam* param, Float* value ) const
{
	ValidateParam( param, ProgramDataType::Float, 1 );
	_set->Get( param, value );
}

SYNKRO_INLINE void ParameterSet::Get( ProgramParam* param, Float* value, UInt count ) const
{
	ValidateParam( param, ProgramDataType::Float, count );
	_set->Get( param, value, count );
}

SYNKRO_INLINE void ParameterSet::Get( ProgramParam* param, math::Vector2* value ) const
{
	ValidateParam( param, ProgramDataType::Vector2, 1 );
	_set->Get( param, value );
}

SYNKRO_INLINE void ParameterSet::Get( ProgramParam* param, math::Vector2* value, UInt count ) const
{
	ValidateParam( param, ProgramDataType::Vector2, count );
	_set->Get( param, value, count );
}

SYNKRO_INLINE void ParameterSet::Get( ProgramParam* param, math::Vector3* value ) const
{
	ValidateParam( param, ProgramDataType::Vector3, 1 );
	_set->Get( param, value );
}

SYNKRO_INLINE void ParameterSet::Get( ProgramParam* param, math::Vector3* value, UInt count ) const
{
	ValidateParam( param, ProgramDataType::Vector3, count );
	_set->Get( param, value, count );
}

SYNKRO_INLINE void ParameterSet::Get( ProgramParam* param, math::Vector4* value ) const
{
	ValidateParam( param, ProgramDataType::Vector4, 1 );
	_set->Get( param, value );
}

SYNKRO_INLINE void ParameterSet::Get( ProgramParam* param, math::Vector4* value, UInt count ) const
{
	ValidateParam( param, ProgramDataType::Vector4, count );
	_set->Get( param, value, count );
}

SYNKRO_INLINE void ParameterSet::Get( ProgramParam* param, math::Matrix4x4* value ) const
{
	ValidateMatrixParam( param, 1 );
	_set->Get( param, value );
}

SYNKRO_INLINE void ParameterSet::Get( ProgramParam* param, math::Matrix4x4* value, UInt count ) const
{
	ValidateMatrixParam( param, count );
	_set->Get( param, value, count );
}

SYNKRO_INLINE UInt ParameterSet::GetParamCount() const
{
	return _set->GetParamCount();
}

SYNKRO_INLINE lang::String ParameterSet::GetParamName( UInt index ) const
{
	assert( index < _set->GetParamCount() );

	if ( index >= _set->GetParamCount() )
		throw lang::OutOfRangeException( index, _set->GetParamCount() );

	return _set->GetParamName( index );
}

SYNKRO_INLINE lang::String ParameterSet::GetParamName( ProgramParam* param ) const
{
	assert( param != nullptr );

	if ( param == nullptr )
		throw lang::BadArgumentException( core::Str::InvalidPointer, L"param", L"nullptr" );

	return _set->GetParamName( param );
}

SYNKRO_INLINE ProgramDataType ParameterSet::GetParamType( ProgramParam* param ) const
{
	assert( param != nullptr );

	if ( param == nullptr )
		throw lang::BadArgumentException( core::Str::InvalidPointer, L"param", L"nullptr" );

	return _set->GetParamType( param );
}

SYNKRO_INLINE UInt ParameterSet::GetParamSize( ProgramParam* param ) const
{
	assert( param != nullptr );

	if ( param == nullptr )
		throw lang::BadArgumentException( core::Str::InvalidPointer, L"param", L"nullptr" );

	return _set->GetParamSize( param );
}

SYNKRO_INLINE UInt ParameterSet::GetParamElementCount( ProgramParam* param ) const
{
	assert( param != nullptr );

	if ( param == nullptr )
		throw lang::BadArgumentException( core::Str::InvalidPointer, L"param", L"nullptr" );

	return _set->GetParamElementCount( param );
}

SYNKRO_INLINE ProgramParam* ParameterSet::GetParam( const lang::String& name ) const
{
	return _set->GetParam( name );
}

SYNKRO_INLINE IParameterSet* ParameterSet::Clone( UInt ownerID, Bool cloneShared ) const
{
	return new ParameterSet( *this, ownerID, cloneShared );
}
