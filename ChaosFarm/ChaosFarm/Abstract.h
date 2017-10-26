#ifndef CF_ABSTRACT_H
#define CF_ABSTRACT_H
#include "Object.h"
#include "Entity.h"
#include "AbstractType.h"
#include <vector>
#include <iterator>
class Entity;

class Abstract :public Object{
public:
	Abstract(){ observer_pool_ = new vector<Entity*>(); }

	~Abstract(){ delete observer_pool_; }

	void add_observer(Entity* ob){ observer_pool_->push_back(ob); }

	bool remove_observer(Entity *observer);


protected:
	vector<Entity*>* observer_pool_;

	virtual void notify();

};



#endif