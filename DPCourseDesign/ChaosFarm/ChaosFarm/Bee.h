#include "Insect.h"

class Bee :public Insect
{
public:
	virtual string* get_species();
	virtual Insect* clone(vector<Abstract*>* abs_list, int size, int max_age, string* name, SEX sex);
protected:
	Bee(vector<Abstract*>* abs_list, int size, int max_age, string* name, SEX sex, int dummy) :Insect(abs_list, size, max_age, name, sex) {}
private:
	static Bee bee_;
	Bee(vector<Abstract*>* abs_list, int size, int max_age, string* name, SEX sex) :Insect(abs_list, size, max_age, name, sex) { addPrototype(this); }
};
Bee Bee::bee_;