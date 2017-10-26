#ifndef CF_TIME_H
#define CF_TIME_H
#include "Abstract.h"

#define HOURS_PER_DAY 24
#define DAYS_PER_MONTH 30
#define MONTHS_PER_YEAR 12


class Time final:Abstract{
public:
	static Time* instance(){
		if (!time_instance_)
			time_instance_ = new Time();
		return time_instance_;
	}


	void get_time(int time_container[4]);

	void set_time(int time_container[4]);

	void hour_pass(int n = 1){
		hour_ += n;
		time_overflow_check(); 
		d_hour_ = n;
		notify();
	}

	int get_d_hour(){ return d_hour_; }

	virtual void report(){
		cout << "Time: " << year_ << "," << month_ << "," << day_ << "---- " << hour_ << endl;
	}

private:
	Time(int year = 0, int month = 0, int day = 0, int hour = 0);

	~Time(){ if (time_instance_)delete time_instance_; }

	int year_;
	int month_;
	int day_;
	int hour_;

	int d_hour_;

	static Time* time_instance_;

	void time_overflow_check();
};




#endif