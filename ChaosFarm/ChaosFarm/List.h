#pragma once
#include "Object.h"

class Node :public Object
{
public:
	Node();
	Node(Object* value);
	~Node();
	Node* get_previous();
	Object* get_value();
	Node* get_next();
	void set_previous(Node* previous);
	void set_value(Object* value);
	void set_next(Node* next);
	void delete_content();
	virtual const char* get_class_name(){ return "Node"; }
private:
	Node* previous_;
	Object* content_;
	Node* next_;
};

class List :public Object
{
public:
	List();
	Node* head();
	void add(Node* new_node);
	void remove(Node* node);
	void erase(Node* node);
	int size();
	bool is_empty();
	virtual const char* get_class_name(){ return "List"; }
private:
	Node* head_;
	int size_;
};