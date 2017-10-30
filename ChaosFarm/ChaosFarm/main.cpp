#include "Time.h"
#include "FarmLand.h"
#include "FarmProduct.h"
#include "Bee.h"
#include "Tool.h"
#include "UnitTool.h"
#include "CollectedTool.h"
#include "Weed.h"
#include "Stock.h"
#include "Chicken.h"
#include "Cattle.h"
#include "Farmland.h"
#include "Bee.h"
#include "Warehouse.h"

void test_chicken_time_atmosphere();
void test_farmland();

int main() {
	InsectGroup* beeGroup = new InsectGroup(new string("bee"));

	for (int i = 0; i < 20; i++)
	{
		beeGroup->hatch(NULL);
	}

	cout << beeGroup->size() << endl;

	delete beeGroup;
	test_farmland();
	system("pause");
	return 0;
}


void test_chicken_time_atmosphere(){
	Time* time = Time::instance();
	Atmosphere* atm = Atmosphere::get_instance();
	time->report();
	vector<Abstract*> abs_list;
	abs_list.push_back(time);
	abs_list.push_back(atm);
	Cattle* cattle = new Cattle(&abs_list);
	time = time->hour_pass(7);
	time->report();
	time = time->hour_pass(4);
	time->report();
	time = time->hour_pass(7);
	time->report();
	time = time->hour_pass(100);
	time->report();

	atm->change_weathertype(WINDY);
	delete cattle;
}


void test_farmland(){
	FarmLand* farmland = new FarmLand(NULL, 100, 100, "farmland,1.0f");
	EffectFarmLand* effect_farm_land = new EffectFarmLand(farmland);
	Crop* crop = new Crop(NULL, 10, 50);
	effect_farm_land->plow(30);
	crop->plant_on(effect_farm_land);
	cout << "Because the crop is planted on an effect farmland, its output rate is set to " << crop->get_output_rate() << "." << endl;
	delete crop;
	delete farmland;
	delete effect_farm_land;
}