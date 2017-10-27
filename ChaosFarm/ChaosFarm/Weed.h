#pragma once
#ifndef CF_WEED_H
#define CF_WEED_H
#include "Plant.h"
#include "WeedStrategy.h"
#include "Atmosphere.h"
#include "Crop.h"

class Weed : public Plant
{
public:
	enum StrategyType
	{
		Dummy,Sing,Dance,Chat
	};

	Weed(vector<Abstract*>* abs_list, int size, int max_age, SEX sex );

	~Weed() {}
	void grow() ;
	virtual void die()  ;
	virtual Living* mate_with(vector<Abstract*>* abs_list, Living* another) { return NULL; }
	virtual void bloom()  ;
	virtual void photoshythesize() ;         //光合作用
	virtual void water_absorb(); 
	virtual void breath() ;
	virtual void time_pass_by() ;
	virtual void when_atmosphere_changed() ;
	virtual void update(Abstract* abs, AbstractType type) ;

	virtual void attack(Crop* crop);        //攻击庄稼
	void setStrategy(StrategyType type);             
	void doIt();                            //杂草的不同动作
	
protected:
	WeedStrategy* strategy_;
};


#endif