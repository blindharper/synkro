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
	DateTime( UShort year, UShort month, UShort day, UShort hour, UShort minute, UShort second, UShort millisecond );

	/**
	 * Creates date with the specified year, month, day and time.
	 * @param year Year component of the date.
	 * @param month Month component of the date.
	 * @param day Day component of the date.
	 * @param hour Hour component of the time.
	 * @param minute Minutes component of the time.
	 * @param second Seconds component of the time.
	 */
	DateTime( UShort year, UShort month, UShort day, UShort hour, UShort minute, UShort second );

	/**
	 * Creates date with the specified year, month, day and time.
	 * @param year Year component of the date.
	 * @param month Month component of the date.
	 * @param day Day component of the date.
	 * @param hour Hour component of the time.
	 * @param minute Minutes component of the time.
	 */
	DateTime( UShort year, UShort month, UShort day, UShort hour, UShort minute );

	/**
	 * Creates date with the specified year, month, day and time.
	 * @param year Year component of the date.
	 * @param month Month component of the date.
	 * @param day Day component of the date.
	 * @param hour Hour component of the time.
	 */
	DateTime( UShort year, UShort month, UShort day, UShort hour );

	/**
	 * Creates date with the specified year, month and day.
	 * @param year Year component of the date.
	 * @param month Month component of the date.
	 * @param day Day component of the date.
	 */
	DateTime( UShort year, UShort month, UShort day );

	/**
	 * Creates invalid date.
	 */
	DateTime( UShort fake );

	/**
	 * Creates current date & time.
	 */
	DateTime();

	/**
	 * Retrieves year component of the date.
	 */
	UShort													Year() const;

	/**
	 * Retrieves month component of the date.
	 */
	UShort													Month() const;

	/**
	 * Retrieves day of week.
	 */
	UShort													DayOfWeek() const;

	/**
	 * Retrieves day component of the date.
	 */
	UShort													Day() const;

	/**
	 * Retrieves hour component of the time.
	 */
	UShort													Hour() const;

	/**
	 * Retrieves minutes component of the time.
	 */
	UShort													Minute() const;

	/**
	 * Retrieves seconds component of the time.
	 */
	UShort													Second() const;

	/**
	 * Retrieves milliseconds component of the time.
	 */
	UShort													Millisecond() const;

	/**
	 * Retrieves the total number of hours passed since the beginning of the day.
	 */
	Float													TotalHours() const;

	/**
	 * Retrieves the total number of minutes passed since the beginning of the current hour.
	 */
	Float													TotalMinutes() const;

	/**
	 * Retrieves the total number of seconds passed since the beginning of the current minute.
	 */
	Float													TotalSeconds() const;

	/**
	 * Returns true if two DateTime values are equal.
	 * @param other DateTime to compare to.
	 */
	Bool													operator==( const DateTime& other ) const;

	/**
	 * Returns true if two DateTime values are not equal.
	 * @param other DateTime to compare to.
	 */
	Bool													operator!=( const DateTime& other ) const;

	/**
	 * Indicates whether the date-time value represents a valid date.
	 */
	Bool													IsValid() const;

private:
	UShort													_value[8];
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_DATETIME_
