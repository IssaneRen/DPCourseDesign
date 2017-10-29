#ifndef CF_CROP_H
#define CF_CROP_H
#include "Plant.h"
#include "FarmLand.h"

class BaseFarmLand;

class Crop : public Plant
{
	class CropState* state;
public:
	Crop(vector<Abstract*>* abs_list, int size, int max_age);
	~Crop(){}
	void absorb_water();
	void weaken(int num);
	bool defend();
	void bloom();
	void photosynthesis();
	void breath();
	void time_pass_by();
	void when_atmosphere_changed();
	void update(AbstractType type);
	void grow();
	void bear_fruit();
	void reproduce();
	void growbigger();
	void setState(CropState* s);
	int get_fruit_size() { return (float(fruit_size_))*output_rate_; }
	void plant_on(BaseFarmLand* farmland);
	void set_output_rate(float new_rate){ output_rate_ = new_rate; }
	float get_output_rate(){ return output_rate_; }
	virtual const char* get_class_name(){ return "Crop"; }
private:
	int fruit_size_;
	float output_rate_;
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