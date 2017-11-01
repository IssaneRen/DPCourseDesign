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

//void test_insect();
void test_tool();
void stock_test();
void test_farmland();
void test_crop();
void test_chicken_cattle_time_atmosphere();

int main() {
	//add Test Functions here!
	//Do not delete test Functions
	//instead, delete invoking them here in main() if you want to
	cout << "==================Test Chicken Cattle Time Atmosphere==================" << endl;
	test_chicken_cattle_time_atmosphere();
	cout << "===============================Test Tool===============================" << endl;
	test_tool();
	cout << "===============================Test Crop===============================" << endl;
	test_crop();
	cout << "===========================Test Crop FarmLand==========================" << endl;
	test_farmland();

	system("pause");
	return 0;
}

void test_chicken_cattle_time_atmosphere() {
	Time* time = Time::instance();
	Atmosphere* atm = Atmosphere::get_instance();
	time->report();
	vector<Abstract*> abs_list;
	abs_list.push_back(time);
	abs_list.push_back(atm);
	Chicken* chicken = new Chicken(&abs_list);
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
	time->remove_observer(chicken);
	time->remove_observer(cattle);
	atm->remove_observer(chicken);
	atm->remove_observer(cattle);
	delete cattle;
	delete chicken;
}


void test_tool()
{
	//Tool* tool = new Tool(nullptr,0);
	UnitTool* mugun = new UnitTool("木棍");
	UnitTool* chuizitou = new UnitTool("锤子头");
	auto list = new vector<Tool*>;
	list->push_back(mugun);
	list->push_back(chuizitou);
	CollectedTool* chuizi = new CollectedTool("锤子", list);
	chuizitou->loss();
	if (chuizi->checkWorstTool()->getName().length() > 0)
		cout << "锤子中最需要修理的是：" << chuizi->checkWorstTool()->getName() << endl;
	chuizi->outputDurability();
	chuizi->loss();
}

void testTool()
{
	//Tool* tool = new Tool(nullptr,0);
	UnitTool* mugun = new UnitTool("鏈ㄦ");
	auto list = new vector<Tool*>;
	list->push_back(mugun);
	mugun->fix();
	CollectedTool* chuizi = new CollectedTool("閿ゅ瓙", list);
	if (chuizi->checkWorstTool()->getName().length() > 0)
		cout << "Needed Fix most urgently: " << chuizi->checkWorstTool()->getName() << endl;
	chuizi->outputDurability();
	chuizi->loss();
}


void test_farmland() {
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

void test_crop() {
	Time* time = Time::instance();
	time->report();
	vector<Abstract*> abs_list;
	abs_list.push_back(time);
	Crop* crop1 = new Crop(&abs_list, 0, 8);						//最大年龄为8
	crop1->absorb_water();
	crop1->weaken(5);
	for (int i = 0; i < 10; i++)
		time = time->hour_pass();									//经过1小时
	time->remove_observer(crop1);
}