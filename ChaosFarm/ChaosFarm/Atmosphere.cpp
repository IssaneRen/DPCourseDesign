#include "Atmosphere.h"


Atmosphere::Atmosphere()
{
}

Atmosphere::~Atmosphere()
{
}

Atmosphere* Atmosphere::atmosphere = new Atmosphere();

Atmosphere* Atmosphere::getInstance(){
	return atmosphere;
}

void Atmosphere::change_water_content(float new_content){
	atmosphere->water_content = new_content;
}

void Atmosphere::change_oxygen_content(float new_content){
	atmosphere->oxygen_content = new_content;
}

void Atmosphere::change_carbon_dioxide_content(float new_content){
	atmosphere->carbon_dioxide_content = new_content;
}

void Atmosphere::change_microorganism_content(float new_content){
	atmosphere->microorganism_content = new_content;
}

void Atmosphere::change_weathertype(weather_type new_weather){
	atmosphere->weather = new_weather;
}

void Atmosphere::add_smell(SmellType smell, float concentration){
	atmosphere->smell[smell] = concentration;
}
