#include "Object.h"
#include "Time.h"
#include "Crop.h"
#include "Insect.h"
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

void testTime();
void testInsect();
void testTool();
void stock_test();
void test_farmland();
void test_chicken_time_atmosphere();

int main(){
	//add Test Functions here!
	//Do not delete test Functions
	//instead, delete invoking them here in main() if you want to

	//testTool();
	//test_chicken_time_atmosphere();

	test_farmland();

	system("pause");
	return 0;
}

void testTime() 
{
	Time* time = Time::instance();
	int test[] = { 2017, 15, 12, 15 };
	time->set_time(test);
	time->report();
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

void test_time_h() {
	Time* time = Time::instance();
	time->report();
	time = time->hour_pass(7);
	time->report();
	time = time->hour_pass(4);
	time->report();
	time = time->hour_pass(7);
	time->report();
	time = time->hour_pass(7);
	time->report();
}


void stock_test(){
	Stock* stock = new Stock(NULL, 100);
	Chicken* chicken = new Chicken();
	stock->put_in(chicken);
	StockList::Iterator* chicken_find = stock->find(chicken);
	if (chicken_find != NULL)cout << "FIND!" << endl;
	else cout << "not find" << endl;
	delete chicken_find;
	delete chicken;
	delete stock;
}

void testTool()
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