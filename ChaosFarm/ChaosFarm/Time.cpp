#include "Time.h"


Time* Time::time_instance_ = 0;



Time::Time(int year, int month, int day, int hour)
	:Abstract(), year_(year), month_(month), day_(day), hour_(hour), d_hour_(0)
{
	time_overflow_check();
}



Time::Time(Time* time)
	:Abstract(time->get_observer_pool()), d_hour_(0)
{
	int time_container[4];
	time->get_time(time_container);
	year_ = time_container[0];
	month_ = time_container[1];
	day_ = time_container[2];
	hour_ = time_container[3];
}

Time* Time::instance(){
		{
			if (!time_instance_)
				time_instance_ = new Time();
			int time[4];
			time_instance_->get_time(time);
			if (time[3] >= 6 && time[3] <= 11)time_instance_ = MorningTime::create_morning_time(time_instance_);
			else if (time[3] >= 11 && time[3] <= 14)time_instance_ = NoonTime::create_noon_time(time_instance_);
			else if (time[3] >= 14 && time[3] <= 18)time_instance_ = AfternoonTime::create_afternoon_time(time_instance_);
			else time_instance_ = NightTime::create_night_time(time_instance_);
			return time_instance_;
		}
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


Time* Time::hour_pass(int n){
	hour_ += n;
	time_overflow_check();
	d_hour_ = n;
	notify();
	if (hour_ >= 6 && hour_ <= 11)time_instance_ = MorningTime::create_morning_time(time_instance_);
	else if (hour_ >= 11 && hour_ <= 14)time_instance_ = NoonTime::create_noon_time(time_instance_);
	else if (hour_ >= 14 && hour_ <= 18)time_instance_ = AfternoonTime::create_afternoon_time(time_instance_);
	else time_instance_ = NightTime::create_night_time(time_instance_);
	return time_instance_;
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
