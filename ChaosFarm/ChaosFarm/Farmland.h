#ifndef CF_FARMLAND_H
#define CF_FARMLAND_H

#include <iostream>
using namespace std;
#include <string>
#include<vector>
#include"Facility.h"
#include"Time.h"
#include"Atmosphere.h"

class Farmland:public Facility{
public:
	Farmland(vector<Abstract*>* abs, int size, int duarability,const char* desc)
		:Facility(abs,size,duarability)
	{
		description_ = new string(desc);
	}
	virtual const char* get_discription() const { return description_->c_str(); }
	virtual int size() { return f_size_; }
	void plow(){
	cout<<"Farmland has plowed."<<endl ;
	}
	void when_atmosphere_changed(){
		cout << "smell changed."<<endl;
	}
	void time_pass_by() {
		f_size_ -= 2;
		if (f_size_ < 0)
		{
			f_size_ = 0;
		}
		cout <<"current size is "<< f_size_<<endl;
	}
	void update(Abstract* abs, AbstractType type){ 
		m_abs = abs;
		if (type == 1)
		{
			time_pass_by();
		}
		if (type == 2)
		{
			when_atmosphere_changed();
		}
		if (type == 0)
		{
			cout << "error" << endl;
		}


	}
private:
	string* description_;
	int f_size_=20 ;
	Abstract* m_abs;
};
/*
//装饰者模式 
class Manure : public Farmland {
public:
	const char* get_discription() const {
		return "";
	}
};

//将土地分为黑土地和红土地，size不同 
class Blackland : public Farmland {
public:
	Blackland() {
		this->description_ = "Blackland";
	}
	string get_discription() const {
		return "Blackland";
	}
	int size() {
		return 50;
	}
private:
	string description_;
};

class Redland : public Farmland {
public:
	Redland() {
		this->description_ = "Redland";
	}
	string get_discription() const {
		return "Redland";
	}
	int size() {
		return 80;
	}
private:
	string description_;
};


//装饰具体类，施肥会扩大size 
class Kcl : public Manure {
public:
	Kcl(Farmland* f) : farmland_(f) { }
	string get_discription() const {
		return farmland_->get_discription() + ",Kcl";
	}
	int size() {
		return 20 + farmland_->size();
	}
private:
	Farmland* farmland_;
};

class Nh4 : public Manure {
public:
	Nh4(Farmland* f) : farmland_(f) { }
	string get_discription() const {
		return farmland_->get_discription() + ",Nh4";
	}
	int size() {
		return 30 + farmland_->size();
	}
private:
	Farmland *farmland_;
};

//命令模式
class Command{
public:
	virtual void execute() { }
};

//具体命令类
class Plow : public Command{
public:
	Plow(Farmland* f) : farmland_(f) { }
	void execute(){
		farmland_->plow();
	}
private:
	Farmland* farmland_;
};

class Smell : public Command {
public:
	Smell(Farmland* f) : farmland_(f) { }
	void execute() {
		farmland_->when_atmosphere_changed();
	}
private:
	Farmland* farmland_;
};

class Ftime :public Command {
public:
	Ftime(Farmland* f) : farmland_(f) { }
	void execute() {
		farmland_->time_pass_by();
	}
private:
	Farmland* farmland_;
};
//控制类
class Control{
public:
	Control(){
		Command* nocommand = new Command();
		for (int i = 0; i <= 2; i++)
		{
			commands_.push_back(nocommand);
		}
	}
	void set_command(int slot,Command* c) {
		commands_[slot] = c;
	}
	void button_is_pressed(int slot){
		commands_[slot]->execute();
	}
private:
	vector<Command*>commands_;
};



*/

#endif