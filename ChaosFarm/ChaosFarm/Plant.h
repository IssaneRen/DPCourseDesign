#ifndef CF_PLANT_H
#define CF_PLANT_H
#include "Living.h"
#include "Atmosphere.h"


class Plant : public Living
{
public:


	Plant(vector<Abstract*>* abs_list, int size, int max_age);
	~Plant(){}

	//*行为函数：开花
	virtual void bloom() = 0;

	//*行为函数：光合作用
	virtual void photosynthesis() = 0;

	//*行为函数：呼吸
	virtual void breath() = 0;

	//*取得植物体内包含的能量值
	const int get_energy() { return energy_; }

	//*取得植物体内的含水量
	int get_water_content() { return water_content_; }

	//*被重写的获取类名的函数，返回"Plant"
	virtual const char* get_class_name(){ return "Plant"; }

protected:
	//*能量值
	int energy_;

	//*水分
	int water_content_;

	//*反应函数。当时间流逝时，由update()调用此函数。
	//*注意：纯虚
	virtual void time_pass_by() = 0;

	//*反应函数。当天气变化时，由update()调用此函数。
	//*注意：纯虚
	virtual void when_atmosphere_changed() = 0;
};


#endif