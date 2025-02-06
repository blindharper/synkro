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
// Purpose: Immutable Unicode string implementation.
//==============================================================================
#include "config.h"
#include <lang/String.h>
#include <lang/Formatter.h>
#include <lang/OutOfRangeException.h>
#include "Convert.h"
#include "Vector.h"
#include "Encoding.h"
#include "Btree.h"
#include <internal/Copy.h>
#include <internal/BinarySemaphore.h>


namespace synkro
{


namespace lang
{


// Whitespace characters.
static Char _ws[] = { 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x20, 0x00 };


// Null string implementation.
#if ( SYNKRO_PROCESSOR == SYNKRO_PROCESSOR_X86 )
static const String::Impl* NULL_IMPL = (const String::Impl*)0xffffffff;
#elif ( SYNKRO_PROCESSOR == SYNKRO_PROCESSOR_X64 )
static const String::Impl* NULL_IMPL = (const String::Impl*)0xffffffffffffffff;
#endif // SYNKRO_PROCESSOR == SYNKRO_PROCESSOR_X86

// Empty string implementation.
static const String::Impl* EMPTY_IMPL = (const String::Impl*)0;


// Tests if the string implementation is non-empty and non-null.
SYNKRO_INLINE static Bool IsValid( String::Impl* impl )
{
	return (impl != EMPTY_IMPL) && (impl != NULL_IMPL);
}


// Internal string representation.
class SYNKRO_API String::Impl
{
public:
	// Global pool of strings.
	static Allocator< BtreeNode<String::Impl> > _alloc;
	static Btree<String::Impl> _strings;

	typedef Allocator<Char> CharAllocator;
	static CharAllocator _charAlloc;

	// Semaphore used for synchronization.
	static BinarySemaphore _semaphore;

	Impl::Impl() :
		perm( false ),
		buffer( 0 )
	{
	}

	Impl::~Impl()
	{
		if ( buffer && size )
		{
			_charAlloc.Deallocate( buffer, size+1 );
		}
	}

	Impl& operator=( const Impl& other )
	{
		if ( this != &other )
		{
			if ( buffer )
			{
				_charAlloc.Deallocate( buffer, size+1 );
			}
			perm	= other.perm;
			size	= other.size;
			hash	= other.hash;
			hashCI	= other.hashCI;
			refs	= other.refs;
			buffer	= _charAlloc.Allocate( size+1 );
			wmemcpy( buffer, other.buffer, size+1 );
			buffer[size] = 0;
		}

		return *this;
	}

	Bool operator==( const Impl& impl ) const
	{
		return (hash == impl.hash) && (wcscmp( buffer, impl.buffer ) == 0);
	}

	Bool operator<( const String::Impl& other ) const
	{
		return (wcscmp( buffer, other.buffer ) < 0);
	}

//------------------------------------------------------------------------------

	// Convert ANSI string to its UNICODE analog.
	static Char* AnsiToUnicode( const char* str, Int len )
	{
		Char* buf = _charAlloc.Allocate( len+1 );

#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	
		::MultiByteToWideChar( CP_ACP, 0, (LPCSTR)str, -1, (LPWSTR)buf, len );

#else

#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
		
		buf[len] = 0;
		return buf;
	}

	// Creates an instance of string of the specified capacity, or returns existing one.
	static Impl* Create( const char* str )
	{
		// Do not allocate memory for empty strings.
		UInt len = (str != 0) ? CastUInt(strlen(str)) : 0;
		if ( len == 0 )
			return 0;

		Char* buf = AnsiToUnicode( str, len );
		Impl* impl = Create( buf );
		len = CastUInt( wcslen(buf) );

		if ( buf )
			_charAlloc.Deallocate( buf, len+1 );

		return impl;
	}

	// Creates an instance of string of the specified capacity, or returns existing one.
	static Impl* Create( const Char* str )
	{
		// Do not allocate memory for empty strings.
		if ( str == 0 )
			return 0;

		UInt len = CastUInt( wcslen(str) );
		if ( len == 0 )
			return 0;

SEMAPHORE_WAIT(_semaphore)

		// Create string implementation
		Impl impl;
		impl.size	= len;
		impl.hash	= Hash( str );
		Char* strLwr = _wcsdup( str );
		strLwr = _wcslwr( strLwr );
		impl.hashCI = Hash( strLwr );
		free( strLwr );
		impl.refs	= 0;
		impl.buffer	= const_cast<Char*>(str);

		BtreeIterator<String::Impl> iter = _strings.Insert( impl );
		impl.buffer = 0; // In order to prevent deleting buffer twice. (See ~Impl())

		// Add reference.
		(*iter).refs++;

SEMAPHORE_SIGNAL(_semaphore)

		return &(*iter);
	}

	// Destroys specified string representation.
	static void Destroy( Impl* impl )
	{
		// Prevent removing strings from empty btree.
		if ( _strings.IsEmpty() )
			return;

SEMAPHORE_WAIT(_semaphore)

		if ( IsValid(impl) )
		{
			BtreeIterator<String::Impl> iter = _strings.Find( *impl );
			if ( iter.IsValid() )
			{
				(*iter).refs--;
				if ( ((*iter).refs == 0) && !impl->perm )
				{
					_strings.Remove( *impl );
				}
			}
		}

SEMAPHORE_SIGNAL(_semaphore)
	}

	// Returns hash code for the string.
	static UInt Hash( const Char* str )
	{
		UInt hash = 0;
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

	Bool		perm;
	UInt		refs;
	UInt		size;
	UInt		hash;
	UInt		hashCI;
	Char*		buffer;
};

String::Impl::CharAllocator String::Impl::_charAlloc( __FILE__, __LINE__ );
Allocator<BtreeNode<String::Impl> > String::Impl::_alloc( __FILE__, __LINE__ );
Btree<String::Impl> String::Impl::_strings( 100, String::Impl::_alloc );
BinarySemaphore String::Impl::_semaphore( true );

//------------------------------------------------------------------------------

const String String::Null( NULL_IMPL );
const String String::Empty( EMPTY_IMPL );

String::String( const String::Impl* impl )
{
	_impl = const_cast<String::Impl*>( impl );
}

String::String()
{
	_impl = 0;
}

String::String( const Char* str )
{
	_impl = Impl::Create( str );
}

String::String( const char* str )
{
	_impl = Impl::Create( str );
}

String::String( const void* buffer, UInt size, const char* encoding )
{
	constexpr UInt BUF_SIZE = 4096;
	Char buf[BUF_SIZE] = {};
	const Byte* bufferBytes = reinterpret_cast<const Byte*>( buffer );
	UInt sz = size; UInt s = 0;
	UInt srcLenUsed = 0; UInt dstLenUsed = 0;

	Vector<Char> chars( A(Char) );
	Encoding* enc = Encoding::Get( encoding );
	while ( enc->Decode(bufferBytes+s, sz-s, &srcLenUsed, buf, BUF_SIZE, &dstLenUsed) )
	{
		chars.Add( buf, srcLenUsed );
		s += srcLenUsed;
	}

	_impl = Impl::Create( chars.Begin() );
}

String::String( const String* entries, UInt count, const String& delim )
{
	Vector<Char> chars( A(Char) );
	for ( UInt i = 0; i < count; ++i )
	{
		if ( i > 0 )
		{
			Impl* impl = delim._impl;
			if ( IsValid(impl) )
			{
				chars.Add( impl->buffer, impl->size );
			}
		}

		Impl* impl = entries[i]._impl;
		if ( IsValid(impl) )
		{
			chars.Add( impl->buffer, impl->size );
		}
	}
	chars.Add( 0 );

	_impl = Impl::Create( chars.Begin() );
}

String::String( Char ch, UInt length )
{
	// Allocate and fill temporary buffer.
	Char* buf = Impl::_charAlloc.Allocate( length+1 );
	wmemset( buf, ch, length );
	buf[length] = 0;

	// Create implementation.
	_impl = Impl::Create( buf );

	// Free temporary buffer.
	Impl::_charAlloc.Deallocate( buf, length+1 );
}

String::String( Char ch )
{
	Char buf[] = { ch, 0 };
	_impl = Impl::Create( buf );
}

String::String( Double num )
{
	char buf[64] = {};
	sprintf( buf, "%.3f", num );
	_impl = Impl::Create( buf );
}

String::String( Int num )
{
	char buf[64] = {};
	sprintf( buf, "%d", num );
	_impl = Impl::Create( buf );
}

String::String( const String& other )
{
	if ( IsValid(_impl = other._impl) )
		_impl->refs++;
}

String::~String()
{
	Impl::Destroy( _impl );
}

void String::Finalize()
{
	String::Impl::_strings.Clear();
}

void String::MakePermanent()
{
	if ( IsValid(_impl) )
	{
		_impl->perm = true;
	}
}

String& String::operator=( const String& other )
{
	if ( this != &other )
	{
		Impl::Destroy( _impl );
		if ( IsValid(_impl = other._impl) )
			_impl->refs++;
	}
	return *this;
}

Bool String::operator==( const String& other ) const
{
	return _impl == other._impl;
}

Bool String::operator!=( const String& other ) const
{
	return _impl != other._impl;
}

Bool String::operator<( const String& other ) const
{
	return CompareTo( other ) < 0;
}

Bool String::operator>( const String& other ) const
{
	return CompareTo( other ) > 0;
}

Bool String::operator<=( const String& other ) const
{
	return CompareTo( other ) <= 0;
}

Bool String::operator>=( const String& other ) const
{
	return CompareTo( other ) >= 0;
}

Int String::CompareTo( const String& other, Bool ignoreCase ) const
{
	return Compare( *this, other, ignoreCase );
}

Int String::CompareTo( const String& other ) const
{
	return CompareTo( other, false );
}

Bool String::EqualsTo( const String& other, Bool ignoreCase ) const
{
	return (Compare( *this, other, ignoreCase ) == 0);
}

Bool String::EqualsTo( const String& other ) const
{
	return EqualsTo( other, false );
}

Bool String::StartsWith( Char prefix, Bool ignoreCase ) const
{
	if ( IsValid(_impl) && (_impl->size > 0) )
	{
		Char p = prefix;
		Char c = _impl->buffer[0];
		if ( ignoreCase )
		{
			p = towlower( p );
			c = towlower( c );
		}
		return (p == c);
	}
	return false;
}

Bool String::StartsWith( Char prefix ) const
{
	return StartsWith( prefix, false );
}

Bool String::StartsWith( const String& prefix, Bool ignoreCase ) const
{
	if ( IsValid(_impl) && IsValid(prefix._impl) && (prefix._impl->size <= _impl->size) )
	{
		if ( ignoreCase )
			return (_wcsnicmp( _impl->buffer, prefix._impl->buffer, prefix._impl->size) == 0);
		else
			return (wmemcmp(_impl->buffer, prefix._impl->buffer, prefix._impl->size) == 0);
	}
	return false;
}

Bool String::StartsWith( const String& prefix ) const
{
	return StartsWith( prefix, false );
}

Bool String::EndsWith( Char suffix, Bool ignoreCase ) const
{
	if ( IsValid(_impl) && (_impl->size > 0) )
	{
		Char s = suffix;
		Char c = _impl->buffer[_impl->size-1];
		if ( ignoreCase )
		{
			s = towlower( s );
			c = towlower( c );
		}
		return (s == c);
	}
	return false;
}

Bool String::EndsWith( Char suffix ) const
{
	return EndsWith( suffix, false );
}

Bool String::EndsWith( const String& suffix, Bool ignoreCase ) const
{
	if ( IsValid(_impl) && IsValid(suffix._impl) && (suffix._impl->size <= _impl->size) )
	{
		const UInt index = _impl->size - suffix._impl->size;
		if ( ignoreCase )
			return (_wcsnicmp(&(_impl->buffer[index]), suffix._impl->buffer, suffix._impl->size) == 0);
		else
			return (wmemcmp(&(_impl->buffer[index]), suffix._impl->buffer, suffix._impl->size) == 0);
	}
	return false;
}

Bool String::EndsWith( const String& suffix ) const
{
	return EndsWith( suffix, false );
}

Bool String::Contains( Char ch, Bool ignoreCase ) const
{
	return (IndexOf(ch, ignoreCase) != none);
}

Bool String::Contains( Char ch ) const
{
	return Contains( ch, false );
}

Bool String::Contains( const String& other, Bool ignoreCase ) const
{
	return (IndexOf(other, ignoreCase) != none);
}

Bool String::Contains( const String& other ) const
{
	return Contains( other, false );
}

UInt String::IndexOf( Char ch, UInt index ) const
{
	if ( IsValid(_impl) && ((index < _impl->size) || index == none) )
	{
		UInt i = (index != none) ? index : 0;
		for ( ; i < _impl->size; ++i )
		{
			if ( _impl->buffer[i] == ch )
				return i;
		}
	}
	return none;
}

UInt String::IndexOf( Char ch ) const
{
	return IndexOf( ch, 0 );
}

UInt String::IndexOf( const String& str, UInt index, Bool ignoreCase ) const
{
	if ( IsValid(_impl) && IsValid(str._impl) && ((index < _impl->size) || index == none) )
	{
		const UInt strLength = str._impl->size;
		const UInt thisLength = _impl->size;
		if ( thisLength >= strLength )
		{
			const UInt diff = thisLength - strLength;
			UInt i = (index != none) ? index : 0;
			for ( ; i <= diff+index; ++i )
			{
				Bool ok = false;
				if ( ignoreCase )
					ok = (_wcsnicmp(&(_impl->buffer[i]), str._impl->buffer, strLength) == 0);
				else
					ok = (wmemcmp(&(_impl->buffer[i]), str._impl->buffer, strLength) == 0);

				if ( ok )
					return i;
			}
		}
	}
	return none;
}

UInt String::IndexOf( const String& str, UInt index ) const
{
	return IndexOf( str, index, false );
}

UInt String::IndexOf( const String& str ) const
{
	return IndexOf( str, 0 );
}

UInt String::IndexOfAny( const String& chars, UInt index ) const
{
	UInt res = none;
	if ( IsValid(_impl) && IsValid(chars._impl) && ((index < _impl->size) || index == none) )
	{
		res = _impl->size;
		const UInt charCount = chars._impl->size;
		for ( UInt i = 0; i < charCount; ++i )
		{
			const UInt idx = IndexOf( chars[i], index );
			if ( (idx != none) && (idx < res) )
				res = idx;
		}
		if ( res == _impl->size )
			res = none;
	}
	return res;
}

UInt String::IndexOfAny( const String& chars ) const
{
	return IndexOfAny( chars, 0 );
}

UInt String::LastIndexOf( Char ch, UInt index ) const
{
	if ( IsValid(_impl) && ((index < _impl->size) || index == none) )
	{
		Int i = (index != none) ? (Int)index : (Int)_impl->size-1;
		for ( ; i >= 0; --i )
		{
			if ( _impl->buffer[i] == ch )
				return CastUInt( i );
		}
	}
	return none;
}

UInt String::LastIndexOf( Char ch ) const
{
	return LastIndexOf( ch, none );
}

UInt String::LastIndexOf( const String& str, UInt index ) const
{
	if ( IsValid(_impl) && IsValid(str._impl) && ((index < _impl->size) || index == none) )
	{
		const UInt thisLength = _impl->size;
		const UInt strLength = str._impl->size;
		if ( thisLength >= strLength )
		{
			Int i = (index != none) ? CastInt(index) : CastInt(thisLength-strLength);
			for ( ; i >= 0; --i )
			{
				if ( wmemcmp(&(_impl->buffer[i]), str._impl->buffer, strLength) == 0 )
					return CastUInt( i );
			}
		}
	}
	return none;
}

UInt String::LastIndexOf( const String& str ) const
{
	return LastIndexOf( str, none );
}

UInt String::LastIndexOfAny( const String& chars, UInt index ) const
{
	Int res = none;
	if ( IsValid(_impl) && IsValid(chars._impl) && ((index < _impl->size) || index == none) )
	{
		const UInt charCount = chars._impl->size;
		for ( UInt i = 0; i < charCount; ++i )
		{
			const Int idx = CastInt( LastIndexOf(chars[i], index) );
			if ( (idx != -1) && (idx > res) )
				res = idx;
		}
	}
	return CastUInt( res );
}

UInt String::LastIndexOfAny( const String& chars ) const
{
	return LastIndexOfAny( chars, none );
}

UInt String::EntryCount( Char delim ) const
{
	UInt count = 0;
	if ( IsValid(_impl) )
	{
		for ( UInt i = 0; i++ != none; ++count )
		{
			i = IndexOf( delim, i );
		}
	}
	return count;
}

UInt String::EntryCount() const
{
	return EntryCount( L',' );
}

UInt String::EntryIndex( const String& entry, Char delim ) const
{
	if ( IsValid(_impl) && IsValid(entry._impl) )
	{
		String list = String( *this ).ToLower();
		String item = entry.ToLower();

		const UInt entryCount = list.EntryCount( delim );
		for ( UInt i = 0; i < entryCount; ++i )
		{
			String listEntry = list.Entry( i, delim );
			if ( item == listEntry )
				return i;
		}
	}
	return none;
}

UInt String::EntryIndex( const String& entry ) const
{
	return EntryIndex( entry, L',' );
}

String String::Entry( UInt index, Char delim ) const
{
	if ( !IsValid(_impl) || (index > EntryCount(delim)) )
		return String::Empty;

	Int start = 0;
	Int end = _impl->size;
	UInt idx0 = 0;
	UInt idx1;

	Int i = CastInt( index );
	for ( ; i > 0 ; --i )
	{
		idx0 = IndexOf( delim, idx0 );
		if ( idx0++ == none )
			break;
	}
	if ( idx0 != none )
		start = idx0;

	if ( _impl->buffer[start] == delim )
		return String::Empty;

	idx1 = IndexOf( delim, start+1 );
	if ( idx1 != none )
		end = idx1;

	return Substring( start, end-start );
}

String String::Entry( UInt index ) const
{
	return Entry( index, L',' );
}

String String::operator+( const String& other ) const
{
	return Append( other );
}

String String::Append( Char ch ) const
{
	return Append( String(ch) );
}

String String::Append( const String& other ) const
{
	// Handle empty strings.
	if ( !IsValid(_impl) && (!IsValid(other._impl)) )
		return String::Empty;

	// Allocate temporary character buffer big enough to hold both strings.
	Int lenThis = IsValid(_impl) ? _impl->size : 0;
	const Int lenOther = (IsValid(other._impl)) ? other._impl->size : 0;
	Int len = lenThis + lenOther;
	Char* buf = Impl::_charAlloc.Allocate( len+1 );

	// Copy strings to the buffer.
	if ( lenThis > 0 )
		wmemcpy( buf, _impl->buffer, lenThis );

	if ( lenOther > 0 )
		wmemcpy( buf + lenThis, other._impl->buffer, lenOther );

	buf[len] = 0;

	// Free temporary buffer.
	String res( buf );
	Impl::_charAlloc.Deallocate( buf, len+1 );
	return res;
}

String String::Substring( UInt start, UInt count ) const
{
	if ( !IsValid(_impl) || (start > _impl->size-1) || (count == 0) )
		return String::Empty;

	// Allocate temporary character buffer.
	UInt len = (start+count < _impl->size) ? count : _impl->size-start;
	Char* buf = Impl::_charAlloc.Allocate( len+1 );

	// Copy characters.
	wmemcpy( buf, &_impl->buffer[start], len );
	buf[len] = 0;

	// Free temporary buffer.
	String res( buf );
	Impl::_charAlloc.Deallocate( buf, len+1 );
	return res;
}

String String::Substring( UInt start ) const
{
	return Substring( start, IsValid(_impl) ? _impl->size : 0 );
}

String String::Reverse() const
{
	// Handle empty strings.
	if ( !IsValid(_impl) )
		return String::Empty;

	// Allocate temporary character buffer.
	UInt len = _impl->size;
	Char* buf = Impl::_charAlloc.Allocate( len+1 );
	
	// Fill in buffer as appropriate.
	UInt j = len - 1;
	for ( UInt i = 0; i < j; ++i, --j )
	{
		buf[i] = _impl->buffer[j];
		buf[j] = _impl->buffer[i];
	}
	buf[len] = 0;

	// Free temporary buffer.
	String res( buf );
	Impl::_charAlloc.Deallocate( buf, len+1 );
	return res;
}

String String::Replace( Char chOld, Char chNew, Bool ignoreCase ) const
{
	// Handle empty strings.
	if ( !IsValid(_impl) )
		return String::Empty;

	// Allocate temporary character buffer.
	UInt len = _impl->size;
	Char* buf = Impl::_charAlloc.Allocate( len+1 );

	// Fill in buffer as appropriate.
	wmemcpy( buf, _impl->buffer, _impl->size );
	for ( UInt i = 0; i < len; ++i )
	{
		Char b = buf[i];
		Char c = chOld;
		if ( ignoreCase )
		{
			b = towlower( b );
			c = towlower( c );
		}
		if ( b == c )
			buf[i] = chNew;
	}
	buf[len] = 0;

	// Free temporary buffer.
	String res( buf );
	Impl::_charAlloc.Deallocate( buf, len+1 );
	return res;
}

String String::Replace( Char chOld, Char chNew ) const
{
	return Replace( chOld, chNew, false );
}

String String::Replace( const String& strOld, const String& strNew, Bool ignoreCase ) const
{
	// Handle empty strings.
	if ( !IsValid(_impl) )
		return String::Empty;

	// Get the number of strOld occurences.
	UInt cnt = 0;
	for ( UInt idx = none; (idx = IndexOf(strOld, idx+1, ignoreCase)) != none; )
	{
		++cnt;
	}
	if ( cnt == 0 )
		return String( *this );

	// Allocate temporary character buffer large enough to hold resulting string.
	const UInt lenOld = strOld.Length();
	const UInt lenNew = strNew.Length();
	const Int delta = cnt*( lenNew - lenOld );
	const UInt len = CastInt(_impl->size) + delta;
	Char* buf = Impl::_charAlloc.Allocate( len+1 );

	// Fill in buffer as appropriate.
	Int pos = 0; Int org = 0; Int old = 0;
	while ( org < CastInt(_impl->size) )
	{
		old = IndexOf( strOld, CastUInt(org), ignoreCase );
		if ( old == none )
			break;

		if ( (old-org) > 0 )
		{
			wmemcpy( buf+pos, _impl->buffer+org, old-org );
			pos += old-org;
			org += old-org;
		}

		if ( lenNew > 0 )
		{
			wmemcpy( buf+pos, strNew._impl->buffer, lenNew );
			pos += lenNew;
		}
		org += lenOld;
	}
	wmemcpy( buf+pos, _impl->buffer+org, _impl->size-org );
	buf[len] = 0;

	// Free temporary buffer.
	String res( buf );
	Impl::_charAlloc.Deallocate( buf, len+1 );
	return res;
}

String String::Replace( const String& strOld, const String& strNew ) const
{
	return Replace( strOld, strNew, false );
}

String String::TrimStart( const String& chars ) const
{
	if ( !IsValid(_impl) || !IsValid(chars._impl) )
		return String( *this );

	const UInt cnt = chars.Length();
	const UInt len = _impl->size;	
	for ( UInt i = 0; i < len; ++i )
	{
		Bool ws = false;
		for ( UInt j = 0; j < cnt; ++j )
		{
			if ( _impl->buffer[i] == chars[j] )
			{
				ws = true;
				break;
			}	
		}
		if ( !ws )
			return Substring( i );
	}

	return String::Empty;
}

String String::TrimStart() const
{
	return TrimStart( String(_ws) );
}

String String::TrimEnd( const String& chars ) const
{
	if ( !IsValid(_impl) || !IsValid(chars._impl) )
		return String( *this );

	const UInt cnt = chars.Length();
	UInt i = _impl->size - 1;
	for ( ; i >= 0; --i )
	{
		Bool ws = false;
		for ( UInt j = 0; j < cnt; ++j )
		{
			if ( _impl->buffer[i] == chars[j] )
			{
				ws = true;
				break;
			}
		}
		if ( !ws )
			return Substring( 0, i+1 );
	}

	return String::Empty;
}

String String::TrimEnd() const
{
	return TrimEnd( String(_ws) );
}

String String::Trim( const String& chars ) const
{
	String res(*this);
	return res.TrimStart(chars).TrimEnd(chars);
}

String String::Trim() const	
{
	return Trim( String(_ws) );
}

String String::ToLower() const
{
	// Handle empty strings.
	if ( !IsValid(_impl) )
		return String( *this );

	// Allocate temporary character buffer big enough to hold both strings.
	UInt len = _impl->size;
	Char* buf = Impl::_charAlloc.Allocate( len+1 );
	
	// Fill in buffer as appropriate.
	for ( UInt i = 0; i < len; ++i )
	{
		buf[i] = towlower(_impl->buffer[i]);
	}
	buf[len] = 0;

	// Free temporary buffer.
	String res( buf );
	Impl::_charAlloc.Deallocate( buf, len+1 );
	return res;
}

String String::ToUpper() const
{
	// Handle empty strings.
	if ( !IsValid(_impl) )
		return String( *this );

	// Allocate temporary character buffer big enough to hold both strings.
	UInt len = _impl->size;
	Char* buf = Impl::_charAlloc.Allocate( len+1 );
	
	// Fill in buffer as appropriate.
	for ( UInt i = 0; i < len; ++i )
	{
		buf[i] = towupper(_impl->buffer[i]);
	}
	buf[len] = 0;

	// Free temporary buffer.
	String res( buf );
	Impl::_charAlloc.Deallocate( buf, len+1 );
	return res;
}

Bool String::IsPermanent() const
{
	return IsValid(_impl) && _impl->perm;
}

Bool String::IsNullOrEmpty() const
{
	return IsNull() || IsEmpty();
}

Bool String::IsNull() const
{
	return (_impl == NULL_IMPL);
}

Bool String::IsEmpty() const
{
	return (_impl != NULL_IMPL) && ((_impl == EMPTY_IMPL) || (_impl->size == 0));
}

Bool String::IsInteger() const
{
	if ( !IsValid(_impl) )
		return false;

	for ( UInt i = 0; i < _impl->size; ++i )
	{
		if ( (i == 0) && (_impl->buffer[i] == L'-') )
		{
			if ( _impl->size == 1 )
				return false;
		}
		else if ( iswdigit(_impl->buffer[i]) == 0  )
			return false;
	}

	return true;
}

Bool String::IsDecimal() const
{
	if ( !IsValid(_impl) )
		return false;

	UInt dotCount = 0;
	for ( UInt i = 0; i < _impl->size; ++i )
	{
		if ( (i == 0) && (_impl->buffer[i] == L'-') )
		{
			if ( _impl->size == 1 )
				return false;
		}
		else if ( _impl->buffer[i] == L'.' )
		{
			if ( ++dotCount > 1 )
				return false;
		}
		else if ( iswdigit(_impl->buffer[i]) == 0 )
			return false;
	}

	return true;
}

Bool String::IsHexadecimal() const
{
	if ( !IsValid(_impl) )
		return false;

	static const Char* _hex = L"0123456789ABCDEF";

	for ( UInt i = 0; i < _impl->size; ++i )
	{
		Bool valid = false;
		for ( Byte b = 0; b < 16; ++b )
		{
			Char ch = _impl->buffer[i];
			if ( _wcsnicmp(&ch, &_hex[b], 1) == 0 )
			{
				valid = true;
				break;
			}
		}
		if ( !valid )
			return false;
	}
	return true;
}

Int String::ToInteger() const
{
	return Convert::ToInt( *this );
}

Float String::ToDecimal() const
{
	return Convert::ToFloat( *this );
}

UInt String::Length() const
{
	return IsValid(_impl) ? _impl->size : 0;
}

UInt String::HashCode( Bool ignoreCase ) const
{
	return IsValid(_impl) ? (ignoreCase ? _impl->hashCI : _impl->hash) : CastUInt((Pointer)_impl);
}

UInt String::HashCode() const
{
	return IsValid(_impl) ? _impl->hash : CastUInt((Pointer)_impl);
}

Char String::operator[]( UInt index ) const
{
	UInt maximum = IsValid(_impl) ? _impl->size : 0;
	if ( index >= maximum )
		throw OutOfRangeException( index, maximum );

	return _impl->buffer[index];
}

String::operator Formattable() const
{
	return Formattable( IsValid(_impl) ? _impl->buffer : nullptr );
}

Char* String::GetChars( UInt start, UInt count, Char* dst ) const
{
	assert( start <= Length() );
	assert( dst != nullptr );

	if ( !IsValid(_impl) )
	{
		*dst = CastChar( 0 );
		return 0;
	}

	UInt cnt = (start+count >= Length()) ? Length()-start : count;
	Copy( dst, &_impl->buffer[start], cnt );
	dst[cnt] = 0;
	return dst;
}

UInt String::GetBytes( void* buffer, UInt size, const char* encoding ) const
{
	if ( !IsValid(_impl) )
	{
		*((Byte*)buffer) = 0;
		return 0;
	}

#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	
	::WideCharToMultiByte( CP_ACP, 0, (LPCWSTR)_impl->buffer, -1, (LPSTR)buffer, size, nullptr, nullptr );
	((Byte*)buffer)[_impl->size] = 0;
	return _impl->size;

#else

#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS

	return 0;
}

UInt String::GetBytes( void* buffer, UInt size ) const
{
	return GetBytes( buffer, size, "ASCII-7" );
}

Int String::Compare( const String& first, const String& second, Bool ignoreCase )
{
	if ( first._impl == second._impl )
		return 0;
	else if ( !IsValid(first._impl) )
		return -1;
	else if ( !IsValid(second._impl) )
		return 1;
	else if ( ignoreCase )
		return _wcsicmp( first._impl->buffer, second._impl->buffer );

	const Int ret = wmemcmp( first._impl->buffer, second._impl->buffer, min(first._impl->size, second._impl->size) );
	if ( ret == 0 )
	{
		if ( first._impl->size == second._impl->size )
			return 0;
		else if ( first._impl->size < second._impl->size ) 
			return -1;
		else
			return 1;
	}
	return ret;
}

Int String::Compare( const String& first, const String& second )
{
	return Compare( first, second, false );
}

String String::Format( const Char* pattern, const Formattable& arg0 )
{
	return Formatter::Format( pattern, arg0 ).ToString();
}

String String::Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1 )
{
	return Formatter::Format( pattern, arg0, arg1 ).ToString();
}

String String::Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2 )
{
	return Formatter::Format( pattern, arg0, arg1, arg2 ).ToString();
}

String String::Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3 )
{
	return Formatter::Format( pattern, arg0, arg1, arg2, arg3 ).ToString();
}

String String::Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4 )
{
	return Formatter::Format( pattern, arg0, arg1, arg2, arg3, arg4 ).ToString();
}

String String::Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5 )
{
	return Formatter::Format( pattern, arg0, arg1, arg2, arg3, arg4, arg5 ).ToString();
}

String String::Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6 )
{
	return Formatter::Format( pattern, arg0, arg1, arg2, arg3, arg4, arg5, arg6 ).ToString();
}

String String::Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7 )
{
	return Formatter::Format( pattern, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7 ).ToString();
}

String String::Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8 )
{
	return Formatter::Format( pattern, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8 ).ToString();
}

String String::Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8, const Formattable& arg9 )
{
	return Formatter::Format( pattern, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9 ).ToString();
}

//------------------------------------------------------------------------------

SYNKRO_API String operator+( const char* first, const String& second )
{
	return String(first).Append( second );
}

SYNKRO_API Bool operator==( const char* first, const String& second )
{
	return String(first) == second;
}

SYNKRO_API Bool operator!=( const char* first, const String& second )
{
	return String(first) != second;
}

SYNKRO_API Bool operator<( const char* first, const String& second )
{
	return String(first) < second;
}

SYNKRO_API Bool operator>( const char* first, const String& second )
{
	return String(first) > second;
}

SYNKRO_API Bool operator<=( const char* first, const String& second )
{
	return String(first) <= second;
}

SYNKRO_API Bool operator>=( const char* first, const String& second )
{
	return String(first) >= second;
}


} // lang


} // synkro
