#include "StockList.h"
#include "Stock.h"

int StockList::size()
{
	return list_->size();
}
bool StockList::is_empty()
{
	return list_->is_empty();
}
void StockList::begin(FarmIterator* iterator)
{
	if (size() > 0)
	{
		Iterator begin(this);
		if (iterator != NULL)
		{
			*(Iterator*)iterator = begin;
		}
		else
		{
			return;
		}
	}
}

void StockList::end(FarmIterator* iterator)
{
	if (size() > 0)
	{
		Iterator end(this);
		for (; end.has_next(); end.turn_next());
		if (iterator != NULL)
		{
			*(Iterator*)iterator = end;
		}
		else
		{
			return;
		}
	}
}

void StockList::add(Object* new_element)
{
	if (new_element != NULL)
	{
		Node* new_node = new Node(new_element);
		list_->add(new_node);
	}
}
void StockList::remove(FarmIterator* iterator)
{
	list_->remove((Node*)(((Iterator*)iterator)->current_node_));
}