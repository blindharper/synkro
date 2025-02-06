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
#ifndef _SYNKRO_CORE_CALLSTACK_
#define _SYNKRO_CORE_CALLSTACK_


#include "config.h"
#include <lang/String.h>


// Records entering a procedure.
#if defined( SYNKRO_DEBUG )
	#define SynkroCall( NAME, CTX ) synkro::core::CallTrigger __ct( NAME, __FILE__, __LINE__, CTX )
#else
	#define SynkroCall( NAME, CTX )
#endif // defined( SYNKRO_DEBUG )


namespace synkro
{


namespace core
{


struct CallItem
{
	CallItem( const lang::String& name, const lang::String& file, int line, const lang::String& context ) :
		Name( name ),
		File( file ),
		Line( line ),
		Context( context )
	{
	}

	CallItem() :
		Line( 0 )
	{
	}

	lang::String	Name;
	lang::String	File;
	int				Line;
	lang::String	Context;
};


// Call stack.
class SYNKRO_API CallStack
{
public:
	// Performs internal initialization.
	static void												Initialize();

	// Performs internal deinitialization.
	static void												Finalize();

	// Enters a procedure.
	static void												EnterProc( const char* name, const char* file, int line, const lang::String& context );

	// Leaves current procedure.
	static void												LeaveProc();

	// Retrieves stack trace.
	static lang::String										GetStackTrace();

	// Retrieves a particular call.
	static Bool												GetCall( CallItem& call );

	// Stops maintaining stack. This is called when an exception is thrown.
	static void												Stop();
};


// Helper object for stack tracing.
class CallTrigger
{
public:
	SYNKRO_INLINE CallTrigger( const char* name, const char* file, int line, const lang::String& context )
	{
		CallStack::EnterProc( name, file, line, context );
	}

	SYNKRO_INLINE ~CallTrigger()
	{
		CallStack::LeaveProc();
	}
};


} // core


} // synkro


#endif // _SYNKRO_CORE_CALLSTACK_
