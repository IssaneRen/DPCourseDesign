#ifndef CF_LIVING_H
#define CF_LIVING_H
#include "Entity.h"
#include "Atmosphere.h"
#include<string>
using namespace std;

//*表征生物的类，继承自Entity，因而也是Observer
//*具有年龄的设定，会随时间流逝而成长。到达最大年龄时将会死去，并且不再对Subject的变化做出反应。
//*注意：年龄的设定，其单位为小时。
//*重要的事情说两遍，年龄的单位为小时。
//*或许你已经觉得烦了，但我觉得有必要再说一遍，年龄的单位为小时。
class Living :public Entity{
public:
	//*abs_list：需要注册的subject列表。
	//*size：该生物的大小。
	//*max_age：该生物的最大年龄。
	Living(vector<Abstract*>* abs_list = NULL, int size = 0, int max_age = 100);

	virtual ~Living(){}

	//*死亡函数。
	//*被调用后，该生物将会死亡，不再对Subject的变化做出反应。
	//*虽然或许可能多余了，即使是死去的生物，new出的空间也不会自动被回收，还请不要忘了delete。
	virtual void die(){
		alive_ = false;
		format_output("Living::die()", "is dead");
	}

	//*成长函数
	//*注意：纯虚
	//*由于Time类的实现涉及Animal类（该类的子类，所以该函数无法在这一层进行实现。
	//*Animal的子类必须实现此函数。
	virtual void grow() = 0;

	//*用以获取年龄的函数
	//*const：你无法通过此函数修改对象的年龄。
	const int get_age() { return age_; }

	//*被重写的获取类名的函数，返回"Living"
	virtual const char* get_class_name(){ return "Living"; }

	//*返回表征是否依然活着的bool值。
	bool is_alive(){ return alive_; }

	//*设置生物是否存活
	void set_alive(bool alive) { alive_ = alive; }

protected:
	//*年龄
	int age_;
	//*最大年龄
	int max_age_;
	//*健康度
	int health_;
	//*表征是否依然活着
	bool alive_;

	//*反应函数。当时间流逝时，由update()调用此函数。
	//*注意：纯虚
	virtual void time_pass_by() = 0;

	//*反应函数。当天气变化时，由update()调用此函数。
	//*注意：纯虚
	virtual void when_atmosphere_changed() = 0;
};


#endif // !CF_ENTITY_H



