//==============================================================================
// This file is a part of the Synkro Framework.
// 
// Copyright (c) Nobody. No rights reserved ;-7
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is encouraged without any permission from the Synkro Project.
// Website: https://synkro.org Email: mailto:blindharper70@gmail.com
//
// Purpose: Standard profiler implementation.
//==============================================================================
#ifndef _SYNKRO_PRF_STDPROFILER_
#define _SYNKRO_PRF_STDPROFILER_


#include "config.h"
#include <lang/Tree.h>
#include <lang/Stack.h>
#include <lang/Vector.h>
#include <internal/Zero.h>
#include <internal/Timer.h>
#include "Allocator.h"


using namespace synkro::lang;
using namespace synkro::prf;
using namespace synkro;


// Profile block information.
struct ProfileBlock
{
	char		name[260];	// Block name.
	UInt		id;			// Unique block identifier.
	Bool		collapsed;	// "Collapsed" flag.
	UInt		hits;		// Hit count.
	ULong		stamp;		// Last time stamp.
	ULong		ticks;		// Total profile ticks.
	ULong		dirtyTicks;	// Redundant ticks.

	ProfileBlock( const char* n = "", ULong s = 0, Bool c = false ) :
		id( 0 ),
		collapsed( c ),
		hits( 0 ),
		stamp( s ),
		ticks( 0 ),
		dirtyTicks( 0 )
	{
		Zero( name, 260 );
		strcpy( name, n );
	}
 
	Bool operator==( const ProfileBlock& other )
	{
		return _strcmpi(name, other.name) == 0;
	}
};

// Accumulated profile block information.
struct ProfileAccum
{
	char	name[260];
	UInt	id;
	UInt	hits;
	ULong	ticks;

	ProfileAccum( const char* n = "", UInt i = 0 ) :
		id( i ),
		hits( 0 ),
		ticks( 0 )
	{
		Zero( name, 260 );
		strcpy( name, n );
	}
};


typedef class Stack<TreeIterator<ProfileBlock>, synkro::prf::Allocator<TreeIterator<ProfileBlock> > > ProfileStack;
typedef class Tree<ProfileBlock, synkro::prf::Allocator< TreeItem<ProfileBlock> > > ProfileTree;
typedef class Vector<ProfileAccum, synkro::prf::Allocator<ProfileAccum> > ProfileVector;


namespace synkro
{


namespace prf
{


// Code profiler.
class StdProfiler
{
public:
	// Performs profiler initialization.
	static void												Initialize( Bool expand );

	// Begins profiling of the specified block of code.
	// @param name Name of the scope to profile.
	static void												BeginProfile( const char* name, Bool collapse );

	// Ends profiling of the current block of code.
	static void												EndProfile();

	// Saves profile report to disk file.
	// @param filename Name of the report file.
	// param plain True to create plain text report, false for rich text report.
	static void												SaveReport( const char* filename, Bool accumulate, Bool plain );

private:
	enum
	{
		STACK_DEPTH = 64,
	};

	static Bool												_expand;
	static Timer											_timer;
	static ProfileStack										_stack;
	static ProfileTree										_profiles;
	static ProfileVector									_blocks;

	static void												CorrectTicks();
	static ProfileAccum*									GetBlock( const char* name, UInt id, ProfileVector& blocks );
	static UInt											ReadBlockTable( const char* filename, ProfileVector& blocks );
	static void												WriteBlockTable( const char* filename, const ProfileVector& blocks, UInt runs );
	static void												SaveReportPlain( const char* filename, Bool accumulate );
	static void												SaveReportRich( const char* filename, Bool accumulate );
};


} // prf


} // synkro


#endif // _SYNKRO_PRF_STDPROFILER_
