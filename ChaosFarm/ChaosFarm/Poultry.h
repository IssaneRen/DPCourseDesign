#ifndef CF_POULTRY_H_
#define CF_POULTRY_H_
#include "Animal.h"
#include "Time.h"


class Poultry :public Animal {
public:
	Poultry(vector<Abstract*>* abs_list, int size, int max_age);

	~Poultry() {}

	void fly(){ cout << "Poultry:" << id_ << ":fly(): A poultry is flying." << endl; }

	virtual void time_pass_by(){ Time::instance()->do_something(this); }

	virtual void lay_egg(){
		cout << get_class_name() << ": " << id_ << " : Poultry:lay_egg(): the " << get_class_name() << " is laying eggs." << endl;
	}

	virtual void incubate() = 0;

	virtual void do_morning() = 0;

	virtual void do_noon() = 0;

	virtual void do_afternoon() = 0;

	virtual void do_night() = 0;

	virtual const char* get_class_name(){ return "Poultry"; }
};
#endif 

