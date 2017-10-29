#pragma once
#ifndef CF_WEEDSTRATEAGY_H
#define CF_WEEDSTRATEAGY_H

using namespace std;

class WeedStrategy:public Object
{
public:
	WeedStrategy(){}
	
	void format()
	{
		justify();
	}
	virtual const char* get_class_name(){ return "WeedStrategy"; }
private:
	virtual void justify() = 0;
};

class SingStrategy : public WeedStrategy
{
public:
	SingStrategy() {};
	virtual const char* get_class_name(){ return "SingStrategy"; }
private:
	void justify()
	{
		cout << "Weed is singing"
			<< endl;
	}
};

class DanceStrategy: public WeedStrategy
{
public:
	DanceStrategy() {};
	virtual const char* get_class_name(){ return "DanceStrategy"; }
private:
	void justify()
	{
		cout << "Weed is dancing"
			<< endl;
	}
};

class ChatStrategy : public WeedStrategy
{
public:
	ChatStrategy() {};
	virtual const char* get_class_name(){ return "ChatStrategy"; }
private:
	void justify()
	{
		cout << "Weed is chatting"
			<< endl;
	}
};

#endif