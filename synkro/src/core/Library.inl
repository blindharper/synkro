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
// Purpose: Library wrapper.
//==============================================================================
SYNKRO_INLINE Bool Library::IsPerf() const
{
	return (_funcIsPerf != nullptr) ? _funcIsPerf() : false;
}

SYNKRO_INLINE Bool Library::IsDebug() const
{
	return (_funcIsDebug != nullptr) ? _funcIsDebug() : false;
}

SYNKRO_INLINE Bool Library::IsObject() const
{
	return (_funcIsDebug != nullptr) && (_funcGetFactoryCount != nullptr) && (_funcGetFactory != nullptr);
}

SYNKRO_INLINE Bool Library::IsString() const
{
	return (_funcGetStringCount != nullptr) && (_funcGetStringName != nullptr) && (_funcGetStringValue != nullptr);
}

SYNKRO_INLINE Bool Library::IsResource() const
{
	return (_funcGetResourceCount != nullptr) && (_funcGetResource != nullptr);
}

SYNKRO_INLINE const Char* Library::GetName() const
{
	return (_funcGetName != nullptr) ? _funcGetName() : L"";
}

SYNKRO_INLINE const Char* Library::GetDescription() const
{
	return (_funcGetDescription != nullptr) ? _funcGetDescription() : L"";
}

SYNKRO_INLINE const Char* Library::GetAuthor() const
{
	return (_funcGetAuthor != nullptr) ? _funcGetAuthor() : L"";
}

SYNKRO_INLINE const Char* Library::GetCopyright() const
{
	return (_funcGetCopyright != nullptr) ? _funcGetCopyright() : L"";
}

SYNKRO_INLINE const Char* Library::GetComment() const
{
	return (_funcGetComment != nullptr) ? _funcGetComment() : L"";
}

SYNKRO_INLINE const Char* Library::GetLanguage() const
{
	return (_funcGetLanguage != nullptr) ? _funcGetLanguage() : L"";
}

SYNKRO_INLINE UInt Library::GetCoreVersion() const
{
	return (_funcGetCoreVersion != nullptr) ? _funcGetCoreVersion() : 0;
}

SYNKRO_INLINE UInt Library::GetVersion() const
{
	return (_funcGetVersion != nullptr) ? _funcGetVersion() : 0;
}

SYNKRO_INLINE UInt Library::GetResourceCount() const
{
	return (_funcGetResourceCount != nullptr) ? _funcGetResourceCount() : 0;
}

SYNKRO_INLINE IResource* Library::GetResource( UInt index ) const
{
	if ( !IsResource() )
		return nullptr;

	assert( index < GetResourceCount() );

	return (index < GetResourceCount()) ? _funcGetResource( index ) : nullptr;
}

SYNKRO_INLINE UInt Library::GetFactoryCount() const
{
	return (_funcGetFactoryCount != nullptr) ? _funcGetFactoryCount() : 0;
}

SYNKRO_INLINE IFactory* Library::GetFactory( UInt index ) const
{
	if ( !IsObject() )
		return nullptr;

	assert( index < GetFactoryCount() );

	return (index < GetFactoryCount()) ? _funcGetFactory( index ) : nullptr;
}

SYNKRO_INLINE UInt Library::GetStringCount() const
{
	return (_funcGetStringCount != nullptr) ? _funcGetStringCount() : 0;
}

SYNKRO_INLINE const Char* Library::GetStringName( UInt index ) const
{
	if ( !IsString() )
		return nullptr;

	assert( index < GetStringCount() );

	return (index < GetStringCount()) ? _funcGetStringName( index ) : nullptr;
}

SYNKRO_INLINE const Char* Library::GetStringValue( UInt index ) const
{
	if ( !IsString() )
		return nullptr;

	assert( index < GetStringCount() );

	return (index < GetStringCount()) ? _funcGetStringValue( index ) : nullptr;
}

SYNKRO_INLINE Bool Library::IsValid() const
{
	return
		(_funcGetName != nullptr) && 
		(_funcGetDescription != nullptr) && 
		(_funcGetAuthor != nullptr) &&
		(_funcGetCopyright != nullptr) && 
		(_funcGetComment != nullptr) && 
		(_funcGetCoreVersion != nullptr) && 
		(_funcGetVersion != nullptr);
}
