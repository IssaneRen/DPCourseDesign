#include "Object.h"
#include "Time.h"

int main(){
	Time* time = Time::instance();
	int test[] = { 2017, 15, 12, 15 };
	time->set_time(test);
	time->report();
	system("pause");
	return 0;
}