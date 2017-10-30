#ifndef CF_OBJECT_H
#define CF_OBJECT_H
#include<iostream>
#include<string>

using namespace std;


//*单根类，所有的类都继承自此类
class Object{
public:
	//*构造函数。在此为对象赋予独一无二的ID
	Object(){ id_ = counter_++; }

	virtual ~Object(){}

	//*调用此函数以获取对象的ID
	//const：你无法借由此函数改变对象的ID。
	const int get_id(){ return id_; }

	//*取得对象所属的类名。
	//*每个子类都应当重写此函数，以返回正确的类名
	virtual const char* get_class_name(){ return "Object"; }

	//*标准输出函数，不建议子类重写。
	//*按照 类名：ID： 类名::成员函数名()：描述语句 的格式进行输出。
	//*描述语句message默认为空字符串，在需要时自行赋予。
	virtual const void format_output(const char* class_function_name, const char* message = ""){
		cout << get_class_name() << " : " << id_ << " : " << class_function_name << " : " << message << endl;
	}

protected:
	int id_;						//*对象的ID。每个对象在创建时都会被赋予唯一的ID。

	static int counter_;			//*计数器，用以赋予对象唯一的ID，在赋予后自加，等待下一个对象被创建
};



#endif