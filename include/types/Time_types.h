#ifndef __TIME_TYPES_H__
#define __TIME_TYPES_H__

#include "..\\include\types\Basic_types.h"

/**
  * A time in hours.
  */
typedef FUint32 THour;

/**
  * A time in minutes.
  */
typedef FUint32 TMinute;

/**
  * A time in seconds.
  */
typedef FUint32 TSecond;

/**
  * A time in milliseconds. 
  */
typedef FUint32 TMillisecond;

/**
  * A time in microseconds.
  */
typedef FUint32 TMicrosecond;

/**
  * A time in nanoseconds.
  */
typedef FUint32 TNanosecond;

/**
  * A time in Universal Time Coordinated (UTC).
  * This value is the number of seconds elapsed since January 1, 1970, 00:00:00 GMT.
  */
typedef FUint32 TUtcTime;


/**
  * Enumerates the months.
  *
  * @param MONTH_JANUARY    Represent month January.
  * @param MONTH_FEBRUARY   Represent month February.
  * @param MONTH_MARCH      Represent month March.
  * @param MONTH_MARS       Represent month March, obsolete.
  * @param MONTH_APRIL      Represent month April.
  * @param MONTH_MAY        Represent month May.
  * @param MONTH_JUNE       Represent month June.
  * @param MONTH_JULY       Represent month July.
  * @param MONTH_AUGUST     Represent month August.
  * @param MONTH_SEPTEMBER  Represent month September.
  * @param MONTH_OCTOBER    Represent month October.
  * @param MONTH_NOVEMBER   Represent month November.
  * @param MONTH_DECEMBER   Represent month December.
  */
typedef enum
{
  MONTH_JANUARY = 1,
  MONTH_FEBRUARY,
  MONTH_MARCH,
  MONTH_MARS = MONTH_MARCH,
  MONTH_APRIL,
  MONTH_MAY,
  MONTH_JUNE,
  MONTH_JULY,
  MONTH_AUGUST,
  MONTH_SEPTEMBER,
  MONTH_OCTOBER,
  MONTH_NOVEMBER,
  MONTH_DECEMBER
} TMonth;

/**
  * Enumerates the weekdays Monday, Tuesday, Wednesday, Thursday, Friday
  * Saturday and Sunday.
  *
  * @param WEEKDAY_MONDAY     Represent weekday Monday.
  * @param WEEKDAY_TUESDAY    Represent weekday Tuesday.
  * @param WEEKDAY_WEDNESDAY  Represent weekday Wednesday.
  * @param WEEKDAY_THURSDAY   Represent weekday Thursday.
  * @param WEEKDAY_FRIDAY     Represent weekday Friday.
  * @param WEEKDAY_SATURDAY   Represent weekday Saturday.
  * @param WEEKDAY_SUNDAY     Represent weekday Sunday.
  */
typedef enum
{
  WEEKDAY_MONDAY = 0,
  WEEKDAY_TUESDAY,
  WEEKDAY_WEDNESDAY,
  WEEKDAY_THURSDAY,
  WEEKDAY_FRIDAY,
  WEEKDAY_SATURDAY,
  WEEKDAY_SUNDAY
} TWeekday;

/**
  * This type is used to store a date, which consists of year, month and day, e.g. 2003 February 10.
  * 
  * @param  Year      A year, full year e.g. 2003.
  * @param  Month     A month from the enum TMonth.
  * @param  Day       A day, between 1 and 31.
  * 
  */
typedef struct
{
  FUint16 Year;   
  TMonth  Month;  
  FUint8  Day;    
} TDate;

/**
  * The day time, expressed in hours, minutes and seconds.
  * 
  * @param  Hours   An hour, between 0 and 23.
  * @param  Minutes A minute, between 0 and 59.
  * @param  Seconds A second, between 0 and 59.
  * @param  Milliseconds A millisecond, between 0 and 999.
  */
typedef struct
{
  FUint8  Hours;  
  FUint8  Minutes;
  FUint8  Seconds;
  FUint16 Milliseconds;
} TDayTime;


/**
  * This type represents both the time and the date.
  *
  * @param Date     The date expressed in year, month and day.
  * @param DayTime  The time expressed in hours, minutes, seconds and milliseconds.
  */
typedef struct
{
  TDate     Date;
  TDayTime  DayTime;
} TDateAndTime;

#endif
