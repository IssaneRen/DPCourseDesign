#include "BaseFarmland.h"

void BaseFarmLand::plant_a_crop(Crop* crop){
	cout << "A crop is planted on " << (*description_) << "." << endl; 
}

void EffectFarmLand::plant_a_crop(Crop* crop){
	FarmLand::plant_a_crop(crop);
	crop->set_output_rate(fertility_); 
}