#ifndef CF_STOCK_ITERATOR_H
#define CF_STOCK_ITERATOR_H

#include "FarmIterator.h"
#include "List.h"


class StockIterator :public FarmIterator{
public:
	StockIterator(Node* item);
	virtual Node* value();
	virtual StockIterator* next();
	virtual StockIterator* previous();
	virtual StockIterator* first();
	virtual StockIterator* last();
	virtual bool has_next();
	virtual bool had_previous();
private:
	Node* current_item_;
};

#endif