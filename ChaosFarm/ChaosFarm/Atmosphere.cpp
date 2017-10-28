#include "Atmosphere.h"

Atmosphere* Atmosphere::instance = 0;


Atmosphere::Atmosphere()
{
	change_weathertype(SUNNY);
}

Atmosphere::~Atmosphere()
{
}


Atmosphere* Atmosphere::getInstance() {
	return instance;
}


void Atmosphere::change_weathertype(WEATHER_TYPE new_weather) {
	weather = new_weather;
	switch (new_weather){
	case SUNNY:lux_ = GOOD_LUX; break;
	case WINDY:lux_ = GOOD_LUX; break;
	case CLOUDY:lux_ = BAD_LUX; break;
	case RAINY:BAD_LUX; break;
	default:break;
	}
	notify();
}
