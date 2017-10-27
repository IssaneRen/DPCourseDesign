#include "Object.h"
#include "Time.h"
#include "Crop.h"
#include "InsectGroup.h"
#include "Insect.h"
#include "Time.h"
#include "InsectGroup.h"
#include "Bee.h"
#include "Weed.h"
#include "BaseFarmland.h"

int main(){
	BaseFarmLand* base_farm_land = new BaseFarmLand(NULL, 100, 100, "base farmland", 0.3);
	FarmLand* farm_land = new FarmLand(base_farm_land);
	EffectFarmLand* effect_farm_land = new EffectFarmLand(farm_land);
	Crop* crop = new Crop(NULL, 10, 50);
	crop->plant_on(effect_farm_land);
	cout << "Because the crop is planted on an effect farmland, its output rate is set to " << crop->get_output_rate() << "." << endl;
	system("pause");
	return 0;
}