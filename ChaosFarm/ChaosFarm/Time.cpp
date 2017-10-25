#include "Time.h"


Time* Time::time_instance_ = 0;



Time::Time(int year, int month, int day, int hour)
	:Abstract(), year_(year), month_(month), day_(day), hour_(hour)
{
	time_overflow_check();
}


void Time::time_overflow_check(){
	if (hour_ >= HOURS_PER_DAY){
		day_ += hour_ / HOURS_PER_DAY;
		hour_ = hour_%HOURS_PER_DAY;
	}
	if (day_ >= DAYS_PER_MONTH){
		month_ += day_ / DAYS_PER_MONTH;
		day_ = day_ % DAYS_PER_MONTH;
	}
	if (month_ >= MONTHS_PER_YEAR){
		year_ += month_ / MONTHS_PER_YEAR;
		month_ = month_%MONTHS_PER_YEAR;
	}
}