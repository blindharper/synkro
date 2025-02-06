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
#include "config.h"
#include "ParameterSet.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


ParameterSet::ParameterSet( IParameterSet* set ) :
	_params( A(ParamEntry) ),
	_set( set ),
	_readonly( true )
{
	CopyParams();
}

ParameterSet::ParameterSet( const ParameterSet& other, UInt ownerID, Bool cloneShared ) :
	_params( A(ParamEntry) ),
	_set( other._set->Clone(ownerID, cloneShared) ),
	_readonly( false )
{
	CopyParams();
}

void ParameterSet::CopyParams()
{
	for ( UInt i = 0; i < _set->GetParamCount(); ++i )
	{
		String name = _set->GetParamName( i );
		ProgramParamEx* param = (ProgramParamEx*)_set->GetParam( name );
		_params[param->ID] = param;
	}
}

void ParameterSet::ValidateParam( ProgramParam* param, const ProgramDataType& type, UInt count ) const
{
	assert( param != nullptr );

	if ( param == nullptr )
		throw BadArgumentException( Str::InvalidPointer, L"param", L"nullptr" );

	ProgramParamEx* p = (ProgramParamEx*)param;
	if ( !_params.ContainsKey(p->ID) )
		throw BadArgumentException( Str::WrongProgramParameter, _set->GetParamName(param) );

	if ( _set->GetParamType(param) != type )
		throw BadArgumentException( Str::WrongProgramParameter, _set->GetParamName(param) );

	if ( _set->GetParamElementCount(param) < count )
		throw BadArgumentException( Str::WrongProgramParameter, _set->GetParamName(param) );
}

void ParameterSet::ValidateMatrixParam( ProgramParam* param, UInt count ) const
{
	assert( param != nullptr );

	if ( param == nullptr )
		throw BadArgumentException( Str::InvalidPointer, L"param", L"nullptr" );

	ProgramParamEx* p = (ProgramParamEx*)param;
	if ( !_params.ContainsKey(p->ID) )
		throw BadArgumentException( Str::WrongProgramParameter, _set->GetParamName(param) );

	ProgramDataType type = _set->GetParamType( param );
	if ( (type != ProgramDataType::Matrix4x4) && (type != ProgramDataType::Matrix4x4Transposed) )
		throw BadArgumentException( Str::WrongProgramParameter, _set->GetParamName(param) );

	if ( _set->GetParamElementCount(param) < count )
		throw BadArgumentException( Str::WrongProgramParameter, _set->GetParamName(param) );
}

void ParameterSet::PreventModify()
{
	if ( _readonly )
		throw InvalidOperationException( L"Cannot modify default parameter set." );
}


} // gfx


} // synkro
