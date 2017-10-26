#include "Object.h"
#include "Time.h"
#include "InsectGroup.h"
#include "Insect.h"

int main(){
	Time* time = Time::instance();
	int test[] = { 2017, 15, 12, 15 };
	time->set_time(test);
	time->report();

	InsectGroup* beeGroup = new InsectGroup(new string("bee"));
	beeGroup->hatch(100, NULL, 0, 0, NON);
	cout << beeGroup->size() << endl;

	InsectIterator* it = beeGroup->create_iterator();

	//it = it->next();

	Insect* temp = (Insect*)it->value()->get_value();

	temp->cry();
	system("pause");
	return 0;
}