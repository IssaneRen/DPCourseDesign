#include<map>
#include "Animal.h"

class Insect:public Animal
{
public:
	static Insect* find_and_clone(vector<Abstract*>* abs_list, int size, int max_age, string* name, SEX sex, string* species);
	virtual void time_pass_by();
	virtual void when_atmosphere_changed();
	virtual void update(Abstract* abs, AbstractType type);
	virtual Living* mate_with(Living* another);
	virtual void breath(Atmosphere* atm);
	virtual void grow();
protected:
	Insect(vector<Abstract*>* abs_list, int size, int max_age, string* name, SEX sex);
	virtual Insect* clone(vector<Abstract*>* abs_list, int size, int max_age, string* name, SEX sex) = 0;
	virtual string* get_species() = 0;
	static void addPrototype(Insect* insect);
private:
	static map<string*, Insect*> prototype_;
};

Insect::Insect(vector<Abstract*>* abs_list, int size, int max_age, string* name, SEX sex):Animal(abs_list,size,max_age,name,sex)
{
	
}

inline void Insect::addPrototype(Insect * insect)
{
	prototype_.insert(map<string*, Insect*>::value_type(insect->get_species(), insect));
}

Insect* Insect::find_and_clone(vector<Abstract*>* abs_list, int size, int max_age, string* name, SEX sex, string* species)
{
	map<string*, Insect*>::iterator it;
	it = prototype_.find(species);
	return (*it).second->clone(abs_list, size, max_age, name, sex);
}
map<string*, Insect*> Insect::prototype_;