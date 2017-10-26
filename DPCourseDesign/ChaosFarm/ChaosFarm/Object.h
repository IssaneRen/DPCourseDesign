#ifndef CF_OBJECT_H
#define CF_OBJECT_H
#include<iostream>
#include<string>

using namespace std;

class Object{
public:
	Object();

	~Object(){}

	int get_id(){
		return id_;
	}

	virtual void report();

protected:

	int id_;

	static int counter_for_id_;
};



#endif