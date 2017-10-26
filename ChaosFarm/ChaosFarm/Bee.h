#pragma once
#include "Insect.h"

class Bee :public Insect
{
public:
	virtual string* get_species();
	virtual void when_atmosphere_changed();
	virtual Living* mate_with(Living* another);
	virtual void grow();
	virtual Insect* clone(vector<Abstract*>* abs_list, int size, int max_age, SEX sex);
protected:
	Bee(vector<Abstract*>* abs_list, int size, int max_age, SEX sex, int dummy) :Insect(abs_list, size, max_age, sex) {}
private:
	static Bee bee_;
	static int reproduction_rate;
	Bee() :Insect(NULL, 0, 0, NON) { addPrototype(this); }
};
Bee Bee::bee_;
int Bee::reproduction_rate = 1;

string* Bee::get_species()
{
	return new string("bee");
}

Insect * Bee::clone(vector<Abstract*>* abs_list, int size, int max_age, SEX sex)
{
	return new Bee(abs_list, size, max_age, sex, 1);
}
void Bee::when_atmosphere_changed()
{

}
Living* Bee::mate_with(Living* another)
{
	return NULL;
}
void Bee::grow()
{
	size_++;
	age_++;
	if (age_ >= max_age_)
	{
		die();
	}
}