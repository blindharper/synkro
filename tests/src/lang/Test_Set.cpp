#include "config.h"
#include "Test.h"
#include <lang/Set.h>
#include <lang/String.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro;

//------------------------------------------------------------------------------

class TestSet :
	public Test
{
public:
	TestSet() : Test( "TestSet", 307 ) {}

	void Run()
	{
		typedef Allocator< SetItem<Float> > ItemAlloc;
		typedef Set<Float> IntSet;

		// Creation.
		ItemAlloc itemAlloc( __FILE__, __LINE__ );
		IntSet set( itemAlloc );
		Assert( set.IsEmpty() );

		// Insertion.
		set.Put( 12.5f );
		set.Put( 0.33f );

		Assert( !set.IsEmpty() );
		Assert( set.Size() == 2 );

		// Writing.
		set.Put( 12.5f );
		Assert( set.Contains(12.5f) );

		for ( UInt i = 0; i < 512; ++i )
		{
			set.Put( (Float)i/(Float)11 );
		}

		// Removal.
		set.Remove( 12.5f );
		Assert( !set.Contains(12.5f) );

		set.Clear();
		Assert( !set.Contains(0.33f) );
		Assert( set.Size() == 0 );

		// Case-insensitive map.
		typedef Allocator< SetItem<String> > CIAlloc;
		typedef SetCI<String> CISet;

		CIAlloc allCI( __FILE__, __LINE__ );
		CISet setCI( allCI );
		String key1( L"one" );
		String key2( L"One" );
		String key3( L"ONE" );
		setCI.Put( key1 );
		Assert( setCI.Contains(key1) );
		Assert( setCI.Contains(key2) );
		Assert( setCI.Contains(key3) );
	}

} _tst;
