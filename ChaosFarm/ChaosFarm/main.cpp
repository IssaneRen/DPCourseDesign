#include "Object.h"
#include "Time.h"
#include "InsectGroup.h"
#include "Insect.h"
#include "Bee.h"
#include "Tool.h"
#include "UnitTool.h"
#include "CollectedTool.h"

void testTime();
void testInsect();
void testTool();


int main(){
	//add Test Functions here!
	//Do not delete test Functions
	//instead, delete invoking them here in main() if you want to

	testTime();
	testInsect();
	testTool();

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

void testInsect() 
{	
	InsectGroup* beeGroup = new InsectGroup(new string("bee"));
	beeGroup->hatch(100, NULL, 0, 0, NON);
	cout << beeGroup->size() << endl;

	InsectIterator* it = beeGroup->create_iterator();
	Insect* temp = (Insect*)it->value()->get_value();
	temp->cry();
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
	if(chuizi->checkWorstTool()->getName().length() > 0)
		cout << "锤子中最需要修理的是：" << chuizi->checkWorstTool()->getName() << endl;
	chuizi->outputDurability();
	chuizi->loss();
}