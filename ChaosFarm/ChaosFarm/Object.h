#ifndef CF_OBJECT_H
#define CF_OBJECT_H
#include<iostream>
#include<string>

using namespace std;

class Object{
public:
	Object(){ id_ = counter_++; }

	virtual ~Object(){}

	int get_id(){ return id_; }

	virtual const char* get_class_name(){ return "Object"; }

	virtual void format_output(const char* class_function_name, const char* message = ""){
		cout << get_class_name() << " : " << id_ << " : " << class_function_name << " : " << message << endl;
	}

protected:
	int id_;

	static int counter_;
};



#endif