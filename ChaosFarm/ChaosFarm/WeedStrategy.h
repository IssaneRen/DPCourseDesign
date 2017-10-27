#pragma once
#ifndef CF_WEEDSTRATEAGY_H
#define CF_WEEDSTRATEAGY_H

using namespace std;

class WeedStrategy
{
public:
	WeedStrategy(){}
	
	void format()
	{
		justify();
	}
private:
	virtual void justify() = 0;
};

class SingStrategy : public WeedStrategy
{
public:
	SingStrategy() {};
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
private:
	void justify()
	{
		cout << "Weed is chatting"
			<< endl;
	}
};

#endif
