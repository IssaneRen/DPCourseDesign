#include "Object.h"
#include "Time.h"
#include "InsectGroup.h"
#include "Insect.h"
#include "Bee.h"

void testTime();
void testInsect();


int main(){
	//add Test Functions here!
	//Do not delete test Functions
	//instead, delete invoking them here in main() if you want to

	testTime();
	testInsect();

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