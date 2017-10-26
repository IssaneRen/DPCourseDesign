#include "Animal.h"


Animal::Animal(vector<Abstract*>* abs_list, int size, int max_age, SEX sex)
	:Living(abs_list, size, max_age, sex), hunger_(0), thirsty_(0){

}

bool Animal::eat(Entity* food){
	if (hunger_ <= 0){
		return false;
	}
	hunger_--;
	return true;

}


bool Animal::drink(){
	if (thirsty_ <= 0){
		return false;
	}
	thirsty_--;
	return true;
}