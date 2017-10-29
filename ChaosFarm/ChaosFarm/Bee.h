#pragma once
#include "Insect.h"
#include "Time.h"

class Bee :public Insect
{
public:
	virtual ~Bee(){}
	virtual string* get_species();
	virtual float get_reproduction_rate();
	virtual void grow();
	virtual void die();
	virtual void do_morning();
	virtual void do_noon();
	virtual void do_afternoon();
	virtual void do_night();
	virtual Insect* clone(vector<Abstract*>* abs_list, int size);
	virtual Living* mate_with(vector<Abstract*>* abs_list, Living* another){ return NULL; }
	virtual const char* get_class_name(){ return "Bee"; }
protected:
	Bee(vector<Abstract*>* abs_list, int size, int dummy) :Insect(abs_list, size, 900){}
private:
	static Bee bee_;
	Bee() :Insect(NULL, 0, 0){ addPrototype(this); }
};
Bee Bee::bee_;

string* Bee::get_species()
{
	return new string("bee");
}

Insect * Bee::clone(vector<Abstract*>* abs_list, int size)
{
	Bee* temp = new Bee(abs_list, size, 1);
	return temp;
}
float Bee::get_reproduction_rate()
{
	return reproduction_rate_;
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

void Bee::die()
{
	format_output("Bee::die()", "is dead.");
}

void Bee::do_morning()
{
	format_output("Bee::get_up()", "is flying.");
}
void Bee::do_noon()
{
	format_output("Bee::produce_honey()", "is busily gathering honey.");
}
void Bee::do_afternoon()
{
	format_output("Bee::produce_honey()", "is busily gathering honey.");
}
void Bee::do_night()
{
	format_output("Bee::sleep()", "zzz...");
}