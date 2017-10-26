#include "Object.h"

class FarmIterator :public Object
{
public:
	virtual void remove() = 0;
	virtual Object* next() = 0;
	virtual Object* previous() = 0;
	virtual Object* first() = 0;
	virtual Object* last() = 0;
	virtual bool has_next() = 0;
	virtual bool had_previous() = 0;
};