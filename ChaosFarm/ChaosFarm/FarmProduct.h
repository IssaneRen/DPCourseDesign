#ifndef CF_FARM_PRODUCT_H
#define CF_FARM_PRODUCT_H
#include "Entity.h"
#include <string>
using namespace std;

class FarmProduct :public Entity{
public:

	FarmProduct(int size, const char* name, int price) :Entity(NULL, size),price_(price){
		name_ = new string(name);
	}

	~FarmProduct(){ delete name_; }

	void set_name(const char* name){ delete name_; name_ = new string(name); }

	void set_price(int price){ price_ = price; }
	
	const int get_rice(){ return price_; }

	const char* get_name(){ return name_->c_str(); }

	virtual const char* get_class_name(){ return "FarmProduct"; }

private:
	string* name_;				//农产品的名字
	int price_;					//农产品的价格
};


#endif