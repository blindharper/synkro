#include "config.h"
#include "Test.h"
#include <lang/Allocator.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro;

//------------------------------------------------------------------------------

class TstAlloc
{
public:
	TstAlloc( int id = 0 ) :
		_id( id )
	{
	}

	int id() const
	{
		return _id;
	}

private:
	int _id;
};

//------------------------------------------------------------------------------

typedef Allocator<Double> DoubleAllocator;
typedef Allocator<TstAlloc> TstAllocator;

class TestAllocator :
	public Test
{
public:
	TestAllocator() : Test( "TestAllocator", 100 ) {}

	void Run()
	{
		DoubleAllocator da( __FILE__ );

		Double* pd = da.Allocate( 7 );
		pd[0] = 3.12;
		Assert( pd[0] == 3.12 );
		da.Deallocate( pd, 7 );

		TstAllocator ta( __FILE__ );
		TstAlloc* pt = ta.Allocate( 100 );
		Assert( pt[55].id() == 0 );

		TstAlloc tst77( 77 );
		ta.Construct( &pt[55], tst77 );
		Assert( pt[55].id() == 77 );
		ta.Deallocate( pt, 100 );
	}

} _tst;
