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
#ifndef _SYNKRO_GFX_PARAMETERSET_
#define _SYNKRO_GFX_PARAMETERSET_


#include "config.h"
#include <lang/Map.h>
#include <core/ObjectImpl.h>
#include <gfx/IParameterSet.h>
#include "ProgramParamEx.h"


namespace synkro
{


namespace gfx
{


// Logical parameter set.
class ParameterSet :
	public core::ObjectImpl<IParameterSet>
{
public:
	// Constructors.
	ParameterSet( IParameterSet* set );
	ParameterSet( const ParameterSet& other, UInt ownerID, Bool cloneShared );

	// IParameterSet methods.
	void													Bind();
	void													Set( ProgramParam* param, Bool value );
	void													Set( ProgramParam* param, const Bool* value, UInt count );
	void													Set( ProgramParam* param, Int value );
	void													Set( ProgramParam* param, const Int* value, UInt count );
	void													Set( ProgramParam* param, Float value );
	void													Set( ProgramParam* param, const Float* value, UInt count );
	void													Set( ProgramParam* param, const math::Vector2& value );
	void													Set( ProgramParam* param, const math::Vector2* value, UInt count );
	void													Set( ProgramParam* param, const math::Vector3& value );
	void													Set( ProgramParam* param, const math::Vector3* value, UInt count );
	void													Set( ProgramParam* param, const math::Vector4& value );
	void													Set( ProgramParam* param, const math::Vector4* value, UInt count );
	void													Set( ProgramParam* param, const math::Matrix4x4& value );
	void													Set( ProgramParam* param, const math::Matrix4x4* value, UInt count );
	void													Set( ProgramParam* param, const Byte* value, UInt size );
	void													Set( ProgramParam* param, const Byte* value, UInt size, UInt count );
	void													Get( ProgramParam* param, Bool* value ) const;
	void													Get( ProgramParam* param, Bool* value, UInt count ) const;
	void													Get( ProgramParam* param, Int* value ) const;
	void													Get( ProgramParam* param, Int* value, UInt count ) const;
	void													Get( ProgramParam* param, Float* value ) const;
	void													Get( ProgramParam* param, Float* value, UInt count ) const;
	void													Get( ProgramParam* param, math::Vector2* value ) const;
	void													Get( ProgramParam* param, math::Vector2* value, UInt count ) const;
	void													Get( ProgramParam* param, math::Vector3* value ) const;
	void													Get( ProgramParam* param, math::Vector3* value, UInt count ) const;
	void													Get( ProgramParam* param, math::Vector4* value ) const;
	void													Get( ProgramParam* param, math::Vector4* value, UInt count ) const;
	void													Get( ProgramParam* param, math::Matrix4x4* value ) const;
	void													Get( ProgramParam* param, math::Matrix4x4* value, UInt count ) const;
	UInt													GetParamCount() const;
	lang::String											GetParamName( UInt index ) const;
	lang::String											GetParamName( ProgramParam* param ) const;
	ProgramDataType											GetParamType( ProgramParam* param ) const;
	UInt													GetParamSize( ProgramParam* param ) const;
	UInt													GetParamElementCount( ProgramParam* param ) const;
	ProgramParam*											GetParam( const lang::String& name ) const;
	IParameterSet*											Clone( UInt ownerID, Bool cloneShared ) const;

private:
	typedef lang::MapPair<UInt, ProgramParamEx*>			ParamEntry;

	lang::Map<UInt, ProgramParamEx*>						_params;
	P(IParameterSet)										_set;
	Bool													_readonly;

	void													CopyParams();
	void													ValidateParam( ProgramParam* param, const ProgramDataType& type, UInt count ) const;
	void													ValidateMatrixParam( ProgramParam* param, UInt count ) const;
	void													PreventModify();
};


#include "ParameterSet.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_PARAMETERSET_
