#pragma once
#include "Insect.h"
#include "Time.h"

class Bee :public Insect
{
public:
	virtual ~Bee(){}
	//*��ȡ����
	virtual string* get_species();
	//*��Ӧ������
	//*�������۷����糿ʱ�������顣
	virtual void do_morning();
	//*��Ӧ������
	//*�������۷�������ʱ�������顣
	virtual void do_noon();
	//*��Ӧ������
	//*�������۷�������ʱ�������顣
	virtual void do_afternoon();
	//*��Ӧ������
	//*�������۷�������ʱ�������顣
	virtual void do_night();
	//*���ڸ���ԭ�������۷��ʵ��
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