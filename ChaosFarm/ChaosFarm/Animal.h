#ifndef CF_ANIMAL_H
#define CF_ANIMAL_H
#include "Living.h"


//*表征动物的类，继承自Living，因而也是Observer。
//*会对时间Subject——Time的前进做出反应，根据所处时间段不同（早上、中午、下午、晚上）会做出不同的动作。
class Animal :public Living{
public:
	//*abs_list：需要注册的subject列表。
	//*size：该动物的大小。
	//*max_age：该动物的最大年龄。
	Animal(vector<Abstract*>* abs_list = NULL, int size = 0, int max_age = 100);

	virtual ~Animal(){}

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

	//*行为函数。
	//*睡觉
	virtual void sleep(){ format_output("Animal::sleep()", "zzz..."); }

	//*行为函数。
	//*鸣叫。
	virtual void cry(){
		format_output("Animal::cry()", "is crying");
	}

	//*行为函数。
	//*喝水。
	virtual void drink(){
		format_output("Animal::drink()", "is driking");
	}

	//*反应函数。当时间流逝时，由update()调用此函数。
	//*注意：纯虚
	virtual void time_pass_by() = 0;

	//*反应函数。当天气变化时，由update()调用此函数。
	//*注意：纯虚
	virtual void when_atmosphere_changed() = 0;		

	//*被重写的获取类名的函数，返回"Animal"
	virtual const char* get_class_name(){ return "Living"; }
};


#endif