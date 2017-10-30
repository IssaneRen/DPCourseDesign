#pragma once
#include "Facility.h"
#include "List.h"
#include "Collection.h"

class Shelf;
class Warehouse;

class Shelf :public Collection
{
public:
	friend class Warehouse;
	class Iterator :public FarmIterator
	{
	public:
		friend class Shelf;
		Iterator();
		Iterator(Shelf* list);
		Iterator(Iterator* another);
		virtual ~Iterator() {}
		//*获取该节点的值
		virtual Object* value();
		//*指向下一节点
		virtual void turn_next();
		//*指向上一节点
		virtual void turn_previous();
		//*指向首节点
		virtual void turn_first();
		//*指向尾节点
		virtual void turn_last();
		//*判断是否有上一节点
		virtual bool has_next();
		//*判断是否有下一节点
		virtual bool has_previous();
		//*被重写的获取类名的函数，返回"Shelf::Iterator"
		virtual const char* get_class_name() { return "Shelf::Iterator"; }
	};
	//*析构函数
	~Shelf()
	{
		delete list_;
	}
	//*获取大小
	virtual int size();
	//*判断是否为空
	virtual bool is_empty();
	//*将iterator指向开始处
	virtual void begin(FarmIterator& iterator);
	//*将iterator指向结束处
	virtual void end(FarmIterator& iterator);
	//*添加新元素
	virtual void add(Object* new_element);
	//*移除iterator指向的元素
	virtual void remove(FarmIterator& iterator);
	//*显示物品列表
	void show_list();
	//*查找某一种类的物品并显示
	void find_kind(string kind_name);
	//*获取剩余容量
	int usable_capacity();
	//*扩容
	void dilate(int extend_space);
	//*获取容量
	int capacity();
	//*被重写的获取类名的函数，返回"Living"
	virtual const char* get_class_name() { return "Shelf"; }
private:
	List* list_;
	int capacity_;
	int used_space_;
	Shelf();
};

class Warehouse :public Facility
{
public:
	static Warehouse* get_instance(vector<Abstract*>* abs_list)
	{
		if (warehouse_p_ != NULL)
		{
			return warehouse_p_;
		}
		else
		{
			warehouse_p_ = new Warehouse(abs_list, 100, 100);
			return warehouse_p_;
		}
	}
	//*反应函数。当时间流逝时，由update()调用此函数。
	virtual void time_pass_by();
	//*反应函数。当天气变化时，由update()调用此函数。
	virtual void when_atmosphere_changed();
	//*修理，恢复耐久
	virtual void fix(int n = 1);
	//*设置最大耐久
	void set_max_durability(int value);
	//*被重写的获取类名的函数，返回"Living"
	virtual const char* get_class_name() { return "Warehouse"; }
	//*判断大小
	int size();
	//*判断是否为空
	bool is_empty();
	//*将iterator指向开始处
	void begin(Collection::FarmIterator& iterator);
	//*将iterator指向结束处
	void end(Collection::FarmIterator& iterator);
	//*添加新元素
	void add(Object* new_element);
	//*移除iterator指向的元素
	void remove(Collection::FarmIterator& iterator);
	//*显示物品列表
	void show_list();
	//*查找某一种类的物品并显示
	void find_kind(string kind_name);
	//*获取剩余容量
	int usable_capacity();
	//*扩容
	void dilate(int extend_space);
	//*获取容量
	int capacity();
private:
	static Warehouse* warehouse_p_;

	Shelf* shelf_;

	Warehouse(vector<Abstract*>* abs_list, int size, int max_durability) :Facility(abs_list, size)
	{
		max_durability_ = max_durability;
	}

	int max_durability_;

	virtual ~Warehouse()
	{
		delete shelf_;
	}
};