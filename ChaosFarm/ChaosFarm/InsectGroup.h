#pragma once
#include "Collection.h"
#include "Insect.h"
#include "List.h"
#include "InsectIterator.h"
#include<vector>

class InsectGroup :public Collection
{
public:
	InsectGroup(string* species) :species_(species)
	{
		list_ = new List();
	}
	~InsectGroup()
	{
		delete species_;
		delete list_;
	}
	virtual InsectIterator* create_iterator();
	virtual int size();
	virtual bool is_empty();
	virtual FarmIterator* begin();
	virtual FarmIterator* end();
	void hatch(int number, vector<Abstract*>* abs_list);
	virtual void add(Object* new_element);
	virtual void remove(FarmIterator* iterator);
private:
	string* species_;
	List*list_;
};

InsectIterator* InsectGroup::create_iterator()
{
	return new InsectIterator(list_->head());
}
int InsectGroup::size()
{
	return list_->size();
}
bool InsectGroup::is_empty()
{
	return list_->is_empty();
}
FarmIterator* InsectGroup::begin()
{
	return new InsectIterator(list_->head());
}
FarmIterator* InsectGroup::end()
{
	Node* temp = list_->head();
	for (; temp->get_next() != NULL; temp = temp->get_next());
	return new InsectIterator(temp);
}
void InsectGroup::hatch(int number, vector<Abstract*>* abs_list)
{
	for (int i = 0; i < number; i++)
	{
		SEX sex;
		if (i % 2 == 0)
		{
			sex = MALE;
		}
		else
		{
			sex = FEMALE;
		}
		Insect*temp = Insect::find_and_clone(abs_list, 1, sex, species_);
		Node* new_element = new Node(temp);
		list_->add(new_element);
	}
}
void InsectGroup::add(Object* new_element)
{
	Insect* temp = (Insect*)new_element;
	if (*species_ == *(temp->get_species()))
	{
		Node* new_node = new Node(temp);
		list_->add(new_node);
	}
}
void InsectGroup::remove(FarmIterator* iterator)
{
	list_->remove((Node*)iterator->get_node());
}