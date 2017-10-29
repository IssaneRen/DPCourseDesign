#ifndef CF_FARM_PRODUCT_H
#define CF_FARM_PRODUCT_H
#include "Entity.h"
#include <string>
using namespace std;

class FarmProduct :public Entity{
public:

	FarmProduct(vector<Abstract*>* abs_list, int size, const char* name, int price) :Entity(abs_list, size),price_(price){
		name_ = new string(name);
	}

	~FarmProduct(){ delete name_; }

	void set_name(const char* name){ delete name_; name_ = new string(name); }

	void set_price(int price){ price_ = price; }
	
	const int get_rice(){ return price_; }

	const char* get_name(){ return name_->c_str(); }

	virtual const char* get_class_name(){ return "FarmProduct"; }

private:
	string* name_;				//ũ��Ʒ������
	int price_;					//ũ��Ʒ�ļ۸�
};


#endif