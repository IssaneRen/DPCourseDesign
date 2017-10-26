#include "Object.h"
#include "Time.h"
#include "Crop.h"

int main(){
	Time* time = Time::instance();
	time->report();
	vector<Abstract*>* a = new vector<Abstract*>;
	string name = "haha";
	Crop* c1 = new Crop(a,1,1,&name,NON);
	c1->time_pass_by();
	system("pause");
	return 0;
}