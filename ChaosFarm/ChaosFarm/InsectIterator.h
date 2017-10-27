#pragma once
#include "FarmIterator.h"
#include "List.h"

class InsectIterator :public FarmIterator
{
public:
	InsectIterator(Node* item);
	virtual Object* value();
	virtual Object* get_node();
	virtual InsectIterator* next();
	virtual InsectIterator* previous();
	virtual InsectIterator* first();
	virtual InsectIterator* last();
	virtual bool has_next();
	virtual bool has_previous();
private:
	Node* current_item_;
};