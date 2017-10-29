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


void Cattle::when_atmosphere_changed()
{
	cout << "Atmosphere has changed." << endl;
}

void Cattle::die()
{
	cout << "A cattle is dead." << endl;
}


void Cattle::grow()
{
	age_ += 1;
}


void Cattle::cry()
{
	cout << "A cattle is crying!" << endl;
}

void Cattle::drink() 
{
	cout << "Cattle:" << id_ << "drink(): the cattle is drinking." << endl;
}

void Cattle::produce_milk()
{
	cout << "I have produced some milk." << endl;
	return;
}

