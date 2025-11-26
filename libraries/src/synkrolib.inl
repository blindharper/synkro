#include <cfg/SynkroVersion.h>
#include <internal/SizeOf.h>

#ifdef SYNKROLIB_RESOURCES
	#include <core/Resource.h>
	#include "resources.inl"
#endif // SYNKROLIB_RESOURCES

#ifdef SYNKROLIB_FACTORIES
	#include "factories.inl"
#endif // SYNKROLIB_FACTORIES

#ifdef SYNKROLIB_STRINGS
#include "strings.inl"
#endif // SYNKROLIB_STRINGS

#ifndef SYNKRO_STATIC

// Define library export directive.
#if !defined( SYNKROLIBRARY_API )
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
#	define SYNKROLIBRARY_API __declspec( dllexport )
#else
#	define SYNKROLIBRARY_API
#endif // ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )	
#endif // !defined( SYNKROLIBRARY_API )

SYNKRO_EXTERN_C SYNKROLIBRARY_API const synkro::Char* SynkroLibGetName()
{
#ifdef SYNKROLIB_NAME
	return SYNKROLIB_NAME;
#else
#	error SYNKROLIB_NAME is not defined.
#endif // SYNKROLIB_NAME
}

SYNKRO_EXTERN_C SYNKROLIBRARY_API const synkro::Char* SynkroLibGetDescription()
{
#ifdef SYNKROLIB_DESC
	return SYNKROLIB_DESC;
#else
#	error SYNKROLIB_DESC is not defined.
#endif // SYNKROLIB_DESC
}

SYNKRO_EXTERN_C SYNKROLIBRARY_API const synkro::Char* SynkroLibGetAuthor()
{
	return L"blindharper";
}

SYNKRO_EXTERN_C SYNKROLIBRARY_API const synkro::Char* SynkroLibGetCopyright()
{
	return L"Copyright (c) Synkro Project";
}

SYNKRO_EXTERN_C SYNKROLIBRARY_API const synkro::Char* SynkroLibGetComment()
{
#ifdef SYNKROLIB_COMMENT
	return SYNKROLIB_COMMENT;
#else
#	error SYNKROLIB_COMMENT is not defined.
#endif // SYNKROLIB_COMMENT
}

SYNKRO_EXTERN_C SYNKROLIBRARY_API synkro::UInt SynkroLibGetCoreVersion()
{
	return SYNKRO_VERSION;
}

SYNKRO_EXTERN_C SYNKROLIBRARY_API synkro::UInt SynkroLibGetVersion()
{
#if defined( SYNKROLIB_VERSION_MAJOR ) && defined ( SYNKROLIB_VERSION_MINOR ) && defined ( SYNKROLIB_VERSION_PATCH )
	return (SYNKROLIB_VERSION_MAJOR << 16) | (SYNKROLIB_VERSION_MINOR << 8) | SYNKROLIB_VERSION_PATCH;
#else
#	error One of SYNKROLIB_VERSION_MAJOR, SYNKROLIB_VERSION_MINOR and SYNKROLIB_VERSION_BUILD is not defined.
#endif // defined( SYNKROLIB_VERSION_MAJOR ) && defined ( SYNKROLIB_VERSION_MINOR ) && defined ( SYNKROLIB_VERSION_BUILD )
}

SYNKRO_EXTERN_C SYNKROLIBRARY_API synkro::Bool SynkroLibGetPerf()
{
#ifdef SYNKRO_PERF
	return true;
#else
	return false;
#endif // SYNKRO_PERF
}

SYNKRO_EXTERN_C SYNKROLIBRARY_API synkro::Bool SynkroLibGetDebug()
{
#ifdef SYNKRO_DEBUG
	return true;
#else
	return false;
#endif // SYNKRO_DEBUG
}

#ifdef SYNKROLIB_RESOURCES
SYNKRO_EXTERN_C SYNKROLIBRARY_API synkro::UInt SynkroLibGetResourceCount()
{
	return SizeOf( SYNKROLIB_RESOURCES );
}

SYNKRO_EXTERN_C SYNKROLIBRARY_API synkro::core::IResource* SynkroLibGetResource( synkro::UInt index )
{
	return (index < SynkroLibGetResourceCount()) ? SYNKROLIB_RESOURCES[index] : null;
}
#endif // SYNKROLIB_RESOURCES

#ifdef SYNKROLIB_FACTORIES
SYNKRO_EXTERN_C SYNKROLIBRARY_API synkro::UInt SynkroLibGetFactoryCount()
{
	return SizeOf( SYNKROLIB_FACTORIES );
}

SYNKRO_EXTERN_C SYNKROLIBRARY_API synkro::core::IFactory* SynkroLibGetFactory( synkro::UInt index )
{
	return (index < SynkroLibGetFactoryCount()) ? SYNKROLIB_FACTORIES[index] : null;
}
#endif // SYNKROLIB_FACTORIES

#ifdef SYNKROLIB_STRINGS
SYNKRO_EXTERN_C SYNKROLIBRARY_API UInt SynkroLibGetStringCount()
{
	return SizeOf( _strings );
}

SYNKRO_EXTERN_C SYNKROLIBRARY_API const Char* SynkroLibGetStringName( UInt index )
{
	return (index < SynkroLibGetStringCount()) ? _strings[index].Name : 0;
}

SYNKRO_EXTERN_C SYNKROLIBRARY_API const Char* SynkroLibGetStringValue( UInt index )
{
	return (index < SynkroLibGetStringCount()) ? _strings[index].Value : 0;
}
#endif // SYNKROLIB_STRINGS

#elif defined( SYNKROLIB_INIT )

namespace synkro
{

extern void SYNKROLIB_INIT()
{
}

} // synkro

#endif // SYNKRO_STATIC
