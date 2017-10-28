#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include "Chicken.h"
#include "Atmosphere.h"
#include "AbstractType.h"
#include "Time.h"

Chicken::Chicken(vector<Abstract*>* abs_list, int size, int max_age) :Poultry(abs_list, size, max_age) 
{

}

void Chicken::time_pass_by()
{
	Time* time = Time::instance();
	int time_container[4];

	time->get_time(time_container);
	cout << "It's " << time_container[3] << ":00, " << time_container[1] << "." << time_container[2] << "." << time_container[0] << " now." << endl;
}

void Chicken::when_atmosphere_changed()
{
	cout << "Atmosphere has changed." << endl;
}

void Chicken::die()
{
	cout << "A chicken is dead." << endl;
}


void Chicken::breath(Atmosphere* atm)
{
	cout << "A chicken is breathing." << endl;
}

void Chicken::grow()
{
	age_ += 1;
}

bool Chicken::eat(Entity* food) 
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

void Chicken::cry()
{
	cout << "A chicken is crying." << endl;
}

bool Chicken::drink() 
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

void Chicken::lay_egg()
{
	cout << "I have laid an egg." << endl;
	return;
}

void Chicken::incubate()
{
	cout << "I am incubating the eggs." << endl;
	return;
}
