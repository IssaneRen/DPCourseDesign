#ifndef CF_POULTRY_H_
#define CF_POULTRY_H_
#include "Animal.h"
#include "Time.h"


class Poultry :public Animal {
public:
	Poultry(vector<Abstract*>* abs_list, int size, int max_age) :Animal(abs_list, size, max_age) {}

	~Poultry() {}

	virtual void grow(){
		age_ += Time::instance()->get_d_hour();
		if (age_ >= max_age_)die();
	}


	void fly(){ cout << "Poultry:" << id_ << ":fly(): A poultry is flying." << endl; }

	virtual void time_pass_by(){ if (alive_)Time::instance()->do_something(this); grow(); }

	virtual void lay_egg(){
		format_output("Poultry::lay_egg()", "is laying eggs.");
	}

	virtual void incubate(){
		format_output("Poultry::incubate()", "is incubating.");
	}

	virtual void do_morning() = 0;

	virtual void do_noon() = 0;

	virtual void do_afternoon() = 0;

	virtual void do_night() = 0;

	virtual const char* get_class_name(){ return "Poultry"; }


	virtual void when_atmosphere_changed(){
		Atmosphere* atm = Atmosphere::getInstance();
		switch (atm->get_weather_type()){
		case SUNNY:format_output("Poultry::when_atmosphere_changed()", "is enjoying the sunshine"); break;
		case WINDY:format_output("Poultry::when_atmosphere_changed()", "is feeling the wind"); break;
		case RAINY:format_output("Poultry::when_atmosphere_changed()", "try to take a shelter from rain"); break;
		case CLOUDY:format_output("Poultry::when_atmosphere_changed()", "is not happy"); break;
		default:break;
		}
	}
};
#endif 

