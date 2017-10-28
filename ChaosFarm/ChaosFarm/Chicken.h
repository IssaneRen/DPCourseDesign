#ifndef CF_CHICKEN_H_
#define CF_CHICKEN_H_
#include "Poultry.h"

class Chicken final: public Poultry{
public:

	Chicken(vector<Abstract*>* abs_list, int size, int max_age);

	~Chicken() {}
    
	void time_pass_by();

	void when_atmosphere_changed();

	void die();

	void breath(Atmosphere* atm);

	void grow();

	bool eat(Entity* food);

	void cry();

	bool drink();

	void lay_egg();

	void incubate();
};

#endif 
