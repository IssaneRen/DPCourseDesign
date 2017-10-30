#pragma once
#include "Object.h"

/*集合*/
class Collection :public Object
{
public:
	Collection(){}
	virtual ~Collection(){}
	class FarmIterator :public Object
	{
	public:
		FarmIterator(){}
		virtual ~FarmIterator(){}
		friend class Collection;
		//*获取该节点的值
		virtual Object* value() = 0;
		//*指向下一节点
		virtual void turn_next() = 0;
		//*指向上一节点
		virtual void turn_previous() = 0;
		//*指向首节点
		virtual void turn_first() = 0;
		//*指向尾节点
		virtual void turn_last() = 0;
		//*判断是否有下一节点
		virtual bool has_next() = 0;
		//*判断是否有上一节点
		virtual bool has_previous() = 0;
		//*被重写的获取类名的函数，返回"FarmIterator"
		virtual const char* get_class_name(){ return "FarmIterator"; }
	protected:
		Object* current_node_;
	};
	//*获取大小
	virtual int size() = 0;
	//*添加新元素
	virtual void add(Object* new_element) = 0;
	//*移除iterator指向的元素
	virtual void remove(FarmIterator& iterator) = 0;
	//*判断是否为空
	virtual bool is_empty() = 0;
	//*将iterator指向开始处
	virtual void begin(FarmIterator& iterator) = 0;
	//*将iterator指向结束处
	virtual void end(FarmIterator& iterator) = 0;
};