#include "Object.h"
#include "Time.h"
#include"Atmosphere.h"
using namespace std;
int main(){
	Time* time = Time::instance();
	time->report();
	Atmosphere* a = Atmosphere::getInstance();
	system("pause");
	return 0;
}