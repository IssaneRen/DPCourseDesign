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


void Chicken::when_atmosphere_changed()
{
	cout << "Atmosphere has changed." << endl;
}


void Chicken::cry()
{
	cout << "A chicken is crying." << endl;
}

void Chicken::drink() 
{
	cout << "Chiken:" << id_ << "drink(): the chicken is drinking." << endl;
}



void Chicken::do_morning(){
	cout << "Chicken:" << id_ << ":do_morning(): the chicken is crowing." << endl;
}


void Chicken::do_noon(){
	lay_egg();
}


void Chicken::do_afternoon(){
	incubate();
}


void Chicken::do_night(){
	cout << "Chicken:" << id_ << ":do_night(): the chicken is sleeping." << endl;
}