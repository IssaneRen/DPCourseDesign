#ifndef CF_FACILITY_H
#define CF_FACILITY_H
#include "Entity.h"

//*设施类。表征具有某些作用的农场物品，其共有特性是具有耐久度，在使用时会被消耗。
//*由于继承自Entity，它也是Observer；但由于没有需求，目前并没有进行相关的实现，相关函数为空。
class Facility :public Entity{
public:
	//*abs_list：需要注册的subject列表。
	//*size：该设施的大小。
	//*init_durability：初始耐久度。
	Facility(vector<Abstract*>* abs_list = NULL, int size = 0, int init_durability = 100);

	virtual ~Facility(){}

	//*修理函数。
	//*参数n表示修理恢复的耐久度数
	virtual void fix(int n = 1){ durability_ += n; }

	//*磨损函数。
	//*参数n表示磨损的耐久度数
	virtual void loss(int n = 1){ if (durability_ >= n)durability_ -= n; }

	//*取得耐久度的函数。
	//*const：你无法由此函数改变函数成员的值。
	const int get_durability(){ return durability_; }

	//*被重写的获取类名的函数，返回"Facility"
	virtual const char* get_class_name(){ return "Facility"; }
protected:
	//*耐久度
	int durability_;

	//*对时间变化的反应函数。由于没有需要，被置空
	virtual void time_pass_by(){}

	//*对天气变化的反应函数。由于没有需要，被置空
	virtual void when_atmosphere_changed(){}
};


#endif