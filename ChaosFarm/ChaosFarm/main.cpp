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
	//add Test Functions here!
	//Do not delete test Functions
	//instead, delete invoking them here in main() if you want to

	//Test Tool
	testTool();

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

void testTool()
{
	//Tool* tool = new Tool(nullptr,0);
	UnitTool* mugun = new UnitTool("木棍");
	auto list = new vector<Tool*>;
	list->push_back(mugun);
	mugun->fix();
	CollectedTool* chuizi = new CollectedTool("锤子", list);
	if (chuizi->checkWorstTool()->getName().length() > 0)
		cout << "Needed Fix most urgently: " << chuizi->checkWorstTool()->getName() << endl;
	chuizi->outputDurability();
	chuizi->loss();
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