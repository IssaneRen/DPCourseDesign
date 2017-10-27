#ifndef CF_CROP_H
#define CF_CROP_H
#include "Plant.h"

class Crop : public Plant
{
	class CropState* state;
public:
	Crop(vector<Abstract*>* abs_list, int size, int max_age, SEX sex = NON);
	~Crop(){}
	void absorb_water();
	void weaken(int num);
	bool defend();
	void bloom();
	void photoshythesize();
	void breath();
	void time_pass_by();
	void when_atmosphere_changed();
	void update(AbstractType type);
	void grow();
	void bear_fruit();
	void reproduce();
	void growbigger();
private:
	int fruit_size_;
	void die();
};

class CropState
{
public:
	virtual void grow(Crop* c);
	virtual void reproduce(Crop* c);
};

class Growing :public CropState
{
public:
	void grow(Crop* c);
};

class Mature :public CropState
{
public:
	void reproduce(Crop* c);
};
#endif