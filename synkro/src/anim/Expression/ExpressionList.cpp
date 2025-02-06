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
// Purpose: Expression list.
//==============================================================================
#include "config.h"
#include "ExpressionList.h"
#include <mem/OperatorNew.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


ExpressionList::ExpressionList( const ExpressionList& other, BaseExpressionScript* script ) :
	_list( A(Expression*) )
{
	for ( UInt i = 0; i < other._list.Size(); ++i )
	{
		_list.Add( other._list[i]->Clone(script) );
	}
}

ExpressionList::ExpressionList() :
	_list( A(Expression*) )
{
}

ExpressionList::~ExpressionList()
{
	for ( UInt i = 0; i < _list.Size(); ++i )
	{
		delete _list[i];
	}
}

ExpressionList* ExpressionList::Clone( BaseExpressionScript* script ) const
{
	return new ExpressionList( *this, script );
}

void ExpressionList::Prepend( Expression* expr )
{
	_list.Insert( 0, expr );
}

void ExpressionList::Append( Expression* expr )
{
	_list.Add( expr );
}

UInt ExpressionList::GetSize() const
{
	return _list.Size();
}

Expression* ExpressionList::Get( UInt index ) const
{
	return (index < _list.Size()) ? _list[index] : nullptr;
}

Bool ExpressionList::ReferencesVariable( const String& name ) const
{
	for ( UInt i = 0; i < _list.Size(); ++i )
	{
		if ( _list[i]->ReferencesVariable(name) )
			return true;
	}
	return false;
}


} // anim


} // synkro
