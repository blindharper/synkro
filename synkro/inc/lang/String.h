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
// Purpose: Defines immutable Unicode string.
//==============================================================================
#ifndef _SYNKRO_LANG_STRING_
#define _SYNKRO_LANG_STRING_


#include "config.h"
#include <lang/Formattable.h>


namespace synkro
{


namespace lang
{


/**
 * Immutable Unicode character string.
 */
class SYNKRO_API String
{
public:
	class SYNKRO_API Impl;

	/**
	 * Null string constant.
	 */
	static const String										Null;

	/**
	 * Empty string constant.
	 */
	static const String										Empty;

	/**
	 * Creates a string from the given internal representation.
	 * @param impl Internal string representation.
	 */
	String( const String::Impl* impl );

	/**
	 * Creates a string from a null-terminated sequence of Unicode characters.
	 * @param str Unicode character sequence.
	 */
	String( const Char* str );

	/**
	 * Creates string from a null-terminated sequence of ASCII-7 characters.
	 * @param str ASCII-7 character sequence.
	 */
	String( const char* str );

	/**
	 * Creates string from a sequence of bytes in the given encoding.
	 * @param buffer Sequence of bytes from which to create a string.
	 * @param size Bytes sequence length.
	 * @param encoding Null-terminated string specifying the encoding.
	 */
	String( const void* buffer, UInt size, const char* encoding );

	/**
	 * Creates a delimited list of string entries.
	 * @param entries An array of string entries.
	 * @param count The number of entries in the array.
	 * @param delim Delimiter string.
	 */
	explicit String( const String* entries, UInt count, const String& delim );

	/**
	 * Creates string holding given number of a particular character.
	 * @param ch Character from which to create a string.
	 * @param length Number of characters in the string.
	 */
	explicit String( Char ch, UInt length );

	/**
	 * Creates string from a single character.
	 * @param ch Character from which to create a string.
	 */
	explicit String( Char ch );

	/**
	 * Creates string from a floating-point value.
	 * @param num Floating-point value from which to create a string.
	 */
	explicit String( Double num );

	/**
	 * Creates string from an integer value.
	 * @param num Whole number value from which to create a string.
	 */
	explicit String( Int num );

	/**
	 * Creates a copy of the string.
	 * @param other String to copy.
	 */
	String( const String& other );

	/**
	 * Creates an empty string.
	 */
	String();

	/**
	 * Destroys the string.
	 */
	virtual ~String();

	/**
	 * Performs string pool uninitialization.
	 */
	static void												Finalize();

	/**
	 * Prevents string destruction even if it's not referenced anymore.
	 */
	void													MakePermanent();

	/**
	 * Copy by reference.
	 * @param other String to copy.
	 * @return Copy of this string.
	 */
	String&													operator=( const String& other );

	/**
	 * Tests the strings for equality.
	 * @param other String to compare to.
	 * @return True if this string is equal to the other, false otherwise.
	 */
	Bool													operator==( const String& other ) const;

	/**
	 * Tests the strings for inequality.
	 * @param other String to compare to.
	 * @return True if this string is not equal to the other, false otherwise.
	 */
	Bool													operator!=( const String& other ) const;

	/**
	 * Compares this string to another one.
	 * @param other String to compare to.
	 * @return True if this string is lexicographically less than the other, false otherwise.
	 */
	Bool													operator<( const String& other ) const;

	/**
	 * Compares this string to another one.
	 * @param other String to compare to.
	 * @return True if this string is lexicographically greater than the other, false otherwise.
	 */
	Bool													operator>( const String& other ) const;

	/**
	 * Compares this string to another one.
	 * @param other String to compare to.
	 * @return True if this string is lexicographically less or equal than the other, false otherwise.
	 */
	Bool													operator<=( const String& other ) const;

	/**
	 * Compares this string to another one.
	 * @param other String to compare to.
	 * @return True if this string is lexicographically greater or equal than the other, false otherwise.
	 */
	Bool													operator>=( const String& other ) const;

	/**
	 * Compares string to another string.
	 * @param other String to compare to.
	 * @param ignoreCase Indicates whether to ignore text case.
	 * @return Return value is identical to that of strcmpi().
	 */
	Int														CompareTo( const String& other, Bool ignoreCase ) const;

	/**
	 * Compares string to another string. The comparison is case-sensitive.
	 * @param other String to compare to.
	 * @return Return value is identical to that of strcmp().
	 */
	Int														CompareTo( const String& other ) const;

	/**
	 * Compares string to another string.
	 * @param other String to compare to.
	 * @param ignoreCase Indicates whether to ignore text case.
	 * @return True if the strings are identical, false otherwise.
	 */
	Bool													EqualsTo( const String& other, Bool ignoreCase ) const;

	/**
	 * Compares string to another string. The comparison is case-sensitive.
	 * @param other String to compare to.
	 * @return True if the strings are identical, false otherwise.
	 */
	Bool													EqualsTo( const String& other ) const;

	/**
	 * Tests if this string starts with the given prefix.
	 * @param prefix Character to search for.
	 * @param ignoreCase Indicates whether to ignore text case.
	 * @return True if string starts with the given character, false otherwise.
	 */
	Bool													StartsWith( Char prefix, Bool ignoreCase ) const;

	/**
	 * Tests if this string starts with the given prefix. The test is case-sensitive.
	 * @param prefix Character to search for.
	 * @return True if string starts with the given character, false otherwise.
	 */
	Bool													StartsWith( Char prefix ) const;

	/**
	 * Tests if this string starts with the given prefix.
	 * @param prefix String to search for.
	 * @param ignoreCase Indicates whether to ignore text case.
	 * @return True if string starts with the given substring, false otherwise.
	 */
	Bool													StartsWith( const String& prefix, Bool ignoreCase ) const;

	/**
	 * Tests if this string starts with the given prefix. The test is case-sensitive.
	 * @param prefix String to search for.
	 * @return True if string starts with the given substring, false otherwise.
	 */
	Bool													StartsWith( const String& prefix ) const;

	/**
	 * Tests if this string ends with the given suffix.
	 * @param suffix Character to search for.
	 * @param ignoreCase Indicates whether to ignore text case.
	 * @return True if string ends with the given character, false otherwise.
	 */
	Bool													EndsWith( Char suffix, Bool ignoreCase ) const;

	/**
	 * Tests if this string ends with the given suffix. The test is case-sensitive.
	 * @param suffix Character to search for.
	 * @return True if string ends with the given character, false otherwise.
	 */
	Bool													EndsWith( Char suffix ) const;

	/**
	 * Tests if this string ends with the given suffix.
	 * @param suffix String to search for.
	 * @param ignoreCase Indicates whether to ignore text case.
	 * @return True if string ends with the given substring, false otherwise.
	 */
	Bool													EndsWith( const String& suffix, Bool ignoreCase ) const;

	/**
	 * Tests if this string ends with the given suffix. The test is case-sensitive.
	 * @param suffix String to search for.
	 * @return True if string ends with the given substring, false otherwise.
	 */
	Bool													EndsWith( const String& suffix ) const;

	/**
	 * Tests if this string contains given character.
	 * @param ch Character to search for.
	 * @param ignoreCase Indicates whether to ignore text case.
	 * @return True if string contains the character, false otherwise.
	 */
	Bool													Contains( Char ch, Bool ignoreCase ) const;

	/**
	 * Tests if this string contains given character. The test is case-sensitive.
	 * @param ch Character to search for.
	 * @return True if string contains the character, false otherwise.
	 */
	Bool													Contains( Char ch ) const;

	/**
	 * Tests if this string contains another string.
	 * @param other String to search for.
	 * @param ignoreCase Indicates whether to ignore text case.
	 * @return True if string contains another string, false otherwise.
	 */
	Bool													Contains( const String& other, Bool ignoreCase ) const;

	/**
	 * Tests if this string contains another string. The test is case-sensitive.
	 * @param other String to search for.
	 * @return True if string contains another string, false otherwise.
	 */
	Bool													Contains( const String& other ) const;

	/**
	 * Finds first occurence of the given character within this string, starting with the given position.
	 * @param ch Character to search for.
	 * @param index Starting search position.
	 * @return Index of the found occurence of the character, or none if nothing found.
	 */	
	UInt													IndexOf( Char ch, UInt index ) const;

	/**
	 * Finds first occurence of the given character within this string.
	 * @param ch Character to search for.
	 * @return Index of the found occurence of the character, or none if nothing found.
	 */	
	UInt													IndexOf( Char ch ) const;

	/** 
	 * Finds first occurence of the given string within the string, starting with the given position.
	 * @param str String to search for.
	 * @param index Starting search position.
	 * @param ignoreCase Indicates whether to ignore text case.
	 * @return Index of the found occurence of the string, or none if nothing found.
	 */
	UInt													IndexOf( const String& str, UInt index, Bool ignoreCase ) const;

	/** 
	 * Finds first occurence of the given string within the string, starting with the given position. The search is case-sensitive.
	 * @param str String to search for.
	 * @param index Starting search position.
	 * @return Index of the found occurence of the string, or none if nothing found.
	 */
	UInt													IndexOf( const String& str, UInt index ) const;

	/** 
	 * Finds first occurence of the given string within the string. The search is case-sensitive.
	 * @param str String to search for.
	 * @return Index of the found occurence of the string, or none if nothing found.
	 */
	UInt													IndexOf( const String& str ) const;

	/** 
	 * Finds first occurence of any of the given characters within the string, starting with the given position.
	 * @param chars Characters to search for.
	 * @param index Starting search position.
	 * @return Index of the found character, or none if nothing found.
	 */
	UInt													IndexOfAny( const String& chars, UInt index ) const;

	/** 
	 * Finds first occurence of any of the given characters within the string.
	 * @param chars Characters to search for.
	 * @return Index of the found character, or none if nothing found.
	 */
	UInt													IndexOfAny( const String& chars ) const;

	/** 
	 * Finds last occurence of the given character within the string, starting with the given position.
	 * @param ch Character to search for.
	 * @param index Starting search position.
	 * @return Index of the found occurence of the character, or none if nothing found.
	 */
	UInt													LastIndexOf( Char ch, UInt index ) const;

	/** 
	 * Finds last occurence of the given character within the string.
	 * @param ch Character to search for.
	 * @return Index of the found occurence of the character, or none if nothing found.
	 */
	UInt													LastIndexOf( Char ch ) const;

	/**
	 * Finds last occurence of the given string within the string, starting with the given position.
	 * @param str String to search for.
	 * @param index Starting search position.
	 * @return Index of the found occurence of the string, or none if nothing found.
	 */
	UInt													LastIndexOf( const String& str, UInt index ) const;

	/** 
	 * Finds last occurence of the given string within the string.
	 * @param str String to search for.
	 * @return Index of the found occurence of the string, or none if nothing found.
	 */
	UInt													LastIndexOf( const String& str ) const;

	/**
	 * Finds last occurence of the given characters within the string, starting with the given position.
	 * @param chars Characters to search for.
	 * @param index Starting search position.
	 * @return Index of the found character, or none if nothing found.
	 */
	UInt													LastIndexOfAny( const String& chars, UInt index ) const;

	/**
	 * Finds last occurence of the given characters within the string.
	 * @param chars Characters to search for.
	 * @return Index of the found character, or none if nothing found.
	 */
	UInt													LastIndexOfAny( const String& chars ) const;

	/**
	 * Returns the number of entries in the string treated as 'delim'-delimited list.
	 * @param delim Delimiter character.
	 * @return Number of entries in the list.
	 */
	UInt													EntryCount( Char delim ) const;

	/**
	 * Counts the number of entries in the string treated as comma-delimited list.
	 * @return Number of entries in the list.
	 */
	UInt													EntryCount() const;

	/**
	 * Searches for the given entry in the string treated as 'delim'-delimited list.
	 * @param entry String to search for.
	 * @param delim Delimiter character.
	 * @return Index of the given entry if successful, or none if entry not found.
	 */
	UInt													EntryIndex( const String& entry, Char delim ) const;

	/**
	 * Searches for the given entry in the string treated as comma-delimited list.
	 * @param entry String to search for.
	 * @return Index of the given entry if successful, or none if entry not found.
	 */
	UInt													EntryIndex( const String& entry ) const;

	/**
	 * Retrieves an entry by index from the string treated as 'delim'-delimited list.
	 * @param index Index of the entry to return.
	 * @param delim Delimiter character.
	 * @return Specified entry.
	 */
	String													Entry( UInt index, Char delim ) const;

	/**
	 * Retrieves an entry by index from the string treated as comma-delimited list.
	 * @param index Index of the entry to return.
	 * @return Specified entry.
	 */
	String													Entry( UInt index ) const;

	/**
	 * Concatenates the string with another string.
	 * @param other String to concatenate with.
	 * @return Concatenation of the string with another string.
	 */
	String													operator+( const String& other ) const;

	/**
	 * Appends a character to this string.
	 * @param ch Character to append.
	 * @return Copy of this string with the given character appended to it.
	 */
	String													Append( Char ch ) const;

	/**
	 * Appends another string to this string.
	 * @param other String to append.
	 * @return Copy of this string with another string appended to it.
	 */
	String													Append( const String& other ) const;

	/** 
	 * Retrieves a part of the string from the given position. The resulting string is no more than 'count' characters long.
	 * @param start Position in the original string where the substring begins.
	 * @param count Maximum number of characters to copy to the substring, beginning with the start.
	 * @return Required substring.
	 */
	String													Substring( UInt start, UInt count ) const;

	/** 
	 * Retrieves a part of the string from the given position and to the end of the string.
	 * @param start Position in the original string where the substring begins.
	 * @return Required substring.
	 */
	String													Substring( UInt start ) const;

	/**
	 * Reverses the order of characters in the string.
	 * @return A copy of the string with the reversed characters order.
	 */
	String													Reverse() const;

	/**
	 * Replaces all occurences of the given character with another one.
	 * @param chOld Character to search for.
	 * @param chNew Character to replace the old one with.
	 * @param ignoreCase Indicates whether to ignore text case.
	 * @return A copy of this string with all occurences of the given character replaced with another one.
	 */
	String													Replace( Char chOld, Char chNew, Bool ignoreCase ) const;

	/**
	 * Replaces all occurences of the given character with another one. The replacement is case-sensitive.
	 * @param chOld Character to search for.
	 * @param chNew Character to replace the old one with.
	 * @return A copy of this string with all occurences of the given character replaced with another one.
	 */
	String													Replace( Char chOld, Char chNew ) const;

	/**
	 * Replaces all occurences of the given substring replaced with another string.
	 * @param strOld String to search for.
	 * @param strNew String to replace the old one with.
	 * @param ignoreCase Indicates whether to ignore text case.
	 * @return A copy of this string with all occurences of the given substring replaced with another string.
	 */
	String													Replace( const String& strOld, const String& strNew, Bool ignoreCase ) const;

	/**
	 * Replaces all occurences of the given substring replaced with another string. The replacement is case-sensitive.
	 * @param strOld String to search for.
	 * @param strNew String to replace the old one with.
	 * @return A copy of this string with all occurences of the given substring replaced with another string.
	 */
	String													Replace( const String& strOld, const String& strNew ) const;

	/**
	 * Trims all leading characters found in the given string.
	 * @param chars Characters to remove.
	 * @return A copy of this string without the leading characters specified by the chars parameter.
	 */
	String													TrimStart( const String& chars ) const;

	/**
	 * Removes all leading whitespaces from the string.
	 * @return A copy of this string with all leading whitespaces removed.
	 */
	String													TrimStart() const;

	/**
	 * Trims all trailing characters found in the given string.
	 * @param chars Characters to remove.
	 * @return A copy of this string without the trailing characters specified by the chars parameter.
	 */
	String													TrimEnd( const String& chars ) const;

	/**
	 * Removes all trailing whitespaces from the string.
	 * @return A copy of this string with all trailing whitespaces removed.
	 */
	String													TrimEnd() const;

	/**
	 * Trims all leading and trailing characters found in the given string.
	 * @param chars Characters to remove.
	 * @return A copy of this string without the leading and trailing characters specified by the chars parameter.
	 */
	String													Trim( const String& chars ) const;

	/**
	 * Removes all leading and trailing whitespaces from the string.
	 * @return A copy of this string with all leading and trailing whitespaces removed.
	 */
	String													Trim() const;

	/**
	 * Converts the string to lower case.
	 * @return A copy of this string with all characters converted to the lower case.
	 */
	String													ToLower() const;

	/**
	 * Converts the string to upper case.
	 * @return A copy of this string with all characters converted to the upper case.
	 */
	String													ToUpper() const;

	/**
	 * Tests if the string length is permanent.
	 * @return True for a permanent string, false otherwise.
	 */
	Bool													IsPermanent() const;

	/**
	 * Tests if the string length is null or empty.
	 * @return True for a null or empty string, false otherwise.
	 */
	Bool													IsNullOrEmpty() const;

	/**
	 * Tests if the string length is null.
	 * @return True for a null string, false otherwise.
	 */
	Bool													IsNull() const;

	/**
	 * Tests if the string length is zero.
	 * @return True for an empty string, false otherwise.
	 */
	Bool													IsEmpty() const;

	/**
	 * Tests if the string can be interpreted as an integer value.
	 * @return True for a valid integer string, false otherwise.
	 */
	Bool													IsInteger() const;

	/**
	 * Tests if the string can be interpreted as a decimal value.
	 * @return True for a valid decimal string, false otherwise.
	 */
	Bool													IsDecimal() const;

	/**
	 * Tests if the string can be interpreted as a hexadecimal value.
	 * @return True for a valid hexadecimal string, false otherwise.
	 */
	Bool													IsHexadecimal() const;

	/**
	 * Returns integer value corresponding to this string.
	 */
	Int														ToInteger() const;

	/**
	 * Returns decimal value corresponding to this string.
	 */
	Float													ToDecimal() const;

	/**
	 * Counts string length.
	 * @return The number of characters in the string.
	 */
	UInt													Length() const;

	/**
	 * Calculates string hash code.
	 * @param ignoreCase Indicates whether to ignore text case.
	 * @return String hash code.
	 */
	UInt													HashCode( Bool ignoreCase ) const;

	/**
	 * Calculates string hash code.
	 * @return String hash code.
	 */
	UInt													HashCode() const;

	/**
	 * Returns character at the given position. Does not provide range checking.
	 * @param index Position of the character to retrieve.
	 * @exception OutOfRangeException.
	 * @return Character at the given position.
	 */
	Char													operator[]( UInt index ) const;

	/**
	 * Casts string to formattable.
	 */
															operator Formattable() const;

	/**
	 * Copies characters from the string to the given character array.
	 * Always adds a null character to the end of the destination buffer.
	 * @param start Index of the first character to be copied to destination buffer.
	 * @param count Maximum number of characters to copy to the substring, beginning with the start.
	 * @param dst Destination buffer.
	 * @return Pointer to destination buffer.
	 */
	Char*													GetChars( UInt start, UInt count, Char* dst ) const;

	/**
	 * Encodes string content to the buffer in the given encoding.
	 * @param buffer Buffer where to copy string content.
	 * @param size Destination buffer size.
	 * @param encoding Encoding name.
	 * @return Number of bytes copied to destination buffer.
	 */
	UInt													GetBytes( void* buffer, UInt size, const char* encoding ) const;

	/**
	 * Encodes string content to the buffer in the default encoding.
	 * @param buffer Buffer where to copy string content.
	 * @param size Destination buffer size.
	 * @return Number of bytes copied to destination buffer.
	 */
	UInt													GetBytes( void* buffer, UInt size ) const;

	/**
	 * Compares two strings.
	 * @param first First string to compare.
	 * @param second Second string to compare.
	 * @param ignoreCase Indicates whether to ignore text case.
	 * @return Return value is identical to that of strcmpi().
	 */
	static Int												Compare( const String& first, const String& second, Bool ignoreCase );

	/**
	 * Compares two strings. The comparison is case-sensitive.
	 * @param first First string to compare.
	 * @param second Second string to compare.
	 * @return Return value is identical to that of strcmp().
	 */
	static Int												Compare( const String& first, const String& second );

	/**
	 * Formats a text string with 1 argument.
	 * 
	 * Pattern syntax:
	 * <ul>
	 * <li>{0} = replaced with 1st argument formatted to string.
	 * <li>{1} = replaced with 2nd argument formatted to string.
	 * <li>{n} = replaced with nth argument formatted to string.
	 * <li>{0,l} = replaced with 1st argument formatted to lower case.
	 * <li>{0,u} = replaced with 1st argument formatted to upper case.
	 * <li>{0,q} = replaced with 1st argument formatted to quoted string.
	 * <li>{0,x} = replaced with 1st argument formatted to hex number.
	 * <li>{0,#.##} = replaced with 1st argument formatted to number using max 2 digits, e.g. 1.2=1.2 but 1.211=1.21.
	 * <li>{0,#.00} = replaced with 1st argument formatted to number using exactly 2 digits, e.g. 1.2=1.20 and 1.211=1.21.
	 * <li>{0,000} = replaced with 1st argument formatted to number using at least 3 numbers, padded with zeros, e.g. 3=003.
	 * <li>Date-time format specifiers: d, D, f, F, g, r, R, t, T, u, o.
	 * </ul>
	 * @param pattern Text pattern.
	 * @param arg0 1st argument.
	 * @return Formatted text string.
	 */
	static String											Format( const Char* pattern, const Formattable& arg0 );

	/**
	 * Formats a text string with 2 arguments.
	 * @param pattern Text pattern.
	 * @param arg0 1st argument.
	 * @param arg1 2nd argument.
	 * @return Formatted text string.
	 */
	static String											Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1 );

	/**
	 * Formats a text string with 3 arguments.
	 * @param pattern Text pattern.
	 * @param arg0 1st argument.
	 * @param arg1 2nd argument.
	 * @param arg2 3rd argument.
	 * @return Formatted text string.
	 */
	static String											Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2 );

	/**
	 * Formats a text string with 4 arguments.
	 * @param pattern Text pattern.
	 * @param arg0 1st argument.
	 * @param arg1 2nd argument.
	 * @param arg2 3rd argument.
	 * @param arg3 4th argument.
	 * @return Formatted text string.
	 */
	static String											Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3 );

	/**
	 * Formats a text string with 5 arguments.
	 * @param pattern Text pattern.
	 * @param arg0 1st argument.
	 * @param arg1 2nd argument.
	 * @param arg2 3rd argument.
	 * @param arg3 4th argument.
	 * @param arg4 5th argument.
	 * @return Formatted text string.
	 */
	static String											Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4 );

	/**
	 * Formats a text string with 6 arguments.
	 * @param pattern Text pattern.
	 * @param arg0 1st argument.
	 * @param arg1 2nd argument.
	 * @param arg2 3rd argument.
	 * @param arg3 4th argument.
	 * @param arg4 5th argument.
	 * @param arg5 6th argument.
	 * @return Formatted text string.
	 */
	static String											Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5 );

	/**
	 * Formats a text string with 7 arguments.
	 * @param pattern Text pattern.
	 * @param arg0 1st argument.
	 * @param arg1 2nd argument.
	 * @param arg2 3rd argument.
	 * @param arg3 4th argument.
	 * @param arg4 5th argument.
	 * @param arg5 6th argument.
	 * @param arg6 7th argument.
	 * @return Formatted text string.
	 */
	static String											Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6 );

	/**
	 * Formats a text string with 8 arguments.
	 * @param pattern Text pattern.
	 * @param arg0 1st argument.
	 * @param arg1 2nd argument.
	 * @param arg2 3rd argument.
	 * @param arg3 4th argument.
	 * @param arg4 5th argument.
	 * @param arg5 6th argument.
	 * @param arg6 7th argument.
	 * @param arg7 8th argument.
	 * @return Formatted text string.
	 */
	static String											Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7 );

	/**
	 * Formats a text string with 9 arguments.
	 * @param pattern Text pattern.
	 * @param arg0 1st argument.
	 * @param arg1 2nd argument.
	 * @param arg2 3rd argument.
	 * @param arg3 4th argument.
	 * @param arg4 5th argument.
	 * @param arg5 6th argument.
	 * @param arg6 7th argument.
	 * @param arg7 8th argument.
	 * @param arg8 9th argument.
	 * @return Formatted text string.
	 */
	static String											Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8 );

	/**
	 * Formats a text string with 10 arguments.
	 * @param pattern Text pattern.
	 * @param arg0 1st argument.
	 * @param arg1 2nd argument.
	 * @param arg2 3rd argument.
	 * @param arg3 4th argument.
	 * @param arg4 5th argument.
	 * @param arg5 6th argument.
	 * @param arg6 7th argument.
	 * @param arg7 8th argument.
	 * @param arg8 9th argument.
	 * @param arg9 10th argument.
	 * @return Formatted text string.
	 */
	static String											Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8, const Formattable& arg9 );

private:
	Impl*													_impl;
};


/**
 * Concatenates null-terminated ASCII-7 string with the Unicode string.
 * @param first null-terminated ASCII-7 string.
 * @param second Unicode string.
 * @return Concatenation of the two strings.
 */
SYNKRO_API String operator+( const char* first, const String& second );

/**
 * Tests two strings for equality.
 * @param first null-terminated ASCII-7 string.
 * @param second Unicode string.
 * @return True if null-terminated ASCII-7 string is equal to Unicode string.
 */
SYNKRO_API Bool operator==( const char* first, const String& second );

/**
 * Tests two strings for inequality.
 * @param first null-terminated ASCII-7 string.
 * @param second Unicode string.
 * @return True if null-terminated ASCII-7 string is equal to Unicode string.
 */
SYNKRO_API Bool operator!=( const char* first, const String& second );

/**
 * Compares two strings.
 * @param first null-terminated ASCII-7 string.
 * @param second Unicode string.
 * @return True if null-terminated ASCII-7 string is less then the Unicode string.
 */
SYNKRO_API Bool operator<( const char* first, const String& second );

/**
 * Compares two strings.
 * @param first null-terminated ASCII-7 string.
 * @param second Unicode string.
 * @return True if null-terminated ASCII-7 string is greater then the Unicode string.
 */
SYNKRO_API Bool operator>( const char* first, const String& second );

/**
 * Compares two strings.
 * @param first null-terminated ASCII-7 string.
 * @param second Unicode string.
 * @return True if null-terminated ASCII-7 string is less or equal then the Unicode string.
 */
SYNKRO_API Bool operator<=( const char* first, const String& second );

/**
 * Compares two strings.
 * @param first null-terminated ASCII-7 string.
 * @param second Unicode string.
 * @return True if null-terminated ASCII-7 string is greater or equal then the Unicode string.
 */
SYNKRO_API Bool operator>=( const char* first, const String& second );


} // lang


} // synkro


#endif // _SYNKRO_LANG_STRING_
