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
// Purpose: Defines expression script.
//==============================================================================
#ifndef _SYNKRO_ANIM_IEXPRESSIONSCRIPT_
#define _SYNKRO_ANIM_IEXPRESSIONSCRIPT_


#include "config.h"
#include <core/IObject.h>
#include <anim/AnimationDataType.h>
#include <img/ColorGradient.h>
#include <lang/Point.h>
#include <lang/Range.h>
#include <lang/Rect.h>
#include <lang/RectF.h>
#include <lang/Size.h>
#include <math/Matrix4x4.h>


namespace synkro
{


namespace anim
{


/**
 * Expression script.
 * 
 * Consists of a set of statements ending with return.
 * Example: 'return 0.5*sin(time);', where 'time' is a predefined scalar parameter.
 */
iface IExpressionScript :
	public core::IObject
{
public:
	/**
	 * Prepares script for execution.
	 * @exception ExpressionException Invalid script syntax.
	 */
	virtual void											Prepare() = 0;

	/**
	 * Declares expression parameter.
	 * @param name Parameter name.
	 * @param type Parameter type.
	 * @return Parameter handle.
	 * @exception BadArgumentException Parameter with this name already exists.
	 */
	virtual ExpressionParam*								DeclareParam( const lang::String& name, const AnimationDataType& type ) = 0;

	/**
	 * Sets expression parameter value.
	 * @param param Parameter handle.
	 * @param value Parameter value.
	 * @exception BadArgumentException Parameter is null.
	 * @exception InvalidOperationException Invalid parameter value type.
	 */
	virtual void											SetParamValue( const ExpressionParam* param, Float value ) = 0;

	/**
	 * Sets expression parameter value.
	 * @param param Parameter handle.
	 * @param value Parameter value.
	 * @exception BadArgumentException Parameter is null.
	 * @exception InvalidOperationException Invalid parameter value type.
	 */
	virtual void											SetParamValue( const ExpressionParam* param, const img::Color& value ) = 0;

	/**
	 * Sets expression parameter value.
	 * @param param Parameter handle.
	 * @param value Parameter value.
	 * @exception BadArgumentException Parameter is null.
	 * @exception InvalidOperationException Invalid parameter value type.
	 */
	virtual void											SetParamValue( const ExpressionParam* param, const math::Vector3& value ) = 0;

	/**
	 * Sets expression parameter value.
	 * @param param Parameter handle.
	 * @param value Parameter value.
	 * @exception BadArgumentException Parameter is null.
	 * @exception InvalidOperationException Invalid parameter value type.
	 */
	virtual void											SetParamValue( const ExpressionParam* param, const math::Matrix4x4& value ) = 0;

	/**
	 * Retrieves expression value.
	 * @param [out] value Expression value.
	 * @exception ExpressionException Wrong expression type.
	 */
	virtual void											GetValue( Bool& value ) const = 0;

	/**
	 * Retrieves expression value.
	 * @param [out] value Expression value.
	 * @exception ExpressionException Wrong expression type.
	 */
	virtual void											GetValue( img::Color& value ) const = 0;

	/**
	 * Retrieves expression value.
	 * @param [out] value Expression value.
	 * @exception ExpressionException Wrong expression type.
	 */
	virtual void											GetValue( img::ColorGradient& value ) const = 0;

	/**
	 * Retrieves expression value.
	 * @param [out] value Expression value.
	 * @exception ExpressionException Wrong expression type.
	 */
	virtual void											GetValue( Float& value ) const = 0;

	/**
	 * Retrieves expression value.
	 * @param [out] value Expression value.
	 * @exception ExpressionException Wrong expression type.
	 */
	virtual void											GetValue( Int& value ) const = 0;

	/**
	 * Retrieves expression value.
	 * @param [out] value Expression value.
	 * @exception ExpressionException Wrong expression type.
	 */
	virtual void											GetValue( math::Matrix4x4& value ) const = 0;

	/**
	 * Retrieves expression value.
	 * @param [out] value Expression value.
	 * @exception ExpressionException Wrong expression type.
	 */
	virtual void											GetValue( lang::Point& value ) const = 0;

	/**
	 * Retrieves expression value.
	 * @param [out] value Expression value.
	 * @exception ExpressionException Wrong expression type.
	 */
	virtual void											GetValue( lang::Range& value ) const = 0;

	/**
	 * Retrieves expression value.
	 * @param [out] value Expression value.
	 * @exception ExpressionException Wrong expression type.
	 */
	virtual void											GetValue( math::Quaternion& value ) const = 0;

	/**
	 * Retrieves expression value.
	 * @param [out] value Expression value.
	 * @exception ExpressionException Wrong expression type.
	 */
	virtual void											GetValue( lang::Rect& value ) const = 0;

	/**
	 * Retrieves expression value.
	 * @param [out] value Expression value.
	 * @exception ExpressionException Wrong expression type.
	 */
	virtual void											GetValue( lang::RectF& value ) const = 0;

	/**
	 * Retrieves expression value.
	 * @param [out] value Expression value.
	 * @exception ExpressionException Wrong expression type.
	 */
	virtual void											GetValue( lang::Size& value ) const = 0;

	/**
	 * Retrieves expression value.
	 * @param [out] value Expression value.
	 * @exception ExpressionException Wrong expression type.
	 */
	virtual void											GetValue( math::Vector3& value ) const = 0;

	/**
	 * Retrieves expression parameter by name.
	 * @param name Parameter name.
	 * @return Parameter handle.
	 */
	virtual ExpressionParam*								GetParam( const lang::String& name ) const = 0;

	/**
	 * Retrieves expression parameter value.
	 * @param param Parameter handle.
	 * @param [out] value Parameter value.
	 * @exception BadArgumentException Parameter is null.
	 * @exception InvalidOperationException Invalid parameter value type.
	 */
	virtual void											GetParamValue( const ExpressionParam* param, Float& value ) const = 0;

	/**
	 * Retrieves expression parameter value.
	 * @param param Parameter handle.
	 * @param [out] value Parameter value.
	 * @exception BadArgumentException Parameter is null.
	 * @exception InvalidOperationException Invalid parameter value type.
	 */
	virtual void											GetParamValue( const ExpressionParam* param, img::Color& value ) const = 0;

	/**
	 * Retrieves expression parameter value.
	 * @param param Parameter handle.
	 * @param [out] value Parameter value.
	 * @exception BadArgumentException Parameter is null.
	 * @exception InvalidOperationException Invalid parameter value type.
	 */
	virtual void											GetParamValue( const ExpressionParam* param, math::Vector3& value ) const = 0;

	/**
	 * Retrieves expression parameter value.
	 * @param param Parameter handle.
	 * @param [out] value Parameter value.
	 * @exception BadArgumentException Parameter is null.
	 * @exception InvalidOperationException Invalid parameter value type.
	 */
	virtual void											GetParamValue( const ExpressionParam* param, math::Matrix4x4& value ) const = 0;

	/** 
	 * Retrieves expression data type.
	 */
	virtual AnimationDataType								GetType() const = 0;

	/**
	 * Retrieves script text.
	 */
	virtual lang::String									GetText() const = 0;

	/**
	 * Creates an exact copy of this script with its own set of parameters.
	 * @exception InvalidOperationException Script is not prepared.
	 * @return Cloned script.
	 */
	virtual IExpressionScript*								Clone() const = 0;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_IEXPRESSIONSCRIPT_
