#include "Object.h"
#include "Time.h"

int main(){
	Object o1, o2, o3, o4;
	o1.report();
	o2.report();
	o3.report();
	o4.report();
	Time* time = Time::instance();
	time->report();
	system("pause");
	return 0;
}