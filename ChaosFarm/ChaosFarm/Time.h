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

//*
//*同时实现了Observer和State，并使得作为Singleton的此类可继承。
//*每当调用hour_pass，时间就会变动。
//*时间变动后，所有注册了的观察者就会对此作出反应，表现为调用自身的time_pass_by。
//*在time_pass_by内，观察者将会调用do_something并将指向自身的指针传递给此singleton。根据本singleton的状态（表现为time_instance_的类型不同）调用do_morning、do_noon……等函数。
class Time :public Abstract{

public:
	//*Singleton：取得时间实例。
	static Time* instance();

	//*取得年月日时格式的时间，存放在一个容量为4的数组内。
	void get_time(int time_container[4]);

	//*将年月日时格式的时间，存放在一个容量为4的数组内传入以修改时间
	void set_time(const int time_container[4]);

	//*表征时间过去的函数。
	//*n表示过去的小时数。
	//*将通知所有注册此subject的observer
	Time* hour_pass(int n = 1);

	//*根据当前的state，调用animal的不同函数。
	//*由于这是基类函数，故不应在运行时被调用。
	virtual void do_something(Animal* animal){
		cerr << "ERROR: You have come into the base class Time. which whill never happen if correct" << endl;
	}

	//*取得上一次调用hour_pass()时过去的小时数
	int get_d_hour(){ return d_hour_; }

	//*格式化地输出时间
	virtual void report(){
		cout << "Time: " << year_ << "," << month_ << "," << day_ << "---- " << hour_ << ":00" << endl;
	}

	~Time(){ }

	//*被重写的获取类名的函数，返回"Time"
	virtual const char* get_class_name(){ return "Time"; }

protected:

	//*通知函数，在hour_pass()中被调用，通知所有observer
	virtual void notify();

	//*年
	int year_;
	//*月
	int month_;
	//*日
	int day_;
	//*时
	int hour_;

	//*上一次调用hour_pass()时过去的小时数，初始为0
	int d_hour_;

	//*时间变动时调用以保持时间符合逻辑格式
	void time_overflow_check();

	//*构造函数，提供年月日时以构造对象
	Time(int year = 0, int month = 0, int day = 0, int hour = 6);

	//*用于time在不同的state之间变换时进行拷贝构造新对象
	Time(Time* time);

private:
	//*Singleton：静态的自身
	static Time* time_instance_;

	//*它的唯一工作就是在析构函数中删除Time的实例
	//*静态声明出的对象会在程序结束时被回收空间，并调用其析构函数
	//*借此释放state影响下扑朔迷离的time_instance_的空间
	class TimeReleaser
	{
	public:
		~TimeReleaser()
		{
			if (Time::time_instance_)

				delete Time::time_instance_;
		}
		static TimeReleaser garbo;
	};


};

//*State：Time的state之一，表征早上的时间段
class MorningTime :public Time{
public:

	~MorningTime(){}

	//*拷贝原本的time实例的内部信息后，消灭原本的time实例，并返回新创建的实例
	//*注意：需要将此函数的返回值赋值给time_instance_或与之等价的指针，以达成State的变换
	static MorningTime* create_morning_time(Time* time){ 
		Time* to_delete = time;
		time = new MorningTime(time);
		delete to_delete;
		return (MorningTime*)time;
	}

	//*State：早晨。调用表征动物早晨行动的函数
	virtual void do_something(Animal* ani){
		ani->do_morning();
	}

	//*报时函数
	virtual void report(){
		format_output("MorningTime::report()", "it is morning now");
		Time::report();
	}

protected:
	MorningTime(Time* time):Time(time){}
};

//*State：Time的state之一，表征中午的时间段
class NoonTime :public Time{
public:
	~NoonTime(){}

	//*拷贝原本的time实例的内部信息后，消灭原本的time实例，并返回新创建的实例
	//*注意：需要将此函数的返回值赋值给time_instance_或与之等价的指针，以达成State的变换
	static NoonTime* create_noon_time(Time* time){
		Time* to_delete = time;
		time = new NoonTime(time);
		delete to_delete;
		return (NoonTime*)time;
	}

	//*State：早晨。调用表征动物中午行动的函数
	virtual void do_something(Animal* ani){
		ani->do_noon();
	}

	//*报时函数
	virtual void report(){
		format_output("NoonTime::report()", "it is noon now");
		Time::report();
	}
protected:
	NoonTime(Time* time) :Time(time){}
};

//*State：Time的state之一，表征下午的时间段
class AfternoonTime :public Time{
public:
	~AfternoonTime(){}

	//*拷贝原本的time实例的内部信息后，消灭原本的time实例，并返回新创建的实例
	//*注意：需要将此函数的返回值赋值给time_instance_或与之等价的指针，以达成State的变换
	static AfternoonTime* create_afternoon_time(Time* time){
		Time* to_delete = time;
		time = new AfternoonTime(time);
		delete to_delete;
		return (AfternoonTime*)time;
	}

	//*State：早晨。调用表征动物下午行动的函数
	virtual void do_something(Animal* ani){
		ani->do_afternoon();
	}

	//*报时函数
	virtual void report(){
		format_output("AfternoonTime::report()", "it is afternoon now");
		Time::report();
	}
protected:
	AfternoonTime(Time* time) :Time(time){}
};


//*State：Time的state之一，表征晚上的时间段
class NightTime :public Time{
public:
	~NightTime(){}

	//*拷贝原本的time实例的内部信息后，消灭原本的time实例，并返回新创建的实例
	//*注意：需要将此函数的返回值赋值给time_instance_或与之等价的指针，以达成State的变换
	static NightTime* create_night_time(Time* time){
		Time* to_delete = time;
		time = new NightTime(time);
		delete to_delete;
		return (NightTime*)time;
	}

	//*State：早晨。调用表征动物晚上行动的函数
	virtual void do_something(Animal* ani){
		ani->do_night();
	}

	//*报时函数
	virtual void report(){
		format_output("NightTime::report()", "it is night now");
		Time::report();
	}
protected:
	NightTime(Time* time) :Time(time){}
};



#endif