#ifndef CF_FENCE_H
#define CF_FENCE_H
#include "Facility.h"
#include "Animal.h"
typedef Animal* FenceIterator;


class Fence:public Facility{

public:

	Fence(vector<Abstract*>* abs_list, int size, int init_durability = 100, int max_size = 10);

	~Fence(){ delete[] animals_; }

	Animal* get_start();

	Animal* get_end();

	bool remove_at(FenceIterator& it);

	bool let_in(Animal* animal);

	bool let_out(Animal* animal);

	bool let_out(string* animal_name);

	void expand(int ex_size);

	virtual void time_pass_by(){ durability_--; }

	virtual void when_atmosphere_changed(){}

	virtual void update(Abstract* abs, AbstractType type);

protected:
	Animal** animals_;

	int max_size_;

};


#endif