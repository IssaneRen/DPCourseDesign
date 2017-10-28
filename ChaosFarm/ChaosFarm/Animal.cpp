#include "Animal.h"


Animal::Animal(vector<Abstract*>* abs_list, int size, int max_age)
	:Living(abs_list, size, max_age), hunger_(0), thirsty_(0){

}




bool Animal::drink(){
	if (thirsty_ <= 0){
		return false;
	}
	thirsty_--;
	return true;
}