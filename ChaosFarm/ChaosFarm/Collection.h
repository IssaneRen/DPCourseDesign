#pragma once
#include "Object.h"
#include "FarmIterator.h"

class Collection :public Object
{
public:
	friend class FarmIterator;
	virtual FarmIterator* create_iterator() = 0;
	virtual int size() = 0;
	virtual void add(Object* new_element) = 0;
	virtual bool is_empty() = 0;
	virtual FarmIterator* begin() = 0;
	virtual FarmIterator* end() = 0;
};