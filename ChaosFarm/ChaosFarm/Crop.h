#ifndef CF_CROP_H
#define CF_CROP_H
#include "Plant.h"

class Crop : public Plant
{
public:
	Crop(vector<Abstract*>* abs_list, int size, int max_age, string* name, SEX sex = NON);
	~Crop(){}
	void absorb_water();
	void weaken(int num);
	bool defend();
	void bloom();
	void photoshythesize();
	void breath();
	void time_pass_by();
	void when_atmosphere_changed();
	void update(Abstract* abs, AbstractType type);
private:
	int fruit_size_;
	void bear_fruit();
	void grow();
	void die();
};

#endif