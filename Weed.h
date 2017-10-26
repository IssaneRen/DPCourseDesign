#pragma once
#ifndef CF_WEED_H
#define CF_WEED_H
#include "Plant.h"
#include "WeedStrategy.h"

class Weed : public Plant
{
public:
	enum StrategyType
	{
		Dummy,Sing,Dance,Chat
	};

	Weed(vector<Abstract*>* abs_list, int size, int max_age, string* name, SEX sex);

	~Weed() {}
	void grow() ;
	virtual void die()  ;
	virtual Living* mate_with(Living* another) { return NULL; }
	virtual void bloom()  ;
	virtual void photoshythesize() ;  //光合作用
	virtual void water_absorb();
	virtual void breath(Atmosphere* atm) ;
	virtual void time_pass_by() ;
	virtual void when_atmosphere_changed() ;
	virtual void update(Abstract* abs, AbstractType type) ;

	void setStrategy(int type);
	void doIt();
	
protected:
	WeedStrategy* strategy_;
};


#endif