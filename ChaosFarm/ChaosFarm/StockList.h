#ifndef CF_STOCK_LIST_H
#define CF_STOCK_LIST_H
#include "Collection.h"
#include "List.h"


class StockList :public Collection{
public:
	class Iterator :public FarmIterator
	{
	public:
		friend class StockList;
		Iterator();
		Iterator(StockList* list);
		Iterator(Iterator* another);
		virtual Object* value();
		virtual void turn_next();
		virtual void turn_previous();
		virtual void turn_first();
		virtual void turn_last();
		virtual bool has_next();
		virtual bool has_previous();
	};
	StockList(){ list_ = new List(); }
	~StockList(){ delete list_; }
	virtual int size();
	virtual void add(Object* new_element);
	virtual void remove(FarmIterator* iterator);
	virtual bool is_empty();
	virtual void begin(FarmIterator* iterator);
	virtual void end(FarmIterator* iterator);
private:
	List* list_;
};


#endif // !CF_STOCK_LIST_H
