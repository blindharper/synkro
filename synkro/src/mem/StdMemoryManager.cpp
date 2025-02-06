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
// Purpose: Standard memory manager implementation.
//==============================================================================
#include "config.h"
#include "StdMemoryManager.h"
#include <internal/Sort.h>
#include <internal/BinarySemaphore.h>


//------------------------------------------------------------------------------

using namespace synkro;

//------------------------------------------------------------------------------


// Memory block descriptor.
struct Block
{
	struct Group* group;				// Parent group.
	Block* next;						// Pointer to next block in the list.
	Block* prev;						// Pointer to previous block in the list.
	UInt size;							// Block size, in bytes.
};

// Global variables.
static BinarySemaphore _semaphore( true );	// Binary semaphore for synchronization.
static Group* _groups = 0;					// Global memory group list.
static UInt _bytesUsed = 0;					// Current number of bytes used by the application.
static UInt _blocksUsed = 0;				// Current number of blocks used by the application.
static UInt _bytesMax = 0;					// Maximum number of bytes used by the application.
static UInt _blocksMax = 0;					// Maximum number of blocks used by the application.

// Constants.
static char _line1[200] = {};
static char _line2[200] = {};
static const char* _line3 = "---------- ---------- -----------------------------------------------------------\n";
const UInt BLOCK_HEADER_SIZE = sizeof( Block );
const UInt BLOCK_SIGNATURE = 0xBAADC0DE;	// Used to search for damaged blocks.
const UInt MAX_GROUP_NAME = 40;

// Memory group.
struct Group
{
	Group* next;						// Next group in the list.
	Group* prev;						// Previous group in the list.
	Block* blocks;						// List of memory blocks.
	char name[MAX_GROUP_NAME+1];		// Group name.
	Long hash;							// Group name hash code.
	UInt refs;							// Group reference count.
	UInt bytesUsed;						// Number of bytes used by the group.
	UInt blocksUsed;					// Number of blocks used by the group.
	UInt bytesMax;						// Maximum number of bytes used by the group.
	UInt blocksMax;						// Maximum number of blocks used by the group.
	UInt bytesTotal;					// All-time number of bytes allocated to the group.
	UInt blocksTotal;					// All-time number of blocks allocated to the group.
	static UInt Count;					// Total group count.
};

UInt Group::Count = 0;

// Memory group data used to print report.
struct GroupData
{
	Group* group;
	UInt bytesTotal;

	GroupData( Group* _group ) :
		group( _group )
	{
		bytesTotal = mem::StdMemoryManager::GroupBytesTotal( group );
	}

	Bool operator<( const GroupData& other )
	{
		return bytesTotal > other.bytesTotal;
	}
};

// Damaged block data used to print report.
struct DamagedBlock
{
	void* address;
	UInt size;
	const char* group;
	static UInt Count;
	static UInt Capacity;
	static DamagedBlock* Blocks;

	static void Add( void* _address, UInt _size, const char* _group )
	{
		if ( Count < Capacity )
		{
			Blocks[Count].address = _address;
			Blocks[Count].size = _size;
			Blocks[Count].group = _group;
			++Count;
		}
	}

	Bool operator<( const DamagedBlock& other )
	{
		return size > other.size;
	}
};

UInt DamagedBlock::Count = 0;
UInt DamagedBlock::Capacity = 128;
DamagedBlock* DamagedBlock::Blocks = (DamagedBlock*)malloc( sizeof(DamagedBlock)*DamagedBlock::Capacity );

// Increments group reference count.
static void ref( Group* group )
{
	assert( group );
	assert( group->refs >= 0 );
	group->refs += 1;
}

// Decrements group reference count and frees it if no references left.
static void unref( Group* group )
{
	assert( group );
	assert( group->refs >= 0 );

	group->refs -= 1;

	// Do not actually free the group, since it stores some useful stats.
	return;

	if ( group->refs == 0 )
	{
		assert( !group->blocks );
		
		if ( group->next )
			group->next->prev = group->prev;
		if ( group->prev )
			group->prev->next = group->next;
		if ( group == _groups )
			_groups = (group->next ? group->next : group->prev);

		free( group );
	}
}

// Computes hash code from the string.
static Long strhash( const char* str )
{
	Long code = 0;
	while ( *str )
	{
		code *= 31;
		code += *str++;
	}
	return code;
}

// Calculates formatted number width.
static UInt GetWidth( UInt num, Bool group )
{
	char buf[32];
	sprintf( buf, "%d", num );
	UInt width = CastUInt( strlen(buf) );
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

// Prints memory report header.
static void PrintHeader( FILE* file )
{
	time_t t; time( &t );
	struct tm* newtime; newtime = localtime( &t );
	char buf[32]; sprintf( buf, "%s", asctime(newtime) );
	UInt padWidth = (CastUInt(strlen(_line1)) - CastUInt(strlen(buf)))/2;
	char pad[100]; memset( pad, ' ', padWidth ); pad[padWidth] = '\0';

	fprintf( file, _line1 );
	fprintf( file, "\n" );
	fprintf( file, pad );
	fprintf( file, buf );
}

// Prints memory report section's header.
static void PrintSectionHeader( FILE* file, UInt num, const char* name )
{
	fprintf( file, "\n" );
	fprintf( file, _line2 );
	fprintf( file, "\n%d. %s\n", num, name );
	fprintf( file, _line2 );
	fprintf( file, "\n" );
}

// Prints memory report footer.
static void PrintFooter( FILE* file )
{
	char buf[] = "End of report.";
	UInt padWidth = (CastUInt(strlen(_line1)) - CastUInt(strlen(buf)))/2;
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

// Prints a whole number in the given position, using comma to group digits.
static void PrintInt0( FILE* file, UInt num, const char* fmt )
{
	static char tmp[32] = {};
	sprintf( tmp, "%d", num );

	static char txt[32] = {};
	memset( txt, 0, 32 );

	static char str[32] = {};
	memset( str, 0, 32 );
	
	int cnt = 0;
	int len = (int)strlen( tmp );
	for ( int i = len-1; i >= 0; --i )
	{
		strcpy( txt, str );
		strncpy( str, &tmp[i], 1 );
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

// Prints a whole number in the given position, using comma to group digits.
static void PrintInt2( FILE* file, UInt num, UInt pos, UInt max )
{
	static char fmt[8] = {};
	sprintf( fmt, "%%%ds", max - pos + 2 );
	PrintInt0( file, num, fmt );
}

// Prints a whole number in the given position, using comma to group digits.
static void PrintInt3( FILE* file, UInt num )
{
	PrintInt0( file, num, nullptr );
}

// Prints a hexadecimal representation of a whole number in the given position.
static void PrintHex( FILE* file, UInt num, UInt pos, UInt max )
{
	static char fmt[8] = {};
	sprintf( fmt, "%%#0%dx", max - pos );
	fprintf( file, fmt, num );
}

// Prints a floating-point value in the given position.
static void PrintFloat( FILE* file, Float num, UInt pos, UInt max )
{
	static char fmt[8] = {};
	sprintf( fmt, "%%%d.3f", max - pos + 2 );
	fprintf( file, fmt, num );
}

// Prints padding.
static void PrintPad( FILE* file, UInt width )
{
	static char pad[MAX_GROUP_NAME] = {};
	memset( pad, ' ', MAX_GROUP_NAME ); pad[width] = '\0';
	fprintf( file, pad );
}

// Prints column.
static void PrintColumn( FILE* file, UInt width, const char* str )
{
	PrintPad( file, width-CastUInt(strlen(str))+1 );
	PrintString( file, str );
}

//------------------------------------------------------------------------------

namespace synkro
{


namespace mem
{


void* StdMemoryManager::Allocate( void* group_, UInt size )
{
	Group* group = (Group*)group_;
	Block*	item = 0;
	char*	memory = 0;
	char*	block = 0;

	assert( size >= 0 );
	assert( sizeof(Block) <= BLOCK_HEADER_SIZE );
SEMAPHORE_WAIT(_semaphore)

	// Update global stats.
	_bytesUsed += size;
	_blocksUsed += 1;
	if ( _bytesUsed > _bytesMax ) { _bytesMax = _bytesUsed; }
	if ( _blocksUsed > _blocksMax ) { _blocksMax = _blocksUsed; }

	// Update group.
	group->bytesUsed += size;
	group->blocksUsed += 1;
	group->bytesTotal += size;
	group->blocksTotal += 1;
	if ( group->bytesUsed > group->bytesMax ) { group->bytesMax = group->bytesUsed; }
	if ( group->blocksUsed > group->blocksMax ) { group->blocksMax = group->blocksUsed; }
	ref( group );

	// Allocate block.
	memory = (char*)malloc( size + sizeof(Long) + BLOCK_HEADER_SIZE );
	item = (Block*)( memory );
	memset( item, 0, BLOCK_HEADER_SIZE );
	block = memory + BLOCK_HEADER_SIZE;
	*(Long*)(block + size) = BLOCK_SIGNATURE; // Check for damaged block.

	// Save group name.
	item->group = group;

	// Link block.
	item->next = group->blocks;
	group->blocks = item;
	if ( item->next )
		item->next->prev = item;
	item->size = size;

SEMAPHORE_SIGNAL(_semaphore)
	assert( item->size == size );
	return block;
}

void StdMemoryManager::Free( void* ptr )
{
	if ( !ptr )
		return;

	Block* block = (Block*)( (char*)ptr - BLOCK_HEADER_SIZE );

	Long n = block->size;
	Group*	group = block->group;
	char*	memory = (char*)ptr - BLOCK_HEADER_SIZE;
	Block*	item = (Block*)( memory );

	assert( item->group == group );
	assert( n == item->size );
SEMAPHORE_WAIT(_semaphore)

	// Check for damaged block.
	if ( *(Long*)((char*)ptr+item->size) != BLOCK_SIGNATURE )
		DamagedBlock::Add( ptr, n, group->name );

	// Unlink block.
	if ( item->next )
		item->next->prev = item->prev;
	if ( item->prev )
		item->prev->next = item->next;
	if ( item == group->blocks )
		group->blocks = (item->next ? item->next : item->prev);

	// Update global stats.
	_bytesUsed -= item->size;
	_blocksUsed -= 1;

	// Update group.
	group->bytesUsed -= item->size;
	group->blocksUsed -= 1;
	unref( group );

	// Free block.
	free( memory );

SEMAPHORE_SIGNAL(_semaphore)
}

UInt StdMemoryManager::BytesUsed()
{
	return _bytesUsed;
}

UInt StdMemoryManager::BlocksUsed()
{
	return _blocksUsed;
}

UInt StdMemoryManager::BytesMaximum()
{
	return _bytesMax;
}

UInt StdMemoryManager::BlocksMaximum()
{
	return _blocksMax;
}

UInt StdMemoryManager::BytesTotal()
{
	UInt	count = 0;
	Group*	group = NULL;

SEMAPHORE_WAIT(_semaphore)
	for ( group = _groups ; group ; group = group->next )
	{
		count += group->bytesTotal;
	}
SEMAPHORE_SIGNAL(_semaphore)
	return count;
}

UInt StdMemoryManager::BlocksTotal()
{
	UInt	count = 0;
	Group*	group = NULL;

SEMAPHORE_WAIT(_semaphore)
	for ( group = _groups ; group ; group = group->next )
	{
		count += group->blocksTotal;
	}
SEMAPHORE_SIGNAL(_semaphore)
	return count;
}

void* StdMemoryManager::GroupCreate( const char* name )
{
	Group* group = 0;
	Long hash;

	if ( strlen(name) >= MAX_GROUP_NAME )
		name = name + strlen(name) - MAX_GROUP_NAME + 1;

	assert(	strlen(name) < MAX_GROUP_NAME );

SEMAPHORE_WAIT(_semaphore)

	// Find existing group.
	hash = strhash(name);	
	for ( group = _groups; group ; group = group->next )
	{
		if ( (group->hash == hash) && !strcmp(group->name, name) )
			break;
	}

	// Create new group if not found.
	if ( !group )
	{
		group = (Group*)malloc( sizeof(Group) );
		memset( group, 0, sizeof(Group) );

		strncpy( group->name, name, MAX_GROUP_NAME );
		group->name[MAX_GROUP_NAME] = 0;
		group->hash = hash;
		group->next = _groups;
		_groups = group;
		if ( group->next )
		{
			group->next->prev = group;
		}
		Group::Count++;
	}

	// Reference group.
	ref( group );

SEMAPHORE_SIGNAL(_semaphore)

	return group;
}

void StdMemoryManager::GroupRelease( void* group_ )
{
	Group* group = (Group*)group_;

	if ( !group )
		return;

SEMAPHORE_WAIT(_semaphore)
	unref( group );
SEMAPHORE_SIGNAL(_semaphore)
}

void* StdMemoryManager::GroupFirst()
{
	Group* first = 0;

SEMAPHORE_WAIT(_semaphore)
	first = _groups;
	if ( first )
		ref( first );
SEMAPHORE_SIGNAL(_semaphore)

	return first;
}

void* StdMemoryManager::GroupNext( void* group_ )
{
	Group* group = (Group*)group_;
	Group* next = 0;

SEMAPHORE_WAIT(_semaphore)
	next = group->next;
	if ( next )
		ref( next );
SEMAPHORE_SIGNAL(_semaphore)

	return next;
}

const char* StdMemoryManager::GroupName( void* group_ )
{
	Group* group = (Group*)group_;
	return group->name;
}

UInt StdMemoryManager::GroupBytesUsed( void* group_ )
{
	Group* group = (Group*)group_;
	return group->bytesUsed;
}

UInt StdMemoryManager::GroupBlocksUsed( void* group_ )
{
	Group* group = (Group*)group_;
	return group->blocksUsed;
}

UInt StdMemoryManager::GroupBytesMaximum( void* group_ )
{
	Group* group = (Group*)group_;
	return group->bytesMax;
}

UInt StdMemoryManager::GroupBlocksMaximum( void* group_ )
{
	Group* group = (Group*)group_;
	return group->blocksMax;
}

UInt StdMemoryManager::GroupBytesTotal( void* group_ )
{
	Group* group = (Group*)group_;
	return group->bytesTotal;
}

UInt StdMemoryManager::GroupBlocksTotal( void* group_ )
{
	Group* group = (Group*)group_;
	return group->blocksTotal;
}

void StdMemoryManager::SaveReport( const char* filename, Bool leaksOnly, Bool plain )
{
	if ( !filename || (strlen(filename) == 0) )
		return;

	if ( plain )
		SaveReportPlain( filename, leaksOnly );
	else
		SaveReportRich( filename, leaksOnly );
}

void StdMemoryManager::SaveReportPlain( const char* filename, Bool leaksOnly )
{
	FILE* file = NULL;
	GroupData* groups = 0;

	__try
	{
		// Prepare data.
		UInt groupCount = 0; UInt width = 0;
		groups = (GroupData*)malloc( sizeof(GroupData)*Group::Count );
		Group* group = static_cast<Group*>( GroupFirst() );
		for ( ; group ; group = static_cast<Group*>( GroupNext(group) ) )
		{
			if ( GroupBytesTotal(group) != 0 )
				groups[groupCount++] = GroupData( group );

			// Release group data.
			GroupRelease( group );
		}
		Sort( groups, groupCount );

		if ( DamagedBlock::Count > 0 )
		{
			Sort( DamagedBlock::Blocks, DamagedBlock::Count );
		}

		const UInt bytesTotal = BytesTotal();
		const UInt blocksTotal = BlocksTotal();

		// Try opening report file.
		if ( file = fopen( filename, "w" ) )
		{
			// Prepare lines.
			const UInt widthGroup = MAX_GROUP_NAME-1;
			const UInt widthUsedBytes = MaxWidth( 5, GetWidth(BytesUsed(), true) );
			const UInt widthUsedBlocks = MaxWidth( 6, GetWidth(BlocksUsed(), false) );
			const UInt widthMaxBytes = MaxWidth( 7, GetWidth(BytesMaximum(), true) );
			const UInt widthMaxBlocks = MaxWidth( 7, GetWidth(BlocksMaximum(), false) );
			const UInt widthTotalBytes = MaxWidth( 5, GetWidth(bytesTotal, true) );
			const UInt widthTotalBlocks = MaxWidth( 6, GetWidth(blocksTotal, false) );
			const UInt widthPercent = 6;

			UInt posUsedBytes = widthGroup + 1;
			UInt posUsedBlocks = posUsedBytes + widthUsedBytes + 1;
			UInt posMaxBytes = posUsedBlocks + widthUsedBlocks + 1;
			UInt posMaxBlocks = posMaxBytes + widthMaxBytes + 1;
			UInt posTotalBytes = posMaxBlocks + widthMaxBlocks + 1;
			UInt posTotalBlocks = posTotalBytes + widthTotalBytes + 1;
			UInt posPercent = posTotalBlocks + widthTotalBlocks + 1;
			UInt lineWidth = posPercent + widthPercent;
			memset( _line1, '-', lineWidth ); _line1[lineWidth] = '\0';
			memset( _line2, '=', lineWidth ); _line2[lineWidth] = '\0';

			// Start report.
			PrintHeader( file );

			//------------------------------------------------------------------

			// 'Memory usage' section.
			UInt sec = 1;
			if ( groupCount > 0 )
			{
				PrintSectionHeader( file, sec++, "Memory usage" );

				// Print column headers.
				PrintPad( file, widthGroup );
				PrintColumn( file, widthUsedBytes, "Used" );
				PrintColumn( file, widthUsedBlocks, "Used" );
				PrintColumn( file, widthMaxBytes, "Maximum" );
				PrintColumn( file, widthMaxBlocks, "Maximum" );
				PrintColumn( file, widthTotalBytes, "Total" );
				PrintColumn( file, widthTotalBlocks, "Total" );
				fprintf( file, "\n" );

				PrintString( file, "Group" );
				PrintPad( file, widthGroup-CastUInt(strlen("Group")) );
				PrintColumn( file, widthUsedBytes, "Bytes" );
				PrintColumn( file, widthUsedBlocks, "Blocks" );
				PrintColumn( file, widthMaxBytes, "Bytes" );
				PrintColumn( file, widthMaxBlocks, "Blocks" );
				PrintColumn( file, widthTotalBytes, "Bytes" );
				PrintColumn( file, widthTotalBlocks, "Blocks" );
				PrintColumn( file, widthPercent+1, " %%" );
				fprintf( file, "\n" );

				// Separate column headers by spaces.
				_line1[posUsedBytes-1] = ' ';
				_line1[posUsedBlocks-1] = ' ';
				_line1[posMaxBytes-1] = ' ';
				_line1[posMaxBlocks-1] = ' ';
				_line1[posTotalBytes-1] = ' ';
				_line1[posTotalBlocks-1] = ' ';
				_line1[posPercent-1] = ' ';
				fprintf( file, _line1 );
				fprintf( file, "\n" );

				// Print groups.
				Bool printLine3 = false;
				for ( UInt i = 0; i < groupCount; ++i )
				{
					if ( !leaksOnly || (GroupBytesUsed(groups[i].group) > 0) )
					{
						printLine3 = true;
						PrintString( file, GroupName(groups[i].group), 0, widthGroup );
						PrintInt2( file, GroupBytesUsed(groups[i].group), posUsedBytes+1, posUsedBlocks-1 );
						PrintInt( file, GroupBlocksUsed(groups[i].group), posUsedBlocks+1, posMaxBytes-1 );
						PrintInt2( file, GroupBytesMaximum(groups[i].group), posMaxBytes+1, posMaxBlocks-1 );
						PrintInt( file, GroupBlocksMaximum(groups[i].group), posMaxBlocks+1, posTotalBytes-1 );
						PrintInt2( file, GroupBytesTotal(groups[i].group), posTotalBytes+1, posTotalBlocks-1 );
						PrintInt( file, GroupBlocksTotal(groups[i].group), posTotalBlocks+1, posPercent-1 );
						Float percent = Float(100.0*CastDouble(GroupBytesTotal(groups[i].group))/CastDouble(bytesTotal));
						if ( (100.0f - percent) < 0.01f )
							PrintInt( file, 100, posPercent+1, posPercent+widthPercent );
						else
							PrintFloat( file, percent, posPercent+1, posPercent+widthPercent );
						fprintf( file, "\n" );
					}
				}

				// Print memory usage totals.
				if ( printLine3 )
				{
					fprintf( file, _line1 );
					fprintf( file, "\n" );
				}
				PrintString( file, "Total:", 0, widthGroup );
				PrintInt2( file, BytesUsed(), posUsedBytes+1, posUsedBlocks-1 );
				PrintInt( file, BlocksUsed(), posUsedBlocks+1, posMaxBytes-1 );
				PrintInt2( file, BytesMaximum(), posMaxBytes+1, posMaxBlocks-1 );
				PrintInt( file, BlocksMaximum(), posMaxBlocks+1, posTotalBytes-1 );
				PrintInt2( file, bytesTotal, posTotalBytes+1, posTotalBlocks-1 );
				PrintInt( file, blocksTotal, posTotalBlocks+1, posPercent-1 );
				PrintFloat( file, 99.999f, posPercent+1, posPercent+widthPercent );
			}

			//------------------------------------------------------------------

			// 'Damaged blocks' section.
			if ( DamagedBlock::Count > 0 )
			{
				PrintSectionHeader( file, sec++, "Damaged blocks" );
				fprintf( file, "   Address       Size Group\n" );
				fprintf( file, _line3 );

				// Print damaged blocks.
				for ( UInt i = 0; i < DamagedBlock::Count; ++i )
				{
					PrintHex( file, (int)(Pointer)(DamagedBlock::Blocks[i].address), 0, 10 );
					PrintInt( file, DamagedBlock::Blocks[i].size, 12, 21 );
					fprintf( file, " " );
					PrintString( file, DamagedBlock::Blocks[i].group, 23, 81 );
					fprintf( file, "\n" );
				}
			}

			//------------------------------------------------------------------

			// End of report.
			memset( _line1, '-', lineWidth );
			PrintFooter( file );
		}
	}
	__finally
	{
		if ( groups != 0 )
			free( groups );

		if ( file != NULL )
			fclose( file );
	}
}

void StdMemoryManager::SaveReportRich( const char* filename, Bool leaksOnly )
{
	FILE* file = NULL;
	GroupData* groups = 0;

	__try
	{
		// Prepare data.
		UInt groupCount = 0; UInt width = 0;
		groups = (GroupData*)malloc( sizeof(GroupData)*Group::Count );
		Group* group = static_cast<Group*>( GroupFirst() );
		for ( ; group ; group = static_cast<Group*>( GroupNext(group) ) )
		{
			if ( GroupBytesTotal(group) != 0 )
				groups[groupCount++] = GroupData( group );

			// Release group data.
			GroupRelease( group );
		}
		Sort( groups, groupCount );

		if ( DamagedBlock::Count > 0 )
		{
			Sort( DamagedBlock::Blocks, DamagedBlock::Count );
		}

		const UInt bytesTotal = BytesTotal();
		const UInt blocksTotal = BlocksTotal();

		// Try opening report file.
		if ( file = fopen( filename, "w" ) )
		{
			fprintf( file, "<html>\n" );
			fprintf( file, "<head>\n" );
			fprintf( file, "<title>Synkro Memory Report</title>\n" );
			fprintf( file, "<style>\n" );
			fprintf( file, "tr:nth-child(even) { background-color:#1f1f1f; }\n" );
			fprintf( file, "body { background-color:#000000; color:#ffffff; font-family:Courier; font-size:1em; }\n" );
			fprintf( file, "::selection { background: #5e011f; color:#ffffff; }\n" );
			fprintf( file, ".centered { text-align:center; }\n" );
			fprintf( file, ".num { color:#51a635; text-align:right; padding-left:8px; }\n" );
			fprintf( file, ".leak { color:#ff0000; }\n" );
			fprintf( file, "</style>\n" );
			fprintf( file, "</head>\n" );
			fprintf( file, "<body>\n" );
			fprintf( file, "<hr><div class='centered'>\n" );
			fprintf( file, "Synkro Memory Report<br><br>\n" );
			time_t t; time( &t );
			struct tm* newtime; newtime = localtime( &t );
			fprintf( file, "%s", asctime(newtime) );
			fprintf( file, "</div><hr>\n" );
			fprintf( file, "<table border='0'>\n" );

			//------------------------------------------------------------------

			// 'Memory usage' section.
			if ( groupCount > 0 )
			{
				// Print column headers.
				fprintf( file, "<tr><td>Group</td>" );
				fprintf( file, "<td class='num'>Used Bytes</td>" );
				fprintf( file, "<td class='num'>Used Blocks</td>" );
				fprintf( file, "<td class='num'>Maximum Bytes</td>" );
				fprintf( file, "<td class='num'>Maximum Blocks</td>" );
				fprintf( file, "<td class='num'>Total Bytes</td>" );
				fprintf( file, "<td class='num'>Total Blocks</td>" );
				fprintf( file, "<td class='num'>%%</td></tr>\n" );

				// Print groups.
				for ( UInt i = 0; i < groupCount; ++i )
				{
					if ( !leaksOnly || (GroupBytesUsed(groups[i].group) > 0) )
					{
						UInt bytesUsed = GroupBytesUsed(groups[i].group);
						fprintf( file, (bytesUsed > 0) ? "<tr><td class='leak'>" : "<tr><td>" );
						fprintf( file, GroupName(groups[i].group) );
						fprintf( file, "</td>" );

						fprintf( file, (bytesUsed > 0) ? "<td class='num leak'>" : "<td class='num'>" );
						PrintInt3( file, bytesUsed );
						fprintf( file, "</td>" );

						fprintf( file, (bytesUsed > 0) ? "<td class='num leak'>" : "<td class='num'>" );
						PrintInt3( file, GroupBlocksUsed(groups[i].group) );
						fprintf( file, "</td>" );

						fprintf( file, (bytesUsed > 0) ? "<td class='num leak'>" : "<td class='num'>" );
						PrintInt3( file, GroupBytesMaximum(groups[i].group) );
						fprintf( file, "</td>" );

						fprintf( file, (bytesUsed > 0) ? "<td class='num leak'>" : "<td class='num'>" );
						PrintInt3( file, GroupBlocksMaximum(groups[i].group) );
						fprintf( file, "</td>" );

						fprintf( file, (bytesUsed > 0) ? "<td class='num leak'>" : "<td class='num'>" );
						PrintInt3( file, GroupBytesTotal(groups[i].group) );
						fprintf( file, "</td>" );

						fprintf( file, (bytesUsed > 0) ? "<td class='num leak'>" : "<td class='num'>" );
						PrintInt3( file, GroupBlocksTotal(groups[i].group) );
						fprintf( file, "</td>" );

						const Float percent = CastFloat( 100.0*CastDouble(GroupBytesTotal(groups[i].group))/CastDouble(bytesTotal) );
						if ( (100.0f-percent) < 0.01f )
						{
							fprintf( file, (bytesUsed > 0) ? "<td class='num leak'>" : "<td class='num'>" );
							fprintf( file, "%d", 100 );
							fprintf( file, "</td>" );
						}
						else
						{
							fprintf( file, (bytesUsed > 0) ? "<td class='num leak'>" : "<td class='num'>" );
							fprintf( file, "%0.3f", percent );
							fprintf( file, "</td>" );
						}
						fprintf( file, "</tr>\n" );
					}
				}

				// Print memory usage totals.
				fprintf( file, "<tr><td>" );
				fprintf( file, "Total" );
				fprintf( file, "</td>" );

				fprintf( file, "<td class='num'>" );
				PrintInt3( file, BytesUsed() );
				fprintf( file, "</td>" );

				fprintf( file, "<td class='num'>" );
				PrintInt3( file, BlocksUsed() );
				fprintf( file, "</td>" );

				fprintf( file, "<td class='num'>" );
				PrintInt3( file, BytesMaximum() );
				fprintf( file, "</td>" );

				fprintf( file, "<td class='num'>" );
				PrintInt3( file, BlocksMaximum() );
				fprintf( file, "</td>" );

				fprintf( file, "<td class='num'>" );
				PrintInt3( file, bytesTotal );
				fprintf( file, "</td>" );

				fprintf( file, "<td class='num'>" );
				PrintInt3( file, blocksTotal );
				fprintf( file, "</td>" );

				fprintf( file, "<td class='num'>" );
				fprintf( file, "%0.3f", 99.999f );
				fprintf( file, "</td>" );
			}

			fprintf( file, "</table>\n" );

			//------------------------------------------------------------------

			// 'Damaged blocks' section.
			if ( DamagedBlock::Count > 0 )
			{
				fprintf( file, "Damaged blocks detected<br>\n" );
			}

			//------------------------------------------------------------------

			fprintf( file, "<hr><div class='centered'>End of report</div><hr>\n" );
			fprintf( file, "</body>\n" );
			fprintf( file, "</html>" );
		}
	}
	__finally
	{
		if ( groups != 0 )
			free( groups );

		if ( file != NULL )
			fclose( file );
	}
}


} // mem


} // synkro
