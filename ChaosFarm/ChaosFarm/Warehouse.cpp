#include "Warehouse.h"
#include "Time.h"
#include "Atmosphere.h"

Warehouse* Warehouse::warehouse_p_ = 0;

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
	if (durability_ == max_durability_)
	{
		format_output("Warehouse::fix()", "Warehouse doesn't need fixing!");
	}
	else
	{
		durability_ = durability_ + n;
		if (durability_ > max_durability_)
		{
			durability_ = max_durability_;
		}
		format_output("Warehouse::fix()", "Warehouse has been fixed!");
	}
}

int Warehouse::size()
{
	if (shelf_ == NULL)
	{
		shelf_ = new Shelf();
	}
	return shelf_->size();
}

bool Warehouse::is_empty()
{
	if (shelf_ == NULL)
	{
		shelf_ = new Shelf();
	}
	return shelf_->is_empty();
}

void Warehouse::begin(Collection::FarmIterator& iterator)
{
	if (shelf_ == NULL)
	{
		shelf_ = new Shelf();
	}
	shelf_->begin(iterator);
}

void Warehouse::end(Collection::FarmIterator& iterator)
{
	if (shelf_ == NULL)
	{
		shelf_ = new Shelf();
	}
	shelf_->end(iterator);
}

void Warehouse::add(Object* new_element)
{
	if (shelf_ == NULL)
	{
		shelf_ = new Shelf();
	}
	shelf_->add(new_element);
}

void Warehouse::remove(Collection::FarmIterator& iterator)
{
	if (shelf_ == NULL)
	{
		shelf_ = new Shelf();
	}
	shelf_->remove(iterator);
}

void Warehouse::show_list()
{
	if (shelf_ == NULL)
	{
		shelf_ = new Shelf();
	}
	shelf_->show_list();
}

void Warehouse::find_kind(string kind_name)
{
	if (shelf_ == NULL)
	{
		shelf_ = new Shelf();
	}
	shelf_->find_kind(kind_name);
}

int Warehouse::usable_capacity()
{
	if (shelf_ == NULL)
	{
		shelf_ = new Shelf();
	}
	return shelf_->usable_capacity();
}

void Warehouse::dilate(int extend_space)
{
	if (shelf_ == NULL)
	{
		shelf_ = new Shelf();
	}
	shelf_->dilate(extend_space);
	format_output("Warehouse::dilate()", "has been dilated!");
}

int Warehouse::capacity()
{
	if (shelf_ == NULL)
	{
		shelf_ = new Shelf();
	}
	return shelf_->capacity();
}

Shelf::Iterator::Iterator()
{
	current_node_ = NULL;
}

Shelf::Iterator::Iterator(Shelf* list)
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

Shelf::Iterator::Iterator(Iterator* another)
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

Object* Shelf::Iterator::value()
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

void Shelf::Iterator::turn_next()
{
	if (has_next())
	{
		current_node_ = ((Node*)current_node_)->get_next();
	}
}
void Shelf::Iterator::turn_previous()
{
	if (has_previous())
	{
		current_node_ = ((Node*)current_node_)->get_previous();
	}
}
void Shelf::Iterator::turn_first()
{
	if (current_node_ != NULL)
	{
		Node* temp = (Node*)current_node_;
		for (; temp->get_previous() != NULL; temp = temp->get_previous());
		current_node_ = temp;
	}
}
void Shelf::Iterator::turn_last()
{
	if (current_node_ != NULL)
	{
		Node* temp = (Node*)current_node_;
		for (; temp->get_next() != NULL; temp = temp->get_next());
		current_node_ = temp;
	}
}
bool Shelf::Iterator::has_next()
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
bool Shelf::Iterator::has_previous()
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

int Shelf::size()
{
	return capacity_;
}

bool Shelf::is_empty()
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

void Shelf::begin(FarmIterator& iterator)
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

void Shelf::end(FarmIterator& iterator)
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

void Shelf::add(Object* new_element)
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
		used_space_ = used_space_ + size;
	}
}

void Shelf::remove(FarmIterator& iterator)
{
	Iterator* temp = (Iterator*)&iterator;
	used_space_ = used_space_ - ((Entity*)temp->value())->get_size();
	list_->remove((Node*)temp->current_node_);
}

void Shelf::show_list()
{
	if (used_space_ == 0)
	{
		cout << "Warehouse Shelf:" << endl;
		cout << "Nothing!" << endl;
	}
	else
	{
		Iterator it;
		begin(it);
		cout << "Warehouse Shelf:" << endl;
		for (; it.has_next(); it.turn_next())
		{
			cout << "kind:" << it.value()->get_class_name() << " id:" << it.value()->get_id() << endl;
		}
		cout << "kind:" << it.value()->get_class_name() << " id:" << it.value()->get_id() << endl;
	}
}

void Shelf::find_kind(string kind_name)
{
	Iterator it;
	begin(it);
	if (it.current_node_ != NULL)
	{
		for (; it.has_next(); it.turn_next())
		{
			if (it.value()->get_class_name() == kind_name)
			{
				cout << "kind:" << it.value()->get_class_name() << " id:" << it.value()->get_id() << endl;
			}
		}
		if (it.value()->get_class_name() == kind_name)
		{
			cout << "kind:" << it.value()->get_class_name() << " id:" << it.value()->get_id() << endl;
		}
	}
}

int Shelf::usable_capacity()
{
	return (capacity_ - used_space_);
}

void Shelf::dilate(int extend_space)
{
	if (extend_space >= 0)
	{
		capacity_ = capacity_ + extend_space;
	}
}

Shelf::Shelf()
{
	list_ = new List;
	capacity_ = 1000;
	used_space_ = 0;
}

int Shelf::capacity()
{
	return capacity_;
}