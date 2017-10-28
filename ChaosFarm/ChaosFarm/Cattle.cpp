#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include "Cattle.h"
#include "Atmosphere.h"
#include "AbstractType.h"
#include "Time.h"

Cattle::Cattle(vector<Abstract*>* abs_list, int size, int max_age) :Mammals(abs_list, size, max_age) 
{

}

void Cattle::time_pass_by()
{
	Time* time = Time::instance();
	int time_container[4];

	time->get_time(time_container);
	cout << "It's " << time_container[3] << ":00, " << time_container[1] << "." << time_container[2] << "." << time_container[0] << " now." << endl;
}

void Cattle::when_atmosphere_changed()
{
	cout << "Atmosphere has changed." << endl;
}

void Cattle::die()
{
	cout << "A cattle is dead." << endl;
}


void Cattle::breath(Atmosphere* atm)
{
	cout << "A cattle is breathing." << endl;
}

void Cattle::grow()
{
	age_ += 1;
}

bool Cattle::eat(Entity* food) 
{
	if (hunger_ <= 0) 
	{
		cout << "I am not hungry, and don't want to eat." << endl;
		return false;
	}
	cout << "I have ate some food." << endl;
	hunger_--;
	return true;

}

void Cattle::cry()
{
	cout << "A cattle is crying!" << endl;
}

bool Cattle::drink() 
{
	if (thirsty_ <= 0) 
	{
		cout << "I am not thirsty, and don't want to drink." << endl;
		return false;
	}
	cout << "I have drunk some water." << endl;
	thirsty_--;
	return true;
}

void Cattle::produce_milk()
{
	cout << "I have produced some milk." << endl;
	return;
}

void Cattle::farrow()
{
	cout << "I am farrowing." << endl;
	return;
}
