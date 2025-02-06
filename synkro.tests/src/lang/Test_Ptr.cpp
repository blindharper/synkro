#include "config.h"
#include "Test.h"
#include <lang/Ptr.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro;

//------------------------------------------------------------------------------

class TstPtr
{
public:
	TstPtr( int d ) :
		_id( d ),
		_refs( 0 )
	{
		++s_data;
	}

	~TstPtr()
	{
		--s_data;
	}

	Long id() const
	{
		return _id;
	}

	Long AddRef()
	{
		return ++_refs;
	}

	Long Release()
	{
		if ( --_refs == 0 )
		{
			delete this;
			return 0;
		}
		return _refs;
	}
	
	// Count of the created TstPtr objects.
	static Long s_data;

private:
	Long _id;
	Long _refs;
};

Long TstPtr::s_data = 0;

//-----------------------------------------------------------------------------

class TestPtr :
	public Test
{
public:
	TestPtr() : Test( "TestPtr", 101 ) {}

	void Run()
	{
		{
			Ptr<TstPtr> p0;
			Assert( p0 == 0 );
			Assert( TstPtr::s_data == 0 );

			TstPtr* tst1 = new TstPtr(7);
			Assert( TstPtr::s_data == 1 );

			p0 = tst1;
			Assert( p0->id() == 7 );
			Assert( TstPtr::s_data == 1 );

			Ptr<TstPtr> p1 = new TstPtr(5);		
			Assert( TstPtr::s_data == 2 );

			p0 = p1;
			Assert( TstPtr::s_data == 1 );
		}

		Assert( TstPtr::s_data == 0 );
	}

} _tst;
