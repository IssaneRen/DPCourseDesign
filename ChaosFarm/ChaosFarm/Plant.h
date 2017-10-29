#ifndef CF_PLANT_H
#define CF_PLANT_H
#include "Living.h"
#include "Atmosphere.h"


class Plant : public Living
{
public:
	Plant(vector<Abstract*>* abs_list, int size, int max_age);
	~Plant(){}
	virtual void grow() = 0;
	virtual void die() = 0;
	virtual void bloom() = 0;
	virtual void photosynthesis() = 0;
	virtual void breath() = 0;
	virtual void time_pass_by() = 0;
	virtual void when_atmosphere_changed() = 0;
	virtual Living* mate_with(vector<Abstract*>* abs_list, Living* another){ return NULL; }
	virtual void update(AbstractType type) = 0;
	int get_energy() { return energy_; }
	int get_water_content() { return water_content_; }
	virtual const char* get_class_name(){ return "Plant"; }
protected:
	int energy_;															//能量值，初始化为50
	int water_content_;														//水含量，初始化为50
};


#endif