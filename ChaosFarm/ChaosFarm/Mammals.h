#ifndef CF_MAMMALS_H_
#define CF_MAMMALS_H_
#include "Animal.h"
#include "Time.h"

//*表征哺乳动物的类。继承自Animal，因而也是Observer
class Mammals :public Animal {
public:

	//*abs_list：需要注册的subject列表。
	//*size：该动物的大小。
	//*max_age：该动物的最大年龄。
	Mammals(vector<Abstract*>* abs_list = NULL, int size = 10, int max_age = 200) :Animal(abs_list, size, max_age) {}

	~Mammals() {}

	//*纯虚函数的实现。
	//*根据时间流逝的长度，增长年龄
	//*年龄达到最大值时，将会死亡。
	virtual void grow(){
		age_ += Time::instance()->get_d_hour();
		if (age_ >= max_age_)die();
	}

	//*反应函数。当时间流逝时，由update()调用此函数。
	//*在判断对象依然活着的时候，会根据目前所处的时间段做一些事情。
	virtual void time_pass_by(){ if (alive_) { Time::instance()->do_something(this); grow(); } }

	//*反应函数。当天气变化时，由update()调用此函数。
	//*在判断对象依然活着的时候，会根据变化后的天气类型做一些事情。
	virtual void when_atmosphere_changed(){
		if (alive_){
			Atmosphere* atm = Atmosphere::getInstance();
			switch (atm->get_weather_type()){
			case SUNNY:format_output("Mammals::when_atmosphere_changed()", "is enjoying the sunshine"); break;
			case WINDY:format_output("Mammals::when_atmosphere_changed()", "is walking briefly."); break;
			case RAINY:format_output("Mammals::when_atmosphere_changed()", "try to take a shelter from rain"); break;
			case CLOUDY:format_output("Mammals::when_atmosphere_changed()", "seems unhappy"); break;
			default:break;
			}
		}
	}

	//*行为函数
	//*奔跑
	void run(){
		format_output("Mammals::run()", "is running");
	}

	//*行为函数。
	//*产奶
	virtual void produce_milk(){
		format_output("Mammals::produce_milk()", "is producing milk");
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

	//*被重写的获取类名的函数，返回"Mammals"
	virtual const char* get_class_name(){ return "Mammals"; }
};
#endif 

