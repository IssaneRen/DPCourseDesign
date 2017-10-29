#include "Warehouse.h"
#include "Time.h"
#include "Atmosphere.h"

void Warehouse::time_pass_by()
{
	int passed_time = Time::instance()->get_d_hour();
	if (durability_ > passed_time)
	{
		durability_ = durability_ - passed_time;
	}
	else
	{
		durability_ = 1;
		cout << "Warehouse needs fixing!" << endl;
	}
}

void Warehouse::when_atmosphere_changed()
{

}

ItemList* Warehouse::get_item_list()
{
	return item_list_;
}

void Warehouse::set_max_durability(int value)
{
	max_durability_ = value;
	if (value > durability_)
	{
		durability_ = value;
	}
}

void Warehouse::fix(int n)
{
	if (durability_ = max_durability_)
	{
		cout << "Warehouse doesn't need fixing!" << endl;
	}
	else
	{
		durability_ = durability_ + n;
		if (durability_ > max_durability_)
		{
			durability_ = max_durability_;
		}
	}
}

ItemList::Iterator::Iterator()
{
	current_node_ = NULL;
}

ItemList::Iterator::Iterator(ItemList* list)
{
	Node* node = list->list_->head();
	if (node != NULL)
	{
		current_node_ = node;
	}
	else
	{
		current_node_ = NULL;
	}
}

ItemList::Iterator::Iterator(Iterator* another)
{
	if (another != NULL)
	{
		current_node_ = another->current_node_;
	}
	else
	{
		current_node_ = NULL;
	}
}

Object* ItemList::Iterator::value()
{
	if (current_node_ != NULL)
	{
		return ((Node*)current_node_)->get_value();
	}
	else
	{
		return NULL;
	}
}

void ItemList::Iterator::turn_next()
{
	if (has_next())
	{
		current_node_ = ((Node*)current_node_)->get_next();
	}
}
void ItemList::Iterator::turn_previous()
{
	if (has_previous())
	{
		current_node_ = ((Node*)current_node_)->get_previous();
	}
}
void ItemList::Iterator::turn_first()
{
	if (current_node_ != NULL)
	{
		Node* temp = (Node*)current_node_;
		for (; temp->get_previous() != NULL; temp = temp->get_previous());
		current_node_ = temp;
	}
}
void ItemList::Iterator::turn_last()
{
	if (current_node_ != NULL)
	{
		Node* temp = (Node*)current_node_;
		for (; temp->get_next() != NULL; temp = temp->get_next());
		current_node_ = temp;
	}
}
bool ItemList::Iterator::has_next()
{
	if (current_node_ != NULL)
	{
		if (((Node*)current_node_)->get_next() == NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}
bool ItemList::Iterator::has_previous()
{
	if (current_node_ != NULL)
	{
		if (((Node*)current_node_)->get_previous() == NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

int ItemList::size()
{
	return capacity_;
}

bool ItemList::is_empty()
{
	if (used_space_ == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ItemList::begin(FarmIterator& iterator)
{
	if (used_space_ > 0)
	{
		Iterator begin(this);
		iterator = begin;
	}
	else
	{
		Iterator begin;
		iterator = begin;
	}
}

void ItemList::end(FarmIterator& iterator)
{
	if (used_space_ > 0)
	{
		Iterator end(this);
		iterator = end;
	}
	else
	{
		Iterator end;
		iterator = end;
	}
}

void ItemList::add(Object* new_element)
{
	int size = ((Entity*)new_element)->get_size();
	if (usable_capacity() < size)
	{
		return;
	}
	if (new_element != NULL)
	{
		Node* new_node = new Node(new_element);
		list_->add(new_node);
	}
}

void ItemList::remove(FarmIterator& iterator)
{
	Iterator* temp = (Iterator*)&iterator;
	list_->remove((Node*)temp->current_node_);
}

void ItemList::show_list()
{

}

List* ItemList::find_kind(string kind_name)
{
	return list_;
}

int ItemList::usable_capacity()
{
	return (capacity_ - used_space_);
}

void ItemList::dilate(int extend_space)
{
	if (extend_space >= 0)
	{
		capacity_ = capacity_ + extend_space;
	}
}