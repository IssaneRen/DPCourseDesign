#ifndef CF_TIME_H
#define CF_TIME_H
#include "Abstract.h"
#include "Animal.h"
#define HOURS_PER_DAY 24
#define DAYS_PER_MONTH 30
#define MONTHS_PER_YEAR 12
class Time;
class Animal;

enum PeriodType{
	MORNING,
	NOON,
	AFTERNOON,
	NIGHT
};


//同时实现了Observer和State，并使得作为Singleton的此类可继承。
//每当调用hour_pass，时间就会变动。
//时间变动后，所有注册了的观察者就会对此作出反应，表现为调用自身的time_pass_by。
//在time_pass_by内，观察者将会调用do_something并将指向自身的指针传递给此singleton。根据本singleton的状态（表现为time_instance_的类型不同）调用do_morning、do_noon……等函数。
class Time :public Abstract{

public:
	static Time* instance();


	void get_time(int time_container[4]);



	void set_time(int time_container[4]);

	Time* hour_pass(int n = 1);

	virtual void do_something(Animal* animal){
		cout << "An animal tried to do something in this Time:";
		report();
	}

	int get_d_hour(){ return d_hour_; }

	virtual void report(){
		cout << "Time: " << year_ << "," << month_ << "," << day_ << "---- " << hour_ << ":00" << endl;
	}

	~Time(){ }

protected:


	virtual void notify();

	int year_;
	int month_;
	int day_;
	int hour_;

	int d_hour_;

	void time_overflow_check();


	Time(int year = 0, int month = 0, int day = 0, int hour = 6);

	Time(Time* time);

private:
	static Time* time_instance_;

	class CGarbo //它的唯一工作就是在析构函数中删除Time的实例
	{
	public:
		~CGarbo()
		{
			if (Time::time_instance_)

				delete Time::time_instance_;
		}
		static CGarbo garbo;
	};


};


class MorningTime :public Time{
public:

	~MorningTime(){}

	static MorningTime* create_morning_time(Time* time){ 
		Time* to_delete = time;
		time = new MorningTime(time);
		delete to_delete;
		return (MorningTime*)time;
	}

	virtual void do_something(Animal* ani){
		ani->do_morning();
	}

	virtual void report(){
		cout << "It's morning now." << endl;
		Time::report();
	}

protected:
	MorningTime(Time* time):Time(time){}
};


class NoonTime :public Time{
public:
	~NoonTime(){}

	static NoonTime* create_noon_time(Time* time){
		Time* to_delete = time;
		time = new NoonTime(time);
		delete to_delete;
		return (NoonTime*)time;
	}

	virtual void do_something(Animal* ani){
		ani->do_noon();
	}

	virtual void report(){
		cout << "It's noon now." << endl;
		Time::report();
	}
protected:
	NoonTime(Time* time) :Time(time){}
};


class AfternoonTime :public Time{
public:
	~AfternoonTime(){}

	static AfternoonTime* create_afternoon_time(Time* time){
		Time* to_delete = time;
		time = new AfternoonTime(time);
		delete to_delete;
		return (AfternoonTime*)time;
	}

	virtual void do_something(Animal* ani){
		ani->do_afternoon();
	}

	virtual void report(){
		cout << "It's afternoon now." << endl;
		Time::report();
	}
protected:
	AfternoonTime(Time* time) :Time(time){}
};

class NightTime :public Time{
public:
	~NightTime(){}

	static NightTime* create_night_time(Time* time){
		Time* to_delete = time;
		time = new NightTime(time);
		delete to_delete;
		return (NightTime*)time;
	}

	virtual void do_something(Animal* ani){
		ani->do_night();
	}

	virtual void report(){
		cout << "It's night now." << endl;
		Time::report();
	}
protected:
	NightTime(Time* time) :Time(time){}
};



#endif