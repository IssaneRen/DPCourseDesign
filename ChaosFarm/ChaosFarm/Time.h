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
//*ͬʱʵ����Observer��State����ʹ����ΪSingleton�Ĵ���ɼ̳С�
//*ÿ������hour_pass��ʱ��ͻ�䶯��
//*ʱ��䶯������ע���˵Ĺ۲��߾ͻ�Դ�������Ӧ������Ϊ���������time_pass_by��
//*��time_pass_by�ڣ��۲��߽������do_something����ָ�������ָ�봫�ݸ���singleton�����ݱ�singleton��״̬������Ϊtime_instance_�����Ͳ�ͬ������do_morning��do_noon�����Ⱥ�����
class Time :public Abstract{

public:
	//*Singleton��ȡ��ʱ��ʵ����
	static Time* instance();

	//*ȡ��������ʱ��ʽ��ʱ�䣬�����һ������Ϊ4�������ڡ�
	void get_time(int time_container[4]);

	//*��������ʱ��ʽ��ʱ�䣬�����һ������Ϊ4�������ڴ������޸�ʱ��
	void set_time(const int time_container[4]);

	//*����ʱ���ȥ�ĺ�����
	//*n��ʾ��ȥ��Сʱ����
	//*��֪ͨ����ע���subject��observer
	Time* hour_pass(int n = 1);

	//*���ݵ�ǰ��state������entity�Ĳ�ͬ������
	//*�������ǻ��ຯ�����ʲ�Ӧ������ʱ�����á�
	virtual void do_something(Animal* animal){
		cerr << "ERROR: You have come into the base class Time. which whill never happen if correct" << endl;
	}

	//*ȡ����һ�ε���hour_pass()ʱ��ȥ��Сʱ��
	int get_d_hour(){ return d_hour_; }

	//*��ʽ�������ʱ��
	virtual void report(){
		cout << "Time: " << year_ << "," << month_ << "," << day_ << "---- " << hour_ << ":00" << endl;
	}

	~Time(){ }

	//*����д�Ļ�ȡ�����ĺ���������"Time"
	virtual const char* get_class_name(){ return "Time"; }

protected:

	//*֪ͨ��������hour_pass()�б����ã�֪ͨ����observer
	virtual void notify();

	//*��
	int year_;
	//*��
	int month_;
	//*��
	int day_;
	//*ʱ
	int hour_;

	//*��һ�ε���hour_pass()ʱ��ȥ��Сʱ������ʼΪ0
	int d_hour_;

	//*ʱ��䶯ʱ�����Ա���ʱ������߼���ʽ
	void time_overflow_check();

	//*���캯�����ṩ������ʱ�Թ������
	Time(int year = 0, int month = 0, int day = 0, int hour = 6);

	//*����time�ڲ�ͬ��state֮��任ʱ���п��������¶���
	Time(Time* time);

private:
	//*Singleton����̬������
	static Time* time_instance_;

	//*����Ψһ��������������������ɾ��Time��ʵ��
	//*��̬�������Ķ�����ڳ������ʱ�����տռ䣬����������������
	//*����ͷ�stateӰ������˷�����time_instance_�Ŀռ�
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

//*State��Time��state֮һ���������ϵ�ʱ���
class MorningTime :public Time{
public:

	~MorningTime(){}

	//*����ԭ����timeʵ�����ڲ���Ϣ������ԭ����timeʵ�����������´�����ʵ��
	//*ע�⣺��Ҫ���˺����ķ���ֵ��ֵ��time_instance_����֮�ȼ۵�ָ�룬�Դ��State�ı任
	static MorningTime* create_morning_time(Time* time){ 
		Time* to_delete = time;
		time = new MorningTime(time);
		delete to_delete;
		return (MorningTime*)time;
	}

	//*State���糿�����ñ��������糿�ж��ĺ���
	virtual void do_something(Animal* ani){
		ani->do_morning();
	}

	//*��ʱ����
	virtual void report(){
		format_output("MorningTime::report()", "it is morning now");
		Time::report();
	}

protected:
	MorningTime(Time* time):Time(time){}
};

//*State��Time��state֮һ�����������ʱ���
class NoonTime :public Time{
public:
	~NoonTime(){}

	//*����ԭ����timeʵ�����ڲ���Ϣ������ԭ����timeʵ�����������´�����ʵ��
	//*ע�⣺��Ҫ���˺����ķ���ֵ��ֵ��time_instance_����֮�ȼ۵�ָ�룬�Դ��State�ı任
	static NoonTime* create_noon_time(Time* time){
		Time* to_delete = time;
		time = new NoonTime(time);
		delete to_delete;
		return (NoonTime*)time;
	}

	//*State���糿�����ñ������������ж��ĺ���
	virtual void do_something(Animal* ani){
		ani->do_noon();
	}

	//*��ʱ����
	virtual void report(){
		format_output("NoonTime::report()", "it is noon now");
		Time::report();
	}
protected:
	NoonTime(Time* time) :Time(time){}
};

//*State��Time��state֮һ�����������ʱ���
class AfternoonTime :public Time{
public:
	~AfternoonTime(){}

	//*����ԭ����timeʵ�����ڲ���Ϣ������ԭ����timeʵ�����������´�����ʵ��
	//*ע�⣺��Ҫ���˺����ķ���ֵ��ֵ��time_instance_����֮�ȼ۵�ָ�룬�Դ��State�ı任
	static AfternoonTime* create_afternoon_time(Time* time){
		Time* to_delete = time;
		time = new AfternoonTime(time);
		delete to_delete;
		return (AfternoonTime*)time;
	}

	//*State���糿�����ñ������������ж��ĺ���
	virtual void do_something(Animal* ani){
		ani->do_afternoon();
	}

	//*��ʱ����
	virtual void report(){
		format_output("AfternoonTime::report()", "it is afternoon now");
		Time::report();
	}
protected:
	AfternoonTime(Time* time) :Time(time){}
};


//*State��Time��state֮һ���������ϵ�ʱ���
class NightTime :public Time{
public:
	~NightTime(){}

	//*����ԭ����timeʵ�����ڲ���Ϣ������ԭ����timeʵ�����������´�����ʵ��
	//*ע�⣺��Ҫ���˺����ķ���ֵ��ֵ��time_instance_����֮�ȼ۵�ָ�룬�Դ��State�ı任
	static NightTime* create_night_time(Time* time){
		Time* to_delete = time;
		time = new NightTime(time);
		delete to_delete;
		return (NightTime*)time;
	}

	//*State���糿�����ñ������������ж��ĺ���
	virtual void do_something(Animal* ani){
		ani->do_night();
	}

	//*��ʱ����
	virtual void report(){
		format_output("NightTime::report()", "it is night now");
		Time::report();
	}
protected:
	NightTime(Time* time) :Time(time){}
};



#endif