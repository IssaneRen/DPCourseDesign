#include "Object.h"
#include "Time.h"
#include "Crop.h"
#include "Insect.h"
#include "Time.h"
#include "BaseFarmland.h"
#include "Bee.h"
#include "Tool.h"
#include "UnitTool.h"
#include "CollectedTool.h"
#include "Weed.h"
#include "Stock.h"
#include "Chicken.h"

void testTime();
void testInsect();
void testTool();
void stock_test();
void test_farmland();
void test_chicken_time();
void test_Crop();


int main(){
	//add Test Functions here!
	//Do not delete test Functions
	//instead, delete invoking them here in main() if you want to

	//testTool();
	//test_chicken_time();
	//test_Crop();
	//test_chicken_time();
	
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

void test_chicken_time(){
	Time* time = Time::instance();
	time->report();
	vector<Abstract*> abs_list;
	abs_list.push_back(time);
	Chicken* chicken = new Chicken(&abs_list);
	time = time->hour_pass(7);
	time->report();
	time = time->hour_pass(4);
	time->report();
	time = time->hour_pass(7);
	time->report();
	time = time->hour_pass(100);
	time->report();
	delete chicken;
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
	BaseFarmLand* base_farm_land = new BaseFarmLand(NULL, 100, 100, "base farmland", 0.3);
	FarmLand* farm_land = new FarmLand(base_farm_land);
	EffectFarmLand* effect_farm_land = new EffectFarmLand(farm_land);
	Crop* crop = new Crop(NULL, 10, 50);
	crop->plant_on(effect_farm_land);
	cout << "Because the crop is planted on an effect farmland, its output rate is set to " << crop->get_output_rate() << "." << endl;
}

void test_Crop(){
	Time* time = Time::instance();
	time->report();
	vector<Abstract*> abs_list;
	abs_list.push_back(time);
	Crop* crop1 = new Crop(&abs_list, 0, 8);						//最大年龄为8
	crop1->absorb_water();
	crop1->weaken(5);
	for (int i = 0; i < 10;i++)
		time = time->hour_pass();									//经过1小时
}