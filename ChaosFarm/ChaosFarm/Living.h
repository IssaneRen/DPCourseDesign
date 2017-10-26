#ifndef CF_LIVING_H
#define CF_LIVING_H
#include "Entity.h"
#include "Atmosphere.h"
#include<string>
using namespace std;

enum SEX{
	NON = 0,
	MALE = 1,
	FEMALE = 2,
	HERMAPHRODITISM = 3,		//雌雄同体

};

class Living :public Entity{
public:

	Living(vector<Abstract*>* abs_list, int size, int max_age, SEX sex);

	~Living(){}

	virtual void die() = 0;

	virtual Living* mate_with(vector<Abstract*>* abs_list, Living* another) = 0;								 //交配函数，与另一个生物进行交配，返回所生子代个体的指针

	virtual void breath(Atmosphere* atm) = 0;										 //呼吸函数。调用改变atm二氧化碳和氧气浓度的函数

	virtual void grow() = 0;															//生长函数。随时间增长年龄

	virtual void time_pass_by() = 0;

	virtual void when_atmosphere_changed() = 0;

	virtual void update(AbstractType type){
		switch (type)
		{
		case ERROR:
			break;
		case TIME:time_pass_by();
			break;
		case ATMOSPHERE:when_atmosphere_changed();
			break;
		default:
			break;
		}
	}

	void set_health_gradient(float new_gradient){ health_gradient_ = new_gradient; }

	SEX get_sex(){ return sex_; }

protected:
	int age_;
	int max_age_;
	float grow_speed_;						//由空气气味浓度影响，是一个系数。在grow()中被使用
	float health_gradient_;					//健康值变化率，由空气微生物浓度影响，是一个系数。在time_pass_by()中被使用，影响健康度变化
	int health_;							 //�?后死亡�?
	SEX sex_;
};


#endif // !CF_ENTITY_H



