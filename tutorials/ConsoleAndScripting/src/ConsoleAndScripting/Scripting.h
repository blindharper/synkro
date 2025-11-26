#ifndef __SCRIPTING__
#define __SCRIPTING__


#define SCRIPT_METHOD_BEGIN( CLASS, NAME, INPUT, OUTPUT )	\
class CLASS :												\
	public ScriptMethod										\
{															\
public:														\
	CLASS() : ScriptMethod( NAME, INPUT, OUTPUT ) {}

#define SCRIPT_METHOD_END( FUNC )	} FUNC;

#endif // __SCRIPTING__
