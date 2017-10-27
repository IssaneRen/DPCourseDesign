#ifndef CF_CATTLE_H_
#define CF_CATTLE_H_
#include "Mammals.h"

class Cattle final: public Mammals{
public:

	Cattle(vector<Abstract*>* abs_list, int size, int max_age, SEX sex);

	~Cattle() {}
    
	void time_pass_by();

	void when_atmosphere_changed();

	void die();

	Living* mate_with(vector<Abstract*>* abs_list,Living* another);

	void breath(Atmosphere* atm);

	void grow();

	bool eat(Entity* food);

	void cry();

	bool drink();

	void produce_milk();

	void farrow();
};

#endif 
