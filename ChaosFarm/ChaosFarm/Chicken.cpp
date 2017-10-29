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




void Chicken::cry()
{
	format_output("Chicken::cry()", "cluck  cluck  cluck !!!");
}

void Chicken::drink() 
{
	format_output("Chicken::drink() ", "the water is great.");
}



void Chicken::do_morning(){
	cry();
}


void Chicken::do_noon(){
	lay_egg();
}


void Chicken::do_afternoon(){
	incubate();
}


void Chicken::do_night(){
	sleep();
}