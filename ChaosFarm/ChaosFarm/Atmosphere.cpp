#include "Atmosphere.h"

Atmosphere* Atmosphere::instance_ = 0;


Atmosphere::Atmosphere()
{


	change_weathertype(SUNNY);
}

Atmosphere::~Atmosphere()
{
}


Atmosphere* Atmosphere::getInstance() {
	if (!instance_)instance_ = new Atmosphere();
	return instance_;
}


void Atmosphere::change_weathertype(WEATHER_TYPE new_weather) {
	weather_ = new_weather;
	switch (new_weather){
	case SUNNY:lux_ = GOOD_LUX; format_output("Atmosphere::change_weathertype()", "it is sunny now."); break;
	case WINDY:lux_ = GOOD_LUX; format_output("Atmosphere::change_weathertype()", "it is windy now."); break;
	case CLOUDY:lux_ = BAD_LUX; format_output("Atmosphere::change_weathertype()", "it is cloudy now."); break;
	case RAINY:BAD_LUX; format_output("Atmosphere::change_weathertype()", "it is rainy now."); break;
	default:break;
	}
	notify();
}

void Atmosphere::notify(){
	if (observer_pool_->empty())return;
	for (vector<Entity*>::iterator it = observer_pool_->begin(); it != observer_pool_->end(); it++){
		(*it)->update(AbstractType::ATMOSPHERE);
	}
}