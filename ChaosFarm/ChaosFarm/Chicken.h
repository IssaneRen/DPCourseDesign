#ifndef CF_CHICKEN_H_
#define CF_CHICKEN_H_
#include "Poultry.h"

//*一个实例类，所有的虚函数都已实现。
//*鸡
class Chicken final: public Poultry{
public:

	//*abs_list：需要注册的subject列表。
	//*size：该动物的大小。
	//*max_age：该动物的最大年龄。
	Chicken(vector<Abstract*>* abs_list = NULL, int size = 3, int max_age = 100);

	~Chicken() {}

	//*被重写的获取类名的函数，返回"Chicken"
	virtual const char* get_class_name(){ return "Chicken"; }

	//*反应函数。
	//*表征此动物在早上时做的事情。
	virtual void do_morning();

	//*反应函数。
	//*表征此动物在中午时做的事情。
	virtual void do_noon();

	//*反应函数。
	//*表征此动物在下午时做的事情。
	virtual void do_afternoon();

	//*反应函数。
	//*表征此动物在晚上时做的事情。
	virtual void do_night();
};

#endif 
