#ifndef CF_CHICKEN_H_
#define CF_CHICKEN_H_
#include "Poultry.h"

class Chicken final: public Poultry{
public:

	Chicken(vector<Abstract*>* abs_list, int size, int max_age, SEX sex);

	~Chicken() {}
    
	void time_pass_by();

	void when_atmosphere_changed();

	void die();

	Living* mate_with(vector<Abstract*>* abs_list,Living* another);

	void breath(Atmosphere* atm);

	void grow();

	bool eat(Entity* food);

	void cry();

	bool drink();

	void lay_egg();

	void incubate();
};

#endif 
