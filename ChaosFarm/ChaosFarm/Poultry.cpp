#include "Poultry.h"

Poultry::Poultry(vector<Abstract*>* abs_list, int size, int max_age, SEX sex) :Animal(abs_list, size, max_age, sex) {

}

void Poultry::fly(){
	cout << "I have flied a short distance." << endl;
}

void Poultry::go_into_fence(Fence* fence) {
	fence->let_in(this);
}

void Poultry::go_out_of_fence(Fence* fence) {
	fence->let_out(this);
}
