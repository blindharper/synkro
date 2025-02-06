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
// Purpose: Defines graphics program stage parameters.
//==============================================================================
#ifndef _SYNKRO_GFX_IPARAMETERSET_
#define _SYNKRO_GFX_IPARAMETERSET_


#include "config.h"
#include <core/IObject.h>
#include <lang/String.h>
#include <math/Vector2.h>
#include <math/Vector3.h>
#include <math/Vector4.h>
#include <math/Matrix4x4.h>
#include <gfx/ProgramDataType.h>


namespace synkro
{


namespace gfx
{


/**
 * Graphics program stage parameters.
 */
iface IParameterSet :
	public core::IObject
{
public:
	/**
	 * Binds parameters to the program stage.
	 * @exception GraphicsException. Thrown if some parameter cannot be set.
	 */
	virtual void											Bind() = 0;

	/**
	 * Sets boolean parameter value.
	 * @param param Parameter handle.
	 * @param value New parameter value.
	 * @exception BadArgumentException. Thrown if parameter handle is null.
	 * @exception BadArgumentException. Thrown if parameter type and value are incompatible.
	 * @exception BadArgumentException. Thrown if parameter does not belong to this parameter set.
	 */
	virtual void											Set( ProgramParam* param, Bool value ) = 0;

	/**
	 * Sets an array of boolean parameters.
	 * @param param Parameter handle.
	 * @param value Pointer to the first element's data.
	 * @param count Number of array elements.
	 * @exception BadArgumentException. Thrown if parameter handle is null.
	 * @exception BadArgumentException. Thrown if parameter type and value are incompatible.
	 * @exception BadArgumentException. Thrown if parameter element count is invalid.
	 * @exception BadArgumentException. Thrown if parameter does not belong to this parameter set.
	 */
	virtual void											Set( ProgramParam* param, const Bool* value, UInt count ) = 0;

	/**
	 * Sets whole number parameter value.
	 * @param param Parameter handle.
	 * @param value New parameter value.
	 * @exception BadArgumentException. Thrown if parameter handle is null.
	 * @exception BadArgumentException. Thrown if parameter type and value are incompatible.
	 * @exception BadArgumentException. Thrown if parameter does not belong to this parameter set.
	 */
	virtual void											Set( ProgramParam* param, Int value ) = 0;

	/**
	 * Sets an array of whole number parameters.
	 * @param param Parameter handle.
	 * @param value Pointer to the first element's data.
	 * @param count Number of array elements.
	 * @exception BadArgumentException. Thrown if parameter handle is null.
	 * @exception BadArgumentException. Thrown if parameter type and value are incompatible.
	 * @exception BadArgumentException. Thrown if parameter element count is invalid.
	 * @exception BadArgumentException. Thrown if parameter does not belong to this parameter set.
	 */
	virtual void											Set( ProgramParam* param, const Int* value, UInt count ) = 0;

	/**
	 * Sets floating-point number parameter value.
	 * @param param Parameter handle.
	 * @param value New parameter value.
	 * @exception BadArgumentException. Thrown if parameter handle is null.
	 * @exception BadArgumentException. Thrown if parameter type and value are incompatible.
	 * @exception BadArgumentException. Thrown if parameter does not belong to this parameter set.
	 */
	virtual void											Set( ProgramParam* param, Float value ) = 0;

	/**
	 * Sets an array of floating-point number parameters.
	 * @param param Parameter handle.
	 * @param value Pointer to the first element's data.
	 * @param count Number of array elements.
	 * @exception BadArgumentException. Thrown if parameter handle is null.
	 * @exception BadArgumentException. Thrown if parameter type and value are incompatible.
	 * @exception BadArgumentException. Thrown if parameter element count is invalid.
	 * @exception BadArgumentException. Thrown if parameter does not belong to this parameter set.
	 */
	virtual void											Set( ProgramParam* param, const Float* value, UInt count ) = 0;

	/**
	 * Sets 2-component vector parameter value.
	 * @param param Parameter handle.
	 * @param value New parameter value.
	 * @exception BadArgumentException. Thrown if parameter handle is null.
	 * @exception BadArgumentException. Thrown if parameter type and value are incompatible.
	 * @exception BadArgumentException. Thrown if parameter does not belong to this parameter set.
	 */
	virtual void											Set( ProgramParam* param, const math::Vector2& value ) = 0;

	/**
	 * Sets an array of 2-component vector parameters.
	 * @param param Parameter handle.
	 * @param value Pointer to the first element's data.
	 * @param count Number of array elements.
	 * @exception BadArgumentException. Thrown if parameter handle is null.
	 * @exception BadArgumentException. Thrown if parameter type and value are incompatible.
	 * @exception BadArgumentException. Thrown if parameter element count is invalid.
	 * @exception BadArgumentException. Thrown if parameter does not belong to this parameter set.
	 */
	virtual void											Set( ProgramParam* param, const math::Vector2* value, UInt count ) = 0;

	/**
	 * Sets 3-component vector parameter value.
	 * @param param Parameter handle.
	 * @param value New parameter value.
	 * @exception BadArgumentException. Thrown if parameter handle is null.
	 * @exception BadArgumentException. Thrown if parameter type and value are incompatible.
	 * @exception BadArgumentException. Thrown if parameter does not belong to this parameter set.
	 */
	virtual void											Set( ProgramParam* param, const math::Vector3& value ) = 0;

	/**
	 * Sets an array of 3-component vector parameters.
	 * @param param Parameter handle.
	 * @param value Pointer to the first element's data.
	 * @param count Number of array elements.
	 * @exception BadArgumentException. Thrown if parameter handle is null.
	 * @exception BadArgumentException. Thrown if parameter type and value are incompatible.
	 * @exception BadArgumentException. Thrown if parameter element count is invalid.
	 * @exception BadArgumentException. Thrown if parameter does not belong to this parameter set.
	 */
	virtual void											Set( ProgramParam* param, const math::Vector3* value, UInt count ) = 0;

	/**
	 * Sets 4-component vector parameter value.
	 * @param param Parameter handle.
	 * @param value New parameter value.
	 * @exception BadArgumentException. Thrown if parameter handle is null.
	 * @exception BadArgumentException. Thrown if parameter type and value are incompatible.
	 * @exception BadArgumentException. Thrown if parameter does not belong to this parameter set.
	 */
	virtual void											Set( ProgramParam* param, const math::Vector4& value ) = 0;

	/**
	 * Sets an array of 4-component vector parameters.
	 * @param param Parameter handle.
	 * @param value Pointer to the first element's data.
	 * @param count Number of array elements.
	 * @exception BadArgumentException. Thrown if parameter handle is null.
	 * @exception BadArgumentException. Thrown if parameter type and value are incompatible.
	 * @exception BadArgumentException. Thrown if parameter element count is invalid.
	 * @exception BadArgumentException. Thrown if parameter does not belong to this parameter set.
	 */
	virtual void											Set( ProgramParam* param, const math::Vector4* value, UInt count ) = 0;

	/**
	 * Sets matrix parameter value.
	 * @param param Parameter handle.
	 * @param value New parameter value.
	 * @exception BadArgumentException. Thrown if parameter handle is null.
	 * @exception BadArgumentException. Thrown if parameter type and value are incompatible.
	 * @exception BadArgumentException. Thrown if parameter does not belong to this parameter set.
	 */
	virtual void											Set( ProgramParam* param, const math::Matrix4x4& value ) = 0;

	/**
	 * Sets an array of matrix parameters.
	 * @param param Parameter handle.
	 * @param value Pointer to the first element's data.
	 * @param count Number of array elements.
	 * @exception BadArgumentException. Thrown if parameter handle is null.
	 * @exception BadArgumentException. Thrown if parameter type and value are incompatible.
	 * @exception BadArgumentException. Thrown if parameter element count is invalid.
	 * @exception BadArgumentException. Thrown if parameter does not belong to this parameter set.
	 */
	virtual void											Set( ProgramParam* param, const math::Matrix4x4* value, UInt count ) = 0;

	/**
	 * Sets structure parameter value.
	 * @param param Parameter handle.
	 * @param value Pointer to new parameter value.
	 * @param size Structure size, in bytes.
	 * @exception BadArgumentException. Thrown if parameter handle is null.
	 * @exception BadArgumentException. Thrown if parameter type and value are incompatible.
	 * @exception BadArgumentException. Thrown if parameter does not belong to this parameter set.
	 */
	virtual void											Set( ProgramParam* param, const Byte* value, UInt size ) = 0;

	/**
	 * Sets an array of structure parameters.
	 * @param param Parameter handle.
	 * @param value Pointer to the first element's data.
	 * @param size Structure size, in bytes.
	 * @param count Number of array elements.
	 * @exception BadArgumentException. Thrown if parameter handle is null.
	 * @exception BadArgumentException. Thrown if parameter type and value are incompatible.
	 * @exception BadArgumentException. Thrown if parameter element count is invalid.
	 * @exception BadArgumentException. Thrown if parameter does not belong to this parameter set.
	 */
	virtual void											Set( ProgramParam* param, const Byte* value, UInt size, UInt count ) = 0;

	/**
	 * Retrieves logical parameter value.
	 * @param param Parameter handle.
	 * @param [out] value Parameter value.
	 * @exception BadArgumentException. Thrown if parameter handle is null.
	 * @exception BadArgumentException. Thrown if value is null.
	 * @exception BadArgumentException. Thrown if parameter type and value are incompatible.
	 * @exception BadArgumentException. Thrown if parameter does not belong to this parameter set.
	 */
	virtual void											Get( ProgramParam* param, Bool* value ) const = 0;

	/**
	 * Retrieves an array of boolean parameters.
	 * @param param Parameter handle.
	 * @param [out] value Pointer to the data.
	 * @param count Number of array elements.
	 * @exception BadArgumentException. Thrown if parameter handle is null.
	 * @exception BadArgumentException. Thrown if parameter type and value are incompatible.
	 * @exception BadArgumentException. Thrown if parameter does not belong to this parameter set.
	 */
	virtual void											Get( ProgramParam* param, Bool* value, UInt count ) const = 0;

	/**
	 * Retrieves whole number parameter value.
	 * @param param Parameter handle.
	 * @param [out] value Parameter value.
	 * @exception BadArgumentException. Thrown if parameter handle is null.
	 * @exception BadArgumentException. Thrown if value is null.
	 * @exception BadArgumentException. Thrown if parameter type and value are incompatible.
	 * @exception BadArgumentException. Thrown if parameter does not belong to this parameter set.
	 */
	virtual void											Get( ProgramParam* param, Int* value ) const = 0;

	/**
	 * Retrieves an array of whole number parameters.
	 * @param param Parameter handle.
	 * @param [out] value Pointer to the data.
	 * @param count Number of array elements.
	 * @exception BadArgumentException. Thrown if parameter handle is null.
	 * @exception BadArgumentException. Thrown if parameter type and value are incompatible.
	 * @exception BadArgumentException. Thrown if parameter does not belong to this parameter set.
	 */
	virtual void											Get( ProgramParam* param, Int* value, UInt count ) const = 0;

	/**
	 * Retrieves floating-point number parameter value.
	 * @param param Parameter handle.
	 * @param [out] value Parameter value.
	 * @exception BadArgumentException. Thrown if parameter handle is null.
	 * @exception BadArgumentException. Thrown if value is null.
	 * @exception BadArgumentException. Thrown if parameter type and value are incompatible.
	 * @exception BadArgumentException. Thrown if parameter does not belong to this parameter set.
	 */
	virtual void											Get( ProgramParam* param, Float* value ) const = 0;

	/**
	 * Retrieves an array of floating-point number parameters.
	 * @param param Parameter handle.
	 * @param [out] value Pointer to the data.
	 * @param count Number of array elements.
	 * @exception BadArgumentException. Thrown if parameter handle is null.
	 * @exception BadArgumentException. Thrown if parameter type and value are incompatible.
	 * @exception BadArgumentException. Thrown if parameter does not belong to this parameter set.
	 */
	virtual void											Get( ProgramParam* param, Float* value, UInt count ) const = 0;

	/**
	 * Retrieves 2-component vector parameter value.
	 * @param param Parameter handle.
	 * @param [out] value Parameter value.
	 * @exception BadArgumentException. Thrown if parameter handle is null.
	 * @exception BadArgumentException. Thrown if value is null.
	 * @exception BadArgumentException. Thrown if parameter type and value are incompatible.
	 * @exception BadArgumentException. Thrown if parameter does not belong to this parameter set.
	 */
	virtual void											Get( ProgramParam* param, math::Vector2* value ) const = 0;

	/**
	 * Retrieves an array of 2-component vector parameters.
	 * @param param Parameter handle.
	 * @param [out] value Pointer to the data.
	 * @param count Number of array elements.
	 * @exception BadArgumentException. Thrown if parameter handle is null.
	 * @exception BadArgumentException. Thrown if parameter type and value are incompatible.
	 * @exception BadArgumentException. Thrown if parameter does not belong to this parameter set.
	 */
	virtual void											Get( ProgramParam* param, math::Vector2* value, UInt count ) const = 0;

	/**
	 * Retrieves 3-component vector parameter value.
	 * @param param Parameter handle.
	 * @param [out] value Parameter value.
	 * @exception BadArgumentException. Thrown if parameter handle is null.
	 * @exception BadArgumentException. Thrown if value is null.
	 * @exception BadArgumentException. Thrown if parameter type and value are incompatible.
	 * @exception BadArgumentException. Thrown if parameter does not belong to this parameter set.
	 */
	virtual void											Get( ProgramParam* param, math::Vector3* value ) const = 0;

	/**
	 * Retrieves an array of 3-component vector parameters.
	 * @param param Parameter handle.
	 * @param [out] value Pointer to the data.
	 * @param count Number of array elements.
	 * @exception BadArgumentException. Thrown if parameter handle is null.
	 * @exception BadArgumentException. Thrown if parameter type and value are incompatible.
	 * @exception BadArgumentException. Thrown if parameter does not belong to this parameter set.
	 */
	virtual void											Get( ProgramParam* param, math::Vector3* value, UInt count ) const = 0;

	/**
	 * Retrieves 4-component vector parameter value.
	 * @param param Parameter handle.
	 * @param [out] value Parameter value.
	 * @exception BadArgumentException. Thrown if parameter handle is null.
	 * @exception BadArgumentException. Thrown if value is null.
	 * @exception BadArgumentException. Thrown if parameter type and value are incompatible.
	 * @exception BadArgumentException. Thrown if parameter does not belong to this parameter set.
	 */
	virtual void											Get( ProgramParam* param, math::Vector4* value ) const = 0;

	/**
	 * Retrieves an array of 4-component vector parameters.
	 * @param param Parameter handle.
	 * @param [out] value Pointer to the data.
	 * @param count Number of array elements.
	 * @exception BadArgumentException. Thrown if parameter handle is null.
	 * @exception BadArgumentException. Thrown if parameter type and value are incompatible.
	 * @exception BadArgumentException. Thrown if parameter does not belong to this parameter set.
	 */
	virtual void											Get( ProgramParam* param, math::Vector4* value, UInt count ) const = 0;

	/**
	 * Retrieves matrix parameter value.
	 * @param param Parameter handle.
	 * @param [out] value Parameter value.
	 * @exception BadArgumentException. Thrown if parameter handle is null.
	 * @exception BadArgumentException. Thrown if value is null.
	 * @exception BadArgumentException. Thrown if parameter type and value are incompatible.
	 * @exception BadArgumentException. Thrown if parameter does not belong to this parameter set.
	 */
	virtual void											Get( ProgramParam* param, math::Matrix4x4* value ) const = 0;

	/**
	 * Retrieves an array of matrix parameters.
	 * @param param Parameter handle.
	 * @param [out] value Pointer to the data.
	 * @param count Number of array elements.
	 * @exception BadArgumentException. Thrown if parameter handle is null.
	 * @exception BadArgumentException. Thrown if parameter type and value are incompatible.
	 * @exception BadArgumentException. Thrown if parameter does not belong to this parameter set.
	 */
	virtual void											Get( ProgramParam* param, math::Matrix4x4* value, UInt count ) const = 0;

	/**
	 * Retrieves the number of parameters in the set.
	 */
	virtual UInt											GetParamCount() const = 0;

	/**
	 * Retrieves parameter name by index.
	 * @param index Index of the parameter to retrieve.
	 * @return Requested parameter name.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual lang::String									GetParamName( UInt index ) const = 0;

	/**
	 * Retrieves parameter name by handle.
	 * @param param Handle of the parameter to retrieve.
	 * @return Requested parameter name.
	 * @exception BadArgumentException Wrong handle.
	 */
	virtual lang::String									GetParamName( ProgramParam* param ) const = 0;

	/**
	 * Retrieves parameter type by handle.
	 * @param param Handle of the parameter to retrieve.
	 * @return Requested parameter type.
	 * @exception BadArgumentException Wrong handle.
	 */
	virtual ProgramDataType									GetParamType( ProgramParam* param ) const = 0;

	/**
	 * Retrieves parameter size by handle.
	 * @param param Handle of the parameter to retrieve.
	 * @return Requested parameter size, in bytes.
	 * @exception BadArgumentException Wrong handle.
	 */
	virtual UInt											GetParamSize( ProgramParam* param ) const = 0;

	/**
	 * Retrieves the number of parameter's elements by handle.
	 * @param param Handle of the parameter to retrieve.
	 * @return Number of parameter's elements.
	 * @exception BadArgumentException Wrong handle.
	 */
	virtual UInt											GetParamElementCount( ProgramParam* param ) const = 0;

	/**
	 * Retrieves parameter handle by name.
	 * @param name Parameter name.
	 * @return Parameter handle, if one exists, or null otherwise.
	 */
	virtual ProgramParam*									GetParam( const lang::String& name ) const = 0;

	/**
	 * Produces a copy of the parameter set.
	 * @param ownerID Identifer of the owner. An owner is the object invoking parameter set's methods.
	 * @param cloneShared Indicates whether to force cloning of the shared (sp_) parameters from original set.
	 * @return Newly created parameter set.
	 */
	virtual IParameterSet*									Clone( UInt ownerID, Bool cloneShared ) const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IPARAMETERSET_
