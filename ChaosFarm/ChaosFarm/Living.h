#ifndef CF_LIVING_H
#define CF_LIVING_H
#include "Entity.h"
#include "Atmosphere.h"
#include<string>
using namespace std;


class Living :public Entity{
public:
	Living(vector<Abstract*>* abs_list, int size, int max_age);

	virtual ~Living(){}

	virtual const char* get_class_name(){ return "Living"; }

	virtual void die(){
		alive_ = false;
		cout << get_class_name() << ":" << id_ << ":" << "the living is dead just now." << endl;
	}

	virtual void grow() = 0;

	virtual void time_pass_by() = 0;

	virtual void when_atmosphere_changed() = 0;

	int get_age() { return age_; }
protected:
	int age_;
	int max_age_;
	int health_;
	bool alive_;
};


#endif // !CF_ENTITY_H



