#ifndef CF_ANIMAL_H
#define CF_ANIMAL_H
#include "Living.h"

class Animal :public	Living{
public:
	Animal(vector<Abstract*>* abs_list, int size, int max_age, SEX sex);

	~Animal(){}

	virtual bool eat(Entity* food);



	virtual void cry() = 0;

	virtual bool drink();

	virtual void time_pass_by() = 0;

	virtual void when_atmosphere_changed() = 0;


	virtual void update(AbstractType type){
		switch (type)
		{
		case ERROR:
			break;
		case TIME:time_pass_by();
			break;
		case ATMOSPHERE:when_atmosphere_changed();
			break;
		default:
			break;
		}
	}

	virtual void die() = 0;

	virtual Living* mate_with(vector<Abstract*>* abs_list, Living* another) = 0;								 //交配函数，与另一个生物进行交配，返回所生子代个体的指针

	virtual void breath(Atmosphere* atm) = 0;										 //呼吸函数。调用改变atm二氧化碳和氧气浓度的函数

	virtual void grow() = 0;															//生长函数。随时间增长年龄

protected:
	int hunger_;				//饱腹�?
	int thirsty_;
};


#endif