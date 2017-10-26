#include "InsectGroup.h"

FarmIterator* InsectGroup::create_iterator()
{
	return NULL;
}
int InsectGroup::size()
{
	return list_.size();
}
bool InsectGroup::is_empty()
{
	return list_.empty();
}
FarmIterator* InsectGroup::begin()
{
	return NULL;
}
FarmIterator* InsectGroup::end()
{
	return NULL;
}
void InsectGroup::hatch(int number, vector<Abstract*>* abs_list, int size, int max_age, string* name, SEX sex)
{
	for (int i = 0; i < number; i++)
	{
		list_.push_back(Insect::find_and_clone(abs_list, size, max_age, name, sex, species_));
	}
}