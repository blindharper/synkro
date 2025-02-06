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
#include "config.h"
#include "StdProfiler.h"
#include <internal/BinarySemaphore.h>


//------------------------------------------------------------------------------

using namespace synkro;
using namespace synkro::lang;

//------------------------------------------------------------------------------


// Global variables.
static BinarySemaphore _semaphore( true );		// Binary semaphore for synchronization.

// Constants.
static char _line1[200];
static char _line2[200];

// Calculates formatted number width.
static UInt GetWidth( ULong num, Bool group )
{
	char buf[32];
	sprintf( buf, "%I64u", num );
	UInt width = (UInt)strlen( buf );
	if ( group )
	{
		UInt groupCount = width/3;
		if ( (width % 3) == 0 )
		{
			--groupCount;
		}
		width += groupCount;
	}
	return width;
}

// Calculates formatted number width.
static UInt GetWidth( UInt num, Bool group )
{
	char buf[32];
	sprintf( buf, "%d", num );
	UInt width = (UInt)strlen( buf );
	if ( group )
	{
		UInt groupCount = width/3;
		if ( (width % 3) == 0 )
		{
			--groupCount;
		}
		width += groupCount;
	}
	return width;
}

// Updates maximum column width.
static UInt MaxWidth( UInt width1, UInt width2 )
{
	return (width1 > width2) ? width1 : width2;
}

// Prints report header.
static void PrintHeader( FILE* file )
{
	time_t t; time( &t );
	struct tm* newtime; newtime = localtime( &t );
	char buf[32]; sprintf( buf, "%s", asctime(newtime) );
	UInt padWidth = ((UInt)strlen(_line1) - (UInt)strlen(buf))/2;
	char pad[100]; memset( pad, ' ', padWidth ); pad[padWidth] = '\0';

	fprintf( file, _line1 );
	fprintf( file, "\n" );
	fprintf( file, pad );
	fprintf( file, buf );
}

// Prints report section's header.
static void PrintSectionHeader( FILE* file, UInt num, const char* name )
{
	fprintf( file, "\n" );
	fprintf( file, _line2 );
	fprintf( file, "\n%d. %s\n", num, name );
	fprintf( file, _line2 );
	fprintf( file, "\n" );
}

// Prints report footer.
static void PrintFooter( FILE* file )
{
	char buf[] = "End of report.";
	UInt padWidth = ((UInt)strlen(_line1) - (UInt)strlen(buf))/2;
	char pad[100]; memset( pad, ' ', padWidth ); pad[padWidth] = '\0';

	fprintf( file, "\n" );
	fprintf( file, _line1 );
	fprintf( file, "\n" );
	fprintf( file, pad );
	fprintf( file, buf );
	fprintf( file, "\n" );
	fprintf( file, _line1 );
	fprintf( file, "\n" );
}

// Prints a string at the given position.
static void PrintString( FILE* file, const char* str, UInt pos, UInt max )
{
	static char fmt[8];
	sprintf( fmt, "%%-%ds", max - pos );
	fprintf( file, fmt, str );
}

// Prints a string at the current position.
static void PrintString( FILE* file, const char* str )
{
	fprintf( file, str );
}

// Prints a whole number in the given position.
static void PrintInt( FILE* file, UInt num, UInt pos, UInt max )
{
	static char fmt[8];
	sprintf( fmt, "%%%dd", max - pos + 2 );
	fprintf( file, fmt, num );
}

// Prints a whole number at the given position, using comma to group digits.
static void PrintInt0( FILE* file, const char* fmt, const char* buf )
{
	static char txt[32];
	memset( txt, 0, 32 );

	static char str[32];
	memset( str, 0, 32 );
	
	int cnt = 0;
	int len = (int)strlen( buf );
	for ( int i = len-1; i >= 0; --i )
	{
		strcpy( txt, str );
		strncpy( str, &buf[i], 1 );
		str[1] = 0;
		strcat( str, txt );
		if ( ++cnt == 3 )
		{
			if ( i > 0 )
			{
				strcpy( txt, str );
				strncpy( str, ",", 1 );
				str[1] = 0;
				strcat( str, txt );
			}
			cnt = 0;
		}
	}

	if ( fmt != nullptr )
	{
		fprintf( file, fmt, str );
	}
	else
	{
		fprintf( file, str );
	}
}

// Prints a whole number at the given position, using comma to group digits.
static void PrintInt2( FILE* file, ULong num, UInt pos, UInt max )
{
	static char fmt[8];
	sprintf( fmt, "%%%ds", max - pos + 2 );

	static char tmp[32];
	sprintf( tmp, "%I64u", num );

	PrintInt0( file, fmt, tmp );
}

// Prints a whole number at the given position, using comma to group digits.
static void PrintInt2( FILE* file, UInt num, UInt pos, UInt max )
{
	static char fmt[8];
	sprintf( fmt, "%%%ds", max - pos + 2 );

	static char tmp[32];
	sprintf( tmp, "%d", num );

	PrintInt0( file, fmt, tmp );
}

// Prints a whole number at the given position, using comma to group digits.
static void PrintInt3( FILE* file, ULong num )
{
	static char tmp[32];
	sprintf( tmp, "%I64u", num );
	PrintInt0( file, nullptr, tmp );
}

// Prints a whole number at the given position, using comma to group digits.
static void PrintInt3( FILE* file, UInt num )
{
	static char tmp[32];
	sprintf( tmp, "%d", num );
	PrintInt0( file, nullptr, tmp );
}

// Prints a floating-point value in the given position.
static void PrintFloat( FILE* file, Float num, UInt pos, UInt max )
{
	static char fmt[8];
	sprintf( fmt, "%%%d.3f", max - pos + 2 );
	fprintf( file, fmt, num );
}

// Prints padding.
static void PrintPad( FILE* file, UInt width )
{
	static char pad[100];
	memset( pad, ' ', 100 ); pad[width] = '\0';
	fprintf( file, pad );
}

// Prints column.
static void PrintColumn( FILE* file, UInt width, const char* str )
{
	PrintPad( file, width-(UInt)strlen(str)+1 );
	PrintString( file, str );
}


namespace synkro
{


namespace prf
{


Bool StdProfiler::_expand = false;
Timer StdProfiler::_timer;
ProfileStack StdProfiler::_stack( prf::Allocator<TreeIterator<ProfileBlock> >(""), StdProfiler::STACK_DEPTH );
ProfileTree StdProfiler::_profiles( prf::Allocator<TreeItem<ProfileBlock> >("") );
ProfileVector StdProfiler::_blocks( prf::Allocator<ProfileAccum>("") );


void StdProfiler::Initialize( Bool expand )
{
	_expand = expand;

	// Create root profile.
	if ( _profiles.IsEmpty() )
	{
		ProfileBlock root( "Synkro", _timer.GetTimeStamp() );
		TreeIterator<ProfileBlock> itRoot = _profiles.Add( 0, root );
		_stack.Push( itRoot );
	}
}

void StdProfiler::BeginProfile( const char* name, Bool collapse )
{
SEMAPHORE_WAIT(_semaphore)

	// Get starting profile time.
	ULong startTime = _timer.GetTimeStamp();

	// Get parent profile.
	TreeIterator<ProfileBlock> itParent = _stack.Top();
	
	// Enable profiling if parent block is not collapsed or expanding is forced.
	if ( !(*itParent).collapsed || _expand )
	{
		// Find existing profile or create new one.
		ProfileBlock profile( name, 0, collapse );
		TreeIterator<ProfileBlock> itProfile = _profiles.Find( itParent, profile );
		if ( !itProfile.IsValid() )
		{
			static UInt _id = 0;
			profile.id = ++_id;
			itProfile = _profiles.Add( itParent, profile );
		}
		
		// Save current profile to stack.	
		_stack.Push( itProfile );

		// Update time stamps.
		(*itProfile).dirtyTicks += ( _timer.GetTimeStamp() - startTime );
		(*itProfile).stamp = _timer.GetTimeStamp();
	}
	else
	{
		// Add fake block with id == 0 to balance stack.
		static ProfileBlock _block;
		static TreeItem<ProfileBlock> _item( _block );
		static TreeIterator<ProfileBlock> it( &_item );
		_stack.Push( it );
	}

SEMAPHORE_SIGNAL(_semaphore)
}

void StdProfiler::EndProfile()
{
SEMAPHORE_WAIT(_semaphore)

	// Get ending profile time.
	ULong endTime = _timer.GetTimeStamp();

	// Retrieve current profile from stack.
	TreeIterator<ProfileBlock> itProfile = _stack.Top();
	_stack.Pop();

	// Accumulate ticks.
	if ( (*itProfile).id != 0 )
	{
		ULong deltaTime = endTime - (*itProfile).stamp;
		(*itProfile).ticks += deltaTime;
		(*itProfile).hits += 1;
		(*itProfile).dirtyTicks += ( _timer.GetTimeStamp() - endTime );
	}

SEMAPHORE_SIGNAL(_semaphore)
}

void StdProfiler::SaveReport( const char* filename, Bool accumulate, Bool plain )
{
	if ( !filename || (strlen(filename) == 0) || (_stack.Size() == 0) )
		return;

	if ( plain )
		SaveReportPlain( filename, plain );
	else
		SaveReportRich( filename, plain );
}

void StdProfiler::CorrectTicks()
{
	TreeIterator<ProfileBlock> itProfile = _profiles.Root();
	TreeIterator<ProfileBlock> itParent;

	for ( ; itProfile.IsValid() ; itProfile = _profiles.TraverseDepth(itProfile) )
	{
		itParent = itProfile; --itParent;

		if ( itParent.IsValid() )
			(*itParent).ticks -= (*itProfile).dirtyTicks;
	}
}

ProfileAccum* StdProfiler::GetBlock( const char* name, UInt id, ProfileVector& blocks )
{
	for ( UInt i = 0; i < blocks.Size(); ++i )
	{
		if ( (blocks[i].id == id) && (strcmp(blocks[i].name, name) == 0) )
		{
			return &blocks[i];
		}
	}

	return 0;
}

UInt StdProfiler::ReadBlockTable( const char* filename, ProfileVector& blocks )
{
	FILE* file = NULL;
	UInt runs = 0;
	Byte len = 0;

	__try
	{
		if ( file = fopen(filename, "r") )
		{
			fread( &runs, 1, sizeof(runs), file );
			for ( ; !feof(file) ; )
			{
				ProfileAccum acc;
				fread( &len, 1, 1, file );
				fread( acc.name, 1, len, file ); acc.name[len] = '\0';
				fread( &acc.id, 1, sizeof(acc.id), file );
				fread( &acc.hits, 1, sizeof(acc.hits), file );
				fread( &acc.ticks, 1, sizeof(acc.ticks), file );
				blocks.Add( acc );
			}
		}
	}
	__finally
	{
		if ( file != NULL )
			fclose( file );
	}

	return runs;
}

void StdProfiler::WriteBlockTable( const char* filename, const ProfileVector& blocks, UInt runs )
{
	FILE* file = NULL;
	size_t len = 0;

	__try
	{
		if ( file = fopen(filename, "w") )
		{
			fwrite( &runs, 1, sizeof(runs), file );
			for ( UInt i = 0; i < blocks.Size(); ++i )
			{
				len = strlen( blocks[i].name );
				fwrite( &len, 1, 1, file );
				fwrite( blocks[i].name, 1, len, file );
				fwrite( &blocks[i].id, 1, sizeof(blocks[i].id), file );
				fwrite( &blocks[i].hits, 1, sizeof(blocks[i].hits), file );
				fwrite( &blocks[i].ticks, 1, sizeof(blocks[i].ticks), file );
			}
		}
	}
	__finally
	{
		if ( file != NULL )
			fclose( file );
	}
}

void StdProfiler::SaveReportPlain( const char* filename, Bool accumulate )
{
	FILE* file = NULL;
	UInt runs = 0;
	UInt lineWidth = 137;
	UInt widthBlocks = 0;
	UInt widthHits = 7;
	UInt widthTicks = 5;
	UInt widthSeconds = 9;
	UInt widthPercent = 6;

	__try
	{
		// Prepare data.
		ULong endTime = _timer.GetTimeStamp();
		TreeIterator<ProfileBlock> itRoot = _stack.Top();
		_stack.Pop();

		ULong deltaTime = endTime - (*itRoot).stamp;
		(*itRoot).ticks += deltaTime;
		(*itRoot).hits += 1;

		// Correct parent ticks.
		CorrectTicks();

		// Calculate column widths.
		Double tps = _timer.GetTicksPerSecond();
		TreeIterator<ProfileBlock> itProfile = _profiles.Root();
		for ( ; itProfile.IsValid() ; itProfile = _profiles.TraverseDepth(itProfile) )
		{
			widthHits = MaxWidth( widthHits, GetWidth((*itProfile).hits, false) );
			widthTicks = MaxWidth( widthTicks, GetWidth((*itProfile).ticks, true) );
			widthSeconds = MaxWidth( widthSeconds, GetWidth( UInt((Double)(*itProfile).ticks/tps), false) );
		}
		widthBlocks = lineWidth - widthHits - widthTicks - widthSeconds - widthPercent - 4;

		// Read accumulated data.
		if ( accumulate )
		{
			char bufAcc[260];
			strcpy( bufAcc, filename );
			strcat( bufAcc, ".acc" );
			runs = ReadBlockTable( bufAcc, _blocks );
		}

		// Try opening report file.
		if ( file = fopen( filename, "w" ) )
		{
			// Prepare lines.
			UInt posHits = widthBlocks+1;
			UInt posTicks = posHits + widthHits+1;
			UInt posSeconds = posTicks + widthTicks+1;
			UInt posPercent = posSeconds + widthSeconds + 1;
			memset( _line1, '-', lineWidth ); _line1[lineWidth] = '\0';
			memset( _line2, '=', lineWidth ); _line2[lineWidth] = '\0';

			// Start report.
			PrintHeader( file );

			// Output report.
			itProfile = _profiles.Root();

			// 'Profile statistics' section.
			UInt sec = 1;
			PrintSectionHeader( file, sec++, "Profile statistics" );

			// Print column headers.
			PrintString( file, "Block" );
			PrintPad( file, widthBlocks-(UInt)strlen("Block") );
			PrintColumn( file, widthHits, "Hits" );
			PrintColumn( file, widthTicks, "Ticks" );
			PrintColumn( file, widthSeconds, "Seconds" );
			PrintColumn( file, widthPercent+1, " %%" );
			fprintf( file, "\n" );

			// Separate column headers by spaces.
			_line1[posHits-1] = ' ';
			_line1[posTicks-1] = ' ';
			_line1[posSeconds-1] = ' ';
			_line1[posPercent-1] = ' ';
			fprintf( file, _line1 );
			fprintf( file, "\n" );

			TreeIterator<ProfileBlock> itParent;
			itProfile = _profiles.Root();
			for ( ; itProfile.IsValid() ; itProfile = _profiles.TraverseDepth(itProfile) )
			{
				itParent = itProfile; --itParent;

				// Block.
				char block[256];
				strcpy( block, "" );
				UInt depth = _profiles.Depth( itProfile );
				for ( UInt d = 0; d < depth; ++d )
				{
					strcat( block, "| " );
				}
				strcat( block, ((*itProfile).collapsed && !_expand) ? "|+ " : "|- " );
				strcat( block, (*itProfile).name );
				PrintString( file, block, 0, widthBlocks );

				// Get accumulated block.
				ProfileAccum* acc = 0;
				if ( accumulate )
				{
					acc = GetBlock( (*itProfile).name, (*itProfile).id, _blocks );
					if ( acc == 0 )
					{
						_blocks.Add( ProfileAccum((*itProfile).name, (*itProfile).id) );
						acc = _blocks.Last();
					}
				}

				// Hits.
				UInt hits = (*itProfile).hits;
				if ( accumulate )
				{
					hits += acc->hits;
					hits /= runs+1;
					acc->hits += (*itProfile).hits;
				}
				PrintInt( file, hits, posHits+1, posTicks-1 );

				// Ticks.
				ULong ticks = (*itProfile).ticks;
				if ( accumulate )
				{
					ticks += acc->ticks;
					ticks /= runs+1;
					acc->ticks += (*itProfile).ticks;
				}
				PrintInt2( file, ticks, posTicks+1, posSeconds-1 );

				// Seconds.
				PrintFloat( file, Float((Double)ticks/tps), posSeconds+1, posPercent-1 );

				// Percentage.
				Double percent = 100.0f;
				if ( itParent.IsValid() )
					percent *= (((Double)(*itProfile).ticks) / ((Double)(*itParent).ticks));
				if ( (100.0f - percent) < 0.01f )
					PrintInt( file, 100, posPercent+1, posPercent+widthPercent );
				else
					PrintFloat( file, Float(percent), posPercent+1, posPercent+widthPercent );

				fprintf( file, "\n" );
			}

			// End of report.
			memset( _line1, '-', lineWidth );
			PrintFooter( file );

			// Write accumulated data.
			if ( accumulate )
			{
				char bufAcc[260] = {};
				strcpy( bufAcc, filename );
				strcat( bufAcc, ".acc" );
				WriteBlockTable( bufAcc, _blocks, ++runs );
			}
		}
	}
	__finally
	{
		if ( file != NULL )
			fclose( file );
	}
}

void StdProfiler::SaveReportRich( const char* filename, Bool accumulate )
{
	FILE* file = NULL;
	UInt runs = 0;

	__try
	{
		// Prepare data.
		ULong endTime = _timer.GetTimeStamp();
		TreeIterator<ProfileBlock> itRoot = _stack.Top();
		_stack.Pop();

		ULong deltaTime = endTime - (*itRoot).stamp;
		(*itRoot).ticks += deltaTime;
		(*itRoot).hits += 1;

		// Correct parent ticks.
		CorrectTicks();

		// Read accumulated data.
		if ( accumulate )
		{
			char bufAcc[260] = {};
			strcpy( bufAcc, filename );
			strcat( bufAcc, ".acc" );
			runs = ReadBlockTable( bufAcc, _blocks );
		}

		// Try opening report file.
		if ( file = fopen( filename, "w" ) )
		{
			fprintf( file, "<html>\n" );
			fprintf( file, "<head>\n" );
			fprintf( file, "<title>Synkro Profiler Report</title>\n" );
			fprintf( file, "<style>\n" );
			fprintf( file, "tr:nth-child(even) { background-color:#1f1f1f; }\n" );
			fprintf( file, "body { background-color:#000000; color:#ffffff; font-family:Courier; font-size:1em; }\n" );
			fprintf( file, "::selection { background: #5e011f; color:#ffffff; }\n" );
			fprintf( file, ".centered { text-align:center; }\n" );
			fprintf( file, ".num { color:#51a635; text-align:right; padding-left:8px; }\n" );
			fprintf( file, "</style>\n" );
			fprintf( file, "</head>\n" );
			fprintf( file, "<body>\n" );
			fprintf( file, "<hr><div class='centered'>\n" );
			fprintf( file, "Synkro Profiler Report<br><br>\n" );
			time_t t; time( &t );
			struct tm* newtime; newtime = localtime( &t );
			fprintf( file, "%s", asctime(newtime) );
			fprintf( file, "</div><hr>\n" );
			fprintf( file, "<table border='0'>\n" );

			//------------------------------------------------------------------

			// Output report.
			Double tps = _timer.GetTicksPerSecond();
			TreeIterator<ProfileBlock> itProfile = _profiles.Root();

			// Print column headers.
			fprintf( file, "<tr><td>Block</td>" );
			fprintf( file, "<td class='num'>Hits</td>" );
			fprintf( file, "<td class='num'>Ticks</td>" );
			fprintf( file, "<td class='num'>Seconds</td>" );
			fprintf( file, "<td class='num'>%%</td></tr>\n" );

			TreeIterator<ProfileBlock> itParent;
			itProfile = _profiles.Root();
			for ( ; itProfile.IsValid() ; itProfile = _profiles.TraverseDepth(itProfile) )
			{
				itParent = itProfile; --itParent;

				// Block.
				char block[256] = {};
				strcpy( block, "" );
				UInt depth = _profiles.Depth( itProfile );
				for ( UInt d = 0; d < depth; ++d )
				{
					strcat( block, "| " );
				}
				strcat( block, ((*itProfile).collapsed && !_expand) ? "|+ " : "|- " );
				strcat( block, (*itProfile).name );
				fprintf( file, "<tr><td>" );
				PrintString( file, block );
				fprintf( file, "</td>" );

				// Get accumulated block.
				ProfileAccum* acc = 0;
				if ( accumulate )
				{
					acc = GetBlock( (*itProfile).name, (*itProfile).id, _blocks );
					if ( acc == 0 )
					{
						_blocks.Add( ProfileAccum((*itProfile).name, (*itProfile).id) );
						acc = _blocks.Last();
					}
				}

				// Hits.
				UInt hits = (*itProfile).hits;
				if ( accumulate )
				{
					hits += acc->hits;
					hits /= runs+1;
					acc->hits += (*itProfile).hits;
				}
				fprintf( file, "<td class='num'>" );
				fprintf( file, "%d", hits );
				fprintf( file, "</td>" );

				// Ticks.
				ULong ticks = (*itProfile).ticks;
				if ( accumulate )
				{
					ticks += acc->ticks;
					ticks /= runs+1;
					acc->ticks += (*itProfile).ticks;
				}
				fprintf( file, "<td class='num'>" );
				PrintInt3( file, ticks );
				fprintf( file, "</td>" );

				// Seconds.
				fprintf( file, "<td class='num'>" );
				fprintf( file, "%0.3f", Float((Double)ticks/tps) );
				fprintf( file, "</td>" );

				// Percentage.
				Double percent = 100.0f;
				if ( itParent.IsValid() )
					percent *= (((Double)(*itProfile).ticks) / ((Double)(*itParent).ticks));
				if ( (100.0f-percent) < 0.01f )
				{
					fprintf( file, "<td class='num'>" );
					fprintf( file, "%d", 100 );
					fprintf( file, "</td>" );
				}
				else
				{
					fprintf( file, "<td class='num'>" );
					fprintf( file, "%0.3f", percent );
					fprintf( file, "</td>" );
				}
				fprintf( file, "</tr>\n" );
			}
			fprintf( file, "</table>\n" );

			// End of report.
			fprintf( file, "<hr><div class='centered'>End of report</div><hr>\n" );
			fprintf( file, "</body>\n" );
			fprintf( file, "</html>" );

			// Write accumulated data.
			if ( accumulate )
			{
				char bufAcc[260] = {};
				strcpy( bufAcc, filename );
				strcat( bufAcc, ".acc" );
				WriteBlockTable( bufAcc, _blocks, ++runs );
			}
		}
	}
	__finally
	{
		if ( file != NULL )
			fclose( file );
	}
}


} // prf


} // synkro
