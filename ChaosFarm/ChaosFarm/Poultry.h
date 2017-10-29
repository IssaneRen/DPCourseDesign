#ifndef CF_POULTRY_H_
#define CF_POULTRY_H_
#include "Animal.h"
#include "Time.h"

//*表征家禽动物的类。继承自Animal，因而也是Observer
class Poultry :public Animal {
public:

	//*abs_list：需要注册的subject列表。
	//*size：该动物的大小。
	//*max_age：该动物的最大年龄。
	Poultry(vector<Abstract*>* abs_list, int size, int max_age) :Animal(abs_list, size, max_age) {}

	~Poultry() {}

	//*纯虚函数的实现。
	//*根据时间流逝的长度，增长年龄
	//*年龄达到最大值时，将会死亡。
	virtual void grow(){
		age_ += Time::instance()->get_d_hour();
		if (age_ >= max_age_)die();
	}

	//*反应函数。当时间流逝时，由update()调用此函数。
	//*在判断对象依然活着的时候，会根据目前所处的时间段做一些事情。
	virtual void time_pass_by(){ if (alive_){ Time::instance()->do_something(this); grow(); } }

	//*反应函数。当天气变化时，由update()调用此函数。
	//*在判断对象依然活着的时候，会根据变化后的天气类型做一些事情。
	virtual void when_atmosphere_changed(){
		Atmosphere* atm = Atmosphere::getInstance();
		switch (atm->get_weather_type()){
		case SUNNY:format_output("Poultry::when_atmosphere_changed()", "is enjoying the sunshine"); break;
		case WINDY:format_output("Poultry::when_atmosphere_changed()", "is feeling the wind"); break;
		case RAINY:format_output("Poultry::when_atmosphere_changed()", "try to take a shelter from rain"); break;
		case CLOUDY:format_output("Poultry::when_atmosphere_changed()", "is not happy"); break;
		default:break;
		}
	}

	
	//*行为函数。
	//*飞来飞去
	void fly(){ cout << "Poultry:" << id_ << ":fly(): A poultry is flying." << endl; }


	virtual void lay_egg(){
		format_output("Poultry::lay_egg()", "is laying eggs.");
	}

	//*行为函数。
	//*孵蛋
	virtual void incubate(){
		format_output("Poultry::incubate()", "is incubating.");
	}
	//*反应函数。
	//*表征此动物在早晨时做的事情。
	virtual void do_morning() = 0;

	//*反应函数。
	//*表征此动物在中午时做的事情。
	virtual void do_noon() = 0;

	//*反应函数。
	//*表征此动物在下午时做的事情。
	virtual void do_afternoon() = 0;

	//*反应函数。
	//*表征此动物在晚上时做的事情。
	virtual void do_night() = 0;

	//*被重写的获取类名的函数，返回"Poultry"
	virtual const char* get_class_name(){ return "Poultry"; }



};
#endif 

