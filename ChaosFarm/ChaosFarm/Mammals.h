#ifndef CF_MAMMALS_H_
#define CF_MAMMALS_H_
#include "Animal.h"


class Mammals :public Animal {
public:
	Mammals(vector<Abstract*>* abs_list, int size, int max_age);

	~Mammals() {}

	void run();

	virtual void produce_milk() = 0;

	virtual void farrow() = 0;

	virtual void do_morning() = 0;

	virtual void do_noon() = 0;

	virtual void do_afternoon() = 0;

	virtual void do_night() = 0;
};
#endif 

