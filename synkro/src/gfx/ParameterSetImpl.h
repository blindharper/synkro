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
// Purpose: Generic program parameter set implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_PARAMETERSETIMPL_
#define _SYNKRO_GFX_PARAMETERSETIMPL_


#include "config.h"
#include <lang/Map.h>
#include <lang/Vector.h>
#include <core/ObjectImpl.h>
#include <math/Vector2.h>
#include <math/Vector3.h>
#include <math/Vector4.h>
#include <math/Matrix4x4.h>
#include <gfx/ProgramDataType.h>
#include <gfx/ProgramStageType.h>


namespace synkro
{


namespace gfx
{


// Generic program parameters implementation.
template <class T, class P>
class ParameterSetImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	ParameterSetImpl( const ProgramStageType& type );
	virtual ~ParameterSetImpl();

	// IParameterSet methods.
	virtual void											Set( ProgramParam* param, Bool value );
	virtual void											Set( ProgramParam* param, const Bool* value, UInt count );
	virtual void											Set( ProgramParam* param, Int value );
	virtual void											Set( ProgramParam* param, const Int* value, UInt count );
	virtual void											Set( ProgramParam* param, Float value );
	virtual void											Set( ProgramParam* param, const Float* value, UInt count );
	virtual void											Set( ProgramParam* param, const math::Vector2& value );
	virtual void											Set( ProgramParam* param, const math::Vector2* value, UInt count );
	virtual void											Set( ProgramParam* param, const math::Vector3& value );
	virtual void											Set( ProgramParam* param, const math::Vector3* value, UInt count );
	virtual void											Set( ProgramParam* param, const math::Vector4& value );
	virtual void											Set( ProgramParam* param, const math::Vector4* value, UInt count );
	virtual void											Set( ProgramParam* param, const math::Matrix4x4& value );
	virtual void											Set( ProgramParam* param, const math::Matrix4x4* value, UInt count );
	virtual void											Set( ProgramParam* param, const Byte* value, UInt size );
	virtual void											Set( ProgramParam* param, const Byte* value, UInt size, UInt count );
	virtual void											Get( ProgramParam* param, Bool* value ) const;
	virtual void											Get( ProgramParam* param, Bool* value, UInt count ) const;
	virtual void											Get( ProgramParam* param, Int* value ) const;
	virtual void											Get( ProgramParam* param, Int* value, UInt count ) const;
	virtual void											Get( ProgramParam* param, Float* value ) const;
	virtual void											Get( ProgramParam* param, Float* value, UInt count ) const;
	virtual void											Get( ProgramParam* param, math::Vector2* value ) const;
	virtual void											Get( ProgramParam* param, math::Vector2* value, UInt count ) const;
	virtual void											Get( ProgramParam* param, math::Vector3* value ) const;
	virtual void											Get( ProgramParam* param, math::Vector3* value, UInt count ) const;
	virtual void											Get( ProgramParam* param, math::Vector4* value ) const;
	virtual void											Get( ProgramParam* param, math::Vector4* value, UInt count ) const;
	virtual void											Get( ProgramParam* param, math::Matrix4x4* value ) const;
	virtual void											Get( ProgramParam* param, math::Matrix4x4* value, UInt count ) const;
	virtual UInt											GetParamCount() const;
	virtual lang::String									GetParamName( UInt index ) const;
	virtual lang::String									GetParamName( ProgramParam* param ) const;
	virtual ProgramDataType									GetParamType( ProgramParam* param ) const;
	virtual UInt											GetParamSize( ProgramParam* param ) const;
	virtual UInt											GetParamElementCount( ProgramParam* param ) const;
	virtual ProgramParam*									GetParam( const lang::String& name ) const;

protected:
	lang::MapCI<lang::String, P>							_params;
	lang::Vector<lang::String>								_names;
	lang::Vector<Byte>										_data;
	ProgramStageType										_type;
};


#include "ParameterSetImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_PARAMETERSETIMPL_
