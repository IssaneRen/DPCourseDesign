#include "Living.h"


Living::Living(vector<Abstract*>* abs_list, int size, int max_age) 
	:Entity(abs_list, size), age_(0), max_age_(max_age), grow_speed_(1.0), health_gradient_(0), health_(100){

}
