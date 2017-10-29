#pragma once
#include "Facility.h"
#include "List.h"
#include "Collection.h"

class ItemList;
class Warehouse;

class ItemList :public Collection
{
public:
	friend class Warehouse;
	class Iterator :public FarmIterator
	{
	public:
		friend class ItemList;
		Iterator();
		Iterator(ItemList* list);
		Iterator(Iterator* another);
		virtual ~Iterator() {}
		virtual Object* value();
		virtual void turn_next();
		virtual void turn_previous();
		virtual void turn_first();
		virtual void turn_last();
		virtual bool has_next();
		virtual bool has_previous();
	};
	~ItemList()
	{
		delete list_;
	}
	virtual int size();
	virtual bool is_empty();
	virtual void begin(FarmIterator& iterator);
	virtual void end(FarmIterator& iterator);
	virtual void add(Object* new_element);
	virtual void remove(FarmIterator& iterator);
	void show_list();
	List* find_kind(string kind_name);
	int usable_capacity();
	void dilate(int extend_space);
private:
	List* list_;
	int capacity_;
	int used_space_;
	ItemList();
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

	virtual void time_pass_by();

	virtual void when_atmosphere_changed();

	virtual void fix(int n = 1);

	ItemList* get_item_list();

	void set_max_durability(int value);

	
private:
	static Warehouse* warehouse_p_;

	ItemList* item_list_;

	Warehouse(vector<Abstract*>* abs_list, int size, int max_durability) :Facility(abs_list, size)
	{
		max_durability_ = max_durability;
		item_list_ = new ItemList();
	}

	int max_durability_;

	virtual ~Warehouse()
	{
		delete item_list_;
	}
};