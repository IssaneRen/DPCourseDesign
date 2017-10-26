#pragma once
#include<map>
#include "Animal.h"

class Insect:public Animal
{
public:
	static Insect* find_and_clone(vector<Abstract*>* abs_list, int size, int max_age, SEX sex, string* species)
	{
		map<string*, Insect*>::iterator it;
		for (it = prototype_.begin(); ; it++)
		{
			if (*(*it).first == *species)break;
			if (it == prototype_.end())
			{
				if (*(*it).first != *species)
				{
					return NULL;
				}
			}
		}
		Insect*temp = (*it).second->clone(abs_list, size, max_age, sex);
		return temp;
	}
	virtual void time_pass_by();
	virtual void when_atmosphere_changed() = 0;
	virtual void update(Abstract* abs, AbstractType type);
	virtual Living* mate_with(Living* another) = 0;
	virtual void breath(Atmosphere* atm);
	virtual void grow() = 0;
	virtual void cry(){ cout << "cry!!" << endl; }
protected:
	Insect(vector<Abstract*>* abs_list, int size, int max_age, SEX sex) :Animal(abs_list, size, max_age, sex) {}
	virtual Insect* clone(vector<Abstract*>* abs_list, int size, int max_age, SEX sex) = 0;
	virtual string* get_species() = 0;
	static void addPrototype(Insect* insect);
private:
	static map<string*, Insect*> prototype_;
};

inline void Insect::addPrototype(Insect * insect)
{
	prototype_.insert(map<string*, Insect*>::value_type(insect->get_species(), insect));
}
map<string*, Insect*> Insect::prototype_;

void Insect::time_pass_by()
{
	grow();
}

void Insect::update(Abstract* abs, AbstractType type)
{

}

void Insect::breath(Atmosphere* atm)
{

}