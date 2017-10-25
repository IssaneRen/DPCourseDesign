#include "Abstract.h"


bool Abstract::remove_observer(Entity* observer){
	if (observer_pool_->empty())return false;
	for (vector<Entity*>::iterator it = observer_pool_->begin(); it != observer_pool_->end(); it++){
		if ((*it) == observer)observer_pool_->erase(it);
		return true;
	}
	return false;
}




void Abstract::notify(){
	if (observer_pool_->empty())return;
	for (vector<Entity*>::iterator it = observer_pool_->begin(); it != observer_pool_->end(); it++){
		(*it)->update(this, AbstractType::ERROR);
	}
}