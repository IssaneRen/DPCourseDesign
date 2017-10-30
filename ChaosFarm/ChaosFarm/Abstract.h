#ifndef CF_ABSTRACT_H
#define CF_ABSTRACT_H
#include "Object.h"
#include "Entity.h"
#include "AbstractType.h"
#include <vector>
#include <iterator>
class Entity;

typedef vector<Entity*> ObserverPool;

//*表征抽象概念的类，继承自Object。
//*Subjetc：是观察者机制中的subject，是Observer——Entity的观察对象。
class Abstract :public Object{
public:
	Abstract(){ observer_pool_ = new vector<Entity*>(); }

	~Abstract(){ delete observer_pool_; }

	//*利用一个现有的ObserverPool以创建一个Abstract
	//*用以创建拥有同样注册列表的Abstract
	Abstract(const ObserverPool* observer_pool){
		observer_pool_ = new ObserverPool((*observer_pool));
	}

	//*传出observer pool，方便复制使用。
	//*由于iterator的使用，此函数无法被设置成const。
	//*请尽量不要进行会造成obserber pool内容变动的操作。
	ObserverPool* get_observer_pool(){ return observer_pool_; }

	//*用以往observer pool里添加observer
	void add_observer(Entity* ob){ 
		observer_pool_->push_back(ob);
	}

	//*在observer pool中移除指针指向的Obserber。
	//*若找到对应observer并成功移除，返回true。
	//*未找到对应observer，无法移除，返回false。
	bool remove_observer(Entity *observer);

	//*被重写的获取类名的函数，返回"Abstract"
	virtual const char* get_class_name(){ return "Abstract"; }
protected:

	//*对象池，存放了所有注册此subject——Abstract的Observer。
	ObserverPool* observer_pool_;

	//*通知函数，用以通知所有observer
	virtual void notify();

};



#endif