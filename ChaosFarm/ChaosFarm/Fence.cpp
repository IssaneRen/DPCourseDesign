#include "Fence.h"


Fence::Fence(vector<Abstract*>* abs_list, int size, int init_durability, int max_size)
	:Facility(abs_list, size, init_durability), max_size_(max_size)
{
	animals_ = new Animal*[max_size_];
	for (int i = 0; i < max_size_; i++)animals_[i] = NULL;
}

Animal* Fence::get_start(){
	return animals_[0];
}


Animal* Fence::get_end(){
	return (animals_[size_-1]);
}

bool Fence::remove_at(FenceIterator& it){
	int pos = 0;
	for (; pos < size_; pos++){
		if (it == animals_[pos]){
			for (int i = pos; i < size_ - 1; i++){
				animals_[i] = animals_[i + 1];
			}
			return true;
		}
	}
	return false;
}


bool Fence::let_in(Animal* animal){
	if (size_ >= max_size_)return false;
	animals_[size_++] = animal;
	return true;
}


bool Fence::let_out(Animal* animal){
	for (FenceIterator it = get_start(); it != get_end(); ++it){
		if (it == animal){
			remove_at(it);
			return true;
		}
	}
	return false;
}


bool Fence::let_out(string* animal_name){
	for (FenceIterator it = get_start(); it != get_end(); ++it){
		if ((*it).get_name() == animal_name){
			remove_at(it);
			return true;
		}
	}
	return false;
}


void Fence::expand(int ex_size){
	max_size_ += ex_size;
	Animal** new_animals_ = new Animal*[max_size_];
	for (int i = 0; i < size_; i++){
		new_animals_[i] = animals_[i];
	}
	delete[] animals_;
	animals_ = new_animals_;
}


void Fence::update(Abstract* abs, AbstractType type){
	switch (type){
	case ERROR:break;
	case TIME:time_pass_by(); break;
	case ATMOSPHERE:when_atmosphere_changed(); break;
	default:break;
	}
}