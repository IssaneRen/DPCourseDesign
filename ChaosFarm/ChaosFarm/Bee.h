#pragma once
#include "Insect.h"
#include "Time.h"

class Bee :public Insect
{
public:
	virtual ~Bee(){}
	//*获取种类
	virtual string* get_species();
	//*反应函数。
	//*表征此蜜蜂在早晨时做的事情。
	virtual void do_morning();
	//*反应函数。
	//*表征此蜜蜂在中午时做的事情。
	virtual void do_noon();
	//*反应函数。
	//*表征此蜜蜂在下午时做的事情。
	virtual void do_afternoon();
	//*反应函数。
	//*表征此蜜蜂在晚上时做的事情。
	virtual void do_night();
	//*用于根据原型制作蜜蜂的实例
	virtual Insect* clone(vector<Abstract*>* abs_list, int size);
	virtual const char* get_class_name(){ return "Bee"; }
protected:

	Bee(vector<Abstract*>* abs_list, int size, int dummy) :Insect(abs_list, size, 900){}
private:
	static Bee bee_;
	Bee() :Insect(NULL, 0, 0){ addPrototype(this); }
};
Bee Bee::bee_;

string* Bee::get_species()
{
	return new string("bee");
}

Insect * Bee::clone(vector<Abstract*>* abs_list, int size)
{
	Bee* temp = new Bee(abs_list, size, 1);
	return temp;
}

void Bee::do_morning()
{
	format_output("Bee::get_up()", "is flying.");
}
void Bee::do_noon()
{
	format_output("Bee::produce_honey()", "is busily gathering honey.");
}
void Bee::do_afternoon()
{
	format_output("Bee::produce_honey()", "is busily gathering honey.");
}
void Bee::do_night()
{
	format_output("Bee::sleep()", "zzz...");
}