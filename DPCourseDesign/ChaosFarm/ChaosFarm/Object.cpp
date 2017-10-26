#include "Object.h"

int Object::counter_for_id_ = 0;


Object::Object(){
	id_ = counter_for_id_++;
}

void Object::report(){
	cout << "Object " << id_ << " is reporting" << endl;
}