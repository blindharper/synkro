#include "config.h"
#include "Test.h"
#include <core/Configuration.h>

//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;
using namespace synkro;

//------------------------------------------------------------------------------

struct ParamDef
{
	const Char*		name;
	ParamType		type;
	ParamConstraint	constraints;
	const Char*		defaultValue;
	const Char*		data;
	const Char*		description;
};

class TestConfiguration :
	public Test
{
public:
	TestConfiguration() : Test( "TestConfiguration", 800 ) {}

	void Run()
	{
		// Config parameter map.
		ParamDef params[] = 
		{
			{ L"Param.String",	ParamType::String,	ParamConstraint::None,			L"default",	L"", L"Test string parameter" },
			{ L"Param.List",	ParamType::List,	ParamConstraint::None,			L"",		L"", L"Test list parameter" },
			{ L"Param.Bool",	ParamType::Boolean,	ParamConstraint::None,			L"false",	L"", L"Test boolean parameter" },
			{ L"Param.Flag",	ParamType::Flag,	ParamConstraint::None,			L"6",		L"", L"Test flag parameter" },
		};

		Configuration* cfg = new Configuration();

		// Parameter registration.
		Long count = sizeof(params)/sizeof(params[0]);
		for ( Long i = 0; i < count; ++i )
		{		
			cfg->RegisterParam( &(Param(params[i].name, params[i].type, params[i].constraints, params[i].defaultValue, params[i].data, params[i].description)) );
		}

		// Parameter retrieval.
		const Param* param = cfg->GetParam( "Param.Bool" );
		Assert( param->Type == ParamType::Boolean );
		Assert( param->Constraints == ParamConstraint::None );
		Assert( param->Description == "Test boolean parameter" );
		Assert( param->DefaultValue == "false" );

		// Set parameters.
		cfg->Set( "Param.String", "String" );
		cfg->Set( "Param.String", "Test string" );
		cfg->Set( "Param.List", "one" );
		cfg->Set( "Param.List", "two" );
		cfg->Set( "Param.List", "three" );
		cfg->Set( "Param.List", "one" );
		cfg->Set( "Param.List", "tWo" );
		cfg->Set( "Param.List", "THREE" );
		cfg->Set( "Param.Bool", true );

		// Validation.
		cfg->Validate();

		// Get parameters.
		String valueString;
		cfg->Get( "Param.String", &valueString );
		Assert( valueString == "Test string" );

		String valueList;
		cfg->Get( "Param.List", &valueList );
		Assert( valueList == "one|two|three" );
		
		cfg->Set( "Param.List", "" );
		cfg->Get( "Param.List", &valueList );
		Assert( valueList == "" );

		Bool valueBool;
		cfg->Get( "Param.Bool", &valueBool );
		Assert( valueBool == true );

		delete cfg;
	}

} _tst;
