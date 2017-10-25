#include "Object.h"
#include "Time.h"

int main(){
	Time* time = Time::instance();
	time->report();
	system("pause");
	return 0;
}