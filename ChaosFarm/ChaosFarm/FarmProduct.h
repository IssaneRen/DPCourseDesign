#ifndef CF_FARM_PRODUCT_H
#define CF_FARM_PRODUCT_H
#include "Entity.h"
#include <string>
using namespace std;

class FarmProduct :public Entity{
public:

	FarmProduct(vector<Abstract*>* abs_list, int size, const char* name);

	~FarmProduct(){ delete name_; }

	void set_name(const char* name){ delete name_; name_ = new string(name); }

	const char* get_name(){ return name_->c_str(); }

private:
	string* name_;
};


#endif