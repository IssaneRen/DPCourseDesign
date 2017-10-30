#include "FarmLand.h"
#pragma execution_character_set("utf-8")

void DecoratedFarmLand::plant_a_crop(Crop* crop){
	base_farmland_->plant_a_crop(crop);
	format_output("DecoratedFarmLand::plant_a_crop()", "a crop is planted.");
}

void EffectFarmLand::plant_a_crop(Crop* crop){
	base_farmland_->plant_a_crop(crop);
	crop->set_output_rate(base_farmland_->get_fertility());
	format_output("EffectFarmLand::plant_a_crop()", "the output rate of the crop is changed.");
}