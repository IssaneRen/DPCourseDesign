#ifndef CF_POULTRY_H_
#define CF_POULTRY_H_
#include "Animal.h"
#include "Fence.h"


class Poultry :public Animal {
public:
	Poultry(vector<Abstract*>* abs_list, int size, int max_age);

	~Poultry() {}

	void go_into_fence(Fence* fence);

	void go_out_of_fence(Fence* fence);

	void fly();

	virtual void lay_egg() = 0;

	virtual void incubate() = 0;

	virtual void do_morning() = 0;

	virtual void do_noon() = 0;

	virtual void do_afternoon() = 0;

	virtual void do_night() = 0;
};
#endif 

