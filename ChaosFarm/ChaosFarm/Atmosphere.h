#ifndef CF_ATMOSPHERE_H
#define CF_ATMOSPHERE_H
#include "Abstract.h"
using namespace::std;

enum weather_type{SUNNY,WINDY,RAINY,CLOUDY};
enum SmellType{FRAGANCE,STINK};
class Atmosphere :public Abstract{

public:
	weather_type weather;
	float smell[2];
	float water_content;
	float oxygen_content;
	float carbon_dioxide_content;
	float microorganism_content;
	virtual void change_water_content(float new_content);
	virtual void change_oxygen_content(float new_content);
	virtual void change_carbon_dioxide_content(float new_content);
	virtual void change_microorganism_content(float new_content);
	virtual void change_weathertype(weather_type new_weather);
	virtual void add_smell(SmellType smell,float concentration);                  
	static Atmosphere* getInstance();
private:
    Atmosphere();
	~Atmosphere();
	static Atmosphere* atmosphere;                                                //单例模式,访问atmosphere这个实例
};



#endif