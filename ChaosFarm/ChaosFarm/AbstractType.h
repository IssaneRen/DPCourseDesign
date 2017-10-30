#ifndef CF_ABSTRACT_TYPE_H
#define CF_ABSTRACT_TYPE_H

//*表征Subject——Abstract的类型的枚举
//*用以帮助Observer——Entity识别调用其update函数的Abstract类型
enum AbstractType{
	ERROR = 0,				//错误，未知的Abstract类型
	TIME = 1,				//Time类
	ATMOSPHERE = 2,			//Atmosphere类
};

#endif // !CF_ABSTRACT_TYPE


