//==============================================================================
// This file is a part of the Synkro Framework.
// 
// Copyright (c) Nobody. No rights reserved ;-7
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is allowed without any permission from the Synkro Project.
// Website: https://synkro.pro Email: mailto:blindharper70@gmail.com
//
// Purpose: Defines dynamically-loaded library.
//==============================================================================
SYNKRO_INLINE DynamicLibrary::DynamicLibrary() :
	_dll( 0 )
{
}

SYNKRO_INLINE void DynamicLibrary::Open( const char* name )
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	_dll = ::LoadLibraryA( name );
#elif ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_LINUX )
	_dll = dlopen( name, RTLD_NOW );
#else

#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
}

SYNKRO_INLINE void DynamicLibrary::Close()
{
	if ( _dll != 0 )
	{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
		::FreeLibrary( _dll );
#elif ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_LINUX )
		dlclose( _dll );
#else

#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
		_dll = 0;
	}
}

SYNKRO_INLINE synkro::Bool DynamicLibrary::IsOpen() const
{
	return (_dll != 0);
}

SYNKRO_INLINE void* DynamicLibrary::GetSymbol( const char* symbol ) const
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	return _dll ? ::GetProcAddress( _dll, symbol ) : 0;
#elif ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_LINUX )
	return _dll ? dlsym( _dll, symbol ) : 0;
#else

#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
}
