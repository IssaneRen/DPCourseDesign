#include "Time.h"


Time* Time::time_instance_ = 0;



Time::Time(int year, int month, int day, int hour)
	:Abstract(), year_(year), month_(month), day_(day), hour_(hour)
{
	time_overflow_check();
}


void Time::time_overflow_check(){
	if (hour_ > HOURS_PER_DAY){
		day_ += hour_ / HOURS_PER_DAY;
		hour_ = hour_%HOURS_PER_DAY;
	}
	if (day_ > DAYS_PER_MONTH){
		month_ += day_ / DAYS_PER_MONTH;
		day_ = day_ % DAYS_PER_MONTH;
	}
	if (month_ > MONTHS_PER_YEAR){
		year_ += month_ / MONTHS_PER_YEAR;
		month_ = month_%MONTHS_PER_YEAR;
	}
}

void Time::set_time(int time_containner[4]){
	year_ = time_containner[0];
	month_ = time_containner[1];
	day_ = time_containner[2];
	hour_ = time_containner[3];
	time_overflow_check();
}


void Time::get_time(int time_container[4]){
	time_container[0] = year_;
	time_container[1] = month_;
	time_container[2] = day_;
	time_container[3] = hour_;
}