#ifndef CF_MAMMALS_H_
#define CF_MAMMALS_H_
#include "Animal.h"
#include "Time.h"


class Mammals :public Animal {
public:
	Mammals(vector<Abstract*>* abs_list, int size, int max_age):Animal(abs_list, size, max_age) {}

	~Mammals() {}

	void run(){
		format_output("Mammals::run()", "is running");
	}


	virtual void grow(){
		age_ += Time::instance()->get_d_hour();
		if (age_ >= max_age_)die();
	}

	virtual void time_pass_by(){ if (alive_) Time::instance()->do_something(this); grow(); }

	virtual void produce_milk(){
		format_output("Mammals::produce_milk()", "is producing milk");
	}

	virtual void do_morning() = 0;

	virtual void do_noon() = 0;

	virtual void do_afternoon() = 0;

	virtual void do_night() = 0;

	virtual const char* get_class_name(){ return "Mammals"; }
};
#endif 

