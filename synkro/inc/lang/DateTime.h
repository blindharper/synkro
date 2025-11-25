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
// Purpose: Defines date-time value.
//==============================================================================
#ifndef _SYNKRO_LANG_DATETIME_
#define _SYNKRO_LANG_DATETIME_


#include "config.h"


namespace synkro
{


namespace lang
{


/**
 * Date-time value.
 */
class SYNKRO_API DateTime
{
public:
	/**
	 * Invalid date-time.
	 */
	static const DateTime									Invalid;

	/**
	 * Creates date with the specified year, month, day and time.
	 * @param year Year component of the date.
	 * @param month Month component of the date.
	 * @param day Day component of the date.
	 * @param hour Hour component of the time.
	 * @param minute Minutes component of the time.
	 * @param second Seconds component of the time.
	 * @param millisecond Millseconds component of the time.
	 */
	DateTime( UShort year, UShort month, UShort day, UShort hour, UShort minute, UShort second, UShort millisecond ) SYNKRO_NOEXCEPT;

	/**
	 * Creates date with the specified year, month, day and time.
	 * @param year Year component of the date.
	 * @param month Month component of the date.
	 * @param day Day component of the date.
	 * @param hour Hour component of the time.
	 * @param minute Minutes component of the time.
	 * @param second Seconds component of the time.
	 */
	DateTime( UShort year, UShort month, UShort day, UShort hour, UShort minute, UShort second ) SYNKRO_NOEXCEPT;

	/**
	 * Creates date with the specified year, month, day and time.
	 * @param year Year component of the date.
	 * @param month Month component of the date.
	 * @param day Day component of the date.
	 * @param hour Hour component of the time.
	 * @param minute Minutes component of the time.
	 */
	DateTime( UShort year, UShort month, UShort day, UShort hour, UShort minute ) SYNKRO_NOEXCEPT;

	/**
	 * Creates date with the specified year, month, day and time.
	 * @param year Year component of the date.
	 * @param month Month component of the date.
	 * @param day Day component of the date.
	 * @param hour Hour component of the time.
	 */
	DateTime( UShort year, UShort month, UShort day, UShort hour ) SYNKRO_NOEXCEPT;

	/**
	 * Creates date with the specified year, month and day.
	 * @param year Year component of the date.
	 * @param month Month component of the date.
	 * @param day Day component of the date.
	 */
	DateTime( UShort year, UShort month, UShort day ) SYNKRO_NOEXCEPT;

	/**
	 * Creates invalid date.
	 */
	DateTime( UShort fake ) SYNKRO_NOEXCEPT;

	/**
	 * Creates current date & time.
	 */
	DateTime() SYNKRO_NOEXCEPT;

	/**
	 * Retrieves year component of the date.
	 */
	UShort													Year() const SYNKRO_NOEXCEPT;

	/**
	 * Retrieves month component of the date.
	 */
	UShort													Month() const SYNKRO_NOEXCEPT;

	/**
	 * Retrieves day of week.
	 */
	UShort													DayOfWeek() const SYNKRO_NOEXCEPT;

	/**
	 * Retrieves day component of the date.
	 */
	UShort													Day() const SYNKRO_NOEXCEPT;

	/**
	 * Retrieves hour component of the time.
	 */
	UShort													Hour() const SYNKRO_NOEXCEPT;

	/**
	 * Retrieves minutes component of the time.
	 */
	UShort													Minute() const SYNKRO_NOEXCEPT;

	/**
	 * Retrieves seconds component of the time.
	 */
	UShort													Second() const SYNKRO_NOEXCEPT;

	/**
	 * Retrieves milliseconds component of the time.
	 */
	UShort													Millisecond() const SYNKRO_NOEXCEPT;

	/**
	 * Retrieves the total number of hours passed since the beginning of the day.
	 */
	Float													TotalHours() const SYNKRO_NOEXCEPT;

	/**
	 * Retrieves the total number of minutes passed since the beginning of the current hour.
	 */
	Float													TotalMinutes() const SYNKRO_NOEXCEPT;

	/**
	 * Retrieves the total number of seconds passed since the beginning of the current minute.
	 */
	Float													TotalSeconds() const SYNKRO_NOEXCEPT;

	/**
	 * Returns true if two DateTime values are equal.
	 * @param other DateTime to compare to.
	 */
	Bool													operator==( const DateTime& other ) const SYNKRO_NOEXCEPT;

	/**
	 * Returns true if two DateTime values are not equal.
	 * @param other DateTime to compare to.
	 */
	Bool													operator!=( const DateTime& other ) const SYNKRO_NOEXCEPT;

	/**
	 * Indicates whether the date-time value represents a valid date.
	 */
	Bool													IsValid() const SYNKRO_NOEXCEPT;

private:
	UShort													_value[8];
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_DATETIME_
