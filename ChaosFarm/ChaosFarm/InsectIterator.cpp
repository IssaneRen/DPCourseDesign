#include "InsectIterator.h"

InsectIterator::InsectIterator(Node* item)
{
	current_item_ = item;
}

Object* InsectIterator::value()
{
	return (Object*)current_item_->get_value();
}

InsectIterator* InsectIterator::next()
{
	InsectIterator* temp = new InsectIterator(current_item_->get_next());
	return temp;
}
InsectIterator* InsectIterator::previous()
{
	InsectIterator* temp = new InsectIterator(current_item_->get_previous());
	return temp;
}
InsectIterator* InsectIterator::first()
{
	Node* temp = current_item_;
	if (temp->get_previous() == NULL)
	{
		InsectIterator* result = new InsectIterator(temp);
		return result;
	}
	else
	{
		for (; temp->get_previous() != NULL; temp = temp->get_previous());
		InsectIterator* result = new InsectIterator(temp);
		return result;
	}
}
InsectIterator* InsectIterator::last()
{
	Node* temp = current_item_;
	if (temp->get_next() == NULL)
	{
		InsectIterator* result = new InsectIterator(temp);
		return result;
	}
	else
	{
		for (; temp->get_next() != NULL; temp = temp->get_next());
		InsectIterator* result = new InsectIterator(temp);
		return result;
	}
}
bool InsectIterator::has_next()
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
bool InsectIterator::had_previous()
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