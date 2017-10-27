#include "StockIterator.h"

StockIterator::StockIterator(Node* item)
{
	current_item_ = item;
}

Node* StockIterator::value()
{
	return current_item_;
}

StockIterator* StockIterator::next()
{
	StockIterator* temp = new StockIterator(current_item_->get_next());
	return temp;
}
StockIterator* StockIterator::previous()
{
	StockIterator* temp = new StockIterator(current_item_->get_previous());
	return temp;
}
StockIterator* StockIterator::first()
{
	Node* temp = current_item_;
	if (temp->get_previous() == NULL)
	{
		StockIterator* result = new StockIterator(temp);
		return result;
	}
	else
	{
		for (; temp->get_previous() != NULL; temp = temp->get_previous());
		StockIterator* result = new StockIterator(temp);
		return result;
	}
}
StockIterator* StockIterator::last()
{
	Node* temp = current_item_;
	if (temp->get_next() == NULL)
	{
		StockIterator* result = new StockIterator(temp);
		return result;
	}
	else
	{
		for (; temp->get_next() != NULL; temp = temp->get_next());
		StockIterator* result = new StockIterator(temp);
		return result;
	}
}
bool StockIterator::has_next()
{
	if (current_item_->get_next() == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool StockIterator::had_previous()
{
	if (current_item_->get_previous() == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}