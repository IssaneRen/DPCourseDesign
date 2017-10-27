#ifndef CF_STOCK_LIST_H
#define CF_STOCK_LIST_H
#include "Collection.h"
#include "List.h"
#include "StockIterator.h"


class StockList :public Collection{
public:
	StockList(){ list_ = new List(); }
	~StockList(){ delete list_; }
	virtual StockIterator* create_iterator();
	virtual int size();
	virtual bool is_empty();
	virtual StockIterator* begin();
	virtual StockIterator* end();
	virtual void add(Object* new_element);
	virtual void remove(FarmIterator* iterator);
private:
	List* list_;
};


#endif // !CF_STOCK_LIST_H
