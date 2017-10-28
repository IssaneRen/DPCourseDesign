#include "Mammals.h"

Mammals::Mammals(vector<Abstract*>* abs_list, int size, int max_age) :Animal(abs_list, size, max_age) {

}

void Mammals::run(){
	cout << "I will run for a while." << endl;
}
