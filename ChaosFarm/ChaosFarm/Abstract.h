#ifndef CF_ABSTRACT_H
#define CF_ABSTRACT_H
#include "Object.h"
#include "Entity.h"
#include "AbstractType.h"
#include <vector>
#include <iterator>
class Entity;

typedef vector<Entity*> ObserverPool;

class Abstract :public Object{
public:
	Abstract(){ observer_pool_ = new vector<Entity*>(); }

	~Abstract(){ delete observer_pool_; }

	Abstract(const ObserverPool* observer_pool){
		observer_pool_ = new ObserverPool((*observer_pool));
	}

	//ÓÃÒÔÌí¼Óobserver
	const ObserverPool* get_observer_pool(){ return observer_pool_; }

	void add_observer(Entity* ob){ observer_pool_->push_back(ob); }

	bool remove_observer(Entity *observer);


protected:
	ObserverPool* observer_pool_;

	virtual void notify();

};



#endif