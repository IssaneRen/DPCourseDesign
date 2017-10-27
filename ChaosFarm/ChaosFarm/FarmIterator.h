#pragma once
#include "Object.h"

class FarmIterator :public Object
{
public:
	virtual Object* value() = 0;
	virtual Object* get_node() = 0;
	virtual FarmIterator* next() = 0;
	virtual FarmIterator* previous() = 0;
	virtual FarmIterator* first() = 0;
	virtual FarmIterator* last() = 0;
	virtual bool has_next() = 0;
	virtual bool has_previous() = 0;
};