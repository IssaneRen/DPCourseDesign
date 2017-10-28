#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include "Cattle.h"
#include "Atmosphere.h"
#include "AbstractType.h"
#include "Time.h"

Cattle::Cattle(vector<Abstract*>* abs_list, int size, int max_age, SEX sex) :Mammals(abs_list, size, max_age, sex) 
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

Living* Cattle::mate_with(vector<Abstract*>* abs_list,Living* another)
{
	int max_size = max(size_, another->get_size());
	int min_size = min(size_, another->get_size());
	srand((unsigned)time(NULL));

	int size = rand() % (max_size - min_size + 1) + min_size;
	SEX sex = (SEX)(rand() % 2 + 1);

	Cattle* child = new Cattle(abs_list, size, 100, sex);
	return child;
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
	if (sex_ == MALE)
	{
		cout << "I am a box." << endl;
		return;
	}
	else
	{
		cout << "I am a cow." << endl;
		return;
	}
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
	if (sex_ != FEMALE)
	{
		cout << "Only cows can produce milk!" << endl;
		return;
	}
	cout << "I have produced some milk." << endl;
	return;
}

void Cattle::farrow()
{
	if (sex_ != FEMALE)
	{
		cout << "Only cows can farrow!" << endl;
		return;
	}
	cout << "I am farrowing." << endl;
	return;
}
