#pragma once
#include "Insect.h"
#include "Time.h"
#include "Atmosphere.h"

class Bee :public Insect
{
public:
	virtual string* get_species();
	virtual float get_reproduction_rate();
	virtual void when_atmosphere_changed();
	virtual void grow();
	virtual void cry();
	virtual void die();
	void produce_honey();
	virtual Insect* clone(vector<Abstract*>* abs_list, int size, SEX sex);
	virtual Living* mate_with(vector<Abstract*>* abs_list, Living* another){ return NULL; }
protected:
	Bee(vector<Abstract*>* abs_list, int size, SEX sex, int dummy) :Insect(abs_list, size, 900, sex) {}
private:
	static Bee bee_;
	float reproduction_rate_; 
	Bee() :Insect(NULL, 0, 0, NON),reproduction_rate_(1) { addPrototype(this); }
};
Bee Bee::bee_;

string* Bee::get_species()
{
	return new string("bee");
}

Insect * Bee::clone(vector<Abstract*>* abs_list, int size, SEX sex)
{
	Bee* temp = new Bee(abs_list, size, sex, 1);
	return temp;
}
float Bee::get_reproduction_rate()
{
	return reproduction_rate_;
}
void Bee::when_atmosphere_changed()
{
	Atmosphere* atmosphere = Atmosphere::getInstance();

}
void Bee::grow()
{
	Time* time = Time::instance();
	if (age_ < max_age_)
	{
		age_ = age_ + time->get_d_hour();
		if (age_ >= max_age_)
		{
			die();
		}
	}
}
void Bee::cry()
{
	cout << "Bee:cry!" << endl;
}
void Bee::die()
{
	cout << "Bee:die!" << endl;
}
void Bee::produce_honey()
{

}