#ifndef CF_PLANT_H
#define CF_PLANT_H
#include "Living.h"
#include "Atmosphere.h"


class Plant : public Living
{
public:
	Plant(vector<Abstract*>* abs_list, int size, int max_age, SEX sex = NON);
	~Plant(){}
	virtual void grow() = 0;
	virtual void die() = 0;
	virtual void bloom() = 0;
	virtual void photoshythesize() = 0;
	virtual void breath() = 0;
	virtual void time_pass_by() = 0;
	virtual void when_atmosphere_changed() = 0;
	virtual void update(Abstract* abs, AbstractType type) = 0;
protected:
	int energy_;
	int water_content_;
};


#endif