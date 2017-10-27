#pragma once
#include "Insect.h"

class Bee :public Insect
{
public:
	virtual string* get_species();
	virtual void when_atmosphere_changed();
	virtual void grow();
	virtual void cry();
	virtual void die();
	virtual Insect* clone(vector<Abstract*>* abs_list, int size, SEX sex);
	virtual Living* mate_with(vector<Abstract*>* abs_list, Living* another){ return NULL; }
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

Insect * Bee::clone(vector<Abstract*>* abs_list, int size, SEX sex)
{
	Bee* temp = new Bee(abs_list, size, 900, sex, 1);
	return temp;
}
void Bee::when_atmosphere_changed()
{

}
void Bee::grow()
{
	
}
void Bee::cry()
{
	cout << "Bee:cry!" << endl;
}
void Bee::die()
{
	cout << "Bee:die!" << endl;
}