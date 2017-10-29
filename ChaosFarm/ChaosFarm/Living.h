#ifndef CF_LIVING_H
#define CF_LIVING_H
#include "Entity.h"
#include "Atmosphere.h"
#include<string>
using namespace std;


class Living :public Entity{
public:
	Living(vector<Abstract*>* abs_list, int size, int max_age);

	~Living(){}

	virtual const char* get_class_name(){ return "Living"; }

	virtual void die(){
		cout << get_class_name() << ":" << id_ << ":" << "the living is dead just now." << endl;
	}

	virtual void grow(){
		age_++;
		if (age_ >= max_age_)die();
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

	int get_age() { return age_; }
	void set_alive(bool alive) { alive_ = alive; }
	bool is_alive() { return alive_; }
protected:
	int age_;
	int max_age_;
	int health_;							 //��0��������
	bool alive_;
};


#endif // !CF_ENTITY_H



