#include "Mammals.h"

Mammals::Mammals(vector<Abstract*>* abs_list, int size, int max_age) :Animal(abs_list, size, max_age) {

}

void Mammals::run(){
	cout << "I will run for a while." << endl;
}

void Mammals::go_into_fence(Fence* fence) {
	fence->let_in(this);
}

void Mammals::go_out_of_fence(Fence* fence) {
	fence->let_out(this);
}
