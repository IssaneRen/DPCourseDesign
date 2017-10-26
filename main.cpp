#include "Object.h"
#include "Time.h"
#include "Plant.h"
#include "Weed.h"
#include <vector>

int main(){
	Object o1, o2, o3, o4;
	o1.report();
	o2.report();
	o3.report();
	o4.report();
	Time* time = Time::instance();
	time->report();


	vector<Abstract*>* abs_list = new vector<Abstract*>();

	string weed_name_ = "weed";
	Weed* myWeed=new Weed(abs_list, 1, 2, &weed_name_, SEX::NON);
	int type = 2;
	
	myWeed->setStrategy(type);
	myWeed->doIt();

	

	return 0;
}