#ifndef CF_FACILITY_H
#define CF_FACILITY_H
#include "Entity.h"

class Facility :public Entity{
public:
	Facility(vector<Abstract*>* abs_list, int size, int init_durability = 100);

	~Facility(){}

	virtual void fix(){ durability_++; }

	virtual void loss(){ if (durability_ > 0)durability_--; }

	virtual void time_pass_by() = 0;

	virtual void when_atmosphere_changed() = 0;

	virtual void update(Abstract* abs, AbstractType type) = 0;


protected:
	int durability_;
};


#endif