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
		virtual Object* value();
		virtual void turn_next();
		virtual void turn_previous();
		virtual void turn_first();
		virtual void turn_last();
		virtual bool has_next();
		virtual bool has_previous();
		virtual const char* get_class_name() { return "Shelf::Iterator"; }
	};
	~Shelf()
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
	void find_kind(string kind_name);
	int usable_capacity();
	void dilate(int extend_space);
	int capacity();
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

	virtual void time_pass_by();

	virtual void when_atmosphere_changed();

	virtual void fix(int n = 1);

	void set_max_durability(int value);

	virtual const char* get_class_name() { return "Warehouse"; }

	int size();
	bool is_empty();
	void begin(Collection::FarmIterator& iterator);
	void end(Collection::FarmIterator& iterator);
	void add(Object* new_element);
	void remove(Collection::FarmIterator& iterator);
	void show_list();
	void find_kind(string kind_name);
	int usable_capacity();
	void dilate(int extend_space);
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