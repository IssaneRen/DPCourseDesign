#include "Living.h"


Living::Living(vector<Abstract*>* abs_list, int size, int max_age) 
	:Entity(abs_list, size), age_(0), max_age_(max_age),health_(100), alive_(true){

}
