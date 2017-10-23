#include "Animal.h"


Animal::Animal(vector<Abstract*>* abs_list, int size, int max_age, string* name, SEX sex)
	:Living(abs_list, size, max_age, name, sex), hunger_(0), thirsty_(0){

}

bool Animal::eat(Entity* food){
	if (hunger_ <= 0){
		cout << name_ << "is not hungry, and don't want to eat." << endl;
		return false;
	}
	hunger_--;
	return true;

}


bool Animal::drink(){
	if (thirsty_ <= 0){
		cout << name_ << "is not hungry, and don't want to drink." << endl;
		return false;
	}
	thirsty_--;
	return true;
}