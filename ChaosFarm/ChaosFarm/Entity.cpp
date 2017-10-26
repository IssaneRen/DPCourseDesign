#include "Entity.h"

Entity::Entity(vector<Abstract*>* abs_list, int size):size_(size){
	if (abs_list != NULL&&!abs_list->empty()){
		for (vector<Abstract*>::iterator it = abs_list->begin(); it != abs_list->end(); it++){
			(*it)->add_observer(this);
		}
	}
}