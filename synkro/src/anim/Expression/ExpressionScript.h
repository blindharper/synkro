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
#ifndef _SYNKRO_ANIM_EXPRESSIONSCRIPT_
#define _SYNKRO_ANIM_EXPRESSIONSCRIPT_


#include "config.h"
#include <core/ObjectImpl.h>
#include <anim/IExpressionScript.h>
#include "ExpressionStatement.h"
#include "Expression.h"
#include "Token.h"
#include "ExpressionCompiler.h"
#include "ExpressionParamEx.h"
#include "BaseExpressionScript.h"
#include <lang/Formatter.h>
#include <lang/Vector.h>
#include <lang/Map.h>


namespace synkro
{


namespace anim
{


// Expression script implementation.
class ExpressionScript :
	public core::ObjectImpl<IExpressionScript>,
	public BaseExpressionScript
{
public:
	// Constructors & destructor.
	ExpressionScript( ExpressionCompiler* compiler, const lang::String& text );
	ExpressionScript( const ExpressionScript& other );
	~ExpressionScript();

	// IExpressionScript methods.
	void													Prepare();
	ExpressionParam*										DeclareParam( const lang::String& name, const AnimationDataType& type );
	void													SetParamValue( const ExpressionParam* param, Float value );
	void													SetParamValue( const ExpressionParam* param, const img::Color& value );
	void													SetParamValue( const ExpressionParam* param, const math::Vector3& value );
	void													SetParamValue( const ExpressionParam* param, const math::Matrix4x4& value );
	void													GetValue( Bool& value ) const;
	void													GetValue( img::Color& value ) const;
	void													GetValue( img::ColorGradient& value ) const;
	void													GetValue( Float& value ) const;
	void													GetValue( Int& value ) const;
	void													GetValue( math::Matrix4x4& value ) const;
	void													GetValue( lang::Point& value ) const;
	void													GetValue( lang::Range& value ) const;
	void													GetValue( math::Quaternion& value ) const;
	void													GetValue( lang::Rect& value ) const;
	void													GetValue( lang::RectF& value ) const;
	void													GetValue( lang::Size& value ) const;
	void													GetValue( math::Vector3& value ) const;
	ExpressionParam*										GetParam( const lang::String& name ) const;
	void													GetParamValue( const ExpressionParam* param, Float& value ) const;
	void													GetParamValue( const ExpressionParam* param, img::Color& value ) const;
	void													GetParamValue( const ExpressionParam* param, math::Vector3& value ) const;
	void													GetParamValue( const ExpressionParam* param, math::Matrix4x4& value ) const;
	AnimationDataType										GetType() const;
	lang::String											GetText() const;
	IExpressionScript*										Clone() const;

	// BaseExpressionScript methods.
	void													Validate();
	void													DeclareVariable( Variable* var );
	void													SetReturnValue( Expression* value );
	void													AddStatement( ExpressionStatement* statement );
	ExpressionParam*										GetParameter( const lang::String& name ) const;
	Variable*												CloneVariable( const lang::String& name ) const;

	// Other methods.
	Bool													Call( ExpressionStatement* statement ) const;

private:
	enum
	{
		VALUE_COUNT = 16,
	};

	typedef lang::MapPair<lang::String, ExpressionParamEx*>	ParamEntry;
	typedef lang::MapPair<lang::String, Variable*>			VariableEntry;

	ExpressionCompiler*										_compiler;
	lang::Map<lang::String, ExpressionParamEx*>				_params;
	mutable lang::Map<lang::String, Variable*>				_variables;
	lang::Vector<ExpressionStatement*>						_statements;
	lang::String											_text;
	mutable AnimationDataType								_type;
	mutable Float											_value[VALUE_COUNT];

	void													Evaluate() const;
	void													ValidateParam( const ExpressionParam* param, const AnimationDataType& type ) const;
};


#include "ExpressionScript.inl"


} // anim


} // synkro


#endif // _SYNKRO_ANIM_EXPRESSIONSCRIPT_
