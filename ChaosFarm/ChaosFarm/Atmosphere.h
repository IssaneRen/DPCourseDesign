#ifndef CF_ATMOSPHERE_H
#define CF_ATMOSPHERE_H
#include "Abstract.h"
using namespace::std;

#define GOOD_LUX 1.0;
#define BAD_LUX 0.5;


enum WEATHER_TYPE { 
	SUNNY,					//晴天。植物可以光合光作用，光强最佳。
	RAINY,					//雨天。光强降低，并且对昆虫孵化有影响。
	WINDY,					//起风。对昆虫孵化有影响。
	CLOUDY					//阴天。光强降低。
};

//Mind：using Singleton
class Atmosphere :public Abstract {

public:
	//取得当前的天气类型。
	WEATHER_TYPE get_weather_type(){ return weather_; }

	//用于设置当前天气。
	void change_weathertype(WEATHER_TYPE new_weather);

	//取得singleton实例。
	static Atmosphere* getInstance();

	//取得当前天气下的光强系数。
	float get_lux(){ return lux_; }

protected:
	Atmosphere();
	~Atmosphere();

	float lux_;								//光强系数。影响植物光合作用一次取得的energy量

	WEATHER_TYPE weather_;					//当前天气类型

	static Atmosphere* instance_;			//singleton的static实例

	virtual void notify();
};



#endif