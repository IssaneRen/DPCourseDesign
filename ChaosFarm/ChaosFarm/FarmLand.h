#ifndef CF_FARMLAND_H
#define CF_FARMLAND_H
#include <iostream>
#include <string>
#include<vector>
#include"Facility.h"
#include"Time.h"
#include"Atmosphere.h"
#include "AbstractType.h"
#include "Crop.h"

using namespace std;

#define PLOW_EFFECT 1.1

class Crop;

//*使用Decorator，对BaseFarmland基类的功能进行包装扩展

//*BaseFarmLand为component类，给出接口规范准备接收附加责任的对象
class BaseFarmLand :public Facility{
	friend class DecoratedFarmLand;
public:
	BaseFarmLand(vector<Abstract*>* abs = NULL, int size = 100, int duarability = 100)
		:Facility(abs, size, duarability){}

	virtual ~BaseFarmLand(){ }

	virtual const char* get_discription() = 0;

	virtual void set_discription(const char* str) = 0;

	virtual const float get_fertility() = 0;

	virtual void set_fertility(float fertility) = 0;

	virtual void plant_a_crop(Crop* crop){
		format_output("BaseFarmLand::plant_a_crop()", "a crop is planted.");
	}

	virtual void watering(){
		format_output("BaseFarmLand::watering()", "the land is watered.");
	}

	virtual const char* get_class_name(){ return "BaseFarmLand"; }

protected:

	virtual void when_atmosphere_changed() = 0;

	virtual void time_pass_by() = 0;
};

//*Farmland是具体的Compontent类，继承BaseFarmLand，定义了将要接收附加责任的对象
class FarmLand :public BaseFarmLand {
public:
	FarmLand(vector<Abstract*>* abs = NULL, int size = 100, int duarability = 100, const char* desc = "", float fertility = 1) :BaseFarmLand(abs, size, duarability), fertility_(fertility){}

	~FarmLand() {}

	virtual const char* get_discription(){ return description_->c_str(); }

	virtual void set_discription(const char* str){ (*description_) = str; }

	virtual const float get_fertility(){ return fertility_; }

	virtual void set_fertility(float fertility){ fertility_ = fertility; }

	virtual void plant_a_crop(Crop* crop){
		format_output("FarmLand::plant_a_crop()", "a crop is planted.");
	}

	virtual void watering(){
		format_output("FarmLand::watering()", "the land is watered.");
	}

	virtual const char* get_class_name(){ return "FarmLand"; }
protected:
	virtual void when_atmosphere_changed(){}

	virtual void time_pass_by(){}

	string* description_;			//*描述字符串

	float fertility_;				//*肥沃度
};


//DecoratedLand为Decorator类，继承BaseFarmLand，提供了装饰器的接口
//*由于构造参数的baseFarmLand指针由外部传入并存储在此类中，析构函数中将不会对其进行delete
class DecoratedFarmLand:public BaseFarmLand{
public:
	DecoratedFarmLand(BaseFarmLand* baseFarmland) :base_farmland_(baseFarmland){}

	~DecoratedFarmLand(){}

	virtual void fix(int n = 1){ base_farmland_->fix(n); }

	virtual void loss(int n = 1){ base_farmland_->loss(n); }

	virtual void time_pass_by() { base_farmland_->time_pass_by(); }

	virtual void when_atmosphere_changed(){ this->base_farmland_->when_atmosphere_changed(); }

	int get_durability(){ return base_farmland_->get_durability(); }

	virtual const char* get_class_name(){ return "DecoratedFarmLand"; }

	virtual const char* get_discription(){ return base_farmland_->get_discription(); }

	virtual void set_discription(const char* str){ base_farmland_->set_discription(str); }

	virtual const float get_fertility(){ return base_farmland_->get_fertility(); }

	virtual void set_fertility(float fertility){ base_farmland_->set_fertility(fertility); }

	virtual void plant_a_crop(Crop* crop);

	virtual void watering(){
		base_farmland_->watering();
		format_output("DecoratedFarmLand::watering()", "the land is watered.");
	}

protected:
	BaseFarmLand* base_farmland_;
};


//*Concrete Decorator类，被此装饰器装饰过的Concrete Compontent将增加以下功能
//*犁地。可以增加农田的肥沃度
//*由肥沃度影响种植在上面的植物的结实率的功能
class EffectFarmLand :public DecoratedFarmLand{
public:
	EffectFarmLand(BaseFarmLand* baseFarmland) :DecoratedFarmLand(baseFarmland){}

	~EffectFarmLand(){}

	//*犁地函数，可以增加农田的肥沃度，n表示犁地的次数，默认n = 1
	void plow(int n = 1){
		format_output("EffectFarmLand::plow()", "the land is plowed.");
		for (int i = 0; i < n; i++)base_farmland_->set_fertility(base_farmland_->get_fertility() * PLOW_EFFECT); 
	}

	//*种植函数。将传入的crop指针指向的农作物种植在此土地上，并且影响其结实率。
	virtual void plant_a_crop(Crop* crop);

	virtual const char* get_class_name(){ return "EffectFarmLand"; }
};


#endif