#include "config.h"
#include "Test.h"
#include <lang/Map.h>
#include <lang/String.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro;

//------------------------------------------------------------------------------

class TestMap :
	public Test
{
public:
	TestMap() : Test( "TestMap", 303 ) {}

	void Run()
	{
		typedef Allocator< MapPair<Float, Long> > PairAlloc;
		typedef Map<Float, Long> IntTable;

		// Creation.
		PairAlloc pairAlloc( __FILE__ );
		IntTable table( pairAlloc );
		Assert( table.IsEmpty() );

		// Insertion.
		table[12.5f] = 26;
		table[0.33f] = 25;

		Assert( !table.IsEmpty() );
		Assert( table.Size() == 2 );

		// Writing.
		table[12.5f] = 17;
		Assert( table[12.5f] == 17 );

		for ( Long i = 0; i < 512; ++i )
		{
			table[(Float)i/11] = i*11;
		}

		// Removal.
		table.Remove( 12.5f );
		Assert( !table.ContainsKey(12.5f) );

		table.Clear();
		Assert( !table.ContainsKey(0.33f) );
		Assert( table.Size() == 0 );

		// Case-insensitive maps.
		typedef Allocator< MapPair<String, Long> > CIAlloc;
		typedef MapCI<String, Long> CITable;

		CIAlloc allCI( __FILE__ );
		CITable tblCI( allCI );
		String key1( L"one" );
		String key2( L"One" );
		String key3( L"ONE" );
		tblCI[key1] = 1;
		Assert( tblCI.ContainsKey(key1) );
		Assert( tblCI.ContainsKey(key2) );
		Assert( tblCI.ContainsKey(key3) );
		Assert( tblCI[key1] == 1 );
		Assert( tblCI[key2] == 1 );
		Assert( tblCI[key3] == 1 );
	}

	static Long Hash( const Char* str )
	{
		Long hash = 0;
		if ( str )
		{
			while ( *str )
			{
				hash *= 31;
				hash += *str++;
			}
		}
		return hash;
	}

} _tst;
