#include "StockList.h"


StockIterator* StockList::create_iterator()
{
	return new StockIterator(list_->head());
}
int StockList::size()
{
	return list_->size();
}
bool StockList::is_empty()
{
	return list_->is_empty();
}
StockIterator* StockList::begin()
{
	return new StockIterator(list_->head());
}
StockIterator* StockList::end()
{
	Node* temp = list_->head();
	for (; temp->get_next() != NULL; temp = temp->get_next());
	return new StockIterator(temp);
}
void StockList::add(Object* new_element)
{
	Node* new_node = new Node(new_element);
	list_->add(new_node);
}
void StockList::remove(FarmIterator* iterator)
{
	list_->remove((Node*)iterator->get_node());
}