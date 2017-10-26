#include "Bee.h"

string* Bee::get_species()
{
	return new string("bee");
}

Insect * Bee::clone(vector<Abstract*>* abs_list, int size, int max_age, string* name, SEX sex)
{
	return new Bee(abs_list, size, max_age, name, sex, 1);
}