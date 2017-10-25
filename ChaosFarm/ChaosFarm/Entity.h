#ifndef CF_ENTITY_H
#define CF_ENTITY_H
#include "Object.h"
#include "Abstract.h"
#include "AbstractType.h"
#include<vector>
#include<iterator>
class Abstract;

class Entity :public Object{
public:
	Entity(vector<Abstract*>* abs_list, int size = 0);

	~Entity(){}

	virtual void time_pass_by() = 0;

	virtual void when_atmosphere_changed() = 0;

	virtual void update(Abstract* abs, AbstractType type) = 0;

protected:
	int size_;
};



#endif