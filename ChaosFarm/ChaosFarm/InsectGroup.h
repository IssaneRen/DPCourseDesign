#pragma once
#include "Collection.h"
#include "Insect.h"
#include "List.h"
#include "InsectIterator.h"
#include<vector>

class InsectGroup :public Collection
{
public:
	InsectGroup(string* species) :species_(species) {};
	virtual InsectIterator* create_iterator();
	virtual int size();
	virtual bool is_empty();
	virtual FarmIterator* begin();
	virtual FarmIterator* end();
	void hatch(int number, vector<Abstract*>* abs_list, int size, int max_age, string* name, SEX sex);
	virtual void add(Object* new_element) {};
private:
	string* species_;
	List list_;
};

InsectIterator* InsectGroup::create_iterator()
{
	return new InsectIterator(list_.head());
}
int InsectGroup::size()
{
	return list_.size();
}
bool InsectGroup::is_empty()
{
	return list_.is_empty();
}
FarmIterator* InsectGroup::begin()
{
	return new InsectIterator(list_.head());
}
FarmIterator* InsectGroup::end()
{
	Node* temp = list_.head();
	for (; temp->get_next() != NULL; temp = temp->get_next());
	return new InsectIterator(temp);
}
void InsectGroup::hatch(int number, vector<Abstract*>* abs_list, int size, int max_age, string* name, SEX sex)
{
	for (int i = 0; i < number; i++)
	{
		Insect*temp = Insect::find_and_clone(abs_list, size, max_age, name, sex, species_);
		Node* new_element = new Node(temp);
		list_.add(new_element);
	}
}