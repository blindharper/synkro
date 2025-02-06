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
// Purpose: Program call stack.
//==============================================================================
#include "config.h"
#include "CallStack.h"
#include "ExceptionHandler.h"
#include <mem/OperatorNew.h>
#include <io/Path.h>
#include <lang/Stack.h>
#include <lang/Formatter.h>
#include <internal/SafeDelete.h>


//------------------------------------------------------------------------------

using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace core
{


static Stack<CallItem>* _calls = nullptr;
static Bool _stopped = false;


void CallStack::Initialize()
{
	if ( _calls == nullptr )
	{
		_calls = new Stack<CallItem>( A(CallItem), 1000 );
	}
}

void CallStack::Finalize()
{
	SafeDelete( _calls );
}

void CallStack::EnterProc( const char* name, const char* file, int line, const String& context )
{
	_calls->Push( CallItem(name, file, line, context) );
}

void CallStack::LeaveProc()
{
	if ( !_stopped )
	{
		_calls->Pop();
	}
}

String CallStack::GetStackTrace()
{
	String trace;

	while ( _calls->Size() > 0 )
	{
		CallItem item = _calls->Top();

		Path pathName( item.File );
		String parent = pathName.GetParent();
		Path pathParent( parent );

		trace = trace.Append( String::Format(L"{0}()\t File: {1}/{2}, Line: {3}\t Context: {4}\r\n", item.Name, pathParent.GetName(), pathName.GetName(), item.Line, item.Context) );
		_calls->Pop();
	}

	return trace.Trim(L"\r\n");
}

Bool CallStack::GetCall( CallItem& call )
{
	if ( _calls->Size() == 0 )
		return false;

	call = _calls->Top();
	_calls->Pop();

	return true;
}

void CallStack::Stop()
{
	_stopped = true;
}


} // core


} // synkro
