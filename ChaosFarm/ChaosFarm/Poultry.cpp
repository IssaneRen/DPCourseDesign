#include "Poultry.h"

Poultry::Poultry(vector<Abstract*>* abs_list, int size, int max_age) :Animal(abs_list, size, max_age) {

}

void Poultry::fly(){
	cout << "I have flied a short distance." << endl;
}

