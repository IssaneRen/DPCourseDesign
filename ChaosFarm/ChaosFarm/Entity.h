#ifndef CF_ENTITY_H
#define CF_ENTITY_H
#include "Object.h"
#include "Abstract.h"
#include "AbstractType.h"
#include<vector>
#include<iterator>
class Abstract;


//*实体类。继承自单根类Object，表征现实中存在的事物
//*Observer：该类及其子类的对象都可以成为subject——Abstract的Observer
class Entity :public Object{
public:
	//*构造函数。
	//*参数abs_list为指向存放了对象将要订阅的subject——Abstract类及其子类对象的指针的vector，在此构造函数中，将完成订阅。
	Entity(vector<Abstract*>* abs_list = NULL, int size = 0);

	~Entity(){}

	//*更新函数。当收到来源于订阅的subject——Abstract的通知时，会根据调用它的Abstract的类型，调用不同的反应函数。
	//*AbstractType: 详见enum AbtractType
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


	//*反应函数。当时间流逝时，由update()调用此函数。
	virtual void time_pass_by(){}

	//*反应函数。当天气变化时，由update()调用此函数。
	virtual void when_atmosphere_changed(){}

	//*取得此实体的大小
	int get_size(){ return size_; }

	//*重设此实体的大小
	void set_size(int new_size){ size_ = new_size; }

	//*被重写的获取类名的函数，返回"Entity"
	virtual const char* get_class_name(){ return "Entity"; }

protected:

	//*大小。表征实体的大小的变量。
	int size_;
};



#endif