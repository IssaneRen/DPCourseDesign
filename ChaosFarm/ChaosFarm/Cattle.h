#ifndef CF_CATTLE_H_
#define CF_CATTLE_H_
#include "Mammals.h"

//*一个实例类，所有的虚函数都已实现。
//*奶牛。
class Cattle final: public Mammals{
public:

	//*abs_list：需要注册的subject列表。
	//*size：该动物的大小。
	//*max_age：该动物的最大年龄。
	Cattle(vector<Abstract*>* abs_list, int size = 7, int max_age = 200):Mammals(abs_list,size,max_age){}

	~Cattle() {}

	//*反应函数。
	//*表征此动物在早上时做的事情。
	virtual void do_morning(){ run(); }

	//*反应函数。
	//*表征此动物在中午时做的事情。
	virtual void do_noon(){ produce_milk(); }

	//*反应函数。
	//*表征此动物在下午时做的事情。
	virtual void do_afternoon(){ drink(); }

	//*反应函数。
	//*表征此动物在晚上时做的事情。
	virtual void do_night(){ sleep(); }

	//*行为函数。
	//*产奶
	void produce_milk(){ format_output("Mammals::produce_milk()", "is producing milk"); }

	//*被重写的获取类名的函数，返回"Cattle"
	virtual const char* get_class_name(){ return "Cattle"; }
};

#endif 
