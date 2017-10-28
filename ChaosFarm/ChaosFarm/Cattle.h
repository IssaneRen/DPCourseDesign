#ifndef CF_CATTLE_H_
#define CF_CATTLE_H_
#include "Mammals.h"

class Cattle final: public Mammals{
public:

	Cattle(vector<Abstract*>* abs_list, int size, int max_age);

	~Cattle() {}
    
	void time_pass_by();

	void when_atmosphere_changed();

	void die();

	void breath(Atmosphere* atm);

	void grow();

	bool eat(Entity* food);

	void cry();

	bool drink();

	void produce_milk();

	void farrow();

	virtual void do_morning(){}

	virtual void do_noon(){}

	virtual void do_afternoon(){}

	virtual void do_night(){}
};

#endif 
