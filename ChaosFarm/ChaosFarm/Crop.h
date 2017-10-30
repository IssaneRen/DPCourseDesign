#ifndef CF_CROP_H
#define CF_CROP_H
#include "Plant.h"
#include "Farmland.h"

class BaseFarmLand;

class Crop : public Plant
{
	class CropState* state;																	//状态，生长期或成熟期
public:
	Crop(vector<Abstract*>* abs_list, int size, int max_age);
	~Crop(){}
	void absorb_water();																	//吸收水分
	void weaken(int num);																	//减少健康值
	bool defend();																			//防卫攻击
	void bloom();																			//开花
	void photosynthesis();																	//光合作用
	void breath();																			//呼吸
	void time_pass_by();																	//时间变化
	void when_atmosphere_changed();															//天气变化
	void grow();																			//生长
	void bear_fruit();																		//结果
	void reproduce();																		//繁殖
	void growbigger();																		//增加体型
	void setState(CropState* s);
	int get_fruit_size() { return (float(fruit_size_))*output_rate_; }
	int get_mature_age() { return mature_age_; }
	void plant_on(BaseFarmLand* farmland);
	void set_output_rate(float new_rate){ output_rate_ = new_rate; }
	float get_output_rate(){ return output_rate_; }
	virtual const char* get_class_name(){ return "Crop"; }
private:
	int fruit_size_;																		//果实体积，初始化为0
	int mature_age_;																		//成熟年龄，初始化为5
	float output_rate_;																		//结果速率，初始化为1.0
	void die();
};

class CropState
{
public:
	virtual void grow(Crop* c);
	virtual void reproduce(Crop* c);
};

class Growing :public CropState																//生长期
{
public:
	void grow(Crop* c);
};

class Mature :public CropState																//成熟期
{
public:
	void reproduce(Crop* c);
};
#endif