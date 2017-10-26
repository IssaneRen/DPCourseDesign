#include "Collection.h"
#include "Insect.h"
#include<vector>

class InsectGroup :public Collection
{
public:
	InsectGroup(string* species) :species_(species) {};
	virtual FarmIterator* create_iterator();
	virtual int size();
	virtual bool is_empty();
	virtual FarmIterator* begin();
	virtual FarmIterator* end();
	void hatch(int number, vector<Abstract*>* abs_list, int size, int max_age, string* name, SEX sex);
private:
	string* species_;
	vector<Insect*> list_;
	virtual void add(Object* new_element) {};
};