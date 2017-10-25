#include "Living.h"


Living::Living(vector<Abstract*>* abs_list, int size, int max_age, const char* name, SEX sex) 
	:Entity(abs_list, size), age_(0), max_age_(max_age), grow_speed_(1.0), health_gradient_(0), health_(100), sex_(sex){
	name_ = new string(name);

}


void Living::set_name(const char* new_name){
	delete name_;
	name_ = new string(new_name);
}