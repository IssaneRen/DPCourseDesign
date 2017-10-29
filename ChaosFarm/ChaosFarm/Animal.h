#ifndef CF_ANIMAL_H
#define CF_ANIMAL_H
#include "Living.h"

class Animal :public Living{
public:
	Animal(vector<Abstract*>* abs_list, int size, int max_age);

	~Animal(){}

	virtual void do_morning() = 0;

	virtual void do_noon() = 0;

	virtual void do_afternoon() = 0;

	virtual void do_night() = 0;

	virtual void sleep(){ format_output("Animal::sleep()", "zzz..."); }

	virtual void cry(){
		format_output("Animal::cry()", "is crying");
	}

	virtual void drink(){
		format_output("Animal::drink()", "is driking");
	}

	virtual void time_pass_by() = 0;

	virtual void when_atmosphere_changed() = 0;


	virtual void update(AbstractType type){
		switch (type)
		{
		case ERROR:
			break;
		case TIME:time_pass_by();
			break;
		case ATMOSPHERE:when_atmosphere_changed();
			break;
		default:
			break;
		}
	}

	virtual void die(){
		alive_ = false;
		format_output("Animal::die()", "is dead");
	}														
};


#endif