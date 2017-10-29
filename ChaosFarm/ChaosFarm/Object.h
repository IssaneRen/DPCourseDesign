#ifndef CF_OBJECT_H
#define CF_OBJECT_H
#include<iostream>
#include<string>

using namespace std;

class Object{
public:
	Object(){ id_ = counter_++; }

	~Object(){}

	int get_id(){ return id_; }

	virtual const char* get_class_name(){ return "Object"; }

protected:
	int id_;

	static int counter_;
};



#endif