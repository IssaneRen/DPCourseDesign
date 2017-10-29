#ifndef CF_CATTLE_H_
#define CF_CATTLE_H_
#include "Mammals.h"

class Cattle final: public Mammals{
public:

	Cattle(vector<Abstract*>* abs_list, int size, int max_age);

	~Cattle() {}

	virtual void when_atmosphere_changed();

	virtual void die();

	virtual void grow();

	virtual void cry();

	virtual void drink();

	void produce_milk();

	virtual void do_morning(){}

	virtual void do_noon(){}

	virtual void do_afternoon(){}

	virtual void do_night(){}
};

#endif 
