#include "config.h"
#include "Test.h"
#include <anim/Expression/ExpressionScript.h>
#include <anim/Expression//ExpressionCompiler.h>
#include <img/Color.h>
#include <math/Vector3.h>

//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::anim;
using namespace synkro::img;
using namespace synkro::lang;
using namespace synkro::math;
using namespace synkro;

//------------------------------------------------------------------------------

class TestExpression :
	public Test
{
public:
	TestExpression() : Test( "TestExpression", 129 ) {}

	void Run()
	{
		ExpressionCompiler compiler( nullptr );

		ExpressionScript script( &compiler, L"return time;" );
		script.DeclareParam( L"time", Type::Float );
		ExpressionParam* paramTime = script.GetParam( L"time" );
		script.Prepare();
		script.SetParamValue( paramTime, 3.14f );
		Assert( script.GetType() == Type::Float );

		Float value;
		script.GetValue( value );
		Assert( value == 3.14f );

		String text(L"float r = 0.2; return 2.0*(r+0.05);");
		ExpressionScript script2( &compiler, text );
		script2.Prepare();
		Float f; script2.GetValue( f );
		Assert( script2.GetType() == Type::Float );
		Assert( f == 0.5f );

		/*String text3(L"float r = 0.5; float g = sin( 2.0*PI*time ); float b = 2.0*cos( 2.0*PI*time ) - 0.7; color c(0.1, 0.2, 0.3); return color(r+c.r, g+c.g, b+c.b);");
		ExpressionScript script3( &compiler, text3 );
		script2.DeclareParam( L"time", Type::Float );
		ExpressionParam* paramTime3 = script3.GetParam( L"time" );
		script3.Prepare();
		script3.SetParamValue( paramTime3, 0.0f );
		Color color; script3.GetValue( color );
		Assert( script3.GetType() == Type::Color );*/
	}

} _tst;
