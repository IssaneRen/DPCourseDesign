#ifndef CF_ATMOSPHERE_H
#define CF_ATMOSPHERE_H
#include "Abstract.h"
using namespace::std;

#define GOOD_LUX 1.0;
#define BAD_LUX 0.5;


enum WEATHER_TYPE { 
	SUNNY,					//*晴天。植物可以光合光作用，光强最佳。
	RAINY,					//*雨天。光强降低
	WINDY,					//*起风。
	CLOUDY					//*阴天。光强降低。
};

//*由于继承自Abstratc，它也是observer。
//*Singleton：单例模式
//*大气：象征当前天气，不同的天气拥有不同的光强系数
class Atmosphere :public Abstract {

public:
	//*取得当前的天气类型。
	WEATHER_TYPE get_weather_type(){ return weather_; }

	//*用于设置当前天气。
	void change_weathertype(WEATHER_TYPE new_weather);

	//*取得singleton实例。
	static Atmosphere* get_instance();

	//*取得当前天气下的光强系数。
	float get_lux(){ return lux_; }

	//*被重写的获取类名的函数，返回"Atmosphere"
	virtual const char* get_class_name(){ return "Atmosphere"; }
protected:
	Atmosphere();
	~Atmosphere();

	float lux_;								//光强系数。影响植物光合作用一次取得的energy量

	WEATHER_TYPE weather_;					//当前天气类型

	static Atmosphere* instance_;			//singleton的static实例

	virtual void notify();

	//*它的唯一工作就是在析构函数中删除Atmosphere的实例
	//*静态声明出的对象会在程序结束时被回收空间，并调用其析构函数
	//*借此释放state影响下扑朔迷离的time_instance_的空间
	class AtmosphereReleaser
	{
	public:
		~AtmosphereReleaser()
		{
			if (Atmosphere::instance_)

				delete Atmosphere::instance_;
		}
		static AtmosphereReleaser garbo;
	};

};



#endif