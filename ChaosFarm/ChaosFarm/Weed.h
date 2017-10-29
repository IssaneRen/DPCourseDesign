#pragma once
#ifndef CF_WEED_H
#define CF_WEED_H
#include "Plant.h"
#include "WeedStrategy.h"
#include "Atmosphere.h"
#include "Crop.h"
#include "Time.h"

enum StrategyType
{
	Dummy, Sing, Dance, Chat
};

class Weed : public Plant
{
public:

	Weed(vector<Abstract*>* abs_list, int size, int max_age);

	~Weed() {}
	void grow();                                                     //杂草生长函数 
	virtual void bloom();                                            //杂草开花函数
	virtual void photosynthesis();                                   //杂草光合作用函数
	virtual void water_absorb();                                     //杂草吸水函数
	virtual void breath();                                           //杂草呼吸函数
	virtual void attack(Crop* crop);                                 //杂草攻击庄稼函数
	void set_strategy(StrategyType type);                             //杂草不同动作的策略
	void do_it(StrategyType type);                                    //杂草进行不同动作

	//*被重写的获取类名的函数，返回"Weed"
	virtual const char* get_class_name(){ return "Weed"; }
	
protected:
	WeedStrategy* strategy_;

	//*反应函数。当时间流逝时，由update()调用此函数。
	virtual void time_pass_by();

	//*反应函数。当天气变化时，由update()调用此函数。
	virtual void when_atmosphere_changed();
};


#endif