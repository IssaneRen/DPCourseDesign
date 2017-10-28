#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include "Chicken.h"
#include "Atmosphere.h"
#include "AbstractType.h"
#include "Time.h"

Chicken::Chicken(vector<Abstract*>* abs_list, int size, int max_age, SEX sex) :Poultry(abs_list, size, max_age, sex) 
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

Living* Chicken::mate_with(vector<Abstract*>* abs_list,Living* another)
{
	int max_size = max(size_, another->get_size());
	int min_size = min(size_, another->get_size());
	srand((unsigned)time(NULL));

	int size = rand() % (max_size - min_size + 1) + min_size;
	SEX sex = (SEX)(rand() % 2 + 1);

	Chicken* child = new Chicken(abs_list, size, 100, sex);
	return child;
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
	if (sex_ == MALE)
	{
		cout << "I am a cock." << endl;
		return;
	}
	else
	{
		cout << "I am a hen." << endl;
		return;
	}
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
	if (sex_ != FEMALE)
	{
		cout << "Only hen can lay egg!" << endl;
		return;
	}
	cout << "I have laid an egg." << endl;
	return;
}

void Chicken::incubate()
{
	if (sex_ != FEMALE)
	{
		cout << "Only hen can incubate the eggs!" << endl;
		return;
	}
	cout << "I am incubating the eggs." << endl;
	return;
}
